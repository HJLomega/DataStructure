#include "LinkList.cpp"						//���õ���������
template <typename T>
void Split(LinkList<T> &L,LinkList<T> &A,LinkList<T> &B)
{
	LinkNode<T> *p=L.head->next,*q;        	//pָ��L���׽��
	LinkNode<T> *r=A.head;					//rʼ��ָ��A��β���	
 	while (p!=NULL)							//����L���������ݽ��
  	{	r->next=p;
    	r=p;							    //β�巨����A
		p=p->next;							//p����һ�����
     	if (p!=NULL)
     	{	q=p->next;						//��ʱ����p���ĺ�̽��
        	p->next=B.head->next;			//ͷ�巨����B
        	B.head->next=p;
        	p=q;							//pָ��q���
        }
	}
	r->next=NULL;							//β���next�ÿ�
}
int main()
{
	int a[]={1,2,3,4};
	int n=sizeof(a)/sizeof(a[0]);
	LinkList<int> L;						//����Ԫ������Ϊint�ĵ��������
	cout << "����������L" << endl;
	L.CreateListR(a,n);
	cout << "������L: "; L.DispList();
	cout << "L -> A,B" << endl;
	LinkList<int> A,B;
	Split(L,A,B);
	cout << "������A: "; A.DispList();
	cout << "������B: "; B.DispList();
	
	return 0;
}
