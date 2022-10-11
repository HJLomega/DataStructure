#include "LinkList.cpp"							//引用单链表泛型类
template <typename T>
void Commnodes(LinkList<T> &A,LinkList<T> &B,LinkList<T> &C)
{
	LinkNode<T> *p=A.head->next;				//p指向A的首结点
 	LinkNode<T> *q=B.head->next;	  			//q指向B的首结点
 	LinkNode<T> *r=C.head;			  			//r为C的尾结点
 	while (p!=NULL && q!=NULL)	    			//两个单链表都没有遍历完
  	{	if (p->data<q->data)					//跳过较小的p结点
        	p=p->next;
    	else if (q->data<p->data)				//跳过较小的q结点
        	q=q->next;
        else									//p结点和q结点值相同
      	{	LinkNode<T> *s=new LinkNode<T>(p->data);
        	r->next=s;
        	r=s;					    		//将s结点链接到C的末尾
        	p=p->next;
        	q=q->next;
    	}
    }
    r->next=NULL;						//尾结点next置空
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
	Commnodes(A,B,C);
	cout << "单链表C: "; C.DispList();
	return 0;
}
