#include "LinkList.cpp"						//���õ���������
template <typename T>
void Delmaxnodes(LinkList<T> &L)         	//����㷨
{
	LinkNode<T> *p=L.head->next;           	//pָ���׽��
  	T maxe=p->data;                      	//maxe��Ϊ�׽��ֵ
  	while (p->next!=NULL)					//���������ֵmaxe
  	{	if (p->next->data>maxe)
      		maxe=p->next->data;
     	p=p->next;
 	}
	LinkNode<T> *pre=L.head;				//preָ��ͷ���
 	p=pre->next;							//pָ��pre�ĺ�̽��
 	while (p!=NULL)							//p�������н��
 	{
  		if (p->data==maxe)					//p���Ϊ���ֵ���
      	{	
		  	pre->next=p->next;				//ɾ��p���
		  	delete p;
         	p=pre->next;					//��pָ��pre�ĺ�̽��
    	}
    	else
      	{
		  	pre=pre->next;					//pre����һ�����
        	p=pre->next;					//��pָ��pre�ĺ�̽��
        }
    }
}

int main()
{
	int a[]={1,5,2,3,5,2,1,5};
	int n=sizeof(a)/sizeof(a[0]);
	LinkList<int> A;						//����Ԫ������Ϊint�ĵ��������
	cout << "����������A" << endl;
	A.CreateListR(a,n);
	cout << "������A: "; A.DispList();
	cout << "ɾ���������ֵ���" << endl;
	Delmaxnodes(A);
	cout << "������A: "; A.DispList();
	return 0;
}
