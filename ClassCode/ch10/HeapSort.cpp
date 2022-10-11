#include<iostream>
#include<vector>
using namespace std;
void disp(vector<int> &R,int low,int high)
{
	for (int i=low;i<=high;i++)
		printf("%d ",R[i]);
	printf("\n");
}
void siftDown(vector<int> &R,int low,int high)	//R[low..high]���Զ�����ɸѡ
{	int i=low;
 	int j=2*i+1;			        		//R[j]��R[i]������
 	int tmp=R[i];							//tmp��ʱ��������
 	while (j<=high)							//ֻ��R[low..high]��Ԫ�ؽ���ɸѡ
  	{	if (j<high && R[j]<R[j+1])
      		j++;							//���Һ��ӽϴ�,��jָ���Һ���
     	if (tmp<R[j]) 						//tmp�ĺ��ӽϴ�
      	{	R[i]=R[j];						//��R[j]������˫��λ����
        	i=j; j=2*i+1;					//�޸�i��jֵ,�Ա��������ɸѡ
        }
     	else break;							//�����ӽ�С����ɸѡ����
  	}
	R[i]=tmp;								//ԭ������������λ��
}

void siftUp(vector<int> &R,int j)  			//�Ե�����ɸѡ:��Ҷ�ӽ��j����ɸѡ
{	int i=(j-1)/2;   						//iָ��R[j]��˫��
 	while (true)
  	{	if (R[j]>R[i])           			//�����ӽϴ�
      		swap(R[i],R[j]);				//����
     	if (i==0) break;					//��������ʱ����
     	j=i; i=(j-1)/2;						//�������ϵ���
	}
}
void HeapSort(vector<int> &R,int n) 		//������
{
	for (int i=n/2-1;i>=0;i--)				//�����һ����֧��㿪ʼѭ��������ʼ��
  		siftDown(R,i,n-1);					//��R[i..n-1]����ɸѡ

	//for (int j=n/2;j<n-1;j++)				//ѭ��������ʼ��
	//	siftUp(R,j);				    	//��R[j]����ɸѡ(R[j]ΪҶ�ӽ��)

  	printf("��ʼ��:   "); disp(R,0,n-1); 
 	for (int i=n-1;i>0;i--)       			//����n-1������,ÿһ�������������Ԫ�ظ�����1
  	{	swap(R[0],R[i]);					//�������������һ��Ԫ����R[0]������������ΪR[i..n-1]
  		printf("��λR[%d]: ",i);disp(R,0,n-1); 
    	siftDown(R,0,i-1);		   			//��������R[0..i-1]����ɸѡ
  		printf("����Ϊ��: "); disp(R,0,n-1); 
	}
}

int main() 
{
	vector<int> a={6,8,7,9,0,1,3,2,4,5};
	int n=a.size();
	printf("����ǰ:   "); disp(a,0,n-1); 
	HeapSort(a,n);
	printf("�����:   "); disp(a,0,n-1); 
	return 0;
}
	

