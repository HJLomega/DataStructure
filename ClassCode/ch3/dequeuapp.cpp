#include<iostream>
#include<vector>
#include<deque>
using namespace std;
void solve(vector<int> &a,deque<int> &qu)
{
	for (int i=0;i<a.size();i++)
	{	if (qu.empty() || a[i]>=qu.back())		//�ӿջ���a[i]���ڵ��ڶ�βʱ��β����
			qu.push_back(a[i]);
		else if (a[i]<=qu.front())				//a[i]С�ڵ��ڶ�ͷʱ��ͷ���� 
			qu.push_front(a[i]);
		else
		{	while (!qu.empty() && a[i]<qu.back()) //����βֱ����β<=a[i]���߶ӿ�
				qu.pop_back();
			qu.push_back(a[i]);					//��a[i]����β
		}
	}
}
int main()
{

	int b[]={3,1,2,5,4};
	vector<int> a(b,b+5);
	deque<int> qu;
	solve(a,qu);
	cout << "�����������(��ͷ����β): ";
	while (!qu.empty())
	{
		cout << qu.front() << " ";
		qu.pop_front();
	}
	cout << endl;
	return 0;  
}

