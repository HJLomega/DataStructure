#include "DLinkList.cpp"					//����˫��������
template <typename T>
void Delx(DLinkList<T> &L,T x)           	//����㷨
{	DLinkNode<T> *p=L.dhead->next;			//pָ���׽��
 	while (p!=NULL && p->data!=x)			//���ҵ�һ��ֵΪx�Ľ��
  		p=p->next;
 	if (p!=NULL)							//�ҵ�ֵΪx�Ľ��p
  	{
    	p->prior->next=p->next;				//ɾ��p���
	  	if (p->next!=NULL)
     		p->next->prior=p->prior; 
     	delete p;							//�ͷſռ� 
	}
}
int main()
{
	int a[]={1,5,3,5,2};
	int n=sizeof(a)/sizeof(a[0]);
	DLinkList<int> A;					//����Ԫ������Ϊint��˫�������
	cout << "����˫����A" << endl;
	A.CreateListR(a,n);
	cout << "˫����A: "; A.DispList();
	int x=5;
	cout << "ɾ����һ��" << x << endl;
	Delx(A,x);
	cout << "˫����A: "; A.DispList();
	return 0;
}
