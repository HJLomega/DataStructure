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

int Partition1_2(vector<int> &R,int s,int t)	//划分算法1
{	int base=R[s];					  			//以表首元素为基准,base存放基准关键字
	int i=s,j=t+1;
	while (i<j)									//循环
	{
		j--;
		while (R[j]>base && i<j) 			//从后向前遍历,找一个小于等于基准的R[j]
			j--;
		i++;
		while (R[i]<=base && i<j)  			//从前向后遍历,找一个大于基准的R[i]
			i++;
     	if (i<j)							//i<j时交换 
			swap(R[i],R[j]);				//保证i左侧i小于等于base，j右侧大于base
		printf("i=%d,j=%d  R:",i,j); disp(R,s,t);
	}
	swap(R[s],R[j]);					//将基准R[s]和R[i]进行交换
	printf("while结束： i=%d,j=%d  R:",i,j); disp(R,s,t);
	return j;
}

int Partition1_1(vector<int> &R,int s,int t)				//划分算法1
{	int base=R[s];					  	//以表首元素为基准,base存放基准关键字
	int i=s,j=t+1;
	while (true)						//循环
	{
		i++;
		while (R[i]<base)  				//R[i]小于base时增大i
        {	if (i==t) break;			//i超界时退出循环 
        	i++;
    	}
    	j--;
		while (base<R[j]) 				//R[j]大于base时减小j
      	{	if(j==s) break;				//j超界时退出循环 
      		j--;
      	}
     	if (i>=j) break;				//i和j相遇后退出循环 
		swap(R[i],R[j]);				//R[i]和R[j]交换:保证i左侧不大于base，j右侧不小于base
	}
	swap(R[s],R[j]);					//将基准R[s]和R[i]进行交换
	return j;
}

void  _QuickSort(vector<int> &R,int s,int t)	//对R[s..t]的元素进行快速排序
{	if (s<t) 				 			//表中至少存在两个元素的情况
  	{	int i=Partition1_2(R,s,t);			//可以使用前面3种划分算法中的任意一种
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
	printf("排序前: "); disp(a,0,n-1); 
	QuickSort(a,n);
	printf("排序后: "); disp(a,0,n-1); 
	return 0;
}
*/
	

