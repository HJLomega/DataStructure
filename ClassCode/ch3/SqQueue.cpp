#include<iostream>
using namespace std; 
const int MaxSize=100;					//���е����� 
template <typename T>
class SqQueue							//��ѭ���Ӷ�����ģ��
{
public:
	T *data;  							//��Ŷ���Ԫ��
	int front, rear;					//��ͷ�Ͷ�βָ��
	SqQueue()							//���캯��
	{
		data=new T[MaxSize];			//Ϊdata��������ΪMaxSize�Ŀռ�
		front=rear=-1;					//��ͷ��βָ���ó�ֵ
	}
	~SqQueue()	//��������
	{
		delete [] data;
	}
	//----------��ѭ���ӻ��������㷨-----------------
	bool empty()						//�жӿ����� 
	{
		return (front==rear); 
	}
	bool push(T e)						//����������
	{
		if (rear==MaxSize-1)			//���������
			return false;
		rear++;
		data[rear]=e;
		return true;
	}
	bool pop(T &e)						//����������
	{
		if (front==rear)				//�ӿ������
			return false;
		front++;
		e=data[front];
		return true;
	}
	bool gethead(T &e)					//ȡ��ͷ����
	{
		if (front==rear)				//�ӿ������
			return false;
		int head=front+1;
		e=data[head];
		return true;
	}
}; 

