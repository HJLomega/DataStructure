#include<iostream>
#include<vector>
using namespace std;
int BinSearch1(vector<int> &R,int k)    	//�����ҷǵݹ��㷨
{	int n=R.size();
 	int low=0,high=n-1;
 	while (low<=high)						//��ǰ����ǿ�ʱ
  	{	int mid=(low+high)/2;				//�����������м�λ��
     	if (k==R[mid])					  	//���ҳɹ����������mid
      		return mid;
    	if (k<R[mid])					    //������R[low..mid-1]�в���
      		high=mid-1;
     	else								//k>R[mid]
      		low=mid+1;						//������R[mid+1..high]�в���
    }
	return -1;								//��ǰ���������ʱ����-1
}

int BinSearch21(vector<int> &R,int low,int high,int k) 	//��BinSearch2��������
{	if (low<=high)						 	//��ǰ��������ǿ�ʱ
  	{	int mid=(low+high)/2;				//�����������м�λ��
    	if (k==R[mid])						//���ҳɹ����������mid
      		return mid;
     	if (k<R[mid])						//�ݹ����������в���
      		return BinSearch21(R,low,mid-1,k);
     	else								//k>R[mid],�ݹ����������в���
      		return BinSearch21(R,mid+1,high,k);
    }
	else return -1;						//��ǰ���������ʱ����-1
}
int BinSearch2(vector<int> &R,int k)		//�����ҵݹ��㷨
{
	return BinSearch21(R,0,R.size()-1,k);
}

int main()
{
	vector<int> R={2,4,7,9,10,14,18,26,32,40};
	for (int i=0;i<R.size();i++)
	{
		int k=R[i];
		printf("�㷨1: R[%d]=%d\n",BinSearch1(R,k),k);
		printf("�㷨2: R[%d]=%d\n",BinSearch2(R,k),k);
	}
	return 0;
}
