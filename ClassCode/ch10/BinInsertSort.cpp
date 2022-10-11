#include<iostream>
#include<vector>
using namespace std;
void disp(vector<int> &R,int low,int high)
{
	for (int i=low;i<=high;i++)
		printf("%d ",R[i]);
	printf("\n");
}
void BinInsertSort(vector<int> &R,int n) 	//折半插入排序
{
	for (int i=1;i<n;i++)					//从R[1]开始
	{
		if (R[i]<R[i-1])					//反序
		{
			int tmp=R[i];					//将R[i]保存到tmp中
			int low=0,high=i-1;
			while (low<=high)				//在R[low..high]中折半查找有序插入的位置
			{
				int mid=(low+high)/2;		//取中间位置
				if (tmp<R[mid])
					high=mid-1;				//插入点在左半区
				else
					low=mid+1;				//插入点在右半区
			}
			for (int j=i-1;j>=high+1;j--)	//元素后移
				R[j+1]=R[j];
			R[high+1]=tmp;					//原R[i]插入到R[high+1]中 
		}	
	}
}
int main() 
{
	vector<int> a={9,8,7,6,5,4,3,2,1,0};
	int n=a.size();
	printf("排序前: "); disp(a,0,n-1); 
	BinInsertSort(a,n);
	printf("排序后: "); disp(a,0,n-1); 
	return 0;
}
	

