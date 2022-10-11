#include<iostream>
#include<vector>
using namespace std;
void disp(vector<int> &R,int low,int high)
{
	for (int i=low;i<=high;i++)
		printf("%d ",R[i]);
	printf("\n");
}
void ShellSort(vector<int> &R,int n) 	//希尔排序
{
	int d=n/2;							//增量置初值
	while (d>0)
	{	for (int i=d;i<n;i++)			//对所有相隔d位置的元素组采用直接插入排序
		{
			if (R[i]<R[i-d])     		//反序时
			{	int tmp=R[i];
				int j=i-d;
				do
				{
					R[j+d]=R[j];		//将大于tmp的元素同组中后移
					j=j-d;				//继续向前比较
				} while (j>=0 && R[j]>tmp);
				R[j+d]=tmp;				//在j+d处插入R[i]
			}
		}
		d=d/2;							//减小增量
	}
}
int main() 
{
	vector<int> a={9,8,7,6,5,4,3,2,1,0};
	int n=a.size();
	printf("排序前: "); disp(a,0,n-1); 
	ShellSort(a,n);
	printf("排序后: "); disp(a,0,n-1); 
	return 0;
}
	

