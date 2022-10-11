#include<iostream>
#include<vector>
using namespace std;
struct EBNode					    //长子兄弟链中结点类
{	char data;				     	//结点的值
    EBNode *brother;				//指向兄弟
    EBNode *eson;					//指向长子结点
	EBNode() 						//构造函数 
	{
		brother=eson=NULL;
	}	
	EBNode(char d)					//重载构造函数 
	{
		data=d;
		brother=eson=NULL;
	}	
};
int Height(EBNode *t)                	//求t的高度
{	if (t==NULL)              			//空树高度为0
  		return 0;
 	int maxsh=0;
 	EBNode *p=t->eson;                 	//p指向t结点的长子
 	while (p!=NULL)
  	{	EBNode *q=p->brother;           //q临时保存结点p的后继结点
    	int sh=Height(p);               //递归求结点p的子树的高度
    	maxsh=max(maxsh,sh);        	//求结点t的所有子树的最大高度
    	p=q;
	}
 	return maxsh+1;
}
int main()
{
	EBNode *t,*b,*c,*d,*e,*f,*g;
	t=new EBNode('A');					//根结点 
	b=new EBNode('B');
	c=new EBNode('C');
	d=new EBNode('D');
	e=new EBNode('E');
	f=new EBNode('F');
	g=new EBNode('G');
	t->eson=b;
	b->eson=d; b->brother=c;
	d->brother=e;
	e->eson=g; e->brother=f;
	cout << "树高度: " << Height(t) << endl;
	return 0;
}
	

