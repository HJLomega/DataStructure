#include<iostream>
#include<vector>
using namespace std;
void disp(vector<int> &R,int low,int high)
{
	for (int i=low;i<=high;i++)
		printf("%d ",R[i]);
	printf("\n");
}
void BinInsertSort(vector<int> &R,int n) 	//�۰��������
{
	for (int i=1;i<n;i++)					//��R[1]��ʼ
	{
		if (R[i]<R[i-1])					//����
		{
			int tmp=R[i];					//��R[i]���浽tmp��
			int low=0,high=i-1;
			while (low<=high)				//��R[low..high]���۰������������λ��
			{
				int mid=(low+high)/2;		//ȡ�м�λ��
				if (tmp<R[mid])
					high=mid-1;				//������������
				else
					low=mid+1;				//��������Ұ���
			}
			for (int j=i-1;j>=high+1;j--)	//Ԫ�غ���
				R[j+1]=R[j];
			R[high+1]=tmp;					//ԭR[i]���뵽R[high+1]�� 
		}	
	}
}
int main() 
{
	vector<int> a={9,8,7,6,5,4,3,2,1,0};
	int n=a.size();
	printf("����ǰ: "); disp(a,0,n-1); 
	BinInsertSort(a,n);
	printf("�����: "); disp(a,0,n-1); 
	return 0;
}
	

