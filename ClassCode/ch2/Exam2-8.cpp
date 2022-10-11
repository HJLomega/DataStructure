#include "LinkList.cpp"						//引用单链表泛型类
template <typename T>
void Delmaxnodes(LinkList<T> &L)         	//求解算法
{
	LinkNode<T> *p=L.head->next;           	//p指向首结点
  	T maxe=p->data;                      	//maxe置为首结点值
  	while (p->next!=NULL)					//查找最大结点值maxe
  	{	if (p->next->data>maxe)
      		maxe=p->next->data;
     	p=p->next;
 	}
	LinkNode<T> *pre=L.head;				//pre指向头结点
 	p=pre->next;							//p指向pre的后继结点
 	while (p!=NULL)							//p遍历所有结点
 	{
  		if (p->data==maxe)					//p结点为最大值结点
      	{	
		  	pre->next=p->next;				//删除p结点
		  	delete p;
         	p=pre->next;					//让p指向pre的后继结点
    	}
    	else
      	{
		  	pre=pre->next;					//pre后移一个结点
        	p=pre->next;					//让p指向pre的后继结点
        }
    }
}

int main()
{
	int a[]={1,5,2,3,5,2,1,5};
	int n=sizeof(a)/sizeof(a[0]);
	LinkList<int> A;						//建立元素类型为int的单链表对象
	cout << "创建单链表A" << endl;
	A.CreateListR(a,n);
	cout << "单链表A: "; A.DispList();
	cout << "删除所有最大值结点" << endl;
	Delmaxnodes(A);
	cout << "单链表A: "; A.DispList();
	return 0;
}
