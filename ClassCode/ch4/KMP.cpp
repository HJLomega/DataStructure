#include <iomanip>
#include<iostream>
#include<string>
using namespace std;
void Dispnext(string t,int next[])			//输出next
{
	int j;
	cout << setw(10) << "j";
	for (j=0;j<t.length();j++)
		cout << setw(3) << j;
	cout << endl;
	cout << setw(10) << "t[j]";
	for (j=0;j<t.length();j++)
		cout << setw(3) << t[j];
	cout << endl;
	cout << setw(10) << "next[j]";
	for (j=0;j<t.length();j++)
		cout << setw(3) << next[j];
	cout << endl;
}
void GetNext(string t,int *next)			//由模式串t求出next值
{
	int j,k;
	j=0; k=-1;
	next[0]=-1;
	while (j<t.length()-1)
	{	if (k==-1 || t[j]==t[k])			//k为-1或比较的字符相等时
		{	j++; k++;						//依次移到下一个字符
			next[j]=k;
		}
		else								//比较的字符不相等时
			k=next[k];						//k回退 
	}
}
int KMP(string s,string t)					//基本KMP算法
{
	int n=s.length(),m=t.length();
	int *next=new int[m];
	GetNext(t,next);						//求出部分匹配信息next数组
	Dispnext(t,next);
	int i=0,j=0;
	while (i<n && j<m)						//s和t均没有遍历完 
	{
		if (j==-1 || s[i]==t[j])			//j=-1或者比较的字符相同时 
		{	i++;
			j++;							//i,j各增1
		}
		else								//比较的字符不相同时
			j=next[j]; 						//i不变,j回退
	}
	if (j>=m)								//t串遍历完毕：匹配成功
		return i-m;							//返回t在s中的首字符索引
	else									//s串遍历完而t串没有遍历完：匹配不成功
		return -1;							//返回-1
}
void GetNextval(string t,int *nextval)		//由模式串t求出nextval值
{	int j=0,k=-1;
	nextval[0]=-1;
	while (j<t.length())
	{	if (k==-1 || t[j]==t[k])			//k为-1或比较的字符相等时
		{	j++;k++;
			if (t[j]!=t[k])					//两个字符不相等时
				nextval[j]=k;
			else
				nextval[j]=nextval[k];
		}
		else								//比较的字符不相等时
			k=nextval[k];					//k回退
	}
}
void Dispnextval(string t,int nextval[])	//输出nextval
{
	int j;
	cout << setw(10) << "j";
	for (j=0;j<t.length();j++)
		cout << setw(3) << j;
	cout << endl;
	cout << setw(10) << "t[j]";
	for (j=0;j<t.length();j++)
		cout << setw(3) << t[j];
	cout << endl;
	cout << setw(10) << "nextval[j]";
	for (j=0;j<t.length();j++)
		cout << setw(3) << nextval[j];
	cout << endl;
}
int KMPval(string s,string t)				//改进的KMP算法
{
	int n=s.length(),m=t.length();
	int *nextval=new int[m];
	GetNextval(t,nextval);					//求出nextval数组
	Dispnextval(t,nextval);
	int i=0,j=0;
	while (i<n && j<m) 
	{
		if (j==-1 || s[i]==t[j])
		{	i++;							//i,j各增1 
			j++;
		}
		else j=nextval[j];					//i不变,j回退
	}
	if (j>=m)
		return i-m;
	else
		return -1;
}
 
int main()
{
	//s="ababcabcacbab";
	string s="abcaabbabcabaacbacba";
	cout << "s: " << s << endl;
	//t="abcac";
	string t="abcabaa";
	cout << "t: " << t << endl;
	cout << "t在s中的位置: " << KMP(s,t) << endl;
	return 0;
}

/*
void GetNext1(string t,int *next)			//由模式串t求出next值
{
	int j,k;
	j=0; k=-1;
	next[0]=-1;
	while (j<t.length()-1)
	{	cout << "k=" << k << ",j=" << j << endl;
		if (k==-1 || t[j]==t[k])			//k为-1或比较的字符相等时
		{	j++; k++;						//依次移到下一个字符
			next[j]=k;
		}
		else								//比较的字符不相等时
			k=next[k];						//k回退 
	}
}

int main()
{
	//s="ababcabcacbab";
	string s="abcd";
	int n=4;
	int next[10];
	GetNext1(s,next);
		cout << setw(10) << "j";

	for (int j=0;j<n;j++)
		cout << setw(3) << j;
	cout << endl;
	cout << setw(10) << "t[j]";
	for (int j=0;j<n;j++)
		cout << setw(3) << s[j];
	cout << endl;
	cout << setw(10) << "next[j]";
	for (int j=0;j<n;j++)
		cout << setw(3) << next[j];
	cout << endl;

	return 0;
}
*/

