#include <iostream>
using namespace std;
template <typename T>
struct LinkNode								//ѭ�������������� 
{
	T data;									//�������Ԫ��
	LinkNode<T> *next;						//ָ����һ��������
	LinkNode():next(NULL) {}				//���캯�� 
	LinkNode(T d):data(d),next(NULL) {}		//���ع��캯�� 
};

template <typename T>
class CLinkList								//ѭ����������
{
public:
	LinkNode<T> *head;						//ѭ��������ͷ���
	CLinkList() 							//���캯��,����һ����ѭ��������
	{
		head=new LinkNode<T>();
		head->next=head;					//����ѭ���Ŀ����� 
	}
	~CLinkList() 							//��������,����ѭ��������
	{
		LinkNode<T> *pre,*p;
		pre=head;p=pre->next;
		while (p!=head)						//��p������㲢�ͷ���ǰ����� 
		{
			delete pre;						//�ͷ�pre��� 
			pre=p; p=p->next;				//pre,pͬ������һ����� 
		}
		delete pre;							//p����headʱpreָ��β���,��ʱ�ͷ�β���						
	}
	
	void CreateListF(T a[],int n)			//ͷ�巨����ѭ��������
	{
		for (int i=0;i<n;i++)				//ѭ���������ݽ��
		{
			LinkNode<T> * s=new LinkNode<T>(a[i]);		//�������ݽ��s
			s->next=head->next;					//�����s������head���֮�� 
			head->next=s;
		}
	}
	void CreateListR(T a[],int n)			//β�巨����ѭ��������
	{
		LinkNode<T> *s,*r;
		r=head;								//rʼ��ָ��β���,��ʼʱָ��ͷ���
		for (int i=0;i<n;i++)				//ѭ���������ݽ��
		{
			s=new LinkNode<T>(a[i]);		//�������ݽ��s
			r->next=s;						//�����s������r֮��
			r=s;
		}
		r->next=head;						//��β����next����Ϊhead
	}
	void Add(T e)							//��ѭ��������ĩβ���һ��ֵΪe�Ľ�� 
	{
		LinkNode<T> *s=new LinkNode<T>(e); 	//�½����s
 		LinkNode<T> *p=head;
		while (p->next!=head)				//����β���p
			p=p->next;
		s->next=p->next;					//�ڽ��p֮�������s
		p->next=s;
	}
	int Getlength()                   		//��ѭ�������������ݽ�����
	{
		LinkNode<T> *p=head;
	 	int cnt=0;
 		while (p->next!=head)				//���ҵ�β���Ϊֹ
  		{	cnt++;
  			p=p->next;
  		}
 		return cnt;
 	}
	bool GetElem(int i,T &e)				//��ѭ�������������Ϊi�Ľ��ֵ
	{
		if (i<0) return false;             	//����i���󷵻�false
 		LinkNode<T> *p=geti(i);				//�������i�Ľ�� 
 		if (p!=head)						//�ҵ������i�Ľ��p 
 		{
 			e=p->data;
		 	return true;					//�ɹ��ҵ�����true 
		}
 		else
 			return false;					//û���ҵ����i�Ľ�㷵��false 
 	} 
	bool SetElem(int i,T e)              	//�������Ϊi�Ľ��ֵ
	{
		if (i<0) return false;             	//����i���󷵻�false
 		LinkNode<T> *p=geti(i);				//�������i�Ľ�� 
 		if (p!=NULL)						//�ҵ������Ϊi�Ľ��p 
 		{
 			p->data=e;
 			return true;
 		}
 		else								//û���ҵ����Ϊi�Ľ��
 			return false;					//����i���󷵻�false
 	} 

	int GetNo(T e)							//���ҵ�һ��Ϊe��Ԫ�ص����
	{
		int j=0;
	 	LinkNode<T> *p=head->next;
 		while (p!=head && p->data!=e)
 		{
  			j++;							//����Ԫ��e
   			p=p->next;
   		}
		if (p==head)
  			return -1;						//δ�ҵ�ʱ����-1
		else
  			return j;						//�ҵ��󷵻������
	}
	bool Insert(int i,T e)					//��ѭ�������������iλ�ò���ֵΪe�Ľ��
	{
		if (i<0) return false; 				//����i���󷵻�false
		LinkNode<T> *s=new LinkNode<T>(e);	//�����½��s
 		LinkNode<T> *p=geti(i-1);			//�������Ϊi-1�Ľ��p
 		if (p!=NULL)						//�ҵ������i-1�Ľ�� 
 		{
 			s->next=p->next;				//��p���������s���
 			p->next=s;
 			return true;					//����ɹ�����true 
 		}
 		else								//û���ҵ����i-1�Ľ�� 
 			return false;					//����i���󷵻�false
	}
	bool Delete(int i)						//��ѭ����������ɾ�����iλ�õĽ��
	{
		if (i<0) return false; 				//����i���󷵻�false		
  		LinkNode<T> *p=geti(i-1);			//�ҵ����Ϊi-1�Ľ��p
 		if (p!=NULL)						//�ҵ����Ϊi-1�Ľ�� 
 		{
 			LinkNode<T> *q=p->next;			//qָ�����i�Ľ�� 
 			if (q!=NULL) 					//�������i�Ľ��ʱɾ���� 
 			{	p->next=q->next;			//ɾ��p���ĺ�̽��
 				delete q;					//�ͷſռ� 
 				return true;				//ɾ���ɹ�����true 
 			}
 			else							//û�����i�Ľ��
				return false;				//����i���󷵻�false 			
 		}
 		else 								//û���ҵ����Ϊi-1�Ľ�� 
 			return false;					//����i���󷵻�false  		
  	}
	void DispList()							//���ѭ�����������н��ֵ
	{
		LinkNode<T> *p;
		p=head->next;						//pָ��ʼ���
		while (p!=head)						//p��Ϊhead,���p����data��
		{
			cout << p->data << " ";
			p=p->next;						//p������һ�����
		}
		cout << endl;
	}
private:
	//*******************************************
	//���i����ȷ��Χ��-1��i<n��������Χ����NULL
	//i=-1ʱ����ͷ���head
	//i��0����i<nʱ�������i�Ľ��
	//*******************************************
	LinkNode<T> *geti(int i)		      	//�������Ϊi�Ľ��
	{
		if (i<-1) return NULL;				//i<-1ʱ����NULL
		if (i==-1) return head;				//i=-1ʱ����ͷ��� 
		LinkNode<T> *p=head->next;			//����pָ���׽�� 
 		int j=0;							//j��Ϊ0Ϊ�׽�����
 		while (j<i && p!=head)				//p�ƶ�i����� 
 		{	j++;
   			p=p->next;
   		}
   		if (p==head)						//û���ҵ����i�Ľ�㷵��NULL
		   return NULL;
		else 
			return p;
	}
};

