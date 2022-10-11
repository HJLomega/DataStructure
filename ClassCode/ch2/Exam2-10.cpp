#include "LinkList.cpp"						//引用单链表泛型类
template <typename T>
void Split(LinkList<T> &L,LinkList<T> &A,LinkList<T> &B)
{
	LinkNode<T> *p=L.head->next,*q;        	//p指向L的首结点
	LinkNode<T> *r=A.head;					//r始终指向A的尾结点	
 	while (p!=NULL)							//遍历L的所有数据结点
  	{	r->next=p;
    	r=p;							    //尾插法建立A
		p=p->next;							//p后移一个结点
     	if (p!=NULL)
     	{	q=p->next;						//临时保存p结点的后继结点
        	p->next=B.head->next;			//头插法建立B
        	B.head->next=p;
        	p=q;							//p指向q结点
        }
	}
	r->next=NULL;							//尾结点next置空
}
int main()
{
	int a[]={1,2,3,4};
	int n=sizeof(a)/sizeof(a[0]);
	LinkList<int> L;						//建立元素类型为int的单链表对象
	cout << "创建单链表L" << endl;
	L.CreateListR(a,n);
	cout << "单链表L: "; L.DispList();
	cout << "L -> A,B" << endl;
	LinkList<int> A,B;
	Split(L,A,B);
	cout << "单链表A: "; A.DispList();
	cout << "单链表B: "; B.DispList();
	
	return 0;
}
