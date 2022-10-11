#include "LinkList.cpp"					//���õ���������
template <typename T>
void Reverse1(LinkList<T> &L)          	//����㷨1
{
	LinkNode<T> *p=L.head->next,*q;	  	//pָ���׽��
	L.head->next=NULL;		    		//��L��Ϊһ���ձ�
 	while (p!=NULL)						//��p�����������ݽ�� 
  	{	q=p->next;			    		//q��ʱ����p���ĺ�̽��
     	p->next=L.head->next;	    	//��p�����뵽��ͷ
     	L.head->next=p;
     	p=q;
	}
}

template <typename T>
void Reverse2(LinkList<T> &L)          	//����㷨2
{
	LinkNode<T> *p=L.head->next,*q,*r;	//pָ���׽��
	if (p==NULL) return;				//LΪ�յ�����ʱ����
	q=p->next;
	if (q==NULL) return;				//Lֻ��һ�����ʱ����
	r=q->next;
	if (r==NULL)						//Lֻ��һ�����ʱ
	{
		L.head->next=q;
		q->next=p;
		p->next=NULL;
		return;
	}
	p->next=NULL;						//ԭ�׽��p��Ϊβ���	
	while (r!=NULL)
	{
		q->next=p;						//�޸Ľ��q��nextָ�� 
		p=q;							//(p,q,r)ͬ��ָ����� 
		q=r;
		r=r->next;
	}
	q->next=p;							//�޸Ľ��q��nextָ��
	L.head->next=q;
}

int main()
{
	int a[]={1,2,3,4,5,6};
	int n=sizeof(a)/sizeof(a[0]);
	LinkList<int> A;					//����Ԫ������Ϊint�ĵ��������
	cout << "����������A" << endl;
	A.CreateListR(a,n);
	cout << "������A: "; A.DispList();
	cout << "���õ�����A" << endl;
	Reverse2(A);
	cout << "������A: "; A.DispList();
	return 0;
}
