#include <iostream>
using namespace std;
template <typename T>
struct LinkNode								//链队数据结点类型
{
	T data;									//结点数据域
	LinkNode *next;							//指向下一个结点
	LinkNode():next(NULL) {}				//构造函数 
	LinkNode(T d):data(d),next(NULL) {}		//重载构造函数 
};

template <typename T>
class LinkQueue								//链队类模板
{
public:
	LinkNode<T> *front;						//队头指针
	LinkNode<T> *rear;						//队尾指针
	LinkQueue():front(NULL),rear(NULL) {}	//构造函数 
	~LinkQueue()							//析构函数
	{
		LinkNode<T> *pre=front,*p;
		if (pre!=NULL)						//非空队的情况
		{
			if (pre==rear)					//只有一个数据结点的情况
				delete pre;					//释放pre结点
			else							//有两个或多个数据结点的情况
			{
				p=pre->next;
				while (p!=NULL)
				{
					delete pre;				//释放pre结点
					pre=p; p=p->next;		//pre、p同步后移
				}
				delete pre;					//释放尾结点
			}
		}
	}
	bool empty()							//判队空运算 
	{
		return rear==NULL; 
	}
	bool push(T e)							//进队运算
	{
		LinkNode<T> *p=new LinkNode<T>(e);
		if (rear==NULL)						//若链队为空的情况 
			front=rear=p;					//新结点既是队首结点又是队尾结点
		else								//若链队不空的情况
		{	rear->next=p;					//将p结点链到队尾,并将rear指向它
			rear=p;
		}
		return true;
	}
	bool pop(T &e)							//出队运算
	{
		if (rear==NULL)						//队列为空
			return false;
		LinkNode<T> *p=front;				//p指向首结点
		if (front==rear)					//队列中只有一个结点时
			front=rear=NULL;
		else								//队列中有多个结点时
			front=front->next;
		e=p->data;
		delete p;							//释放出队结点
		return true;
	}
	bool gethead(T &e)						//取队头运算
	{
		if (rear==NULL)						//队列为空
			return false;
		e=front->data;						//取首结点值 
		return true;
	}
};

