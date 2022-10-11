#include "LinkList.cpp"							//引用单链表泛型类
template <typename T>
T Middle1(LinkList<T> &L)                 		//求解算法1
{
	int j=1;
 	int n=L.Getlength();
 	LinkNode<T> *p=L.head->next;				//p指向首结点
 	while (j<=(n-1)/2)							//找中间位置的p结点
 	{
  		j++;
   		p=p->next;
   	}
 	return p->data;
}
template <typename T>
T Middle2(LinkList<T> &L)                 		//求解算法2
{
	LinkNode<T> *slow=L.head->next;
 	LinkNode<T> *fast=L.head->next;				//均指向首结点
 	while (fast!=NULL && slow!=NULL)
 	{
 		if (fast->next==NULL || fast->next->next==NULL)	
			return slow->data;					//满足结束条件时返回
  		slow=slow->next;						//慢指针每次后移1个结点
   		fast=fast->next->next;					//快指针每次后移2个结点
   	}
 	return slow->data;
}

int main()
{
	int a[]={1,2,3};
	int n=sizeof(a)/sizeof(a[0]);
	LinkList<int> L;							//建立元素类型为int的单链表对象
	cout << "创建单链表L" << endl;
	L.CreateListR(a,n);
	cout << "单链表L: "; L.DispList();
	cout << "解法1：中间位置元素=" << Middle1(L) << endl;
	cout << "单链表L: "; L.DispList();
	cout << "解法2：中间位置元素=" << Middle2(L) << endl;
	return 0;
}
