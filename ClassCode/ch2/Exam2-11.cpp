#include "LinkList.cpp"					//引用单链表泛型类
template <typename T>
void Merge2(LinkList<T> &A,LinkList<T> &B,LinkList<T> &C)
{
	LinkNode<T> *p=A.head->next;		//p指向A的首结点
 	LinkNode<T> *q=B.head->next;	  	//q指向B的首结点
 	LinkNode<T> *r=C.head;			  	//r为C的尾结点
 	while (p!=NULL && q!=NULL)	    	//两个单链表都没有遍历完
  	{	if (p->data<q->data)			//将较小结点p链接到C的末尾
      	{	r->next=p;
        	r=p;
        	p=p->next;
        }
    	else							//将较小结点q链接到C的末尾
      	{	r->next=q;
        	r=q;
        	q=q->next;
        }
    }
	r->next=NULL;						//尾结点next置空
 	if (p!=NULL) r->next=p;
 	if (q!=NULL) r->next=q;
 }

int main()
{
	int a[]={1,3,5};
	int n=sizeof(a)/sizeof(a[0]);
	LinkList<int> A;					//建立元素类型为int的单链表对象
	cout << "创建单链表A" << endl;
	A.CreateListR(a,n);
	cout << "单链表A: "; A.DispList();

	int b[]={2,3,4,5,8};
	int m=sizeof(b)/sizeof(b[0]);
	LinkList<int> B;					//建立元素类型为int的单链表对象
	cout << "创建单链表B" << endl;
	B.CreateListR(b,m);
	cout << "单链表B: "; B.DispList();
	LinkList<int> C;
	cout << "A,B -> C" << endl;
	Merge2(A,B,C);
	cout << "单链表C: "; C.DispList();
	return 0;
}
