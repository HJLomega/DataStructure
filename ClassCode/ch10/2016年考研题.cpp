#include<iostream>
#include<vector>
using namespace std;
void disp(vector<int> &R,int low,int high)
{
	for (int i=low;i<=high;i++)
		printf("%d ",R[i]);
	printf("\n");
}

int Partition2(vector<int>& R,int s,int t)  //�����㷨2
{  int i=s,j=t;
   int base=R[s];			//�Ա���Ԫ��Ϊ��׼
   while (i<j)				//�ӱ����˽������м����,ֱ��i=jΪֹ
   {  while (j>i && R[j]>base)
         j--;				//���ǰ��һ��С�ڵ��ڻ�׼��R[j]
      if (j>i)
      {  R[i]=R[j];			//R[j]ǰ�Ƹ���R[i]
         i++;
      }
      while (i<j && R[i]<=base)
         i++;				//ǰ������һ�����ڻ�׼��R[i]
      if (i<j)
      {  R[j]=R[i];			//R[i]���Ƹ���R[j]
         j--;
      }
   }
   R[i]=base;				//��׼��λ
   return i;				//���ع�λ��λ��
}
int Solution(vector<int> a,int n)		//����㷨
{  int low=0,high=n-1;
   bool flag=true;
   while (flag)
   {  int i=Partition2(a,low,high);		//����ǰ��3�ֻ����㷨������һ��
      if (i==n/2-1)			//��׼a[i]Ϊ��n/2��Ԫ��
         flag=false;
      else if (i<n/2-1)			//�����������
         low=i+1;
      else
         high=i-1;			//�����������
   }
   int s1=0,s2=0;
   for (int i=0;i<n/2;i++)
       s1+=a[i];
   for (int j=n/2;j<n;j++)
       s2+=a[j];
    return s2-s1;
}
int main()
{
	printf("����1\n");
	vector<int> a={3,1,6,5,4,2};
	printf("  a: "); disp(a,0,a.size()-1);
	printf("  �����=%d\n",Solution(a,a.size()));
	printf("����2\n");
	vector<int> b={3,1,6,5,4,2,7};
	printf("  b: "); disp(b,0,b.size()-1);
	printf("  �����=%d\n",Solution(b,b.size()));
	return 0;
}

