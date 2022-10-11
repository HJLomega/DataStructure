#include <iostream>
using namespace std;
template <typename T>
struct DLinkNode										//循环双链表结点类型 
{
	T data;												//存放数据元素
	DLinkNode<T> *next;									//指向后继结点的指针
	DLinkNode<T> *prior;								//指向前驱结点的指针 
	DLinkNode():next(NULL),prior(NULL) {}				//构造函数 
	DLinkNode(T d):data(d),next(NULL),prior(NULL) {}	//重载构造函数 
};

template <typename T>
class CDLinkList										//循环双链表类
{
public:
	DLinkNode<T> *dhead;									//循环双链表头结点
	CDLinkList() 										//构造函数,创建一个空循环双链表
	{
		dhead=new DLinkNode<T>();
		dhead->next=dhead;								//构成循环的空链表
		dhead->prior=dhead; 
	}
	~CDLinkList() 								//析构函数,销毁循环双链表
	{
		DLinkNode<T> *pre,*p;
		pre=dhead;p=pre->next;
		while (p!=dhead)						//用p遍历结点并释放其前驱结点 
		{
			delete pre;							//释放pre结点 
			pre=p; p=p->next;					//pre,p同步后移一个结点 
		}
		delete pre;								//p等于dhead时pre指向尾结点,此时释放尾结点						
	}
	
	void CreateListF(T a[],int n)			//头插法建立循环双链表
	{
		for (int i=0;i<n;i++)				//循环建立数据结点
		{
			DLinkNode<T> *s=new DLinkNode<T>(a[i]);	//创建数据结点s
			s->next=dhead->next;					//修改s结点的next字段
			dhead->next->prior=s;
			dhead->next=s;							//修改头结点的next字段
			s->prior=dhead;							//修改s结点的prior字段
		}
	}
	void CreateListR(T a[],int n)					//尾插法建立循环双链表
	{
		DLinkNode<T> *s,*r;
		r=dhead;									//r始终指向尾结点,开始时指向头结点
		for (int i=0;i<n;i++)						//循环建立数据结点
		{
			s=new DLinkNode<T>(a[i]);				//创建数据结点s
			r->next=s;								//将结点s插入结点r之后
			s->prior=r;
			r=s;
		}
		r->next=dhead;								//将尾结点的next域置为dhead
		dhead->prior=r;								//将头结点的prior域置为结点r
	}

	void Add(T e)								//在循环双链表末尾添加一个值为e的结点 
	{
		DLinkNode<T> *s=new DLinkNode<T>(e); 	//新建结点s
 		DLinkNode<T> *p=dhead;
		while (p->next!=dhead)					//查找尾结点p
			p=p->next;
		p->next->prior=s;						//在结点p之后插入结点s
		s->next=p->next;
		p->next=s;
		s->prior=p;
	}

	int Getlength()                   			//求循环双链表中数据结点个数
	{
		DLinkNode<T> *p=dhead;
	 	int cnt=0;
 		while (p->next!=dhead)					//查找到尾结点为止
  		{	cnt++;
  			p=p->next;
  		}
 		return cnt;
 	}

	bool GetElem(int i,T &e)					//求循环双链表中序号为i的结点值
	{
		if (i<0) return false;              	//参数i错误返回false	
 		DLinkNode<T> *p=geti(i);				//查找序号i的结点 
 		if (p!=dhead)							//找到了序号i的结点p 
 		{
 			e=p->data;
		 	return true;						//成功找到返回true 
		}
 		else
 			return false;						//没有找到序号i的结点返回false 
 	} 
	bool SetElem(int i,T e)              		//设置序号为i的结点值
	{
		if (i<0) return false;             		//参数i错误返回false
 		DLinkNode<T> *p=geti(i);				//查找序号i的结点 
 		if (p!=NULL)							//找到了序号为i的结点p 
 		{
 			p->data=e;
 			return true;
 		}
 		else									//没有找到序号为i的结点
 			return false;						//参数i错误返回false
 	} 

	int GetNo(T e)								//查找第一个为e的元素的序号
	{
		int j=0;
	 	DLinkNode<T> *p=dhead->next;
 		while (p!=dhead && p->data!=e)
 		{
  			j++;								//查找元素e
   			p=p->next;
   		}
		if (p==dhead)
  			return -1;							//未找到时返回-1
		else
  			return j;							//找到后返回其序号
	}
	bool Insert(int i,T e)						//在循环双链表中序号i位置插入值为e的结点
	{
		if (i<0) return false; 					//参数i错误返回false
		DLinkNode<T> *s=new DLinkNode<T>(e);	//建立新结点s
 		DLinkNode<T> *p=geti(i-1);				//查找序号i-1的结点p
 		if (p!=NULL)							//找到了序号i-1的结点 
 		{
			s->next=p->next;					//修改s结点的next域
 			if (p->next!=NULL)					//修改p结点的非空后继结点的prior域
  				p->next->prior=s;
			p->next=s;							//修改p结点的next域
 			s->prior=p;							//修改s结点的prior域
 			return true;						//插入成功返回true 
 		}
 		else									//没有找到序号i-1的结点 
 			return false;						//参数i错误返回false
	}
	bool Delete(int i)							//在循环双链表中删除序号i位置的结点
	{
		if (i<0) return false; 					//参数i错误返回false
  		DLinkNode<T> *p=geti(i);				//查找序号i的结点
 		if (p!=NULL)							//找到了序号i的结点p 
 		{
			p->prior->next=p->next;				//修改p结点的前驱结点的next
			p->next->prior=p->prior;			//修改p结点后继结点的prior
			delete p;							//释放空间 
 			return true;						//删除成功返回true 
 		}
 		else 									//没有找到序号i-1的结点 
 			return false;						//参数i错误返回false  		
  	}
	void DispList()								//输出循环双链表所有结点值
	{
		DLinkNode<T> *p;
		p=dhead->next;							//p指向开始结点
		while (p!=dhead)						//p不为dhead,输出p结点的data域
		{
			cout << p->data << " ";
			p=p->next;							//p移向下一个结点
		}
		cout << endl;
	}
private:
	//*******************************************
	//序号i的正确范围：-1≤i<n，超出范围返回NULL
	//i=-1时返回头结点dhead
	//i≥0并且i<n时返回序号i的结点
	//*******************************************
	DLinkNode<T> *geti(int i)		      	//返回序号为i的结点
	{
		if (i<-1) return NULL;				//i<-1时返回NULL
		if (i==-1) return dhead;			//i=-1时返回头结点 
		DLinkNode<T> *p=dhead->next;		//首先p指向首结点 
 		int j=0;							//j置为0为首结点序号
 		while (j<i && p!=dhead)				//p移动i个结点 
 		{	j++;
   			p=p->next;
   		}
   		if (p==dhead)						//没有找到序号i的结点返回NULL
		   return NULL;
		else 
			return p;
	}
};

