#include <iostream>
#include <vector>
using namespace std;

int* lower_bound1(vector<int> &R,int n,int k)
{
	int low=0,high=n;
   	while (low<high)
   	{
	   	int mid=(low+high)/2;
	   	if (R[mid]>=k)						//p(x)=x>=k,谓词为true 
			high=mid;						//在左区间中查找 
		else								//谓词为false
			low=mid+1;						//在右区间中查找 
	}
	return &R[low];							//返回R[low]元素地址 
}
int* lower_bound2(vector<int> &R,int n,int k)	//STL版本 
{
    int low=0,mid;
    int half,len;
    len=n;
    while (len>0)
	{
		half=len/2;
        mid=low+half;
        if (R[mid]>=k)			//p(x)=x>=k，谓词为true 
			len=half;			//左区间(以R[low]开始的len个元素，含R[mid])中查找,low不变 
		else					//谓词为false
		{     
            low=mid+1;          //修改low 
            len=len-half-1;     //在右区间(以R[low]开始的len个元素)中查找
        }
    }
	return &R[low];				//返回R[low]元素地址 
}

int* lower_bound3(vector<int> &R,int n,int k)
{
	int low=0,high=n-1;
	while (low<=high)						//当前区间至少有一个元素时
	{	int mid=(low+high)/2;				//求查找区间的中间位置
		if (R[mid]>=k)						//p(x)=x>=k,谓词为true
			high=mid-1;						//在R[low..mid-1]中查找,low不变 
		else								//谓词为false
			low=mid+1;						//在R[mid+1..high]中查找
	}
	return &R[low];							//返回R[low]或者R[high+1]元素地址 
}
int main()
{
	vector<int> a={1,3,3,3,5,8};
	int n=a.size();
	int k=5;
	cout << "查找第一个大于等于" << k << "的位置" << endl; 
	cout << "  解法1: " << lower_bound1(a,n,k)-&a[0] << endl;
	cout << "  解法2: " << lower_bound2(a,n,k)-&a[0] << endl;
	cout << "  解法3: " << lower_bound3(a,n,k)-&a[0] << endl;
    return 0;
}


