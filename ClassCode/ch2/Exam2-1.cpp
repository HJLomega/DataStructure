#include "SqList.cpp"					//引用顺序表泛型类 
template <typename T>
void Reverse(SqList<T> &L)				//求解算法
{	T tmp;
	int i=0,j=L.length-1;
	while (i<j)
	{	swap(L.data[i],L.data[j]);		//序号为i和j的两个元素交换
		i++; j--;
	}
}


int main()
{
	int n=6;
	int a[]={1,2,3,4,5,6};
	SqList<int> L;		//建立元素类型为int的顺序表对象L
	cout << "创建顺序表L" << endl;
	L.CreateList(a,n);
	cout << "顺序表L:"; L.DispList();
	cout << "逆置顺序表L" << endl;
	Reverse(L);
	cout << "顺序表L:"; L.DispList();
	cout << "销毁顺序表L" << endl;
	return 0;
}
