#include "SqListSearch.h"					//包含线性表查找类模板的声明
template <typename T>
SqListSearchClass<T>::SqListSearchClass()	//构造函数，用于查找顺序表的初始化
{
	length=0;
}
template <typename T>
void SqListSearchClass<T>::SetK(T a[],int n)	//设置顺序表的关键字
{
	int i;
	for (i=0;i<n;i++)
		R[i].key=a[i];
	length=n;
}
template <typename T>
int SqListSearchClass<T>::SeqSearch(T k)	//顺序查找算法
{
	int i=0;
	while (i<length && R[i].key!=k)	i++;	//从表头往后找
	if (i>=length) return 0;				//未找到返回0
	else return i+1;						//找到后返回其逻辑序号i+1
}
template <typename T>
int SqListSearchClass<T>::BinSearch(T k)	//拆半查找非递归算法
{
	int low=0,high=length-1,mid;
	while (low<=high)			//当前区间存在元素时循环
	{
		mid=(low+high)/2;		//求查找区间的中间位置
		if (R[mid].key==k)		//查找成功返回其逻辑序号mid+1
			return mid+1;		//找到后返回其逻辑序号mid+1
		if (R[mid].key>k)		//继续在R[low..mid-1]中查找
			high=mid-1;
		else					//R[mid].key<k
			low=mid+1;			//继续在R[mid+1..high]中查找
	}
	return 0;					//若当前查找区间没有元素时返回0
}
template <typename T>
int SqListSearchClass<T>::BinSearch1(T k)	//拆半查找递归算法
{
	return BinSearch11(0,length-1,k);
}
template <typename T>
int SqListSearchClass<T>::BinSearch11(int low,int high,T k)	//被BinSearch1函数调用
{
	int mid;
	if (low<=high)				//若当前查找区间存在元素
	{
		mid=(low+high)/2;		//求查找区间的中间位置
		if (R[mid].key==k)		//查找成功返回其逻辑序号mid+1
			return mid+1;		//找到后返回其逻辑序号mid+1
		if (R[mid].key>k)		//继续在R[low..mid-1]中查找
			return BinSearch11(low,mid-1,k);//递归在左区间中查找
		else						//R[mid].key<k
			return BinSearch11(mid+1,high,k);	//递归在右区间中查找
	}
	else return 0;				//若当前查找区间没有元素时返回0
}
template <typename T>
int SqListSearchClass<T>::IdxSearch(IdxType<T> I[],int b,T k)
//在顺序表R[0..length-1]和索引表I[0..b-1]中查找关键字k的记录
{
	int low=0,high=b-1,mid,i;
	int s=(length+b-1)/b;		//s为每块的元素个数，应为n/b的向上取整
	while (low<=high)			//在索引表中进行折半查找,找到的位置为high+1
	{
		mid=(low+high)/2;
		if (I[mid].key>=k)
			high=mid-1;
		else 
			low=mid+1;
	}
	//找到索引表的high+1块,再在顺序表在该块中顺序查找
	i=I[high+1].link;
	while (i<=I[high+1].link+s-1 && R[i].key!=k)
		i++;
	if (i<=I[high+1].link+s-1)
		return i+1;		//查找成功,返回该元素的逻辑序号
	else
		return 0;		//查找失败,返回0
}
template <typename T>
void SqListSearchClass<T>::dispR()		//输出顺序表R中的元素
{
	int i;
	for (i=0;i<length;i++)
		cout << R[i].key << " ";
	cout << endl;
}
void main()
{
	SqListSearchClass<int> s,s1,s2;
	int k=7,i;
	int A[]={3,9,1,5,8,10,6,7,2,4},n1=10;
	int B[]={2,4,7,9,10,14,18,26,32,40},n2=10;
	int C[]={8,14,6,9,10,22,34,18,19,31,40,38,54,66,46,71,78,68,80,85,100,94,88,96,87},n3=25,b=5;
	//---------------顺序查找------------------
	s.SetK(A,n1);
	cout << "关键字序列:"; s.dispR();
	i=s.SeqSearch(k);
	if (i>0)
		cout << "顺序查找:第" << i << "个记录的关键字是" << k << endl;
	else
		cout << "顺序查找:未找到关键字" << k << endl;
	//---------------拆半查找查找------------------
	k=7;
	s1.SetK(B,n2);
	cout << "关键字序列:"; s1.dispR();
	i=s1.BinSearch(k);
	if (i>0)
		cout << "拆半查找1:第" << i << "个记录的关键字是" << k << endl;
	else
		cout << "拆半查找1:未找到关键字" << k << endl;
	i=s1.BinSearch1(k);
	if (i>0)
		cout << "拆半查找2:第" << i << "个记录的关键字是" << k << endl;
	else
		cout << "拆半查找2:未找到关键字" << k << endl;
	//---------------分块查找查找------------------
	k=80;
	IdxType<int> I[MaxSize];
	I[0].key=14; I[0].link=0; 
	I[1].key=34; I[1].link=5; 
	I[2].key=66; I[2].link=10; 
	I[3].key=85; I[3].link=15; 
	I[4].key=100; I[4].link=20; 
	s2.SetK(C,n3);
	cout << "关键字序列:"; s2.dispR();
	i=s2.IdxSearch(I,b,k);
	if (i>0)
		cout << "分块查找:第" << i << "个记录的关键字是" << k << endl;
	else
		cout << "分块查找:未找到关键字" << k << endl;
}
