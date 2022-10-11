#include<iostream>
using namespace std;
void f(int n)							//递归函数
{	if (n==0)							//递归出口
  		return;
	else								//递归体
  	{	printf("Pre:  n=%d\n",n);
    	printf("执行f(%d)\n",n-1);
     	f(n-1);
     	printf("Post: n=%d\n",n);
	}
}
int main()
{
	f(4);
	return 0;
}

