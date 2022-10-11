#include<iostream>
using namespace std; 
#define MaxSize 100						//���е����� 
template <typename T>
class CSqQueue							//ѭ���Ӷ�����ģ��
{
public:
	T *data;  							//��Ŷ���Ԫ��
	int front, rear;					//��ͷ�Ͷ�βָ��
	CSqQueue()							//���캯��
	{
		data=new T[MaxSize];			//Ϊdata��������ΪMaxSize�Ŀռ�
		front=rear=0;					//��ͷ��βָ���ó�ֵ
	}
	~CSqQueue()							//��������
	{
		delete [] data;
	}
	//----------ѭ���ӻ��������㷨-----------------
	bool empty()						//�жӿ����� 
	{
		return (front==rear); 
	}
	bool push(T e)						//����������
	{
		if ((rear+1)%MaxSize==front)	//���������
			return false;
		rear=(rear+1)%MaxSize;
		data[rear]=e;
		return true;
	}
	bool pop(T &e)						//����������
	{
		if (front==rear)				//�ӿ������
			return false;
		front=(front+1)%MaxSize;
		e=data[front];
		return true;
	}
	bool gethead(T &e)					//ȡ��ͷ����
	{
		if (front==rear)				//�ӿ������
			return false;
		int head=(front+1)%MaxSize;
		e=data[head];
		return true;
	}
	int getlength()					    	//���ض���Ԫ�ظ���	
	{
		return (rear-front+MaxSize)%MaxSize;
	}
}; 

