#include<iostream>
using namespace std;
struct LinkNode								//链串结点类型
{	char data;								//存放一个字符
	LinkNode *next;							//指向下一个结点
	LinkNode():next(NULL) {}				//构造函数
	LinkNode(char d):data(d),next(NULL) {}	//重载构造函数
	 
};
class LinkString							//链串类
{
public:
	LinkNode *head;							//链串头结点head
	int length;								//链串长度 
	LinkString()							//构造函数
	{
		head=new LinkNode();				//创建头结点
		head->next=NULL;
		length=0;
	}
	~LinkString()							//析构函数
	{
		LinkNode *pre,*p;
		pre=head;p=pre->next;
		while (p!=NULL)						//释放链串所有结点空间
		{
			delete pre;
			pre=p; p=p->next;				//pre,p同步后移 
		}
		delete pre;
	}
    void StrAssign(char *cstr)		 		//创建一个串
	{
		LinkNode *r=head;					//r始终指向尾结点
		int i=0;
		for (;cstr[i]!='\0';i++)		//循环建立字符结点
		{
			LinkNode *p=new LinkNode(cstr[i]);
			r->next=p; r=p;					//将p结点插入到尾部
		}
		length=i;
		r->next=NULL;						//尾结点的next置为NULL
	}
	void operator=(LinkString &t)			//重载=运算符实现串复制StrCopy
	{
		LinkNode *p=t.head->next;
		LinkNode *r=head;					//r始终指向尾结点
		while (p!=NULL)						//将t中结点p复制产生结点q
		{
			LinkNode *q=new LinkNode(p->data);
			r->next=q; r=q;					//将结点q插入到尾部
			p=p->next;
		}		
		r->next=NULL;						//尾结点的next置为NULL
		length=t.length;
	}
	int getlength()							//求串长度
	{
		return length;
	}
	char geti(int i)						//返回序号i的字符
	{
		if (i<0 || i>=length)
			throw -1;			
		LinkNode *p=head;
        int j=-1;
        while (j<i)                          //查找序号为i的结点p
        {	j++;
            p=p->next;
        }
		return p->data;                       //返回p结点值
    }

    void seti(int i,char x)					//设置序号i的字符为x
	{
		if (i<0 || i>=length)
			throw -1;			
		LinkNode *p=head;
        int j=-1;
        while (j<i)                          //查找序号为i的结点p
        {	j++;
            p=p->next;
        }
		p->data=x;                       	//设置p结点的值
    }

	LinkString &operator+(LinkString &t) 		//串连接,Concat
	{
		static LinkString s;	//新建一个空串
		LinkNode *p=head->next,*q;
		LinkNode *r=s.head;
		while (p!=NULL)					//将当前链串的所有结点复制到s
		{
			q=new LinkNode(p->data);	//新建结点q 
			r->next=q; r=q;				//将结点q链接到尾部
			p=p->next;
		}
		p=t.head->next;
		while (p!=NULL)					//将链串t的所有结点复制到s
		{
			q=new LinkNode(p->data);	//新建结点q
			r->next=q; r=q;				//将结点q链接到尾部
			p=p->next;
		}
		r->next=NULL;					//尾结点的next置为NULL
		s.length=length+t.length;
		return s;						//返回新建的链串
	}
	LinkString &SubStr(int i,int j)				//求子串
	{
		static LinkString s;							//建立结果空串 
		if (i<0 || i>=length || j<0 || i+j>length)
			return s;							//参数不正确时返回空串
		LinkNode *p=head->next,*q,*r;
		r=s.head;								//r指向新建链串的尾结点
		for (int k=0;k<i;k++)					//移动i-1个结点
			p=p->next;
		for (int k=0;k<j;k++) 					//将s的序号i结点开始的j个结点复制到s
		{
			q=new LinkNode(p->data);
			r->next=q; r=q;					//将*q结点插入到尾部
			p=p->next;
		}
		r->next=NULL;						//尾结点的next置为NULL
		s.length=j;
		return s;							//返回新建的链串
	}
	LinkString &InsStr(int i,LinkString &t)			//串插入
	{
		static LinkString s;						//新建一个空串
		if (i<0 || i>length)						//参数不正确时返回空串
			return s;
		LinkNode *p=head->next,*p1=t.head->next;
		LinkNode *r=s.head,*q;						//r指向新建链表的尾结点
		for (int k=0; k<i; k++)						//将当前链串的前i个结点复制到s
		{	q=new LinkNode(p->data);				//新建结点q 
			r->next=q; r=q;							//将结点q链接到尾部
			p=p->next;
		}
		while (p1!=NULL)							//将t中所有结点复制到s
		{	q=new LinkNode(p1->data);				//新建结点q
			r->next=q; r=q;							//将结点q链接到尾部
			p1=p1->next;
		}
		while (p!=NULL)								//将p及其后的结点复制到s
		{	q=new LinkNode(p->data);				//新建结点q
			r->next=q; r=q;							//将结点q链接到尾部
			p=p->next;
		}
		s.length=length+t.length;
		r->next=NULL;								//尾结点的next置为空
		return s;									//返回新建的链串
	}
	LinkString &DelStr(int i,int j)			//串删除
	{	static LinkString s;	//新建一个空串
		if (i<0 || i>length || i+j>length)				//参数不正确时返回空串
			return s;
		LinkNode *p=head->next,*q;
		LinkNode *r=s.head;									//r指向新建链表的尾结点
		for (int k=0; k<i;k++)							//将s的前i个结点复制到s
		{	q=new LinkNode(p->data);
			r->next=q; r=q;							//将q结点插入到尾部
			p=p->next;
		}
		for (int k=0;k<j;k++)						//让p沿next跳j个结点
			p=p->next;
		while (p!=NULL)								//将p及其后的结点复制到s
		{	q=new LinkNode(p->data);
			r->next=q; r=q;							//将q结点插入到尾部
			p=p->next;
		}
		s.length=length-j;
		r->next=NULL;								//尾结点的next置为空
		return s;									//返回新建的链串
	}
	LinkString &RepStr(int i,int j,LinkString t) 	//串替换
	{
		static LinkString s;	//新建一个空串
		if (i<0 || i>length || i+j>length)				//参数不正确时返回空串
			return s;
		LinkNode *p=head->next,*p1=t.head->next,*q;
		LinkNode *r=s.head;									//r指向新建链表的尾结点
		for (int k=0; k<i; k++)						//将s的前i个结点复制到s
		{	q=new LinkNode(p->data);
			r->next=q; r=q;							//将q结点插入到尾部
			p=p->next;
		}
		for (int k=0;k<j;k++)						//让p沿next跳j个结点
			p=p->next;
		while (p1!=NULL)							//将t中所有结点复制到s
		{	q=new LinkNode(p1->data);
			r->next=q; r=q;							//将q结点插入到尾部
			p1=p1->next;
		}
		while (p!=NULL)								//将p及其后的结点复制到s
		{	q=new LinkNode(p->data);
			r->next=q; r=q;							//将q结点插入到尾部
			p=p->next;
		}
		s.length=length-j+t.length;
		r->next=NULL;								//尾结点的next置为空
		return s;									//返回新建的链串
	}
	void DispStr()			//串输出
	{
		LinkNode *p=head->next;				//p指向链串的头结点
		while (p!=NULL)
		{
			cout << p->data;
			p=p->next;						//p指向下一个结点
		}
		cout << endl;
	}
};

