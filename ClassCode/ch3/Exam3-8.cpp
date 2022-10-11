#include "LinkStack.cpp"   			//包含链栈类模板的定义
const int MaxSize=100;
void Reverse(LinkStack<int> &st)    //逆置栈st
{
	int a[MaxSize];					//定义一个辅助数组 
	int i=0,e;
 	while (!st.empty())				//将出栈的元素放到数组a中
 	{
 		st.pop(e);
 		a[i++]=e;
 	}
	for (int j=0;j<i;j++)         	//将数组a的所有元素进栈
  		st.push(a[j]);
}

int main()
{
	LinkStack<int> st;
	cout << "1到5进栈" << endl; 
	for (int i=1;i<=5;i++)
		st.push(i);
	cout << "栈元素逆置" << endl;
	Reverse(st);
	int e;
	cout << "出栈序列: "; 
	while (!st.empty())
	{
		st.pop(e);
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
