#include<iostream>
using namespace std;
template <typename T>
class Array
{
	T *data;					//TΪ���Ͳ���
	int length;
public:
	Array(int n=1)				//���캯��
	{	data=new T[n];			//Ϊ��̬��������ڴ�ռ�
		length=0;
	}
	~Array()					//��������
	{
		delete [] data;
	}
	void add(T x)				//���һ��Ԫ��x
	{
		data[length]=x;
		length++;
	}		
	void display()
	{	for (int i=0;i<length;i++)
			cout << data[i] << " ";
		cout << endl;
	}
};
int main()
{
	Array<char> ac(3);			//����ģ����Ķ���ac
	ac.add('x');
	ac.add('y');
	ac.add('z');
	cout << "ac: ";
	ac.display();				//���: x y z 

	Array<int> ai(5);			//����ģ����Ķ���ai
	ai.add(1);
	ai.add(2);
	ai.add(3);
	ai.add(4);
	ai.add(5);
	cout << "ai: ";
	ai.display();				//���: 1 2 3 4 5
	return 0;
}

