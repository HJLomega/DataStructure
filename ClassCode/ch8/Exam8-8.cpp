#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 10
int a[]={1,2,3,4};
int n=4;
char x[MAXN];
void solve(int i,int sum)			//���ݷ���� 
{
	if (i==n-1)						//����Ҷ�ӽ�� 
	{
		if (abs(sum)==4)			//�ҵ�һ�����н� 
		{
			for (int j=0;j<n;j++)	//������ 
			{
				printf("%d",a[j]);
				printf("%c",x[j]);
			}
			printf("=%d\n",sum);
		}
		return;
	}
	x[i]='+';						//x[i]ȡ+�� 
	sum+=a[i+1];					//����sum 
	solve(i+1,sum);					//������һ�� 
	sum-=a[i+1];					//���˻ָ�sum 
	
	x[i]='-';						//x[i]ȡ-�� 
	sum-=a[i+1];					//����sum 
	solve(i+1,sum);					//������һ��
	sum+=a[i+1];					//���˻ָ�sum
}

int main()
{
	int sum=1;						//�����ȡֵ1 
	int i=0;						//�Ӹ���㿪ʼ 
	solve(i,sum);
	return 0;
}
