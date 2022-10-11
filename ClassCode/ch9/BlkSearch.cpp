#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct IdxType									//索引表类型
{	int key;									//关键字（这里是对应块中的最大关键字）
	int link;									//该索引块在数据表中的起始下标
};

void CreateI(vector<int> &R,IdxType I[],int b)	//构造索引表I[0..b-1]
{   int n=R.size();
    int s=(n+b-1)/b;							//每块的元素个数
    int j=0;
    int jmax=R[j];
    for (int i=0;i<b;i++)						//构造b个块
	{   I[i].link=j;
        while (j<=(i+1)*s-1 && j<=n-1)			//j遍历一个块,查找其中最大关键字jmax
        {	if (R[j]>jmax) jmax=R[j];
            j++;
    	}
        I[i].key=jmax;
        if (j<=n-1)								//j没有遍历完,jmax置为下一个块首元素关键字
            jmax=R[j];
    }
}

int BlkSearch(vector<int> &R,IdxType I[],int b,int k)   //在R[0..n-1]和索引表I[0..b-1]中查找k
{   int n=R.size();
    int low=0,high=b-1;
    while (low<=high)					    	//在索引表中折半查找,找到块号为high+1
    {   int mid=(low+high)/2;
        if (k<=I[mid].key) high=mid-1;
        else low=mid+1;
	}
    if (high+1>=b) return -1;					//块号超界,查找失败,返回-1
    int i=I[high+1].link;						//求所在块的起始位置
    int s=(n+b-1)/b;							//求每块的元素个数s
    if (i==b-1)									//第i块是最后块,元素个数可能少于s
        s=n-s*(b-1);
    while (i<=I[high+1].link+s-1 && R[i]!=k)	//在对应块中顺序查找k 
        i++;
    if (i<=I[high+1].link+s-1)
		return i;								//查找成功,返回该元素的序号
    else
		return -1;								//查找失败,返回-1
}
int main()
{
	vector<int> R={8,14,6,9,10,22,34,18,19,31,40,38,54,66,46,71,78,68,80,85,100,94,88,96,87};
	int b=5;
	IdxType *I=new IdxType[b];
	CreateI(R,I,b);
	printf("\n (1)初始数据\n   ");	
	for (int i=0;i<R.size();i++)
		printf("%d ",R[i]);
	printf("\n (2)创建索引块(分为b=5个块)\n");
	for (int i=0;i<b;i++)
    	printf("    块%d: [%3d,%2d]\n",i,I[i].key,I[i].link);
	printf("  (3)分块查找\n");
	for (int i=0;i<R.size();i+=2)
    {
		int k1=R[i],k2=R[i+1];
    	printf("    k=%3d的位置:%2d\t  k=%3d的位置:%2d\n",k1,BlkSearch(R,I,b,k1),k2,BlkSearch(R,I,b,k2));
    }
    return 0;
}

