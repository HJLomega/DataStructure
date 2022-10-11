#include "CDLinkList.cpp"					//引用循环双链表泛型类
template <typename T>
void Comb(CDLinkList<T> &A,CDLinkList<T> &B) //求解算法
{
	DLinkNode<T> *ta=A.dhead->prior;		//ta指向A的尾结点
 	DLinkNode<T> *tb=B.dhead->prior;		//tb指向B的尾结点
 	ta->next=B.dhead->next;					//尾首相连
 	B.dhead->next->prior=ta;
 	tb->next=A.dhead;
 	A.dhead->prior=tb;
 	B.dhead->next=B.dhead;					//置B为空表 
 	B.dhead->prior=B.dhead;
}
int main()
{
	int a[]={1,2,3,4};
	int n=sizeof(a)/sizeof(a[0]);
	CDLinkList<int> A;
	cout << "创建循环双链表A" << endl;
	A.CreateListR(a,n);
	cout << "循环双链表A: "; A.DispList();

	int b[]={6,7,8};
	int m=sizeof(b)/sizeof(b[0]);
	CDLinkList<int> B;
	cout << "创建循环双链表B" << endl;
	B.CreateListR(b,m);
	cout << "循环双链表B: "; B.DispList();
	cout << "合并" << endl;
	Comb(A,B);
	cout << "循环双链表A: "; A.DispList();	

	return 0;
}
