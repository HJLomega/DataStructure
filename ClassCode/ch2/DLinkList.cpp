#include<iostream>
using namespace std;
template <typename T>
struct DLinkNode										//˫���������� 
{
	T data;												//�������Ԫ��
	DLinkNode<T> *next;									//ָ���̽���ָ��
	DLinkNode<T> *prior;								//ָ��ǰ������ָ�� 
	DLinkNode():next(NULL),prior(NULL) {}				//���캯�� 
	DLinkNode(T d):data(d),next(NULL),prior(NULL) {}	//���ع��캯�� 
};

template <typename T>
class DLinkList									//˫������
{
public:
	DLinkNode<T> *dhead;						//˫����ͷ���
	DLinkList() 								//���캯��,����һ����˫����
	{
		dhead=new DLinkNode<T>();
	}
	~DLinkList() 								//��������,����˫����
	{
		DLinkNode<T> *pre,*p;
		pre=dhead;p=pre->next;
		while (p!=NULL)							//��p������㲢�ͷ���ǰ����� 
		{
			delete pre;							//�ͷ�pre��� 
			pre=p; p=p->next;					//pre,pͬ������һ����� 
		}
		delete pre;								//pΪ��ʱpreָ��β���,��ʱ�ͷ�β���						
	}
	void CreateListF(T a[],int n)				//ͷ�巨����˫����
	{
		DLinkNode<T> *s;
		for (int i=0;i<n;i++)					//ѭ���������ݽ��
		{
			s=new DLinkNode<T>(a[i]);			//�������ݽ��s
     		s->next=dhead->next;				//�޸�s����next��Ա
     		if (dhead->next!=NULL)				//�޸�ͷ���ķǿպ�̽���prior
      			dhead->next->prior=s;
     		dhead->next=s;						//�޸�ͷ����next
    		s->prior=dhead;						//�޸�s����prior
		}
	}
	void CreateListR(T a[],int n)				//β�巨����˫����
	{
		DLinkNode<T> *s,*r;
		r=dhead;								//rʼ��ָ��β���,��ʼʱָ��ͷ���
		for (int i=0;i<n;i++)					//ѭ���������ݽ��
		{
			s=new DLinkNode<T>(a[i]);			//�������ݽ��s
     		r->next=s;					    	//��s������r���֮��
     		s->prior=r;
     		r=s;
		}
		r->next=NULL;							//��β����next����ΪNULL
	}
	void Add(T e)								//��˫����ĩβ���һ��ֵΪe�Ľ�� 
	{
		DLinkNode<T> *s=new DLinkNode<T>(e); 	//�½����s
 		DLinkNode<T> *p=dhead;
 		while (p->next!=NULL)					//����β���p
  			p=p->next;
 		p->next=s;								//��β���֮�������s
 		s->prior=p;
	}
	int Getlength()                   			//��˫���������ݽ�����
	{
		DLinkNode<T> *p=dhead;
	 	int cnt=0;
 		while (p->next!=NULL)					//�ҵ�β���Ϊֹ
  		{	cnt++;
  			p=p->next;
  		}
 		return cnt;
 	}
	bool GetElem(int i,T &e)					//��˫���������Ϊi�Ľ��ֵ
	{
		if (i<0) return false;              	//����i���󷵻�false
 		DLinkNode<T> *p=geti(i);
 		if (p!=NULL)							//�ҵ����Ϊi�Ľ�� 
 		{
 			e=p->data;
		 	return true;						//�ɹ��ҵ�����true 
		 }
 		else
 			return false;						//û���ҵ����i�Ľ�㷵��false 
 	} 
	bool SetElem(int i,T e)              		//�������Ϊi�Ľ��ֵ
	{
		if (i<0) return false;              	//����i���󷵻�false
 		DLinkNode<T> *p=geti(i);
 		if (p!=NULL)							//�ҵ����Ϊi�Ľ�� 
 		{
 			p->data=e;
 			return true;
 		}
 		else									//û���ҵ����Ϊi�Ľ��
 			return false;						//����i���󷵻�false
 	} 

	int GetNo(T e)								//���ҵ�һ��Ϊe��Ԫ�ص����
	{
		int j=0;								//j��Ϊ0��pָ���׽�� 
	 	DLinkNode<T> *p=dhead->next;
 		while (p!=NULL && p->data!=e)
 		{
  			j++;								//����Ԫ��e
   			p=p->next;
   		}
		if (p==NULL)
  			return -1;							//δ�ҵ�ʱ����-1
		else
  			return j;							//�ҵ��󷵻������
	}
	bool Insert(int i,T e)						//��˫���������iλ�ò���ֵΪe�Ľ��
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
	bool Delete(int i)							//��˫������ɾ�����iλ�õĽ��
	{
		if (i<0) return false; 					//����i���󷵻�false
  		DLinkNode<T> *p=geti(i);				//�������i�Ľ��
 		if (p!=NULL)							//�ҵ������i�Ľ��p 
 		{
			p->prior->next=p->next;				//�޸�p����ǰ������next
			if (p->next!=NULL)					//�޸�p���ǿպ�̽���prior
 				p->next->prior=p->prior;
			delete p;							//�ͷſռ� 
 			return true;						//ɾ���ɹ�����true 
 		}
 		else 									//û���ҵ����i-1�Ľ�� 
 			return false;						//����i���󷵻�false  		
  	}
	void DispList()								//���˫�������н��ֵ
	{
		DLinkNode<T> *p;
		p=dhead->next;							//pָ��ʼ���
		while (p!=NULL)							//p��ΪNULL,���p����data��
		{
			cout << p->data << " ";
			p=p->next;							//p������һ�����
		}
		cout << endl;
	}
	
	void reverse()								//����������� 
	{
		DLinkNode<T> *p=dhead;
		while (p->next!=NULL)					//����β��� 
			p=p->next;
		while (p!=dhead)						//�Ӻ���ǰ���� 
		{
			cout << p->data << " ";
			p=p->prior;
		}
		cout << endl;
	}
		
private:
	//*******************************************
	//���i����ȷ��Χ��-1��i<n��������Χ����NULL
	//i=-1ʱ����ͷ���head
	//i��0����i<nʱ�������i�Ľ��
	//*******************************************
	DLinkNode<T> *geti(int i)		      		//�������Ϊi�Ľ��
	{
		if (i<-1) return NULL;					//i<-1����NULL 
		DLinkNode<T> *p=dhead;					//����pָ��ͷ���
 		int j=-1;								//j��Ϊ-1(������Ϊͷ������Ϊ-1)
 		while (j<i && p!=NULL)					//ָ��p�ƶ�i+1�����
 		{	j++;
   			p=p->next;
   		}
		return p;								//����p
	}
};

