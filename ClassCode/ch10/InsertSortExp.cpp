#include<iostream>
#include<vector>
using namespace std;
void disp(vector<int> &R,int low,int high)
{
	for (int i=low;i<=high;i++)
		printf("%d ",R[i]);
	printf("\n");
}
bool cmp(int x,int y)					//ʵ�ֵ���������Զ���ȽϺ���
{
	if (x<y) return true;
 	else return false;
}
void InsertSort(vector<int> &R,int n) 	//ֱ�Ӳ�������
{
	for (int i=1;i<n;i++)				//��R[1]��ʼ
	{
		if (cmp(R[i],R[i-1]))			//����ʱ 
		{
			int tmp=R[i];				//ȡ���������ĵ�һ��Ԫ��
			int j=i-1;					//������R[0..i-1]����ǰ��R[i]�Ĳ���λ��
			do
			{
				R[j+1]=R[j];			//������tmp��Ԫ�غ���
				j--;					//������ǰ�Ƚ�
			} while (j>=0 && !cmp(R[j],tmp));
			R[j+1]=tmp;					//��j+1������R[i]
		}
	}
}
int main() 
{
	vector<int> a={9,8,7,6,5,4,3,2,1,0};
	int n=a.size();
	printf("����ǰ: "); disp(a,0,n-1); 
	InsertSort(a,n);
	printf("�����: "); disp(a,0,n-1); 
	return 0;
}
	

