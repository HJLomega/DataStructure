#include<iostream>
using namespace std; 
const int MaxSize=100;					//���е����� 
template <typename T>
class CSqQueue1							//ѭ���Ӷ�����ģ��
{
public:
	T *data;  								//��Ŷ���Ԫ��
	int front;								//��ͷָ��
	int count;								//����Ԫ�ظ���
	CSqQueue1()								//���캯��
	{
		data=new T[MaxSize];				//Ϊdata��������ΪMaxSize�Ŀռ�
		front=0;							//��ͷָ���ó�ֵ
		count=0;							//Ԫ�ظ����ó�ֵ
	}
	~CSqQueue1()							//��������
	{
		delete [] data;
	}
	//----------ѭ���ӻ��������㷨-----------------
	bool empty()							//�жӿ����� 
	{
		return count==0; 
	}
	bool push(T e)							//����������
	{
		if (count==MaxSize)					//���������
			return false;
		int rear1=(front+count)%MaxSize;	//���β 
     	rear1=(rear1+1) % MaxSize;
     	data[rear1]=e; 
     	count++;			         		//Ԫ�ظ�����1
		return true;
	}
	bool pop(T &e)							//����������
	{
		if (count==0)						//�ӿ������
			return false;		
		front=(front+1)%MaxSize;
		e=data[front];
		count--;							//Ԫ�ظ�������1 
		return true;
	}
	bool gethead(T &e)						//ȡ��ͷ����
	{
		if (count==0)						//�ӿ������
			return false;
		int head=(front+1)%MaxSize;
		e=data[head];
		return true;
	}
}; 
int main()
{	CSqQueue1<char> qu;			//����һ���ַ�˳���sq
	char e;
	cout << "����һ���ն�sq\n";
	cout << "��quq" << (qu.empty()?"��":"����") << endl;
	cout << "Ԫ��a����\n"; qu.push('a');
	cout << "Ԫ��b����\n"; qu.push('b');
	cout << "Ԫ��c����\n"; qu.push('c');
	cout << "Ԫ��d����\n"; qu.push('d');
	cout << "Ԫ��e����\n"; qu.push('e');
	cout << "��qu" << (qu.empty()?"��":"����") << endl;
	cout << "����Ԫ�س��Ӵ���:";
	while (!qu.empty())		//�Ӳ���ѭ��
	{
		qu.pop(e);				//����Ԫ��e
		cout << e << " ";			//���Ԫ��e
	}
	cout << endl;
	cout << "���ٶ�qu" << endl;
	return 0;
}

