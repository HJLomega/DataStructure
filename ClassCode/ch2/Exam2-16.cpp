#include <iostream>
using namespace std;
struct Child					        	//小孩结点类型
{
	int no;                     			//小孩编号
	Child *next;							//下一个结点指针 
	Child(int d):no(d),next(NULL) {}		//构造函数
};

class Joseph						   		//求解约瑟夫问题类
{
	int n,m;
	Child *first;							//小孩循环单链表的首结点 
public:	
	Joseph(int n1,int m1):n(n1),m(m1) {}	//构造函数
	void CreateList()						//创建小孩循环单链表 
	{
		first=new Child(1);            		//循环单链表首结点
     	Child *r=first,*p;					//r为尾结点指针 
     	for (int i=2;i<=n;i++)
      	{	p=new Child(i);					//建立一个编号为i的新结点p
        	r->next=p;						//将p结点链到末尾
        	r=p;
        }
   		r->next=first;						//构成一个首结点为first的循环单链表
	}
	void Jsequence()						//输出约瑟夫序列
	{
		Child *p,*q; 
  		for (int i=1;i<=n;i++)				//共出列n个小孩
     	{	p=first;
        	int j=1;
        	while (j!=m)		    		//从first结点开始报数，报到第m个结点
         	{	j++;						//报数递增
            	p=p->next;			    	//移到下一个结点
         	}
         	cout << p->no << " ";		   	//该结点的小孩出列
			q=p->next;						//q指向结点p的后继结点
         	p->no=q->no;					//将结点q的值复制到结点p 
         	p->next=q->next;				//删除q结点
         	delete q;
         	first=p;						//从结点p重新开始
    	}
		cout << endl;
	}
};

int main()
{
	int n=6,m=3;
	Joseph L(n,m);
	cout << "n=" << n << "，m=" << m << "的约瑟夫序列:" << endl;
	L.CreateList();
	L.Jsequence();
	return 0;
}
