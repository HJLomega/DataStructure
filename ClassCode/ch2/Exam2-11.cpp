#include "LinkList.cpp"					//���õ���������
template <typename T>
void Merge2(LinkList<T> &A,LinkList<T> &B,LinkList<T> &C)
{
	LinkNode<T> *p=A.head->next;		//pָ��A���׽��
 	LinkNode<T> *q=B.head->next;	  	//qָ��B���׽��
 	LinkNode<T> *r=C.head;			  	//rΪC��β���
 	while (p!=NULL && q!=NULL)	    	//����������û�б�����
  	{	if (p->data<q->data)			//����С���p���ӵ�C��ĩβ
      	{	r->next=p;
        	r=p;
        	p=p->next;
        }
    	else							//����С���q���ӵ�C��ĩβ
      	{	r->next=q;
        	r=q;
        	q=q->next;
        }
    }
	r->next=NULL;						//β���next�ÿ�
 	if (p!=NULL) r->next=p;
 	if (q!=NULL) r->next=q;
 }

int main()
{
	int a[]={1,3,5};
	int n=sizeof(a)/sizeof(a[0]);
	LinkList<int> A;					//����Ԫ������Ϊint�ĵ��������
	cout << "����������A" << endl;
	A.CreateListR(a,n);
	cout << "������A: "; A.DispList();

	int b[]={2,3,4,5,8};
	int m=sizeof(b)/sizeof(b[0]);
	LinkList<int> B;					//����Ԫ������Ϊint�ĵ��������
	cout << "����������B" << endl;
	B.CreateListR(b,m);
	cout << "������B: "; B.DispList();
	LinkList<int> C;
	cout << "A,B -> C" << endl;
	Merge2(A,B,C);
	cout << "������C: "; C.DispList();
	return 0;
}
