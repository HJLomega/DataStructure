#include "LinkList.cpp"							//引用单链表泛型类
template <typename T>
int Maxcount(LinkList<T> &L)                    //求解算法
{
	int cnt=1;
 	LinkNode<T> *p=L.head->next;			   	//p指向首结点
 	T maxe=p->data;					    		//maxe置为首结点值
 	while (p->next!=NULL)						//循环到p结点为尾结点
 	{
  		if (p->next->data>maxe)					//找到更大的结点
  		{
  			maxe=p->next->data;					//第一次找到maxe的结点 
      		cnt=1;
      	}
    	else if (p->next->data==maxe)	   		//p结点为当前最大值结点
      		cnt++;								//次数增1 
     	p=p->next;
	}
	return cnt;
}

int main()
{
	int a[]={1,5,2,3,5,2,1,5};
	int n=sizeof(a)/sizeof(a[0]);
	LinkList<int> A;							//建立元素类型为int的单链表对象
	cout << "创建单链表A" << endl;
	A.CreateListR(a,n);
	cout << "单链表A: "; A.DispList();
	cout << "最大值结点个数=" << Maxcount(A) << endl;
	return 0;
}
