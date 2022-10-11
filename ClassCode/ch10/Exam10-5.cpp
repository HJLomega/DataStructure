#include<iostream>
#include<vector>
using namespace std;
void disp(vector<int> &R,int low,int high)
{
	for (int i=low;i<=high;i++)
		printf("%d ",R[i]);
	printf("\n");
}
int Partition2(vector<int> &R,int s,int t)  //划分算法2
{	int i=s,j=t;
 	int base=R[s];							//以表首元素为基准
 	while (i!=j)							//从表两端交替向中间遍历,直至i=j为止
  	{	while (j>i && R[j]>=base)
      		j--;							//从后向前遍历,找一个小于基准的R[j]
    	if (j>i)
      	{	R[i]=R[j];						//R[j]前移覆盖R[i]
        	i++;
    	}
     	while (i<j && R[i]<=base)
      		i++;							//从前向后遍历,找一个大于基准的R[i]
     	if (i<j)
      	{	R[j]=R[i];						//R[i]后移覆盖R[j]
        	j--;
    	}
	}
 	R[i]=base;								//基准归位
 	return i;								//返回归位的位置
}

void QuickSort1(vector<int> &R,int s,int t)	//以排序序列的中间位置元素为基准的快速排序
{	if (s<t) 				 				//表中至少存在两个元素的情况
  	{	int mid=(s+t)/2;
     	swap(R[s],R[mid]); 					//R[s]与R[mid]交换
    	int i=Partition2(R,s,t);			//可以使用前面3种划分算法中的任意一种
     	QuickSort1(R,s,i-1);				//对左子表递归排序
     	QuickSort1(R,i+1,t);				//对右子表递归排序
	}
}

void QuickSort(vector<int> &R,int n)	//快速排序
{
	QuickSort1(R,0,n-1);
}

int main() 
{
	vector<int> a={9,8,7,6,5,4,3,2,1,0};
	int n=a.size();
	printf("排序前: "); disp(a,0,n-1); 
	QuickSort(a,n);
	printf("排序后: "); disp(a,0,n-1); 
	return 0;
}
	

