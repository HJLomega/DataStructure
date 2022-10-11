#include <iostream.h>
const int MaxSize=100;
//递归求解Hanoi问题
void Hanoi1(int n,char x,char y,char z)
{	if (n==1)
		cout << "  将第" << n << "个圆盘从" << x << "移动到" << z << endl;
	else
	{	Hanoi1(n-1,x,z,y);
		cout << "  将第" << n << "个圆盘从" << x << "移动到" << z << endl;
		Hanoi1(n-1,y,x,z);
	}
}
//非递归求解Hanoi问题
struct SType				//顺序栈中元素类型
{	int n;
	char x,y,z;
	bool flag;				//可直接移动时为true,否则为false
};
class Stack							//顺序栈类
{
	SType *data;					//存放栈中元素
	int top;						//栈顶指针
public:
	Stack()							//构造函数
	{
		data=new SType[MaxSize];	//分配空间
		top=-1;
	}
	~Stack()						//析构函数
	{
		delete [] data;				//释放空间
	}
	bool StackEmpty()				//判栈空否
	{
		return(top==-1);
	}
	void Push(int n1,char x1,char y1,char z1,bool flag1)	//进栈
	{
		top++;
		data[top].n=n1; data[top].x=x1; data[top].y=y1;
		data[top].z=z1; data[top].flag=flag1;
	}
	void Pop(int &n1,char &x1,char &y1,char &z1,bool &flag1) //退栈
	{
		n1=data[top].n; x1=data[top].x; y1=data[top].y;
		z1=data[top].z; flag1=data[top].flag;
		top--;
	}
	void GetTop(int &n1,char &x1,char &y1,char &z1,bool &flag1)	//取栈顶元素
	{
		n1=data[top].n; x1=data[top].x; y1=data[top].y;
		z1=data[top].z; flag1=data[top].flag;
	}
};
void Hanoi2(int n, char x, char y, char z)
{
	Stack st;										//建立一个顺序栈
	int n1; char x1,y1,z1; bool flag1;
	if (n<=0) return;								//参数错误返回
	else if (n==1)									//只有一个圆盘的情况
		cout << "  将第" << n << "个圆盘从" << x << "移动到" << z << endl;
	else
	{
		st.Push(n,x,y,z,false);						//初值(n,x,y,z,false)进栈
		while (!st.StackEmpty())					//栈不空循环
		{
			st.GetTop(n1,x1,y1,z1,flag1);			//取栈顶元素(n1,x1,y1,z1,flag1)
			if (flag1==false && n1>1)				//当不能直接移时
			{
				st.Pop(n1,x1,y1,z1,flag1);			//退栈
				if (n1-1==1)						//只有一个盘片时可直接移动
					st.Push(n1-1,y1,x1,z1,true);	//将(n1-1,y1,x1,z1,true)进栈
				else
					st.Push(n1-1,y1,x1,z1,false);	//将(n1-1,y1,x1,z1,false)进栈
				st.Push(n1,x1,y1,z1,true);			//将第n1个圆盘从x1移到z1
				if (n1-1==1)						//再将(n1-1,x1,z1,y1)进栈
					st.Push(n1-1,x1,z1,y1,true);
				else
					st.Push(n1-1,x1,z1,y1,false);
			}
			else if (flag1==true)					//当可以直接移动时
			{
				cout << "  将第" << n1 << "个圆盘从" << x1 << "移动到" << z1 << endl;
				st.Pop(n1,x1,y1,z1,flag1);			//移动盘片后退栈
			}
		}
	}
}
void main()
{
	cout << "n=3的Hanoi问题递归求解如下:\n";
	Hanoi1(3,'A','B','C');
	cout << "n=3的Hanoi问题非递归求解如下:\n";
	Hanoi2(3,'A','B','C');
}
