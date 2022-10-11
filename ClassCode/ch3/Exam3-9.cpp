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
class STACK									//��ջ������
{
public:
	LinkNode<T> *rear;						//��ջβ���ָ�� 
	STACK()									//���캯��
	{	
		rear=NULL;
	}
	~STACK()							//��������
	{	
		if (rear==NULL) return;			//������ֱ�ӷ���	 
		LinkNode<T> *pre=rear,*p=pre->next;
		while (p!=rear)
		{
			delete pre;
			pre=p; p=p->next;				//pre��pͬ������
		}
		delete pre;
	}
	bool empty()							//��ջ���㷨
	{
		return rear==NULL; 
	}
	bool push(T e)							//��ջ�㷨
	{
		LinkNode<T> *p=new LinkNode<T>(e);	//�½����p
		if (empty())						//ջΪ�յ���� 
		{
			rear=p;
			rear->next=rear;
		}
		else								//ջ���յ����
		{
			p->next=rear->next;				//�����p���뵽���rear֮�� 
			rear->next=p;
		}
		return true;
	}
	bool pop(T &e)							//��ջ�㷨
	{
		LinkNode<T> *p;
		if (empty())						//ջ�յ����
			return false;
		if (rear->next==rear)				//ջ��ֻ��һ���������
		{	p=rear; 
			rear=NULL;
		}
		else								//ջ����2�������Ͻ������
		{
			p=rear->next;
			rear->next=p->next;
		}
		e=p->data;
		delete p;							//�ͷŽ��p
		return true;
	}
	bool gettop(T &e)						//ȡջ��Ԫ��
	{
		if (empty())						//ջ�յ����
			return false;
		e=rear->next->data;
		return true;
	}
	T Getbottom()							//ȡջ��Ԫ��
	{
		if (empty()) throw "ջ��";
		return rear->data;
	}
};
int main()
{
	int e;
	STACK<int> st;
	cout << st.Getbottom() << endl;
	cout << "1��5��ջ" << endl;
	for (int i=1;i<=5;i++)
		st.push(i);
	cout << "ջ��Ԫ��: " << st.Getbottom() << endl;
	st.pop(e);
	cout << "��ջԪ��" <<  e << endl;
	st.pop(e);
	cout << "��ջԪ��" <<  e << endl;
	cout << "ջ��Ԫ��: " << st.Getbottom() << endl;
	return 0;
}
