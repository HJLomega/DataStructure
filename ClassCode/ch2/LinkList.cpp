#include <iostream>
using namespace std;
template <typename T>
struct LinkNode								//������������ 
{
	T data;									//�������Ԫ��
	LinkNode<T> *next;						//ָ����һ��������
	LinkNode():next(NULL) {}				//���캯�� 
	LinkNode(T d):data(d),next(NULL) {}		//���ع��캯�� 
};

template <typename T>
class LinkList								//��������
{
public:
	LinkNode<T> *head;						//������ͷ���
	LinkList() 								//���캯��,����һ���յ�����
	{
		head=new LinkNode<T>();
	}
	~LinkList() 							//��������,���ٵ�����
	{
		LinkNode<T> *pre,*p;
		pre=head;p=pre->next;
		while (p!=NULL)						//��p������㲢�ͷ���ǰ����� 
		{
			delete pre;						//�ͷ�pre��� 
			pre=p; p=p->next;				//pre,pͬ������һ����� 
		}
		delete pre;							//pΪ��ʱpreָ��β���,��ʱ�ͷ�β���						
	}
	void CreateListF(T a[],int n)			//ͷ�巨����������
	{
		for (int i=0;i<n;i++)				//ѭ���������ݽ��
		{
			LinkNode<T> * s=new LinkNode<T>(a[i]);		//�������ݽ��s
			s->next=head->next;					//�����s������head���֮�� 
			head->next=s;
		}
	}
	void CreateListR(T a[],int n)			//β�巨����������
	{
		LinkNode<T> *s,*r;
		r=head;								//rʼ��ָ��β���,��ʼʱָ��ͷ���
		for (int i=0;i<n;i++)				//ѭ���������ݽ��
		{
			s=new LinkNode<T>(a[i]);		//�������ݽ��s
			r->next=s;						//�����s������r֮��
			r=s;
		}
		r->next=NULL;						//��β����next����ΪNULL
	}
	void Add(T e)							//�ڵ�����ĩβ���һ��ֵΪe�Ľ�� 
	{
		LinkNode<T> *s=new LinkNode<T>(e); 	//�½����s
 		LinkNode<T> *p=head;
 		while (p->next!=NULL)				//����β���p
  			p=p->next;
 		p->next=s;							//��β���֮�������s
	}
	int Getlength()                   		//�����������ݽ�����
	{
		LinkNode<T> *p=head;
	 	int cnt=0;
 		while (p->next!=NULL)				//�ҵ�β���Ϊֹ
  		{	cnt++;
  			p=p->next;
  		}
 		return cnt;
 	}
	bool GetElem(int i,T &e)				//�����������Ϊi�Ľ��ֵ
	{
		if (i<0) return false;              //����i���󷵻�false
 		LinkNode<T> *p=geti(i);				//�������i�Ľ��p
 		if (p!=NULL)						//�ҵ������i�Ľ�� 
 		{
 			e=p->data;
		 	return true;					//�ɹ��ҵ�����true 
		 }
 		else
 			return false;					//û���ҵ����i�Ľ�㷵��false 
 	} 
	bool SetElem(int i,T e)              	//�������Ϊi�Ľ��ֵ
	{
		if (i<0) return false;              //����i���󷵻�false
 		LinkNode<T> *p=geti(i);				//�������i�Ľ��p 
 		if (p!=NULL)						//�ҵ������i�Ľ�� 
 		{
 			p->data=e;
 			return true;
 		}
 		else								//û���ҵ����i�Ľ��
 			return false;					//����i���󷵻�false
 	} 

	int GetNo(T e)							//���ҵ�һ��Ϊe��Ԫ�ص����
	{
		int j=0;
	 	LinkNode<T> *p=head->next;
 		while (p!=NULL && p->data!=e)
 		{
  			j++;							//����Ԫ��e
   			p=p->next;
   		}
		if (p==NULL)
  			return -1;						//δ�ҵ�ʱ����-1
		else
  			return j;						//�ҵ��󷵻������
	}
	bool Insert(int i,T e)					//�ڵ����������iλ�ò���ֵΪe�Ľ��
	{
		if (i<0) return false; 				//����i���󷵻�false
		LinkNode<T> *s=new LinkNode<T>(e);	//�����½��s
 		LinkNode<T> *p=geti(i-1);			//�������Ϊi-1�Ľ��p
 		if (p!=NULL)						//�ҵ������Ϊi-1�Ľ�� 
 		{
 			s->next=p->next;				//��p���������s���
 			p->next=s;
 			return true;					//����ɹ�����true 
 		}
 		else								//û���ҵ����Ϊi-1�Ľ�� 
 			return false;					//����i���󷵻�false

	}
	bool Delete(int i)						//�ڵ�������ɾ�����iλ�õĽ��
	{
		if (i<0) return false; 				//����i���󷵻�false
  		LinkNode<T> *p=geti(i-1);			//�������i-1�Ľ��p
 		if (p!=NULL)						//�ҵ������i-1�Ľ�� 
 		{
 			LinkNode<T> *q=p->next;			//qָ�����i�Ľ�� 
 			if (q!=NULL) 					//�������i�Ľ��ʱɾ���� 
 			{	p->next=q->next;			//ɾ��p���ĺ�̽��
 				delete q;					//�ͷſռ� 
 				return true;				//ɾ���ɹ�����true 
 			}
 			else							//û���ҵ����i�Ľ��
				return false;				//����i���󷵻�false
 			
 		}
 		else 								//û���ҵ����Ϊi-1�Ľ�� 
 			return false;					//����i���󷵻�false  		
  	}
	void DispList()							//������������н��ֵ
	{
		LinkNode<T> *p;
		p=head->next;						//pָ��ʼ���
		while (p!=NULL)						//p��ΪNULL,���p����data��
		{
			cout << p->data << " ";
			p=p->next;						//p������һ�����
		}
		cout << endl;
	}
private:
	//*******************************************
	//���i����ȷ��Χ��-1<=i<n��������Χ����NULL
	//i=-1ʱ����ͷ���head
	//i��0����i<nʱ�������i�Ľ��
	//*******************************************
	LinkNode<T> *geti(int i)		      	//�������Ϊi�Ľ��
	{
		if (i<-1) return NULL;				//i<-1����NULL 
		LinkNode<T> *p=head;				//����pָ��ͷ���
 		int j=-1;							//j��Ϊ-1(������Ϊͷ������Ϊ-1)
 		while (j<i && p!=NULL)				//ָ��p�ƶ�i+1�����			
 		{	j++;
   			p=p->next;
   		}
		return p;							//����p 
	}

};

