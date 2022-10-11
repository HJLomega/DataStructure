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
	{	if (st.empty() || a[i]<st.top())	//ջ�ջ���a[i]С��ջ��Ԫ�أ�ֱ�ӽ�ջ 
		{	st.push(a[i]);
			i++;
		}
		else st.pop();						//�����ջջ��Ԫ��			
	}
}
int main()  
{	int b[]={3,4,2,6,4,5,2,3};	
	vector<int> a(b,b+8);
	stack<int> st;
	solve(a,st);
	cout << "�������ջ(ջ����ջ��): ";
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
{	stack<int> st1;							//������ʱջst1
	int e;
	while (!st.empty())						//��st1��Ϊ����ջ
	{	e=st.top();							//st��ջԪ��e
		st.pop();
		while (!st1.empty() &&e<st1.top()) 	//e���st1�Ƿ���� 
		{	st.push(st1.top());				//��ջst1�д���e��Ԫ�ز���ջst
			st1.pop();
		}
		st1.push(e);						//��e��st1ջ 
	}
	while (!st1.empty())					//��st1����Ԫ����ջ������stջ��
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
	cout << "���ջ(ջ����ջ��): ";
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
	return 0;  
}

