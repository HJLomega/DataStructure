#include <iostream>
const int MaxSize = 100;					//���е����� 

template <typename T>
class CQueue							//ѭ���Ӷ�����ģ��
{
public:
	T* data;  							//��Ŷ���Ԫ��
	int size, rear;					//�����е�Ԫ�ظ����Ͷ�βԪ�ص�λ��
	CQueue()							//���캯��
	{
		data = new T[MaxSize];			//Ϊdata��������ΪMaxSize�Ŀռ�
		size = 0;
		rear = -1;					//��ͷ��βָ���ó�ֵ
	}
	~CQueue()	//��������
	{
		delete[] data;
	}
	bool empty()						//�жӿ����� 
	{
		return size == 0;
	}
	bool push(T e)						//����������
	{
		if (size == MaxSize)			//���������
			return false;
		rear = (rear + 1)%MaxSize;
		data[rear] = e;
		size++;
		return true;
	}
	bool pop(T& e)						//����������
	{
		if (size == 0)				//�ӿ������
			return false;
		int front1 = (rear - size +1 + MaxSize) % MaxSize;
		e = data[front1];
		size--;
		return true;
	}
	bool init(T* p, int length) {  //ѭ��˳��ӵĳ�ʼ��
		while (!(this->empty())) {
			T temp ;
			this->pop(temp);
		}

		for (int i = 0; i < length; i++) {

			if ( !(this->push(p[i])) ) {
				return false;
			}
		}
		return true;
	}
};

void test() {
	CQueue<int> q = CQueue<int>();
	int ar[] = { 1,2,3,4,5 };
	q.init(ar,5);
	while (!(q.empty())) {
		int temp ;
		q.pop(temp);
		std::cout << temp << "\n";
	}
}
int main() {
	test();
	std::cin.get();
}