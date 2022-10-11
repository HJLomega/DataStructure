#include<iostream>
#include<vector>
using namespace std;
void disp(vector<int> &R,int low,int high)
{
	for (int i=low;i<=high;i++)
		printf("%d ",R[i]);
	printf("\n");
}
int Partition2(vector<int> &R,int s,int t)  //�����㷨2
{	int i=s,j=t;
 	int base=R[s];							//�Ա���Ԫ��Ϊ��׼
 	while (i!=j)							//�ӱ����˽������м����,ֱ��i=jΪֹ
  	{	while (j>i && R[j]>=base)
      		j--;							//�Ӻ���ǰ����,��һ��С�ڻ�׼��R[j]
    	if (j>i)
      	{	R[i]=R[j];						//R[j]ǰ�Ƹ���R[i]
        	i++;
    	}
     	while (i<j && R[i]<=base)
      		i++;							//��ǰ������,��һ�����ڻ�׼��R[i]
     	if (i<j)
      	{	R[j]=R[i];						//R[i]���Ƹ���R[j]
        	j--;
    	}
	}
 	R[i]=base;								//��׼��λ
 	return i;								//���ع�λ��λ��
}

void QuickSort1(vector<int> &R,int s,int t)	//���������е��м�λ��Ԫ��Ϊ��׼�Ŀ�������
{	if (s<t) 				 				//�������ٴ�������Ԫ�ص����
  	{	int mid=(s+t)/2;
     	swap(R[s],R[mid]); 					//R[s]��R[mid]����
    	int i=Partition2(R,s,t);			//����ʹ��ǰ��3�ֻ����㷨�е�����һ��
     	QuickSort1(R,s,i-1);				//�����ӱ�ݹ�����
     	QuickSort1(R,i+1,t);				//�����ӱ�ݹ�����
	}
}

void QuickSort(vector<int> &R,int n)	//��������
{
	QuickSort1(R,0,n-1);
}

int main() 
{
	vector<int> a={9,8,7,6,5,4,3,2,1,0};
	int n=a.size();
	printf("����ǰ: "); disp(a,0,n-1); 
	QuickSort(a,n);
	printf("�����: "); disp(a,0,n-1); 
	return 0;
}
	

