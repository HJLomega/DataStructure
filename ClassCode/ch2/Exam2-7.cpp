#include "LinkList.cpp"							//���õ���������
template <typename T>
int Maxcount(LinkList<T> &L)                    //����㷨
{
	int cnt=1;
 	LinkNode<T> *p=L.head->next;			   	//pָ���׽��
 	T maxe=p->data;					    		//maxe��Ϊ�׽��ֵ
 	while (p->next!=NULL)						//ѭ����p���Ϊβ���
 	{
  		if (p->next->data>maxe)					//�ҵ�����Ľ��
  		{
  			maxe=p->next->data;					//��һ���ҵ�maxe�Ľ�� 
      		cnt=1;
      	}
    	else if (p->next->data==maxe)	   		//p���Ϊ��ǰ���ֵ���
      		cnt++;								//������1 
     	p=p->next;
	}
	return cnt;
}

int main()
{
	int a[]={1,5,2,3,5,2,1,5};
	int n=sizeof(a)/sizeof(a[0]);
	LinkList<int> A;							//����Ԫ������Ϊint�ĵ��������
	cout << "����������A" << endl;
	A.CreateListR(a,n);
	cout << "������A: "; A.DispList();
	cout << "���ֵ������=" << Maxcount(A) << endl;
	return 0;
}
