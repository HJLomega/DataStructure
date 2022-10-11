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

int Partition1_2(vector<int> &R,int s,int t)	//�����㷨1
{	int base=R[s];					  			//�Ա���Ԫ��Ϊ��׼,base��Ż�׼�ؼ���
	int i=s,j=t+1;
	while (i<j)									//ѭ��
	{
		j--;
		while (R[j]>base && i<j) 			//�Ӻ���ǰ����,��һ��С�ڵ��ڻ�׼��R[j]
			j--;
		i++;
		while (R[i]<=base && i<j)  			//��ǰ������,��һ�����ڻ�׼��R[i]
			i++;
     	if (i<j)							//i<jʱ���� 
			swap(R[i],R[j]);				//��֤i���iС�ڵ���base��j�Ҳ����base
		printf("i=%d,j=%d  R:",i,j); disp(R,s,t);
	}
	swap(R[s],R[j]);					//����׼R[s]��R[i]���н���
	printf("while������ i=%d,j=%d  R:",i,j); disp(R,s,t);
	return j;
}

int Partition1_1(vector<int> &R,int s,int t)				//�����㷨1
{	int base=R[s];					  	//�Ա���Ԫ��Ϊ��׼,base��Ż�׼�ؼ���
	int i=s,j=t+1;
	while (true)						//ѭ��
	{
		i++;
		while (R[i]<base)  				//R[i]С��baseʱ����i
        {	if (i==t) break;			//i����ʱ�˳�ѭ�� 
        	i++;
    	}
    	j--;
		while (base<R[j]) 				//R[j]����baseʱ��Сj
      	{	if(j==s) break;				//j����ʱ�˳�ѭ�� 
      		j--;
      	}
     	if (i>=j) break;				//i��j�������˳�ѭ�� 
		swap(R[i],R[j]);				//R[i]��R[j]����:��֤i��಻����base��j�Ҳ಻С��base
	}
	swap(R[s],R[j]);					//����׼R[s]��R[i]���н���
	return j;
}

void  _QuickSort(vector<int> &R,int s,int t)	//��R[s..t]��Ԫ�ؽ��п�������
{	if (s<t) 				 			//�������ٴ�������Ԫ�ص����
  	{	int i=Partition1_2(R,s,t);			//����ʹ��ǰ��3�ֻ����㷨�е�����һ��
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
	vector<int> a={2,1};
	Partition1_2(a,0,a.size()-1);
	return 0;
}

/*
int main() 
{
	vector<int> a={9,8,7,6,5,4,3,2,1,0};
    //vector<int> a={5,2,3,1};
    //vector<int> a={9,8,7,6,5,4,3,2,1};
    //vector<int> a={1,3,4,2,1,5,2,6,3,4,4};
    //vector<int> a={1,2};
	int n=a.size();
	printf("����ǰ: "); disp(a,0,n-1); 
	QuickSort(a,n);
	printf("�����: "); disp(a,0,n-1); 
	return 0;
}
*/
	

