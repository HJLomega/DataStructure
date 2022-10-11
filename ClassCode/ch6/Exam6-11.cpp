#include<iostream>
using namespace std;
int Fib1(int n)
{
	if (n==1 || n==2)
		return 1;
	int a=1,b=1,c;
	for (int i=3;i<=n;i++) 
	{
		c=a+b;
		a=b;
		b=c;
	}
	return c;
}

int main()
{
	int n=6;
	printf("Fib1(%d)=%d\n",n,Fib1(n));
	return 0;
}

