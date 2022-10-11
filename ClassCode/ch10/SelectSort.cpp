#include<iostream>
#include<vector>
using namespace std;
void disp(vector<int> &R,int low,int high)
{
	for (int i=low;i<=high;i++)
		printf("%d ",R[i]);
	printf("\n");
}
void SelectSort(vector<int> &R,int n) 	//简单选择排序
{
	for (int i=0;i<n-1;i++)				//做第i趟排序
	{	int minj=i;
		for (int j=i+1;j<n;j++)			//在当前无序区R[i..n-1]中选最小元素R[minj]
			if (R[j]<R[minj])
				minj=j;					//minj记下目前找到的最小元素的位置
		if (minj!=i)					//若R[minj]不是无序区首元素
			swap(R[i],R[minj]);			//交换R[i]和R[minj]
	}
}
int main() 
{
	vector<int> a={9,8,7,6,5,4,3,2,1,0};
	int n=a.size();
	printf("排序前: "); disp(a,0,n-1); 
	SelectSort(a,n);
	printf("排序后: "); disp(a,0,n-1); 
	return 0;
}
	

