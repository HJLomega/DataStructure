/*
#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
void solve(vector<int> &a,stack<int> &st)
{
	int i=0;
	while (i<a.size())
	{	if (st.empty() || a[i]<st.top())	//栈空或者a[i]小于栈顶元素，直接进栈 
		{	st.push(a[i]);
			i++;
		}
		else st.pop();						//否则出栈栈顶元素			
	}
}
int main()  
{	int b[]={3,4,2,6,4,5,2,3};	
	vector<int> a(b,b+8);
	stack<int> st;
	solve(a,st);
	cout << "输出单调栈(栈顶到栈底): ";
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
	return 0;  
}
*/

#include<iostream>
#include<stack>
using namespace std;

void Sortst(stack<int> &st)
{	stack<int> st1;							//定义临时栈st1
	int e;
	while (!st.empty())						//将st1变为递增栈
	{	e=st.top();							//st出栈元素e
		st.pop();
		while (!st1.empty() &&e<st1.top()) 	//e相对st1是反序的 
		{	st.push(st1.top());				//退栈st1中大于e的元素并进栈st
			st1.pop();
		}
		st1.push(e);						//将e进st1栈 
	}
	while (!st1.empty())					//将st1所有元素退栈并进到st栈中
	{	e=st1.top();
		st1.pop();
		st.push(e);
	}
}
int main()  
{
	int a[]={3,4,3,2,3};	
	stack<int> st;
	for (int i=0;i<5;i++)
		st.push(a[i]);
	Sortst(st);
	cout << "输出栈(栈顶到栈底): ";
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
	return 0;  
}

