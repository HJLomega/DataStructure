#include<iostream>
using namespace std;
bool Sum1(int n,int &s)              		//�㷨1
{
    if (n<1)
        return false;
    s=n*(n+1)/2;
    return true;
}

int Sum2(int n)                     		//�㷨2
{
	if (n<1)
        return -1;
    return n*(n+1)/2;
}

int Sum3(int n)						    	//�㷨3 
{
	if (n<1)
		throw "����n����";         			//�׳��쳣
    return n*(n+1)/2;
}

int main() 
{
	int n,s;
	printf("n:");
	scanf("%d",&n);
	if (Sum1(n,s))
		printf("�ⷨ1��Sum1(%d)=%d\n",n,s);
	else
		printf("�ⷨ1����������\n");
	s=Sum2(n);
	if (s>0)
		printf("�ⷨ2��Sum2(%d)=%d\n",n,s);
	else
		printf("�ⷨ2����������\n");
	try
	{
		s=Sum3(n);
		printf("�ⷨ3��Sum3(%d)=%d\n",n,s);
	}
	catch(char const *e)
	{
		printf("�ⷨ3��%s\n",e);
	}
	return 0;
}
	
