#include<iostream>
#include<string>
using namespace std;
const int MAX=10;									//���ά����
void disp(int A[MAX][MAX],int n)					//���n�׶�ά����A
{	for (int i=0;i<n;i++)
	{	for (int j=0;j<n;j++)
			printf("%3d",A[i][j]);
		printf("\n");
	}
}
void compression(int A[MAX][MAX],int n,int a[]) 	//��Aѹ���洢��a��
{	for (int i=0;i<n;i++)
		for (int j=0;j<=i;j++)
	 	{	int k=i*(i+1)/2+j;
			a[k]=A[i][j];
		}
}
int getk(int i,int j)									//��i��j��ѹ���洢�е�k�±�
{	if (i>=j)
		return i*(i+1)/2+j;
	else
		return j*(j+1)/2+i;
}
void Mult(int a[],int b[],int C[MAX][MAX],int n)	//����˷�
{	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
		{	int s=0;
		 	for (int k=0;k<n;k++)
			{	int k1=getk(i,k);
				int k2=getk(k,j);
				s+=a[k1]*b[k2];
			}
			C[i][j]=s;
		}
}
int main()
{	int n=3;
	int m=n*(n+1)/2;
	int A[MAX][MAX]={{1,2,3},{2,4,5},{3,5,6}};
	int B[MAX][MAX]={{2,1,3},{1,5,2},{3,2,4}};
	int C[MAX][MAX];
	int *a=new int[m];
	int *b=new int[m];
	printf("A:\n"); disp(A,n);
	printf("Aѹ���洢��a��\n");
	compression(A,n,a);
	printf("a: ");
	for (int i=0;i<m;i++)
		printf("%3d",a[i]);
	printf("\n");
	printf("B:\n"); disp(B,n);
	printf("Bѹ���洢��b��\n");
	compression(B,n,b);
	printf("b: ");
	for (int i=0;i<m;i++)
		printf("%3d",b[i]);
	printf("\n");
	printf("C=A*B\n");
	Mult(a,b,C,n);
	printf("C:\n"); disp(C,n);
	return 0;	
}

