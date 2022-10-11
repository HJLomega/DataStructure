#include <iostream>
using namespace std;
template <typename T>
struct LinkNode								//链栈结点类型 
{
	 T data;								//数据域
	 LinkNode *next;						//指针域
	 LinkNode():next(NULL) {} 				//构造函数 
	 LinkNode(T d):data(d),next(NULL) {} 	//重载构造函数 
};

template <typename T>
class STACK									//链栈泛型类
{
public:
	LinkNode<T> *rear;						//链栈尾结点指针 
	STACK()									//构造函数
	{	
		rear=NULL;
	}
	~STACK()							//析构函数
	{	
		if (rear==NULL) return;			//空链表直接返回	 
		LinkNode<T> *pre=rear,*p=pre->next;
		while (p!=rear)
		{
			delete pre;
			pre=p; p=p->next;				//pre、p同步后移
		}
		delete pre;
	}
	bool empty()							//判栈空算法
	{
		return rear==NULL; 
	}
	bool push(T e)							//进栈算法
	{
		LinkNode<T> *p=new LinkNode<T>(e);	//新建结点p
		if (empty())						//栈为空的情况 
		{
			rear=p;
			rear->next=rear;
		}
		else								//栈不空的情况
		{
			p->next=rear->next;				//将结点p插入到结点rear之后 
			rear->next=p;
		}
		return true;
	}
	bool pop(T &e)							//出栈算法
	{
		LinkNode<T> *p;
		if (empty())						//栈空的情况
			return false;
		if (rear->next==rear)				//栈中只有一个结点的情况
		{	p=rear; 
			rear=NULL;
		}
		else								//栈中有2个及以上结点的情况
		{
			p=rear->next;
			rear->next=p->next;
		}
		e=p->data;
		delete p;							//释放结点p
		return true;
	}
	bool gettop(T &e)						//取栈顶元素
	{
		if (empty())						//栈空的情况
			return false;
		e=rear->next->data;
		return true;
	}
	T Getbottom()							//取栈底元素
	{
		if (empty()) throw "栈空";
		return rear->data;
	}
};
int main()
{
	int e;
	STACK<int> st;
	cout << st.Getbottom() << endl;
	cout << "1到5进栈" << endl;
	for (int i=1;i<=5;i++)
		st.push(i);
	cout << "栈底元素: " << st.Getbottom() << endl;
	st.pop(e);
	cout << "出栈元素" <<  e << endl;
	st.pop(e);
	cout << "出栈元素" <<  e << endl;
	cout << "栈底元素: " << st.Getbottom() << endl;
	return 0;
}
