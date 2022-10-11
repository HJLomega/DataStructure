#include "SqList.cpp"							//引用顺序表泛型类
template <typename T>
bool Deletek(SqList<T> &L,int i,int k)           //求解算法
{
	if (i<0 || k<1 || i+k<1 || i+k>L.length)
		return false;							//参数i和k错误返回false
	for (int j=i+k;j<L.length;j++)				//删除k个元素 
 		L.data[j-k]=L.data[j];
	L.length-=k;								//长度减k
	return true;
}

int main()
{
	int n=5,i=1,k=3;
	int a[]={1,2,3,4,5};
	SqList<int> L;								//建立元素类型为int的顺序表对象L
	cout << "创建顺序表L" << endl;
	L.CreateList(a,n);
	cout << "顺序表L:"; L.DispList();
	cout << "删除L中序号" << i << "开始的" << k << "个元素" << endl;
	Deletek(L,i,k);
	cout << "顺序表L:"; L.DispList();
	cout << "销毁顺序表L" << endl;
	return 0;
}

