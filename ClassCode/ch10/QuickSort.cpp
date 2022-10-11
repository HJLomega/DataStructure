#include<iostream>
#include<vector>
using namespace std;
void disp(vector<int> &R,int low,int high)
{
	for (int i=low;i<=high;i++)
		printf("%d ",R[i]);
	printf("\n");
}

int Partition1(vector<int> &R,int s,int t)		//划分算法1
{	int base=R[s];						//以表首元素为基准
	int i=s,j=t;
 	while (i<j)							//从表两端交替向中间遍历,直至i=j为止
  	{	while (i<j && R[j]>base)
      		j--;						//从后向前遍历,找一个小于等于基准的R[j]
    	while (i<j && R[i]<=base)
      		i++;						//从前向后遍历,找一个大于基准的R[i]
    	if (i<j)
      		swap(R[i],R[j]);     		//将R[i]和R[j]进行交换
	}
 	swap(R[s],R[i]);            		//将基准R[s]和R[i]进行交换
 	return i;
}

int Partition1_1(vector<int> &R,int s,int t)	//划分算法1的改进版本 
{	int base=R[s];					  			//以表首元素为基准,base存放基准关键字
	int i=s,j=t+1;
	while (i<j)									//i<j时循环
	{
		j--;
		while (R[j]>base && i<j) 				//从后向前遍历,找一个小于等于基准的R[j]
			j--;
		i++;
		while (R[i]<=base && i<j)  				//从前向后遍历,找一个大于基准的R[i]
			i++;
     	if (i<j)								//i<j时交换 
			swap(R[i],R[j]);					//保证i左侧i小于等于base，j右侧大于base
	}
	swap(R[s],R[j]);							//将基准R[s]和R[i]进行交换
	return j;
}

int Partition2(vector<int> &R,int s,int t)  	//划分算法2
{	int i=s,j=t;
 	int base=R[s];							//以表首元素为基准
 	while (i<j)								//从表两端交替向中间遍历,直至i=j为止
  	{	while (j>i && R[j]>base)
      		j--;							//从后向前遍历,找一个小于等于基准的R[j]
    	if (j>i)
      	{	R[i]=R[j];						//R[j]前移覆盖R[i]
        	i++;
    	}
     	while (i<j && R[i]<=base)
      		i++;						//从前向后遍历,找一个大于基准的R[i]
     	if (i<j)
      	{	R[j]=R[i];					//R[i]后移覆盖R[j]
        	j--;
    	}
	}
 	R[i]=base;								//基准归位
 	return i;								//返回归位的位置
}

int Partition3(vector<int> &R,int s,int t)		//划分算法3
{	int i=s,j=s+1;
 	int base=R[s];						//以表首元素为基准
 	while (j<=t)						//j从s+1开始遍历其他元素
  	{	if (R[j]<=base)					//找到小于等于基准的元素R[j]
      	{	i++;						//扩大小于等于base的元素区间
        	if (i!=j)
         		swap(R[i],R[j]); 	//将R[i]与R[j]交换
    	}
    	j++;						//继续扫描
	}
	swap(R[s],R[i]);             		//将基准R[s]和R[i]进行交换
 	return i;
}

void _QuickSort(vector<int> &R,int s,int t)	//对R[s..t]的元素进行快速排序
{	if (s<t) 				 			//表中至少存在两个元素的情况
  	{	int i=Partition2(R,s,t);			//可以使用前面3种划分算法中的任意一种
    	_QuickSort(R,s,i-1);			//对左子表递归排序
     	_QuickSort(R,i+1,t);			//对右子表递归排序
	}
}

void QuickSort(vector<int> &R,int n)	//快速排序
{
	_QuickSort(R,0,n-1);
}

int main() 
{
    vector<int> a={1,3,4,2,1,5,2,6,3,4,4};
	//vector<int> a={9,8,7,6,5,4,3,2,1,0};
	int n=a.size();
	printf("排序前: "); disp(a,0,n-1); 
	QuickSort(a,n);
	printf("排序后: "); disp(a,0,n-1); 
	return 0;
}
	

