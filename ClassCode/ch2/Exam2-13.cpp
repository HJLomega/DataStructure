#include "DLinkList.cpp"					//引用双链表泛型类
template <typename T>
void Delx(DLinkList<T> &L,T x)           	//求解算法
{	DLinkNode<T> *p=L.dhead->next;			//p指向首结点
 	while (p!=NULL && p->data!=x)			//查找第一个值为x的结点
  		p=p->next;
 	if (p!=NULL)							//找到值为x的结点p
  	{
    	p->prior->next=p->next;				//删除p结点
	  	if (p->next!=NULL)
     		p->next->prior=p->prior; 
     	delete p;							//释放空间 
	}
}
int main()
{
	int a[]={1,5,3,5,2};
	int n=sizeof(a)/sizeof(a[0]);
	DLinkList<int> A;					//建立元素类型为int的双链表对象
	cout << "创建双链表A" << endl;
	A.CreateListR(a,n);
	cout << "双链表A: "; A.DispList();
	int x=5;
	cout << "删除第一个" << x << endl;
	Delx(A,x);
	cout << "双链表A: "; A.DispList();
	return 0;
}
