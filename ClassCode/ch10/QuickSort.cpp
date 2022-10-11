#include<iostream>
#include<vector>
using namespace std;
void disp(vector<int> &R,int low,int high)
{
	for (int i=low;i<=high;i++)
		printf("%d ",R[i]);
	printf("\n");
}

int Partition1(vector<int> &R,int s,int t)		//�����㷨1
{	int base=R[s];						//�Ա���Ԫ��Ϊ��׼
	int i=s,j=t;
 	while (i<j)							//�ӱ����˽������м����,ֱ��i=jΪֹ
  	{	while (i<j && R[j]>base)
      		j--;						//�Ӻ���ǰ����,��һ��С�ڵ��ڻ�׼��R[j]
    	while (i<j && R[i]<=base)
      		i++;						//��ǰ������,��һ�����ڻ�׼��R[i]
    	if (i<j)
      		swap(R[i],R[j]);     		//��R[i]��R[j]���н���
	}
 	swap(R[s],R[i]);            		//����׼R[s]��R[i]���н���
 	return i;
}

int Partition1_1(vector<int> &R,int s,int t)	//�����㷨1�ĸĽ��汾 
{	int base=R[s];					  			//�Ա���Ԫ��Ϊ��׼,base��Ż�׼�ؼ���
	int i=s,j=t+1;
	while (i<j)									//i<jʱѭ��
	{
		j--;
		while (R[j]>base && i<j) 				//�Ӻ���ǰ����,��һ��С�ڵ��ڻ�׼��R[j]
			j--;
		i++;
		while (R[i]<=base && i<j)  				//��ǰ������,��һ�����ڻ�׼��R[i]
			i++;
     	if (i<j)								//i<jʱ���� 
			swap(R[i],R[j]);					//��֤i���iС�ڵ���base��j�Ҳ����base
	}
	swap(R[s],R[j]);							//����׼R[s]��R[i]���н���
	return j;
}

int Partition2(vector<int> &R,int s,int t)  	//�����㷨2
{	int i=s,j=t;
 	int base=R[s];							//�Ա���Ԫ��Ϊ��׼
 	while (i<j)								//�ӱ����˽������м����,ֱ��i=jΪֹ
  	{	while (j>i && R[j]>base)
      		j--;							//�Ӻ���ǰ����,��һ��С�ڵ��ڻ�׼��R[j]
    	if (j>i)
      	{	R[i]=R[j];						//R[j]ǰ�Ƹ���R[i]
        	i++;
    	}
     	while (i<j && R[i]<=base)
      		i++;						//��ǰ������,��һ�����ڻ�׼��R[i]
     	if (i<j)
      	{	R[j]=R[i];					//R[i]���Ƹ���R[j]
        	j--;
    	}
	}
 	R[i]=base;								//��׼��λ
 	return i;								//���ع�λ��λ��
}

int Partition3(vector<int> &R,int s,int t)		//�����㷨3
{	int i=s,j=s+1;
 	int base=R[s];						//�Ա���Ԫ��Ϊ��׼
 	while (j<=t)						//j��s+1��ʼ��������Ԫ��
  	{	if (R[j]<=base)					//�ҵ�С�ڵ��ڻ�׼��Ԫ��R[j]
      	{	i++;						//����С�ڵ���base��Ԫ������
        	if (i!=j)
         		swap(R[i],R[j]); 	//��R[i]��R[j]����
    	}
    	j++;						//����ɨ��
	}
	swap(R[s],R[i]);             		//����׼R[s]��R[i]���н���
 	return i;
}

void _QuickSort(vector<int> &R,int s,int t)	//��R[s..t]��Ԫ�ؽ��п�������
{	if (s<t) 				 			//�������ٴ�������Ԫ�ص����
  	{	int i=Partition2(R,s,t);			//����ʹ��ǰ��3�ֻ����㷨�е�����һ��
    	_QuickSort(R,s,i-1);			//�����ӱ�ݹ�����
     	_QuickSort(R,i+1,t);			//�����ӱ�ݹ�����
	}
}

void QuickSort(vector<int> &R,int n)	//��������
{
	_QuickSort(R,0,n-1);
}

int main() 
{
    vector<int> a={1,3,4,2,1,5,2,6,3,4,4};
	//vector<int> a={9,8,7,6,5,4,3,2,1,0};
	int n=a.size();
	printf("����ǰ: "); disp(a,0,n-1); 
	QuickSort(a,n);
	printf("�����: "); disp(a,0,n-1); 
	return 0;
}
	

