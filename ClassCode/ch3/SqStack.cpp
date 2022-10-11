#include <iostream>
using namespace std;
const int MaxSize=100;			//栈的容量 
template <typename T>
class SqStack					//顺序栈类
{
	T *data;					//存放栈中元素
	int top;       				//栈顶指针
public:
	SqStack()					//构造函数
	{
		data=new T[MaxSize];	//为data分配容量为MaxSize的空间
		top=-1;					//栈顶指针初始化
	}
	~SqStack()					//析构函数
	{
		delete [] data;
	}
	//----------栈基本运算算法-----------------
	bool empty()				//判断栈是否为空
	{
		return(top==-1);
	}
	bool push(T e)				//进栈算法
	{
		if (top==MaxSize-1)		//栈满时返回false
			return false;
		top++;					//栈顶指针增1
		data[top]=e;			//将x进栈
		return true;
	}
	bool pop(T &e)				//出栈算法
	{
		if (empty())			//栈为空的情况，即栈下溢出
			return false;
		e=data[top];			//取栈顶指针元素的元素
		top--;					//栈顶指针减1
		return true;
	}
	bool gettop(T &e)			//取栈顶元素算法
	{
		if (empty())			//栈为空的情况，即栈下溢出
			return false;
		e=data[top];			//取栈顶指针位置的元素
		return true;
	}
}; 

