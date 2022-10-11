#include "SqList.cpp"							//引用顺序表泛型类
template <typename T>
T Middle(SqList<T> A,SqList<T> B)             	//求解算法
{	int i=0,j=0;								//i,j分别遍历A和B 
	int k=0;									//累计归并的次数 
	while (i<A.length && j<B.length)			//两个有序顺序表均没有扫描完
  	{
	  	k++;							      	//归并次数增1
    	if (A.data[i]<B.data[j])            	//A中当前元素为较小的元素
      	{	if (k==A.length)					//恰好比较了n次
         		return A.data[i];				//返回A中的当前元素
        	i++;
    	}
    	else 									//B中当前元素为较小的元素
    	{
      		if (k==B.length)					//恰好比较了n次
       			return B.data[j];				//返回B中的当前元素
       		j++;
       }
   }
	return 0;
}

int main()
{
	int a[]={11,13,15,17,19};
	int n=sizeof(a)/sizeof(a[0]);
	SqList<int> L1;						//建立元素类型为int的顺序表对象L
	L1.CreateList(a,n);
	cout << "顺序表L1: "; L1.DispList();

	int b[]={2,4,6,8,20};
	int m=sizeof(b)/sizeof(b[0]);
	SqList<int> L2;						//建立元素类型为int的顺序表对象L
	L2.CreateList(b,m);
	cout << "顺序表L2: "; L2.DispList();
	int ans=Middle(L1,L2);

	cout << "中位数: " << ans << endl;
	return 0;
}
