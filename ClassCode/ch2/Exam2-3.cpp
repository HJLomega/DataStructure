#include "SqList.cpp"					//引用顺序表泛型类
template <typename T>
void Deletex1(SqList<T> &L, int x)   	//求解算法1
{
    int k=0;
    for (int i=0;i<L.length;i++)
    	if (L.data[i]!=x)				//将不为x的元素插入到data中
    	{
    		L.data[k]=L.data[i];
    		k++;
    	}
    L.length=k;							//重置L的长度为k
}

template <typename T>
void Deletex2(SqList<T> &L, int x)   	//求解算法2
{
    int k=0;							//累计等于k的元素个数			
    for (int i=0;i<L.length;i++)
        if (L.data[i]!=x)				//将不为x的元素前移k个位置
            L.data[i-k]=L.data[i];
        else							//累计删除的元素个数k
            k++;
    L.length-=k;						//重置长度
}        

template <typename T>
void Deletex3(SqList<T> &L, int x)   	//求解算法3
{
	int i=-1,j=0;
    while (j<L.length)					//j遍历所有元素
    {
        if (L.data[j]!=x)				//找到不为x的元素a[j]
        {
            i++;					    //扩大不为x的区间
            if (i!=j)
				swap(L.data[i],L.data[j]);	//序号为i和j的两个元素交换
		}
        j++;							//继续扫描
    }
    L.length=i+1;						//重置长度
}
int main()
{
	int a[]={2,1,1,1,1,1,3};
	int n=sizeof(a)/sizeof(a[0]);
	SqList<int> L1;						//建立元素类型为int的顺序表对象L
	L1.CreateList(a,n);
	cout << "顺序表L1:"; L1.DispList();
	int x=1;
	printf("解法1:删除L1中所有%d的元素\n",x);
	Deletex1(L1,x);
	cout << "顺序表L1:"; L1.DispList();

	SqList<int> L2;						//建立元素类型为int的顺序表对象L
	L2.CreateList(a,n);
	cout << "顺序表L2:"; L2.DispList();
	printf("解法2:删除L2中所有%d的元素\n",x);
	Deletex2(L2,x);
	cout << "顺序表L2:"; L2.DispList();


	SqList<int> L3;						//建立元素类型为int的顺序表对象L
	L3.CreateList(a,n);
	cout << "顺序表L3:"; L3.DispList();
	printf("解法3:删除L3中所有%d的元素\n",x);
	Deletex3(L3,x);
	cout << "顺序表L3:"; L3.DispList();

	return 0;
}
