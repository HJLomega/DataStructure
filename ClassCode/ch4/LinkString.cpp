#include<iostream>
using namespace std;
struct LinkNode								//�����������
{	char data;								//���һ���ַ�
	LinkNode *next;							//ָ����һ�����
	LinkNode():next(NULL) {}				//���캯��
	LinkNode(char d):data(d),next(NULL) {}	//���ع��캯��
	 
};
class LinkString							//������
{
public:
	LinkNode *head;							//����ͷ���head
	int length;								//�������� 
	LinkString()							//���캯��
	{
		head=new LinkNode();				//����ͷ���
		head->next=NULL;
		length=0;
	}
	~LinkString()							//��������
	{
		LinkNode *pre,*p;
		pre=head;p=pre->next;
		while (p!=NULL)						//�ͷ��������н��ռ�
		{
			delete pre;
			pre=p; p=p->next;				//pre,pͬ������ 
		}
		delete pre;
	}
    void StrAssign(char *cstr)		 		//����һ����
	{
		LinkNode *r=head;					//rʼ��ָ��β���
		int i=0;
		for (;cstr[i]!='\0';i++)		//ѭ�������ַ����
		{
			LinkNode *p=new LinkNode(cstr[i]);
			r->next=p; r=p;					//��p�����뵽β��
		}
		length=i;
		r->next=NULL;						//β����next��ΪNULL
	}
	void operator=(LinkString &t)			//����=�����ʵ�ִ�����StrCopy
	{
		LinkNode *p=t.head->next;
		LinkNode *r=head;					//rʼ��ָ��β���
		while (p!=NULL)						//��t�н��p���Ʋ������q
		{
			LinkNode *q=new LinkNode(p->data);
			r->next=q; r=q;					//�����q���뵽β��
			p=p->next;
		}		
		r->next=NULL;						//β����next��ΪNULL
		length=t.length;
	}
	int getlength()							//�󴮳���
	{
		return length;
	}
	char geti(int i)						//�������i���ַ�
	{
		if (i<0 || i>=length)
			throw -1;			
		LinkNode *p=head;
        int j=-1;
        while (j<i)                          //�������Ϊi�Ľ��p
        {	j++;
            p=p->next;
        }
		return p->data;                       //����p���ֵ
    }

    void seti(int i,char x)					//�������i���ַ�Ϊx
	{
		if (i<0 || i>=length)
			throw -1;			
		LinkNode *p=head;
        int j=-1;
        while (j<i)                          //�������Ϊi�Ľ��p
        {	j++;
            p=p->next;
        }
		p->data=x;                       	//����p����ֵ
    }

	LinkString &operator+(LinkString &t) 		//������,Concat
	{
		static LinkString s;	//�½�һ���մ�
		LinkNode *p=head->next,*q;
		LinkNode *r=s.head;
		while (p!=NULL)					//����ǰ���������н�㸴�Ƶ�s
		{
			q=new LinkNode(p->data);	//�½����q 
			r->next=q; r=q;				//�����q���ӵ�β��
			p=p->next;
		}
		p=t.head->next;
		while (p!=NULL)					//������t�����н�㸴�Ƶ�s
		{
			q=new LinkNode(p->data);	//�½����q
			r->next=q; r=q;				//�����q���ӵ�β��
			p=p->next;
		}
		r->next=NULL;					//β����next��ΪNULL
		s.length=length+t.length;
		return s;						//�����½�������
	}
	LinkString &SubStr(int i,int j)				//���Ӵ�
	{
		static LinkString s;							//��������մ� 
		if (i<0 || i>=length || j<0 || i+j>length)
			return s;							//��������ȷʱ���ؿմ�
		LinkNode *p=head->next,*q,*r;
		r=s.head;								//rָ���½�������β���
		for (int k=0;k<i;k++)					//�ƶ�i-1�����
			p=p->next;
		for (int k=0;k<j;k++) 					//��s�����i��㿪ʼ��j����㸴�Ƶ�s
		{
			q=new LinkNode(p->data);
			r->next=q; r=q;					//��*q�����뵽β��
			p=p->next;
		}
		r->next=NULL;						//β����next��ΪNULL
		s.length=j;
		return s;							//�����½�������
	}
	LinkString &InsStr(int i,LinkString &t)			//������
	{
		static LinkString s;						//�½�һ���մ�
		if (i<0 || i>length)						//��������ȷʱ���ؿմ�
			return s;
		LinkNode *p=head->next,*p1=t.head->next;
		LinkNode *r=s.head,*q;						//rָ���½������β���
		for (int k=0; k<i; k++)						//����ǰ������ǰi����㸴�Ƶ�s
		{	q=new LinkNode(p->data);				//�½����q 
			r->next=q; r=q;							//�����q���ӵ�β��
			p=p->next;
		}
		while (p1!=NULL)							//��t�����н�㸴�Ƶ�s
		{	q=new LinkNode(p1->data);				//�½����q
			r->next=q; r=q;							//�����q���ӵ�β��
			p1=p1->next;
		}
		while (p!=NULL)								//��p�����Ľ�㸴�Ƶ�s
		{	q=new LinkNode(p->data);				//�½����q
			r->next=q; r=q;							//�����q���ӵ�β��
			p=p->next;
		}
		s.length=length+t.length;
		r->next=NULL;								//β����next��Ϊ��
		return s;									//�����½�������
	}
	LinkString &DelStr(int i,int j)			//��ɾ��
	{	static LinkString s;	//�½�һ���մ�
		if (i<0 || i>length || i+j>length)				//��������ȷʱ���ؿմ�
			return s;
		LinkNode *p=head->next,*q;
		LinkNode *r=s.head;									//rָ���½������β���
		for (int k=0; k<i;k++)							//��s��ǰi����㸴�Ƶ�s
		{	q=new LinkNode(p->data);
			r->next=q; r=q;							//��q�����뵽β��
			p=p->next;
		}
		for (int k=0;k<j;k++)						//��p��next��j�����
			p=p->next;
		while (p!=NULL)								//��p�����Ľ�㸴�Ƶ�s
		{	q=new LinkNode(p->data);
			r->next=q; r=q;							//��q�����뵽β��
			p=p->next;
		}
		s.length=length-j;
		r->next=NULL;								//β����next��Ϊ��
		return s;									//�����½�������
	}
	LinkString &RepStr(int i,int j,LinkString t) 	//���滻
	{
		static LinkString s;	//�½�һ���մ�
		if (i<0 || i>length || i+j>length)				//��������ȷʱ���ؿմ�
			return s;
		LinkNode *p=head->next,*p1=t.head->next,*q;
		LinkNode *r=s.head;									//rָ���½������β���
		for (int k=0; k<i; k++)						//��s��ǰi����㸴�Ƶ�s
		{	q=new LinkNode(p->data);
			r->next=q; r=q;							//��q�����뵽β��
			p=p->next;
		}
		for (int k=0;k<j;k++)						//��p��next��j�����
			p=p->next;
		while (p1!=NULL)							//��t�����н�㸴�Ƶ�s
		{	q=new LinkNode(p1->data);
			r->next=q; r=q;							//��q�����뵽β��
			p1=p1->next;
		}
		while (p!=NULL)								//��p�����Ľ�㸴�Ƶ�s
		{	q=new LinkNode(p->data);
			r->next=q; r=q;							//��q�����뵽β��
			p=p->next;
		}
		s.length=length-j+t.length;
		r->next=NULL;								//β����next��Ϊ��
		return s;									//�����½�������
	}
	void DispStr()			//�����
	{
		LinkNode *p=head->next;				//pָ��������ͷ���
		while (p!=NULL)
		{
			cout << p->data;
			p=p->next;						//pָ����һ�����
		}
		cout << endl;
	}
};

