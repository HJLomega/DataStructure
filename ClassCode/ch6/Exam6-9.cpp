#include<iostream>
using namespace std;
const int MAXN=15;
int a[MAXN][MAXN];         					//�����������
void Spiral(int x,int y,int start,int n)	//�ݹ鴴����������
{	if (n<=0) return;						//�ݹ��������
	if (n==1)								//�����СΪ1ʱ
  	{	a[x][y]=start;
    	return;
    }
 	for (int j=x;j<x+n-1;j++)				//��һ��
  	{	a[y][j]=start;
    	start++;
    }
	for (int i=y;i<y+n-1;i++)				//��һ��
  	{	a[i][x+n-1]=start;
    	start++;
    }
 	for (int j=x+n-1;j>x;j--)				//��һ��
 	{	a[y+n-1][j]=start;
    	start+=1;
    }
 	for (int i=y+n-1;i>y;i--)				//��һ��
  	{	a[i][x]=start;
    	start++;
	}
	Spiral(x+1,y+1,start,n-2);				//�ݹ����
}
int main()
{
	int n=5;
	Spiral(0,0,1,n);
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
  			printf("%3d",a[i][j]);
  		printf("\n");
  	}
}

