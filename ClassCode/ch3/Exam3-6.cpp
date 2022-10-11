#include<iostream>
using namespace std;
const int MaxSize=100;						//栈中最多元素个数 
template <typename T>
class STACK									//含Getmin()的栈类
{
	T data[MaxSize];                 		//存放主栈中元素，初始为空
    T mindata[MaxSize];              		//存放min栈中元素，初始为空
	int top;
	int mintop;
public:
	STACK():top(-1),mintop(-1) {}			//构造函数 
private:		
	//min栈简化的基本运算算法
	bool minempty()               			//判断min栈是否空
  	{
	  	return mintop==-1;
	}
	void minpush(T e)              			//元素e进min栈
	{
		mintop++;
		mindata[mintop]=e;
	}
	T minpop()                 				//元素出min栈
  	{
   		T x=mindata[mintop];
		mintop--;
		return x;
	}
	T mingettop()              				//取min栈栈顶元素
  	{
    	return mindata[mintop];
    }
public:
	//主栈基本运算算法
  	bool empty()                    		//判断主栈是否空
  	{
  		return top==-1;
	}
	bool push(T x)                   		//元素进主栈
  	{
  		if (top==MaxSize-1)					//主栈满返回false 
  			return false;
	  	if (empty() || x<=Getmin())
			minpush(x);						//栈空或者x<=min栈顶元素时进min栈
     	top++;
		data[top]=x;            			//将x进主栈
		return true;
	}
	bool pop(T &x)                      	//元素出主栈
  	{
 		if (empty())						//栈为空的情况，即栈下溢出
			return false;
    	x=data[top];               			//从主栈出栈x
    	top--;
    	if (x==mingettop())	    			//若栈顶元素为最小元素
      		minpop();             			//min栈出栈一次
    	return true;
    }
	bool gettop(T &e)                   	//取主栈栈顶元素
	{
		if (empty())						//栈为空的情况，即栈下溢出
			return false;
		e=data[top];						//取栈顶指针位置的元素
		return true;
	}
	T Getmin()			        			//获取栈中最小元素
  	{
    	return mingettop();					//返回min栈的栈顶元素即主栈中最小元素
	}
};
int main()
{
	STACK<int> st;							//定义栈对象 
	int e;
	cout <<"元素5,6,3,7依次进栈" << endl;
	st.push(5);
	st.push(6);
	st.push(3);
	st.push(7);
	cout << "  求最小元素并出栈" << endl;
	while (!st.empty())
    {
		cout << "    最小元素: " << st.Getmin() << endl;
		st.pop(e);
    	cout << "    出栈元素: " << e << endl;
    }
	return 0;
}
