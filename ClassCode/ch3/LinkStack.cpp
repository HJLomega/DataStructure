#include <iostream>
using namespace std;
template <typename T>
struct LinkNode								//��ջ������� 
{
	 T data;								//������
	 LinkNode *next;						//ָ����
	 LinkNode():next(NULL) {} 				//���캯�� 
	 LinkNode(T d):data(d),next(NULL) {} 	//���ع��캯�� 
};

template <typename T>
class LinkStack								//��ջ������
{
public:
	LinkNode<T> *head;						//��ջͷ���
	LinkStack()								//���캯��
	{	
		head=new LinkNode<T>();
	}
	~LinkStack()							//��������
	{	
		LinkNode<T> *pre=head,*p=pre->next;
		while (p!=NULL)
		{
			delete pre;
			pre=p; p=p->next;				//pre��pͬ������
		}
		delete pre;
	}
	bool empty()						//��ջ���㷨
	{
		return head->next==NULL; 
	}
	bool push(T e)							//��ջ�㷨
	{
		LinkNode<T> *p=new LinkNode<T>(e);	//�½����p
		p->next=head->next;					//������p��Ϊ�׽��
		head->next=p;
		return true;
	}
	bool pop(T &e)							//��ջ�㷨
	{
		LinkNode<T> *p;
		if (head->next==NULL)				//ջ�յ����
			return false;
		p=head->next;						//pָ��ʼ���
		e=p->data;
		head->next=p->next;					//ɾ�����p
		delete p;							//�ͷŽ��p
		return true;
	}
	bool gettop(T &e)						//ȡջ��Ԫ��
	{
		LinkNode<T> *p;
		if (head->next==NULL)				//ջ�յ����
			return false;
		p=head->next;						//pָ��ʼ���
		e=p->data;
		return true;
	}
};

