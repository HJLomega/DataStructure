#include<iostream>
#include<string>
using namespace std;
int BF(string s,string t)					//BF模式匹配算法 
{	int i=0,j=0;
	while (i<s.length() && j<t.length())	//两串未遍历完时循环
	{
		if (s[i]==t[j])						//比较的两个字符相同时
		{
			i++;							//依次移到s和t串下一个字符
			j++;
		}
		else								//比较的两个字符不相同时
		{	i=i-j+1;						//i回退到s的本趟开始的下一个字符 
			j=0; 							//j移动到t串的开头
		}
	}
	if (j>=t.length())						//t串遍历完毕：匹配成功 
		return i-t.length();				//返回t在s中的首字符索引
	else									//s串遍历完而t串没有遍历完：匹配不成功
		return -1;							//返回-1 
}
int main()
{
	string s="ababcabcacbab";
	cout << "s: " << s << endl;
	string t="abcac";
	cout << "t: " << t << endl;
	cout << "t在s中的位置: " << BF(s,t) << endl;
	return 0;
}

