#include <iostream>
const int MaxSize = 100;					//队列的容量 

template <typename T>
class CQueue							//循环队队列类模板
{
public:
	T* data;  							//存放队中元素
	int size, rear;					//队列中的元素个数和队尾元素的位置
	CQueue()							//构造函数
	{
		data = new T[MaxSize];			//为data分配容量为MaxSize的空间
		size = 0;
		rear = -1;					//队头队尾指针置初值
	}
	~CQueue()	//析构函数
	{
		delete[] data;
	}
	bool empty()						//判队空运算 
	{
		return size == 0;
	}
	bool push(T e)						//进队列运算
	{
		if (size == MaxSize)			//队满上溢出
			return false;
		rear = (rear + 1)%MaxSize;
		data[rear] = e;
		size++;
		return true;
	}
	bool pop(T& e)						//出队列运算
	{
		if (size == 0)				//队空下溢出
			return false;
		int front1 = (rear - size +1 + MaxSize) % MaxSize;
		e = data[front1];
		size--;
		return true;
	}
	bool init(T* p, int length) {  //循环顺序队的初始化
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