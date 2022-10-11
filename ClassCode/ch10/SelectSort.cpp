#include<iostream>
#include<vector>
using namespace std;
void disp(vector<int> &R,int low,int high)
{
	for (int i=low;i<=high;i++)
		printf("%d ",R[i]);
	printf("\n");
}
void SelectSort(vector<int> &R,int n) 	//��ѡ������
{
	for (int i=0;i<n-1;i++)				//����i������
	{	int minj=i;
		for (int j=i+1;j<n;j++)			//�ڵ�ǰ������R[i..n-1]��ѡ��СԪ��R[minj]
			if (R[j]<R[minj])
				minj=j;					//minj����Ŀǰ�ҵ�����СԪ�ص�λ��
		if (minj!=i)					//��R[minj]������������Ԫ��
			swap(R[i],R[minj]);			//����R[i]��R[minj]
	}
}
int main() 
{
	vector<int> a={9,8,7,6,5,4,3,2,1,0};
	int n=a.size();
	printf("����ǰ: "); disp(a,0,n-1); 
	SelectSort(a,n);
	printf("�����: "); disp(a,0,n-1); 
	return 0;
}
	

