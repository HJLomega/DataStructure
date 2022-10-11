#include<iostream>
#include<stack>
using namespace std;
struct SNode									//栈元素类型 
{	int n;
	char x,y,z;
	bool flag;										//是否可以直接移动 
	SNode()	{}										//构造函数
	SNode(int n1,char x1,char y1,char z1,bool f1)	//重载构造函数
	{
		n=n1;
		x=x1; y=y1; z=z1;
		flag=f1;
	}
};
void Hanoi1(int n,char x,char y,char z)
{
	if (n==1)							//只有一个盘片时直接移动 
	{	cout << "盘片" << n << "从" << x << "移动到" << z << endl;
		return;
	}
	SNode e,e1,e2,e3;
	stack<SNode> st;					//定义一个栈st 
	e=SNode(n,x,y,z,false);
	st.push(e);
	while (!st.empty())					//栈不空时循环
	{
		e=st.top(); st.pop();			//出栈元素e,对应任务(n1,x1,y1,z1) 
		bool flag1=e.flag;
		char x1=e.x,y1=e.y,z1=e.z;
		int n1=e.n; 
		if (flag1)						//该任务可以直接移动
			cout << "盘片" << n1 << "从" << x1 << "移动到" << z1 << endl;
		else
		{
			if (n1-1==1)
				e1=SNode(n1-1,y1,x1,z1,true);
			else
				e1=SNode(n1-1,y1,x1,z1,false);
			st.push(e1);
			e2=SNode(n1,x1,' ',z1,true);
			st.push(e2);
			if (n1-1==1)
				e3=SNode(n1-1,x1,z1,y1,true);
			else
				e3=SNode(n1-1,x1,z1,y1,false);
			st.push(e3);
		}
	}
}


int main()
{
	Hanoi1(3,'a','b','c');
	return 0;
}

