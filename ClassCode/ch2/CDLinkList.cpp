#include <iostream>
using namespace std;
template <typename T>
struct DLinkNode										//ѭ��˫���������� 
{
	T data;												//�������Ԫ��
	DLinkNode<T> *next;									//ָ���̽���ָ��
	DLinkNode<T> *prior;								//ָ��ǰ������ָ�� 
	DLinkNode():next(NULL),prior(NULL) {}				//���캯�� 
	DLinkNode(T d):data(d),next(NULL),prior(NULL) {}	//���ع��캯�� 
};

template <typename T>
class CDLinkList										//ѭ��˫������
{
public:
	DLinkNode<T> *dhead;									//ѭ��˫����ͷ���
	CDLinkList() 										//���캯��,����һ����ѭ��˫����
	{
		dhead=new DLinkNode<T>();
		dhead->next=dhead;								//����ѭ���Ŀ�����
		dhead->prior=dhead; 
	}
	~CDLinkList() 								//��������,����ѭ��˫����
	{
		DLinkNode<T> *pre,*p;
		pre=dhead;p=pre->next;
		while (p!=dhead)						//��p������㲢�ͷ���ǰ����� 
		{
			delete pre;							//�ͷ�pre��� 
			pre=p; p=p->next;					//pre,pͬ������һ����� 
		}
		delete pre;								//p����dheadʱpreָ��β���,��ʱ�ͷ�β���						
	}
	
	void CreateListF(T a[],int n)			//ͷ�巨����ѭ��˫����
	{
		for (int i=0;i<n;i++)				//ѭ���������ݽ��
		{
			DLinkNode<T> *s=new DLinkNode<T>(a[i]);	//�������ݽ��s
			s->next=dhead->next;					//�޸�s����next�ֶ�
			dhead->next->prior=s;
			dhead->next=s;							//�޸�ͷ����next�ֶ�
			s->prior=dhead;							//�޸�s����prior�ֶ�
		}
	}
	void CreateListR(T a[],int n)					//β�巨����ѭ��˫����
	{
		DLinkNode<T> *s,*r;
		r=dhead;									//rʼ��ָ��β���,��ʼʱָ��ͷ���
		for (int i=0;i<n;i++)						//ѭ���������ݽ��
		{
			s=new DLinkNode<T>(a[i]);				//�������ݽ��s
			r->next=s;								//�����s������r֮��
			s->prior=r;
			r=s;
		}
		r->next=dhead;								//��β����next����Ϊdhead
		dhead->prior=r;								//��ͷ����prior����Ϊ���r
	}

	void Add(T e)								//��ѭ��˫����ĩβ���һ��ֵΪe�Ľ�� 
	{
		DLinkNode<T> *s=new DLinkNode<T>(e); 	//�½����s
 		DLinkNode<T> *p=dhead;
		while (p->next!=dhead)					//����β���p
			p=p->next;
		p->next->prior=s;						//�ڽ��p֮�������s
		s->next=p->next;
		p->next=s;
		s->prior=p;
	}

	int Getlength()                   			//��ѭ��˫���������ݽ�����
	{
		DLinkNode<T> *p=dhead;
	 	int cnt=0;
 		while (p->next!=dhead)					//���ҵ�β���Ϊֹ
  		{	cnt++;
  			p=p->next;
  		}
 		return cnt;
 	}

	bool GetElem(int i,T &e)					//��ѭ��˫���������Ϊi�Ľ��ֵ
	{
		if (i<0) return false;              	//����i���󷵻�false	
 		DLinkNode<T> *p=geti(i);				//�������i�Ľ�� 
 		if (p!=dhead)							//�ҵ������i�Ľ��p 
 		{
 			e=p->data;
		 	return true;						//�ɹ��ҵ�����true 
		}
 		else
 			return false;						//û���ҵ����i�Ľ�㷵��false 
 	} 
	bool SetElem(int i,T e)              		//�������Ϊi�Ľ��ֵ
	{
		if (i<0) return false;             		//����i���󷵻�false
 		DLinkNode<T> *p=geti(i);				//�������i�Ľ�� 
 		if (p!=NULL)							//�ҵ������Ϊi�Ľ��p 
 		{
 			p->data=e;
 			return true;
 		}
 		else									//û���ҵ����Ϊi�Ľ��
 			return false;						//����i���󷵻�false
 	} 

	int GetNo(T e)								//���ҵ�һ��Ϊe��Ԫ�ص����
	{
		int j=0;
	 	DLinkNode<T> *p=dhead->next;
 		while (p!=dhead && p->data!=e)
 		{
  			j++;								//����Ԫ��e
   			p=p->next;
   		}
		if (p==dhead)
  			return -1;							//δ�ҵ�ʱ����-1
		else
  			return j;							//�ҵ��󷵻������
	}
	bool Insert(int i,T e)						//��ѭ��˫���������iλ�ò���ֵΪe�Ľ��
	{
		if (i<0) return false; 					//����i���󷵻�false
		DLinkNode<T> *s=new DLinkNode<T>(e);	//�����½��s
 		DLinkNode<T> *p=geti(i-1);				//�������i-1�Ľ��p
 		if (p!=NULL)							//�ҵ������i-1�Ľ�� 
 		{
			s->next=p->next;					//�޸�s����next��
 			if (p->next!=NULL)					//�޸�p���ķǿպ�̽���prior��
  				p->next->prior=s;
			p->next=s;							//�޸�p����next��
 			s->prior=p;							//�޸�s����prior��
 			return true;						//����ɹ�����true 
 		}
 		else									//û���ҵ����i-1�Ľ�� 
 			return false;						//����i���󷵻�false
	}
	bool Delete(int i)							//��ѭ��˫������ɾ�����iλ�õĽ��
	{
		if (i<0) return false; 					//����i���󷵻�false
  		DLinkNode<T> *p=geti(i);				//�������i�Ľ��
 		if (p!=NULL)							//�ҵ������i�Ľ��p 
 		{
			p->prior->next=p->next;				//�޸�p����ǰ������next
			p->next->prior=p->prior;			//�޸�p����̽���prior
			delete p;							//�ͷſռ� 
 			return true;						//ɾ���ɹ�����true 
 		}
 		else 									//û���ҵ����i-1�Ľ�� 
 			return false;						//����i���󷵻�false  		
  	}
	void DispList()								//���ѭ��˫�������н��ֵ
	{
		DLinkNode<T> *p;
		p=dhead->next;							//pָ��ʼ���
		while (p!=dhead)						//p��Ϊdhead,���p����data��
		{
			cout << p->data << " ";
			p=p->next;							//p������һ�����
		}
		cout << endl;
	}
private:
	//*******************************************
	//���i����ȷ��Χ��-1��i<n��������Χ����NULL
	//i=-1ʱ����ͷ���dhead
	//i��0����i<nʱ�������i�Ľ��
	//*******************************************
	DLinkNode<T> *geti(int i)		      	//�������Ϊi�Ľ��
	{
		if (i<-1) return NULL;				//i<-1ʱ����NULL
		if (i==-1) return dhead;			//i=-1ʱ����ͷ��� 
		DLinkNode<T> *p=dhead->next;		//����pָ���׽�� 
 		int j=0;							//j��Ϊ0Ϊ�׽�����
 		while (j<i && p!=dhead)				//p�ƶ�i����� 
 		{	j++;
   			p=p->next;
   		}
   		if (p==dhead)						//û���ҵ����i�Ľ�㷵��NULL
		   return NULL;
		else 
			return p;
	}
};

