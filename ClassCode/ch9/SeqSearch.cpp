#include<iostream>
#include<vector>
using namespace std;
int SeqSearch1(vector<int> &R,int k)	//顺序查找算法1
{	int n=R.size();
 	int i=0;
 	while (i<n && R[i]!=k)
	 	i++;	    					//从表头往后找
 	if (i>=n) return -1;		        //未找到返回-1
 	else return i;						//找到后返回其序号i
}

int SeqSearch2(vector<int> &R,int k)	//顺序查找算法2
{	int n=R.size();
 	R.push_back(k);                     //末尾添加一个哨兵
 	int i=0;
 	while (R[i]!=k) i++;				//从表头往后找
 	if (i==n) return -1;				//未找到返回-1
 	else return i;						//找到后返回其序号i
}

int main()
{
	vector<int> R={3,9,1,5,8,10,6,7,2,4};
	int k=6;
	printf("R[%d]=%d\n",SeqSearch1(R,k),k);
	printf("R[%d]=%d\n",SeqSearch2(R,k),k);
	return 0;
}
