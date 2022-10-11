#include <iostream>
using namespace std;
template <typename T>
struct LinkNode								//�������ݽ������
{
	T data;									//���������
	LinkNode *next;							//ָ����һ�����
	LinkNode():next(NULL) {}				//���캯�� 
	LinkNode(T d):data(d),next(NULL) {}		//���ع��캯�� 
};

template <typename T>
class LinkQueue								//������ģ��
{
public:
	LinkNode<T> *front;						//��ͷָ��
	LinkNode<T> *rear;						//��βָ��
	LinkQueue():front(NULL),rear(NULL) {}	//���캯�� 
	~LinkQueue()							//��������
	{
		LinkNode<T> *pre=front,*p;
		if (pre!=NULL)						//�ǿնӵ����
		{
			if (pre==rear)					//ֻ��һ�����ݽ������
				delete pre;					//�ͷ�pre���
			else							//�������������ݽ������
			{
				p=pre->next;
				while (p!=NULL)
				{
					delete pre;				//�ͷ�pre���
					pre=p; p=p->next;		//pre��pͬ������
				}
				delete pre;					//�ͷ�β���
			}
		}
	}
	bool empty()							//�жӿ����� 
	{
		return rear==NULL; 
	}
	bool push(T e)							//��������
	{
		LinkNode<T> *p=new LinkNode<T>(e);
		if (rear==NULL)						//������Ϊ�յ���� 
			front=rear=p;					//�½����Ƕ��׽�����Ƕ�β���
		else								//�����Ӳ��յ����
		{	rear->next=p;					//��p���������β,����rearָ����
			rear=p;
		}
		return true;
	}
	bool pop(T &e)							//��������
	{
		if (rear==NULL)						//����Ϊ��
			return false;
		LinkNode<T> *p=front;				//pָ���׽��
		if (front==rear)					//������ֻ��һ�����ʱ
			front=rear=NULL;
		else								//�������ж�����ʱ
			front=front->next;
		e=p->data;
		delete p;							//�ͷų��ӽ��
		return true;
	}
	bool gethead(T &e)						//ȡ��ͷ����
	{
		if (rear==NULL)						//����Ϊ��
			return false;
		e=front->data;						//ȡ�׽��ֵ 
		return true;
	}
};

