#include "SqList.cpp"						//引用顺序表泛型类
template <typename T>
void Merge2(SqList<T> A,SqList<T> B,SqList<T> &C)
{ 	int i=0,j=0;                        	//i用于遍历A,j用于遍历B
 	while (i<A.length && j<B.length)  		//两个表均没有遍历完毕
  	{	if (A.data[i]<B.data[j])
      	{
		  	C.Add(A.data[i]);           	//归并A[i]:将较小的A[i]添加到C中
        	i++; 
        }
    	else								//归并B[j]:将较小的B[j]添加到C中
    	{
    		C.Add(B.data[j]);
    		j++;
		}
    }
 	while (i<A.length)						//若A没有遍历完毕
 	{
  		C.Add(A.data[i]);					//归并A中剩余元素 
    	i++;
    }
 	while (j<B.length)						//若B没有遍历完毕
  	{	C.Add(B.data[j]);					//归并B中剩余元素
    	j++;
	}
}
int main()
{
	int a[]={1,3,5,8};
	int n=sizeof(a)/sizeof(a[0]);
	SqList<int> L1;						//建立元素类型为int的顺序表对象L
	L1.CreateList(a,n);
	cout << "顺序表L1: "; L1.DispList();

	int b[]={1,2,5,6,7,9,20};
	int m=sizeof(b)/sizeof(b[0]);
	SqList<int> L2;						//建立元素类型为int的顺序表对象L
	L2.CreateList(b,m);
	cout << "顺序表L2: "; L2.DispList();

	cout << "A,B -> C" << endl;
	SqList<int> L3;
	Merge2(L1,L2,L3);
	cout << "顺序表L3: "; L3.DispList();

}
