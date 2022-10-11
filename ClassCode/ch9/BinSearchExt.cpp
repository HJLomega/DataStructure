#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
int GOEk(vector<int> &R,int k)      		//查找第一个大于等于k的序号即k的插入点
{	int n=R.size();
 	int low=0,high=n-1;
 	while (low<=high)					  	//当前区间至少有一个元素时
  	{	int mid=(low+high)/2;				//求查找区间的中间位置
    	if (k<=R[mid])				      	//继续在R[low..mid-1]中查找
      		high=mid-1;
     	else							  	//k>R[mid]
      		low=mid+1;					  	//继续在R[mid+1..high]中查找
	}
	return high+1;						   	//返回high+1
}

int Firstequalsk(vector<int> &R,int k)      //查找第一个等于k的元素序号
{	int n=R.size();
 	int low=0,high=n-1;
 	while (low<high)						//当前区间至少有2个元素时					
  	{	int mid=(low+high)/2;				//长度为偶数时求低中间位
    	if (k<=R[mid])
			high=mid;
     	else
			low=mid+1;
	}
 	if (k==R[low]) return low;				//区间中恰好有一个为k的元素 
 	else return -1;
}

int Lastequalsk(vector<int> &R,int k)       //查找最后一个等于k的元素序号
{	int n=R.size();
 	int low=0,high=n-1;
 	while (low<high)						//当前区间至少有2个元素时					
  	{	int mid=(low+high+1)/2;				//长度为偶数时求高中间位
    	if (k>=R[mid])
			low=mid;
     	else
		 	high=mid-1;
	}
 	if (k==R[low]) return low;				//区间中恰好有一个为k的元素 
 	else return -1;
}
vector<int> Intervalk(vector<int> &R,int k)    //查找为k的元素区间res
{
	vector<int> res(2);
 	res[0]=Firstequalsk(R,k);
 	res[1]=Lastequalsk(R,k);
 	return res;
}

int lower_bound2(vector<int> &a,int val)
{
    int first = 0, last = a.size() - 1, mid;
    while(first <= last) {
        mid = last - (last - first) / 2;
        if(a[mid] >= val) last = mid - 1;
        else first = mid + 1;
    }
    return first;
}
int lower_bound1(vector<int> R,int size,int k)	//错误 
{
    int low=0,high=size-1;
    int mid,pos=0;       	//用pos记录第一个大于等于k的元素位置
    while (low<high)
    {
        mid=(low+high)/2;
        if(R[mid]<k)		//中位数<k，走右分支 
		{
            low=mid+1;
            pos=low;		//右区间的首位置可能是pos 
        }
        else				//中位数大于等于k，走左分支 
		{
            high=mid;
            pos=high;		//pos可能是mid
        }
    }
    return pos;
}
int lower_bound2(vector<int> R,int size,int k)	//正确 
{
    int low=0,mid,half;
	int len=size;
    while(len>0)
	{
        half=len >> 1;
        mid=low+half;
        if (k>R[mid])
		{     
            low=mid+1;          
            len=len-half-1;       //在右边子序列中查找
        }
        else
            len=half;            //在左边子序列（包含middle）中查找
    }
    return low;
}
int upper_bound1(vector<int> R,int size,int k)
{
    int low=0,high=size-1;
    int mid,pos=0;
    while (low<high)
    {
        mid=(low+high)/2;
        if (k<R[mid])     //当中位数大于key时，last不动，让first不断逼近last
        {
            high=mid;
            pos=high;
        }
        else
		{
            low=mid+1;     //当中位数小于等于key时，将first递增，并记录新的位置
            pos=low;
        }
    }
    return pos;
}
int upper_bound2(vector<int> R,int size,int k)
{
    int low=0,mid,half;
	int len=size-1;
    while (len>0)
	{
        half=len>>1;
        mid=low+half;
        if (k<R[mid])     		//中位数大于key,在包含last的左半边序列中查找。
            len=half;
        else
		{
            low=mid+1;    		//中位数小于等于key,在右半边序列中查找。
            len=len-half-1;
        }
    }
    return low;
}
int main()
{
	//vector<int> R={1,1,1};
	vector<int> R={1,3,3,3,3};
	int k=3;
	printf("lower_bound1(%d): %d\n",k,lower_bound1(R,R.size(),k));
	//printf("lower_bound2(%d): %d\n",k,lower_bound2(R,R.size(),k));
	//printf("upper_bound(%d): %d\n",k,upper_bound(R,R.size(),k));
	return 0;
}
 
/*
int main()
{
	//vector<int> R={1,1,1};
	vector<int> R={1,2,2,2,3};
	int k=2;
	printf("%d的插入点: %d\n",k,GOEk(R,k));
	printf("第一个为%d的位置: %d\n",k,Firstequalsk(R,k));
	printf("最后一个为%d的位置: %d\n",k,Lastequalsk(R,k));	
	vector<int> ans;
	ans=Intervalk(R,k);
	printf("第一个为%d的位置: %d\n",k,ans[0]);
	printf("最后一个为%d的位置: %d\n",k,ans[1]);	
	
	return 0;
}
*/
