#include<iostream>
#include<vector>
using namespace std;
void disp(vector<int> &R,int low,int high)
{
	for (int i=low;i<=high;i++)
		printf("%d ",R[i]);
	printf("\n");
}
void BubbleSort(vector<int> &R,int n) 	//ð������
{
	for (int i=0;i<n-1;i++) 
	{	bool exchange=false;		//����ǰ��exchange��Ϊfalse
		for (int j=n-1;j>i;j--)		//һ�����ҳ���С�ؼ��ֵ�Ԫ��
			if (R[j]<R[j-1])		//����ʱ����
			{	swap(R[j],R[j-1]);
				exchange=true;		//���˷���������exchangeΪtrue
			}
		if (!exchange)				//����û�з�����������;�����㷨
			return;
	}
}

int main() 
{
	vector<int> a={9,8,7,6,5,4,3,2,1,0};
	int n=a.size();
	printf("����ǰ: "); disp(a,0,n-1); 
	BubbleSort(a,n);
	printf("�����: "); disp(a,0,n-1); 
	return 0;
}
	

