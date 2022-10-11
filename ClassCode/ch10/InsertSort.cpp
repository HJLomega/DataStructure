#include<iostream>
#include<vector>
using namespace std;
void disp(vector<int> &R,int low,int high)
{
	for (int i=low;i<=high;i++)
		printf("%d ",R[i]);
	printf("\n");
}
void InsertSort(vector<int> &R,int n) 	//直接插入排序
{
	for (int i=1;i<n;i++)				//从R[1]开始
	{
		if (R[i]<R[i-1])				//反序时 
		{
			int tmp=R[i];				//取出无序区的第一个元素
			int j=i-1;					//有序区R[0..i-1]中向前找R[i]的插入位置
			do
			{
				R[j+1]=R[j];			//将大于tmp的元素后移
				j--;					//继续向前比较
			} while (j>=0 && R[j]>tmp);
			R[j+1]=tmp;					//在j+1处插入R[i]
		}
	}
}
int main() 
{
	vector<int> a={9,8,7,6,5,4,3,2,1,0};
	int n=a.size();
	printf("排序前: "); disp(a,0,n-1); 
	InsertSort(a,n);
	printf("排序后: "); disp(a,0,n-1); 
	return 0;
}
	

