#include<iostream>
#include<vector>
using namespace std;
void disp(vector<int> &R,int low,int high)
{
	for (int i=low;i<=high;i++)
		printf("%d ",R[i]);
	printf("\n");
}

int Partition2(vector<int>& R,int s,int t)  //划分算法2
{  int i=s,j=t;
   int base=R[s];			//以表首元素为基准
   while (i<j)				//从表两端交替向中间遍历,直至i=j为止
   {  while (j>i && R[j]>base)
         j--;				//后→前找一个小于等于基准的R[j]
      if (j>i)
      {  R[i]=R[j];			//R[j]前移覆盖R[i]
         i++;
      }
      while (i<j && R[i]<=base)
         i++;				//前→后找一个大于基准的R[i]
      if (i<j)
      {  R[j]=R[i];			//R[i]后移覆盖R[j]
         j--;
      }
   }
   R[i]=base;				//基准归位
   return i;				//返回归位的位置
}
int Solution(vector<int> a,int n)		//求解算法
{  int low=0,high=n-1;
   bool flag=true;
   while (flag)
   {  int i=Partition2(a,low,high);		//可用前面3种划分算法中任意一种
      if (i==n/2-1)			//基准a[i]为第n/2的元素
         flag=false;
      else if (i<n/2-1)			//在右区间查找
         low=i+1;
      else
         high=i-1;			//在左区间查找
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
	printf("测试1\n");
	vector<int> a={3,1,6,5,4,2};
	printf("  a: "); disp(a,0,a.size()-1);
	printf("  求解结果=%d\n",Solution(a,a.size()));
	printf("测试2\n");
	vector<int> b={3,1,6,5,4,2,7};
	printf("  b: "); disp(b,0,b.size()-1);
	printf("  求解结果=%d\n",Solution(b,b.size()));
	return 0;
}

