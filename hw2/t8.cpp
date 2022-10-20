#include <iostream>
/*
设计一个循环队列QUEUE<T>，用data[0..MaxSize-1]存放队列元素，
用front和rear分别作为队头和队尾指针，
另外用一个标志tag标识队列可能空（false）或可能满（true），
这样加上front==rear可以作为队空或队满的条件。
要求设计队列的相关基本运算算法。
*/
#define MaxSize 100						//队列的容量 
template <typename T>
class QUEUE						//循环队队列类模板
{
public:
	T* data;  							//存放队中元素
	int front, rear;					//队头和队尾指针
	bool flag;          //队可能空（false），队可能满（true）
	QUEUE()							//构造函数
	{
		data = new T[MaxSize];			//为data分配容量为MaxSize的空间
		front = rear = 0;					//队头队尾指针置初值
		flag = false;
	}
	~QUEUE()							//析构函数
	{
		delete[] data;
	}
	//----------循环队基本运算算法-----------------
	bool empty()						//判队空运算 
	{
		return (front == rear)&&(!flag);
	}
	bool full()                        //判队满运算 
	{
		return (front == rear) && (flag);
	}
	bool push(T e)						//进队列运算
	{
		
		if (this->full())	//队满上溢出
			return false;
		rear = (rear + 1) % MaxSize;
		data[rear] = e;
		flag = true;
		return true;
	}
	bool pop(T& e)						//出队列运算
	{
		if (this->empty())				//队空下溢出
			return false;
		front = (front + 1) % MaxSize;
		e = data[front];
		flag = !(rear == front);
		return true;
	}
	bool gethead(T& e)					//取队头运算
	{
		if (this->empty())				//队空下溢出
			return false;
		int head = (front + 1) % MaxSize;
		e = data[head];
		return true;
	}
	int getlength()					    	//返回队中元素个数	
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