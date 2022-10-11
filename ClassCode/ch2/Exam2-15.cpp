#include "CLinkList.cpp"						//引用循环单链表泛型类
template <typename T>
int Count(CLinkList<T> &L,T x)               	//求解算法
{	int cnt=0;									//cnt置为0
 	LinkNode<T> *p=L.head->next;			    //首先p指向首结点
 	while (p!=L.head)							//遍历循环单链表
  	{	if (p->data==x)
      		cnt++;								//找到一个值为x的结点cnt增1
    	p=p->next;								//p后移一个结点
    }
	return cnt;
}
int main()
{
	int a[]={1,5,3,5,2,5};
	int n=sizeof(a)/sizeof(a[0]);
	CLinkList<int> A;						//建立元素类型为int的循环单链表对象
	cout << "创建循环单链表A" << endl;
	A.CreateListR(a,n);
	cout << "循环单链表A: "; A.DispList();
	int x=5;	
	cout << "x=" << x << "的结点个数=" << Count(A,x) << endl;
	return 0;
}
