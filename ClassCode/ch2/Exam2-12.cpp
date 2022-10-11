#include "LinkList.cpp"							//���õ���������
template <typename T>
void Commnodes(LinkList<T> &A,LinkList<T> &B,LinkList<T> &C)
{
	LinkNode<T> *p=A.head->next;				//pָ��A���׽��
 	LinkNode<T> *q=B.head->next;	  			//qָ��B���׽��
 	LinkNode<T> *r=C.head;			  			//rΪC��β���
 	while (p!=NULL && q!=NULL)	    			//����������û�б�����
  	{	if (p->data<q->data)					//������С��p���
        	p=p->next;
    	else if (q->data<p->data)				//������С��q���
        	q=q->next;
        else									//p����q���ֵ��ͬ
      	{	LinkNode<T> *s=new LinkNode<T>(p->data);
        	r->next=s;
        	r=s;					    		//��s������ӵ�C��ĩβ
        	p=p->next;
        	q=q->next;
    	}
    }
    r->next=NULL;						//β���next�ÿ�
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
	Commnodes(A,B,C);
	cout << "������C: "; C.DispList();
	return 0;
}
