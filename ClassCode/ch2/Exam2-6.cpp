#include "LinkList.cpp"							//���õ���������
template <typename T>
T Middle1(LinkList<T> &L)                 		//����㷨1
{
	int j=1;
 	int n=L.Getlength();
 	LinkNode<T> *p=L.head->next;				//pָ���׽��
 	while (j<=(n-1)/2)							//���м�λ�õ�p���
 	{
  		j++;
   		p=p->next;
   	}
 	return p->data;
}
template <typename T>
T Middle2(LinkList<T> &L)                 		//����㷨2
{
	LinkNode<T> *slow=L.head->next;
 	LinkNode<T> *fast=L.head->next;				//��ָ���׽��
 	while (fast!=NULL && slow!=NULL)
 	{
 		if (fast->next==NULL || fast->next->next==NULL)	
			return slow->data;					//�����������ʱ����
  		slow=slow->next;						//��ָ��ÿ�κ���1�����
   		fast=fast->next->next;					//��ָ��ÿ�κ���2�����
   	}
 	return slow->data;
}

int main()
{
	int a[]={1,2,3};
	int n=sizeof(a)/sizeof(a[0]);
	LinkList<int> L;							//����Ԫ������Ϊint�ĵ��������
	cout << "����������L" << endl;
	L.CreateListR(a,n);
	cout << "������L: "; L.DispList();
	cout << "�ⷨ1���м�λ��Ԫ��=" << Middle1(L) << endl;
	cout << "������L: "; L.DispList();
	cout << "�ⷨ2���м�λ��Ԫ��=" << Middle2(L) << endl;
	return 0;
}
