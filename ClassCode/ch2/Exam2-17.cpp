#include "CDLinkList.cpp"					//����ѭ��˫��������
template <typename T>
void Comb(CDLinkList<T> &A,CDLinkList<T> &B) //����㷨
{
	DLinkNode<T> *ta=A.dhead->prior;		//taָ��A��β���
 	DLinkNode<T> *tb=B.dhead->prior;		//tbָ��B��β���
 	ta->next=B.dhead->next;					//β������
 	B.dhead->next->prior=ta;
 	tb->next=A.dhead;
 	A.dhead->prior=tb;
 	B.dhead->next=B.dhead;					//��BΪ�ձ� 
 	B.dhead->prior=B.dhead;
}
int main()
{
	int a[]={1,2,3,4};
	int n=sizeof(a)/sizeof(a[0]);
	CDLinkList<int> A;
	cout << "����ѭ��˫����A" << endl;
	A.CreateListR(a,n);
	cout << "ѭ��˫����A: "; A.DispList();

	int b[]={6,7,8};
	int m=sizeof(b)/sizeof(b[0]);
	CDLinkList<int> B;
	cout << "����ѭ��˫����B" << endl;
	B.CreateListR(b,m);
	cout << "ѭ��˫����B: "; B.DispList();
	cout << "�ϲ�" << endl;
	Comb(A,B);
	cout << "ѭ��˫����A: "; A.DispList();	

	return 0;
}
