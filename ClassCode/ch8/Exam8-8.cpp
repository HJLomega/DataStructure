#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 10
int a[]={1,2,3,4};
int n=4;
char x[MAXN];
void solve(int i,int sum)			//回溯法求解 
{
	if (i==n-1)						//到达叶子结点 
	{
		if (abs(sum)==4)			//找到一个可行解 
		{
			for (int j=0;j<n;j++)	//输出结果 
			{
				printf("%d",a[j]);
				printf("%c",x[j]);
			}
			printf("=%d\n",sum);
		}
		return;
	}
	x[i]='+';						//x[i]取+号 
	sum+=a[i+1];					//计算sum 
	solve(i+1,sum);					//进入下一层 
	sum-=a[i+1];					//回退恢复sum 
	
	x[i]='-';						//x[i]取-号 
	sum-=a[i+1];					//计算sum 
	solve(i+1,sum);					//进入下一层
	sum+=a[i+1];					//回退恢复sum
}

int main()
{
	int sum=1;						//根结点取值1 
	int i=0;						//从根结点开始 
	solve(i,sum);
	return 0;
}
