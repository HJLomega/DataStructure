#include "DLinkList.cpp"					//����˫��������
template <typename T>
void Swap(DLinkList<T> &L,T x)             //����㷨
{
	DLinkNode<T> *p=L.dhead->next,*q;		//pָ���׽��
 	q=NULL;
 	while (p!=NULL)                  		//�������һ��ֵΪx�Ľ��q
  	{	if (p->data==x) q=p;
  		p=p->next;
  	}
 	if (q==NULL || L.dhead->next==q)  		//������x�����߸ý�����׽��
  		return;                      		//ֱ�ӷ���
 	else                           			//�ҵ��������Ľ��q
  	{	DLinkNode<T> *pre=q->prior;			//preָ����q��ǰ����� 
     	pre->next=q->next;             		//ɾ��q���
     	if (q->next!=NULL)
     		q->next->prior=pre;
    	pre->prior->next=q;            		//��q�����뵽pre���֮ǰ
     	q->prior=pre->prior;
     	pre->prior=q;
     	q->next=pre;
     }
}
int main()
{
	int a[]={1,5,3,5,2};
	int n=sizeof(a)/sizeof(a[0]);
	DLinkList<int> A;						//����Ԫ������Ϊint��˫�������
	cout << "����˫����A" << endl;
	A.CreateListR(a,n);
	cout << "˫����A: "; A.DispList();
	int x=5;
	cout << "���� x=" << x << endl;
	Swap(A,x);
	cout << "˫����A: "; A.DispList();
	return 0;
}
