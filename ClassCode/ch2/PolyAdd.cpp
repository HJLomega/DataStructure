#include<iostream>
using namespace std;
struct PolyNode						//多项式单链表结点类型
{
	double coef;					//系数
	int exp;						//指数
	PolyNode *next;					//指向下一个结点的指针
	PolyNode():next(NULL) {}		//构造函数
	PolyNode(double c,int e)		//重载构造函数 
	{
		coef=c;
		exp=e;
		next=NULL;
	} 
};
class PolyList							//多项式单链表类
{
public:
	PolyNode *head;						//多项式单链表的头结点指针
	PolyList()							//构造函数
	{
		head=new PolyNode();			//建立头结点
	}
	~PolyList()							//析构函数
	{
		PolyNode *pre=head,*p=pre->next;
		while (p!=NULL)
		{
			delete pre;
			pre=p; p=p->next;			//pre、p指针同步后移
		}
		delete pre;
	}
	void CreateList(char *fname)		//读文件采用尾插法建立多项式单链表
	{
		freopen(fname,"r",stdin);		//输入重定向到fname文件 
		PolyNode *s,*r;
		double c;
		int n,e;
		scanf("%d",&n);
		r=head;							//r始终指向尾结点,开始时指向头结点
		for (int i=0;i<n;i++)
		{
			scanf("%lf%d",&c,&e);
			s=new PolyNode(c,e);		//创建新结点s
			r->next=s;					//将结点s插入结点r之后
			r=s;
		}
		r->next=NULL;					//尾结点next域置为NULL
	}
	void Sort()							//对多项式单链表按exp域递减排序
	{
		PolyNode *p,*pre,*q;
		q=head->next;					//q指向开始结点
		if (q==NULL) return;			//原单链表空时返回
		p=head->next->next;				//p指向结点q的后继结点
		if (p==NULL) return;			//原单链表只有一个数据结点时返回
		q->next=NULL;					//构造只含一个数据结点的有序单链表
		while (p!=NULL)
		{
			q=p->next;					//q用于临时保存结点p后继结点
			pre=head;					//从有序表开头比较
			while (pre->next!=NULL && pre->next->exp>p->exp)
				pre=pre->next;			//在有序表中查找插入结点p的前驱结点pre
			p->next=pre->next;			//在结点pre之后插入结点p
			pre->next=p;
			p=q;						//继续处理原单链表余下的结点
		}
	}
	void DispPoly()						//输出多项式单链表
	{
		bool first=true;				//first为true表示是第一项
		PolyNode *p=head->next;			//p指向开始结点
		while (p!=NULL)	
		{				
			if (first)
			{
				printf("[%.1lf,%d]",p->coef,p->exp);				
				first=false;
			}
			else
				printf(",[%.1lf,%d]",p->coef,p->exp);				
			p=p->next;
		}
		printf("\n");
	}
};
void PolyAdd(PolyList &A,PolyList &B,PolyList &C) 	//A+B->C 
{	PolyNode *pa=A.head->next;				//pa指向A的开始结点
	PolyNode *pb=B.head->next;				//pb指向B的开始结点
	PolyNode *s,*r;
	double c;
	r=C.head;								//r指向尾结点
	while (pa!=NULL && pb!=NULL)
	{	if (pa->exp>pb->exp)						//归并指数较大的结点pa
		{	s=new PolyNode(pa->coef,pa->exp);	//复制产生结点s
			r->next=s; r=s;						//将结点s链到C末尾 
			pa=pa->next;
		}
		else if (pa->exp<pb->exp)				//归并指数较大的结点pb
		{	s=new PolyNode(pb->coef,pb->exp);	//复制产生结点s
			r->next=s; r=s;						//将结点s链到C末尾 
			pb=pb->next;
		}
		else										//两结点指数相等的情况 
		{	c=pa->coef+pb->coef;				//求两指数相等结点的系数和c
			if (c!=0)								//系数和不为0的情况
			{	s=new PolyNode(c,pa->exp);		//新建结点s
				r->next=s; r=s;					//将结点s链到C末尾 
			}
			pa=pa->next;
			pb=pb->next;
		}
	}
	if (pb!=NULL) pa=pb;						//复制余下的结点
	while (pa!=NULL)
	{	s=new PolyNode(pa->coef,pa->exp);		//复制产生结点s
		r->next=s; r=s;							//将结点s链到C末尾
		pa=pa->next;
	}
	r->next=NULL;								//尾结点的next域置为NULL
}
int main()
{
	freopen("abc.out","w",stdout);		//输出重定向到abc.out文件 
	PolyList A,B,C;			//建立3个多项式单链表对象
	A.CreateList("abc1.in");
	cout << "第1个多项式: "; A.DispPoly();
	A.Sort(); 
	cout << "排序后结果:  "; A.DispPoly();

	B.CreateList("abc2.in");
	cout << "第2个多项式: "; B.DispPoly();
	B.Sort(); 
	cout << "排序后结果:  "; B.DispPoly();

	PolyAdd(A,B,C);
	cout << "相加多项式:  "; C.DispPoly();
	return 0;
}
