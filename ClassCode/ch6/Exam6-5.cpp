#include<iostream>
using namespace std;
int Min(int a[],int i)              //求a[0..i]中的最小值
{	if (i==0)						//递归出口
  		return a[0];
  	else							//递归体
  	{	int mind=Min(a,i-1);
     	return min(mind,a[i]);
	}
}
int main()
{
	int a[]={1,2,3,4,5};
	int n=sizeof(a)/sizeof(a[0]);
	cout << Min(a,n-1) << endl;
}
