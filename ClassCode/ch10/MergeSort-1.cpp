#include<iostream>
#include<vector>
using namespace std;
void disp(vector<int> &R,int low,int high)
{
	for (int i=low;i<=high;i++)
		printf("%d ",R[i]);
	printf("\n");
}
void Merge(vector<int> &R,int low,int mid,int high)
//��R[low..mid]��R[mid+1..high]��������ζ�·�鲢Ϊһ�������R[low..high]
{
	vector<int> R1;
	R1.resize(high-low+1);					//����R1�ĳ���Ϊhigh-low+1; 
	int i=low,j=mid+1,k=0;					//k��R1���±�,i��j�ֱ�Ϊ��1��2�ε��±�
	while (i<=mid && j<=high)				//�ڵ�1�κ͵�2�ξ�δɨ����ʱѭ��
		if (R[i]<=R[j])						//����1���е�Ԫ�ط���R1��
		{	R1[k]=R[i];
			i++; k++;
		}
		else								//����2���е�Ԫ�ط���R1��
		{	R1[k]=R[j];
			j++; k++; 
		}
	while (i<=mid)							//����1�����²��ָ��Ƶ�R1
	{	R1[k]=R[i];
		i++; k++;
	}
	while (j<=high)							//����2�����²��ָ��Ƶ�R1
	{	R1[k]=R[j];
		j++; k++;
	}
	for (k=0,i=low;i<=high;k++,i++)			//��R1���ƻ�R��
		R[i]=R1[k];
}

void  _MergeSort2(vector<int> &R,int s,int t)  	//��MergeSort2����
{
	if (s>=t) return;							//R[s..t]�ĳ���Ϊ0����1ʱ����
 	int m=(s+t)/2;						   		//ȡ�м�λ��m
 	_MergeSort2(R,s,m);							//��ǰ�ӱ�����
 	_MergeSort2(R,m+1,t);						//�Ժ��ӱ�����
 	Merge(R,s,m,t);								//�����������ӱ�ϲ���һ�������
}

void MergeSort2(vector<int> &R,int n)			//�Զ����µĶ�·�鲢����	
{
	_MergeSort2(R,0,n-1);
}

int main() 
{
	vector<int> a={9,8,7,6,5,4,3,2,1,0};
	int n=a.size();
	printf("����ǰ: "); disp(a,0,n-1); 
	MergeSort2(a,n);
	printf("�����: "); disp(a,0,n-1); 
	return 0;
}
	

