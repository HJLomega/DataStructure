#include "CLinkList.cpp"						//����ѭ������������
template <typename T>
int Count(CLinkList<T> &L,T x)               	//����㷨
{	int cnt=0;									//cnt��Ϊ0
 	LinkNode<T> *p=L.head->next;			    //����pָ���׽��
 	while (p!=L.head)							//����ѭ��������
  	{	if (p->data==x)
      		cnt++;								//�ҵ�һ��ֵΪx�Ľ��cnt��1
    	p=p->next;								//p����һ�����
    }
	return cnt;
}
int main()
{
	int a[]={1,5,3,5,2,5};
	int n=sizeof(a)/sizeof(a[0]);
	CLinkList<int> A;						//����Ԫ������Ϊint��ѭ�����������
	cout << "����ѭ��������A" << endl;
	A.CreateListR(a,n);
	cout << "ѭ��������A: "; A.DispList();
	int x=5;	
	cout << "x=" << x << "�Ľ�����=" << Count(A,x) << endl;
	return 0;
}
