#include<iostream>
#include<vector>
using namespace std;
void disp(vector<int> &R,int low,int high)
{
	for (int i=low;i<=high;i++)
		printf("%d ",R[i]);
	printf("\n");
}
void ShellSort(vector<int> &R,int n) 	//ϣ������
{
	int d=n/2;							//�����ó�ֵ
	while (d>0)
	{	for (int i=d;i<n;i++)			//���������dλ�õ�Ԫ�������ֱ�Ӳ�������
		{
			if (R[i]<R[i-d])     		//����ʱ
			{	int tmp=R[i];
				int j=i-d;
				do
				{
					R[j+d]=R[j];		//������tmp��Ԫ��ͬ���к���
					j=j-d;				//������ǰ�Ƚ�
				} while (j>=0 && R[j]>tmp);
				R[j+d]=tmp;				//��j+d������R[i]
			}
		}
		d=d/2;							//��С����
	}
}
int main() 
{
	vector<int> a={9,8,7,6,5,4,3,2,1,0};
	int n=a.size();
	printf("����ǰ: "); disp(a,0,n-1); 
	ShellSort(a,n);
	printf("�����: "); disp(a,0,n-1); 
	return 0;
}
	

