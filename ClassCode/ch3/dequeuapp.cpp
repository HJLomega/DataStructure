#include<iostream>
#include<vector>
#include<deque>
using namespace std;
void solve(vector<int> &a,deque<int> &qu)
{
	for (int i=0;i<a.size();i++)
	{	if (qu.empty() || a[i]>=qu.back())		//队空或者a[i]大于等于队尾时队尾进队
			qu.push_back(a[i]);
		else if (a[i]<=qu.front())				//a[i]小于等于队头时队头进队 
			qu.push_front(a[i]);
		else
		{	while (!qu.empty() && a[i]<qu.back()) //出队尾直到队尾<=a[i]或者队空
				qu.pop_back();
			qu.push_back(a[i]);					//将a[i]进队尾
		}
	}
}
int main()
{

	int b[]={3,1,2,5,4};
	vector<int> a(b,b+5);
	deque<int> qu;
	solve(a,qu);
	cout << "输出单调队列(队头到队尾): ";
	while (!qu.empty())
	{
		cout << qu.front() << " ";
		qu.pop_front();
	}
	cout << endl;
	return 0;  
}

