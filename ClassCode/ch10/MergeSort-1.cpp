#include<iostream>
#include<vector>
using namespace std;
void disp(vector<int> &R,int low,int high)
{
	for (int i=low;i<=high;i++)
		printf("%d ",R[i]);
	printf("\n");
}
void Merge(vector<int> &R,int low,int mid,int high)
//将R[low..mid]和R[mid+1..high]两个有序段二路归并为一个有序段R[low..high]
{
	vector<int> R1;
	R1.resize(high-low+1);					//设置R1的长度为high-low+1; 
	int i=low,j=mid+1,k=0;					//k是R1的下标,i、j分别为第1、2段的下标
	while (i<=mid && j<=high)				//在第1段和第2段均未扫描完时循环
		if (R[i]<=R[j])						//将第1段中的元素放入R1中
		{	R1[k]=R[i];
			i++; k++;
		}
		else								//将第2段中的元素放入R1中
		{	R1[k]=R[j];
			j++; k++; 
		}
	while (i<=mid)							//将第1段余下部分复制到R1
	{	R1[k]=R[i];
		i++; k++;
	}
	while (j<=high)							//将第2段余下部分复制到R1
	{	R1[k]=R[j];
		j++; k++;
	}
	for (k=0,i=low;i<=high;k++,i++)			//将R1复制回R中
		R[i]=R1[k];
}

void  _MergeSort2(vector<int> &R,int s,int t)  	//被MergeSort2调用
{
	if (s>=t) return;							//R[s..t]的长度为0或者1时返回
 	int m=(s+t)/2;						   		//取中间位置m
 	_MergeSort2(R,s,m);							//对前子表排序
 	_MergeSort2(R,m+1,t);						//对后子表排序
 	Merge(R,s,m,t);								//将两个有序子表合并成一个有序表
}

void MergeSort2(vector<int> &R,int n)			//自顶向下的二路归并排序	
{
	_MergeSort2(R,0,n-1);
}

int main() 
{
	vector<int> a={9,8,7,6,5,4,3,2,1,0};
	int n=a.size();
	printf("排序前: "); disp(a,0,n-1); 
	MergeSort2(a,n);
	printf("排序后: "); disp(a,0,n-1); 
	return 0;
}
	

