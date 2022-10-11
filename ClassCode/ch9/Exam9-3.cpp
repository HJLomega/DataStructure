#include<iostream>
#include<vector>
using namespace std;
int BSearch1(vector<int> &R,int k)
{	int n=R.size();
 	int low=0,high=n-1;
 	while (low<=high)
  	{	int mid=(low+high)/2;
    	if (k==R[mid])
			return mid;
    	if (k<R[mid])
			high=mid-1;
     	else low=mid;
	}
	return -1;
}

int BSearch2(vector<int> &R,int k)
{	int n=R.size();
 	int low=0,high=n-1;
 	while (low<high)
	{	int mid=(low+high)/2;
    	if (k==R[mid])
			return mid;
     	if (k<R[mid])
		 	high=mid-1;
     	else
		 	low=mid+1;
	}
 	if (R[low]==k) return low;
 	else return -1;
}

int main()
{
	vector<int> R={1,3,5};
	for (int i=0;i<R.size();i++)
	{
		int k=R[i];
		printf("Ëã·¨2: R[%d]=%d\n",BSearch2(R,k),k);
	}

	return 0;
}
