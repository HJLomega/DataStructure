#include <iostream>
using namespace std;
const int MaxSize=100;			//ջ������ 
template <typename T>
class SqStack					//˳��ջ��
{
	T *data;					//���ջ��Ԫ��
	int top;       				//ջ��ָ��
public:
	SqStack()					//���캯��
	{
		data=new T[MaxSize];	//Ϊdata��������ΪMaxSize�Ŀռ�
		top=-1;					//ջ��ָ���ʼ��
	}
	~SqStack()					//��������
	{
		delete [] data;
	}
	//----------ջ���������㷨-----------------
	bool empty()				//�ж�ջ�Ƿ�Ϊ��
	{
		return(top==-1);
	}
	bool push(T e)				//��ջ�㷨
	{
		if (top==MaxSize-1)		//ջ��ʱ����false
			return false;
		top++;					//ջ��ָ����1
		data[top]=e;			//��x��ջ
		return true;
	}
	bool pop(T &e)				//��ջ�㷨
	{
		if (empty())			//ջΪ�յ��������ջ�����
			return false;
		e=data[top];			//ȡջ��ָ��Ԫ�ص�Ԫ��
		top--;					//ջ��ָ���1
		return true;
	}
	bool gettop(T &e)			//ȡջ��Ԫ���㷨
	{
		if (empty())			//ջΪ�յ��������ջ�����
			return false;
		e=data[top];			//ȡջ��ָ��λ�õ�Ԫ��
		return true;
	}
}; 

