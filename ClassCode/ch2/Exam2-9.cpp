#include "LinkList.cpp"					//引用单链表泛型类
template <typename T>
void Reverse1(LinkList<T> &L)          	//求解算法1
{
	LinkNode<T> *p=L.head->next,*q;	  	//p指向首结点
	L.head->next=NULL;		    		//将L置为一个空表
 	while (p!=NULL)						//用p遍历所有数据结点 
  	{	q=p->next;			    		//q临时保存p结点的后继结点
     	p->next=L.head->next;	    	//将p结点插入到表头
     	L.head->next=p;
     	p=q;
	}
}

template <typename T>
void Reverse2(LinkList<T> &L)          	//求解算法2
{
	LinkNode<T> *p=L.head->next,*q,*r;	//p指向首结点
	if (p==NULL) return;				//L为空单链表时返回
	q=p->next;
	if (q==NULL) return;				//L只有一个结点时返回
	r=q->next;
	if (r==NULL)						//L只有一个结点时
	{
		L.head->next=q;
		q->next=p;
		p->next=NULL;
		return;
	}
	p->next=NULL;						//原首结点p置为尾结点	
	while (r!=NULL)
	{
		q->next=p;						//修改结点q的next指针 
		p=q;							//(p,q,r)同步指针后移 
		q=r;
		r=r->next;
	}
	q->next=p;							//修改结点q的next指针
	L.head->next=q;
}

int main()
{
	int a[]={1,2,3,4,5,6};
	int n=sizeof(a)/sizeof(a[0]);
	LinkList<int> A;					//建立元素类型为int的单链表对象
	cout << "创建单链表A" << endl;
	A.CreateListR(a,n);
	cout << "单链表A: "; A.DispList();
	cout << "逆置单链表A" << endl;
	Reverse2(A);
	cout << "单链表A: "; A.DispList();
	return 0;
}
