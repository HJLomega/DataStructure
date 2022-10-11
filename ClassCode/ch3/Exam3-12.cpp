#include<iostream>
using namespace std; 
const int MaxSize=100;					//队列的容量 
template <typename T>
class CSqQueue1							//循环队队列类模板
{
public:
	T *data;  								//存放队中元素
	int front;								//队头指针
	int count;								//队中元素个数
	CSqQueue1()								//构造函数
	{
		data=new T[MaxSize];				//为data分配容量为MaxSize的空间
		front=0;							//队头指针置初值
		count=0;							//元素个数置初值
	}
	~CSqQueue1()							//析构函数
	{
		delete [] data;
	}
	//----------循环队基本运算算法-----------------
	bool empty()							//判队空运算 
	{
		return count==0; 
	}
	bool push(T e)							//进队列运算
	{
		if (count==MaxSize)					//队满上溢出
			return false;
		int rear1=(front+count)%MaxSize;	//求队尾 
     	rear1=(rear1+1) % MaxSize;
     	data[rear1]=e; 
     	count++;			         		//元素个数增1
		return true;
	}
	bool pop(T &e)							//出队列运算
	{
		if (count==0)						//队空下溢出
			return false;		
		front=(front+1)%MaxSize;
		e=data[front];
		count--;							//元素个数减少1 
		return true;
	}
	bool gethead(T &e)						//取队头运算
	{
		if (count==0)						//队空下溢出
			return false;
		int head=(front+1)%MaxSize;
		e=data[head];
		return true;
	}
}; 
int main()
{	CSqQueue1<char> qu;			//定义一个字符顺序队sq
	char e;
	cout << "建立一个空队sq\n";
	cout << "队quq" << (qu.empty()?"空":"不空") << endl;
	cout << "元素a进队\n"; qu.push('a');
	cout << "元素b进队\n"; qu.push('b');
	cout << "元素c进队\n"; qu.push('c');
	cout << "元素d进队\n"; qu.push('d');
	cout << "元素e进队\n"; qu.push('e');
	cout << "队qu" << (qu.empty()?"空":"不空") << endl;
	cout << "所有元素出队次序:";
	while (!qu.empty())		//队不空循环
	{
		qu.pop(e);				//出队元素e
		cout << e << " ";			//输出元素e
	}
	cout << endl;
	cout << "销毁队qu" << endl;
	return 0;
}

