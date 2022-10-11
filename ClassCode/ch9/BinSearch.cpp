#include<iostream>
#include<vector>
using namespace std;
int BinSearch1(vector<int> &R,int k)    	//拆半查找非递归算法
{	int n=R.size();
 	int low=0,high=n-1;
 	while (low<=high)						//当前区间非空时
  	{	int mid=(low+high)/2;				//求查找区间的中间位置
     	if (k==R[mid])					  	//查找成功返回其序号mid
      		return mid;
    	if (k<R[mid])					    //继续在R[low..mid-1]中查找
      		high=mid-1;
     	else								//k>R[mid]
      		low=mid+1;						//继续在R[mid+1..high]中查找
    }
	return -1;								//当前查找区间空时返回-1
}

int BinSearch21(vector<int> &R,int low,int high,int k) 	//被BinSearch2方法调用
{	if (low<=high)						 	//当前查找区间非空时
  	{	int mid=(low+high)/2;				//求查找区间的中间位置
    	if (k==R[mid])						//查找成功返回其序号mid
      		return mid;
     	if (k<R[mid])						//递归在左区间中查找
      		return BinSearch21(R,low,mid-1,k);
     	else								//k>R[mid],递归在右区间中查找
      		return BinSearch21(R,mid+1,high,k);
    }
	else return -1;						//当前查找区间空时返回-1
}
int BinSearch2(vector<int> &R,int k)		//拆半查找递归算法
{
	return BinSearch21(R,0,R.size()-1,k);
}

int main()
{
	vector<int> R={2,4,7,9,10,14,18,26,32,40};
	for (int i=0;i<R.size();i++)
	{
		int k=R[i];
		printf("算法1: R[%d]=%d\n",BinSearch1(R,k),k);
		printf("算法2: R[%d]=%d\n",BinSearch2(R,k),k);
	}
	return 0;
}
