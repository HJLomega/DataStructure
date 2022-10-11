#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 5
void fun1(int a[MAXN][MAXN],int b[MAXN][MAXN],int n)
{
	int c[MAXN][MAXN];
	memset(c,0,sizeof(c));
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			for (int k=0;k<n;k++)
			{
				c[i][j]+=a[i][k]*b[k][j];
				printf("c[%d][%d]+=a[%d][%d]*b[%d][%d]\n",i,j,i,k,k,j);
			}
	printf("C:\n");
	for (int i=0;i<n;i++)
	{	for (int j=0;j<n;j++)
			printf("%4d",c[i][j]);
		printf("\n");
	}
}

void fun2(int a[MAXN][MAXN],int b[MAXN][MAXN],int n)
{
	int c[MAXN][MAXN];
	memset(c,0,sizeof(c));
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			for (int k=0;k<n;k++)
			{
				c[i][k]+=a[i][j]*b[j][k];
				printf("c[%d][%d]+=a[%d][%d]*b[%d][%d]\n",i,k,i,j,j,k);
			}
	printf("C:\n");
	for (int i=0;i<n;i++)
	{	for (int j=0;j<n;j++)
			printf("%4d",c[i][j]);
		printf("\n");
	}
}


int main()
{
	int n=2;
	int a[MAXN][MAXN]={{1,2,3},{4,5,6},{7,8,1}};
	int b[MAXN][MAXN]={{2,1,6},{3,1,5},{1,4,2}};
	fun1(a,b,n);
	fun2(a,b,n);
	return 0;
}
	
