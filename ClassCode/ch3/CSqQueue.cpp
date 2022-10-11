#include<iostream>
using namespace std; 
#define MaxSize 100						//队列的容量 
template <typename T>
class CSqQueue							//循环队队列类模板
{
public:
	T *data;  							//存放队中元素
	int front, rear;					//队头和队尾指针
	CSqQueue()							//构造函数
	{
		data=new T[MaxSize];			//为data分配容量为MaxSize的空间
		front=rear=0;					//队头队尾指针置初值
	}
	~CSqQueue()							//析构函数
	{
		delete [] data;
	}
	//----------循环队基本运算算法-----------------
	bool empty()						//判队空运算 
	{
		return (front==rear); 
	}
	bool push(T e)						//进队列运算
	{
		if ((rear+1)%MaxSize==front)	//队满上溢出
			return false;
		rear=(rear+1)%MaxSize;
		data[rear]=e;
		return true;
	}
	bool pop(T &e)						//出队列运算
	{
		if (front==rear)				//队空下溢出
			return false;
		front=(front+1)%MaxSize;
		e=data[front];
		return true;
	}
	bool gethead(T &e)					//取队头运算
	{
		if (front==rear)				//队空下溢出
			return false;
		int head=(front+1)%MaxSize;
		e=data[head];
		return true;
	}
	int getlength()					    	//返回队中元素个数	
	{
		return (rear-front+MaxSize)%MaxSize;
	}
}; 

