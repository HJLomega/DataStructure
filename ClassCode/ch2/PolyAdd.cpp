#include<iostream>
using namespace std;
struct PolyNode						//����ʽ������������
{
	double coef;					//ϵ��
	int exp;						//ָ��
	PolyNode *next;					//ָ����һ������ָ��
	PolyNode():next(NULL) {}		//���캯��
	PolyNode(double c,int e)		//���ع��캯�� 
	{
		coef=c;
		exp=e;
		next=NULL;
	} 
};
class PolyList							//����ʽ��������
{
public:
	PolyNode *head;						//����ʽ�������ͷ���ָ��
	PolyList()							//���캯��
	{
		head=new PolyNode();			//����ͷ���
	}
	~PolyList()							//��������
	{
		PolyNode *pre=head,*p=pre->next;
		while (p!=NULL)
		{
			delete pre;
			pre=p; p=p->next;			//pre��pָ��ͬ������
		}
		delete pre;
	}
	void CreateList(char *fname)		//���ļ�����β�巨��������ʽ������
	{
		freopen(fname,"r",stdin);		//�����ض���fname�ļ� 
		PolyNode *s,*r;
		double c;
		int n,e;
		scanf("%d",&n);
		r=head;							//rʼ��ָ��β���,��ʼʱָ��ͷ���
		for (int i=0;i<n;i++)
		{
			scanf("%lf%d",&c,&e);
			s=new PolyNode(c,e);		//�����½��s
			r->next=s;					//�����s������r֮��
			r=s;
		}
		r->next=NULL;					//β���next����ΪNULL
	}
	void Sort()							//�Զ���ʽ������exp��ݼ�����
	{
		PolyNode *p,*pre,*q;
		q=head->next;					//qָ��ʼ���
		if (q==NULL) return;			//ԭ�������ʱ����
		p=head->next->next;				//pָ����q�ĺ�̽��
		if (p==NULL) return;			//ԭ������ֻ��һ�����ݽ��ʱ����
		q->next=NULL;					//����ֻ��һ�����ݽ�����������
		while (p!=NULL)
		{
			q=p->next;					//q������ʱ������p��̽��
			pre=head;					//�������ͷ�Ƚ�
			while (pre->next!=NULL && pre->next->exp>p->exp)
				pre=pre->next;			//��������в��Ҳ�����p��ǰ�����pre
			p->next=pre->next;			//�ڽ��pre֮�������p
			pre->next=p;
			p=q;						//��������ԭ���������µĽ��
		}
	}
	void DispPoly()						//�������ʽ������
	{
		bool first=true;				//firstΪtrue��ʾ�ǵ�һ��
		PolyNode *p=head->next;			//pָ��ʼ���
		while (p!=NULL)	
		{				
			if (first)
			{
				printf("[%.1lf,%d]",p->coef,p->exp);				
				first=false;
			}
			else
				printf(",[%.1lf,%d]",p->coef,p->exp);				
			p=p->next;
		}
		printf("\n");
	}
};
void PolyAdd(PolyList &A,PolyList &B,PolyList &C) 	//A+B->C 
{	PolyNode *pa=A.head->next;				//paָ��A�Ŀ�ʼ���
	PolyNode *pb=B.head->next;				//pbָ��B�Ŀ�ʼ���
	PolyNode *s,*r;
	double c;
	r=C.head;								//rָ��β���
	while (pa!=NULL && pb!=NULL)
	{	if (pa->exp>pb->exp)						//�鲢ָ���ϴ�Ľ��pa
		{	s=new PolyNode(pa->coef,pa->exp);	//���Ʋ������s
			r->next=s; r=s;						//�����s����Cĩβ 
			pa=pa->next;
		}
		else if (pa->exp<pb->exp)				//�鲢ָ���ϴ�Ľ��pb
		{	s=new PolyNode(pb->coef,pb->exp);	//���Ʋ������s
			r->next=s; r=s;						//�����s����Cĩβ 
			pb=pb->next;
		}
		else										//�����ָ����ȵ���� 
		{	c=pa->coef+pb->coef;				//����ָ����Ƚ���ϵ����c
			if (c!=0)								//ϵ���Ͳ�Ϊ0�����
			{	s=new PolyNode(c,pa->exp);		//�½����s
				r->next=s; r=s;					//�����s����Cĩβ 
			}
			pa=pa->next;
			pb=pb->next;
		}
	}
	if (pb!=NULL) pa=pb;						//�������µĽ��
	while (pa!=NULL)
	{	s=new PolyNode(pa->coef,pa->exp);		//���Ʋ������s
		r->next=s; r=s;							//�����s����Cĩβ
		pa=pa->next;
	}
	r->next=NULL;								//β����next����ΪNULL
}
int main()
{
	freopen("abc.out","w",stdout);		//����ض���abc.out�ļ� 
	PolyList A,B,C;			//����3������ʽ���������
	A.CreateList("abc1.in");
	cout << "��1������ʽ: "; A.DispPoly();
	A.Sort(); 
	cout << "�������:  "; A.DispPoly();

	B.CreateList("abc2.in");
	cout << "��2������ʽ: "; B.DispPoly();
	B.Sort(); 
	cout << "�������:  "; B.DispPoly();

	PolyAdd(A,B,C);
	cout << "��Ӷ���ʽ:  "; C.DispPoly();
	return 0;
}
