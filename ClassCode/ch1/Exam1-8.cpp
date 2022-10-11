#include<iostream>
using namespace std;
bool Sum1(int n,int &s)              		//算法1
{
    if (n<1)
        return false;
    s=n*(n+1)/2;
    return true;
}

int Sum2(int n)                     		//算法2
{
	if (n<1)
        return -1;
    return n*(n+1)/2;
}

int Sum3(int n)						    	//算法3 
{
	if (n<1)
		throw "参数n错误";         			//抛出异常
    return n*(n+1)/2;
}

int main() 
{
	int n,s;
	printf("n:");
	scanf("%d",&n);
	if (Sum1(n,s))
		printf("解法1：Sum1(%d)=%d\n",n,s);
	else
		printf("解法1：参数错误\n");
	s=Sum2(n);
	if (s>0)
		printf("解法2：Sum2(%d)=%d\n",n,s);
	else
		printf("解法2：参数错误\n");
	try
	{
		s=Sum3(n);
		printf("解法3：Sum3(%d)=%d\n",n,s);
	}
	catch(char const *e)
	{
		printf("解法3：%s\n",e);
	}
	return 0;
}
	
