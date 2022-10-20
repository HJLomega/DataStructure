#include <iostream>
/*
���һ��ѭ������QUEUE<T>����data[0..MaxSize-1]��Ŷ���Ԫ�أ�
��front��rear�ֱ���Ϊ��ͷ�Ͷ�βָ�룬
������һ����־tag��ʶ���п��ܿգ�false�����������true����
��������front==rear������Ϊ�ӿջ������������
Ҫ����ƶ��е���ػ��������㷨��
*/
#define MaxSize 100						//���е����� 
template <typename T>
class QUEUE						//ѭ���Ӷ�����ģ��
{
public:
	T* data;  							//��Ŷ���Ԫ��
	int front, rear;					//��ͷ�Ͷ�βָ��
	bool flag;          //�ӿ��ܿգ�false�����ӿ�������true��
	QUEUE()							//���캯��
	{
		data = new T[MaxSize];			//Ϊdata��������ΪMaxSize�Ŀռ�
		front = rear = 0;					//��ͷ��βָ���ó�ֵ
		flag = false;
	}
	~QUEUE()							//��������
	{
		delete[] data;
	}
	//----------ѭ���ӻ��������㷨-----------------
	bool empty()						//�жӿ����� 
	{
		return (front == rear)&&(!flag);
	}
	bool full()                        //�ж������� 
	{
		return (front == rear) && (flag);
	}
	bool push(T e)						//����������
	{
		
		if (this->full())	//���������
			return false;
		rear = (rear + 1) % MaxSize;
		data[rear] = e;
		flag = true;
		return true;
	}
	bool pop(T& e)						//����������
	{
		if (this->empty())				//�ӿ������
			return false;
		front = (front + 1) % MaxSize;
		e = data[front];
		flag = !(rear == front);
		return true;
	}
	bool gethead(T& e)					//ȡ��ͷ����
	{
		if (this->empty())				//�ӿ������
			return false;
		int head = (front + 1) % MaxSize;
		e = data[head];
		return true;
	}
	int getlength()					    	//���ض���Ԫ�ظ���	
	{
		return (rear - front + MaxSize) % MaxSize;
	}
};
void test() {
	QUEUE<int> q = QUEUE<int>();
	int temp;
	std::cout << " q.empty():" << q.empty() << " q.full():" << q.full() << "\n";
	std::cout << " push 0" << "\n";
	q.push(0);
	std::cout << " q.empty():" << q.empty() << " q.full():" << q.full() << "\n";
	q.pop(temp);
	std::cout << " pop " << temp <<"\n";
	std::cout << " q.empty():" << q.empty() << " q.full():" << q.full() << "\n";
	std::cout << " push Maxsize - 1 nums" << "\n";
	for (int i = 0; i < MaxSize - 1; i++) {
		q.push(i);
	}
	std::cout << " q.empty():" << q.empty() << " q.full():" << q.full() << "\n";
	std::cout << " push MaxSize" << "\n";
	q.push(MaxSize);
	std::cout << " q.empty():" << q.empty() << " q.full():" << q.full() << "\n";
}
int main() {
	test();
	std::cin.get();
}