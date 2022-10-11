#include "DLinkList.cpp"					//引用双链表泛型类
template <typename T>
void Swap(DLinkList<T> &L,T x)             //求解算法
{
	DLinkNode<T> *p=L.dhead->next,*q;		//p指向首结点
 	q=NULL;
 	while (p!=NULL)                  		//查找最后一个值为x的结点q
  	{	if (p->data==x) q=p;
  		p=p->next;
  	}
 	if (q==NULL || L.dhead->next==q)  		//不存在x结点或者该结点是首结点
  		return;                      		//直接返回
 	else                           			//找到了这样的结点q
  	{	DLinkNode<T> *pre=q->prior;			//pre指向结点q的前驱结点 
     	pre->next=q->next;             		//删除q结点
     	if (q->next!=NULL)
     		q->next->prior=pre;
    	pre->prior->next=q;            		//将q结点插入到pre结点之前
     	q->prior=pre->prior;
     	pre->prior=q;
     	q->next=pre;
     }
}
int main()
{
	int a[]={1,5,3,5,2};
	int n=sizeof(a)/sizeof(a[0]);
	DLinkList<int> A;						//建立元素类型为int的双链表对象
	cout << "创建双链表A" << endl;
	A.CreateListR(a,n);
	cout << "双链表A: "; A.DispList();
	int x=5;
	cout << "交换 x=" << x << endl;
	Swap(A,x);
	cout << "双链表A: "; A.DispList();
	return 0;
}
