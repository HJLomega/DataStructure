#include<iostream>
#include<vector>
using namespace std;
void disp(vector<int> &R,int low,int high)
{
	for (int i=low;i<=high;i++)
		printf("%d ",R[i]);
	printf("\n");
}
void BubbleSort(vector<int> &R,int n) 	//冒泡排序
{
	for (int i=0;i<n-1;i++) 
	{	bool exchange=false;		//本趟前将exchange置为false
		for (int j=n-1;j>i;j--)		//一趟中找出最小关键字的元素
			if (R[j]<R[j-1])		//反序时交换
			{	swap(R[j],R[j-1]);
				exchange=true;		//本趟发生交换置exchange为true
			}
		if (!exchange)				//本趟没有发生交换，中途结束算法
			return;
	}
}

int main() 
{
	vector<int> a={9,8,7,6,5,4,3,2,1,0};
	int n=a.size();
	printf("排序前: "); disp(a,0,n-1); 
	BubbleSort(a,n);
	printf("排序后: "); disp(a,0,n-1); 
	return 0;
}
	

