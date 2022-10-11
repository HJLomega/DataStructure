#include<iostream>
using namespace std;
const int MAXR=20;					//稀疏矩阵最大行数
const int MAXC=20;					//稀疏矩阵最大列数
const int MaxSize=100;				//三元组顺序表最大元素个数
struct TupElem						//单个三元组元素的类型
{	int r;							//行号
	int c;							//列号
	int d;							//元素值
	TupElem() {}					//构造函数 
	TupElem(int r1,int c1,int d1)	//重载构造函数 
	{
		r=r1;
		c=c1;
		d=d1;
	}		
};
class TupClass						//三元组存储结构类
{
	int rows;						//行数
	int cols;						//列数
	int nums;						//非零元素个数
	TupElem *data;					//稀疏矩阵对应的三元组顺序表
public:
	TupClass()						//构造函数
	{
		data=new TupElem[MaxSize];	//分配空间
		nums=0;
	}
	~TupClass()						//析构函数
	{
		delete [] data;				//释放空间
	}
	void CreateTup(int A[][MAXC],int m,int n)	//创建三元组
	{
		rows=m; cols=n; nums=0;
		for (int i=0;i<m;i++)
			for (int j=0;j<n;j++)
				if (A[i][j]!=0)		//只存储非零元素
				{
					data[nums]=TupElem(i,j,A[i][j]);
					nums++;
				}
	}
	bool Setvalue(int i,int j,int x)			//三元组元素赋值A[i][j]=x
	{
		if (i<0 || i>=rows || j<0 || j>=cols)
			return false;						//下标错误时返回false
		int k=0,k1;
		while (k<nums && i>data[k].r)
			k++;								//查找第i行的第一个非零元素
		while (k<nums && i==data[k].r && j>data[k].c)
			k++;								//在第i行中查找第j列的元素
		if (data[k].r==i && data[k].c==j)		//找到了这样的元素
			data[k].d=x;
		else									//不存在这样的元素时插入一个元素
		{
			for (k1=nums-1; k1>=k;k1--)			//后移元素以便插入
			{
				data[k1+1].r=data[k1].r;
				data[k1+1].c=data[k1].c;
				data[k1+1].d=data[k1].d;
			}
			data[k].r=i; data[k].c=j; data[k].d=x;
			nums++;
		}
		return true;							//赋值成功时返回true
	}
	bool GetValue(int i,int j,int &x)	//将指定位置的元素值赋给变量x=A[i][j]
	{
		if (i<0 || i>=rows || j<0 || j>=cols)
			return false;						//下标错误时返回false
		int k=0;
		while (k<nums && data[k].r<i)
			k++;								//查找第i行的第一个非零元素
		while (k<nums && data[k].r==i && data[k].c<j)
			k++;								//在第i行中查找第j列的元素
		if (data[k].r==i && data[k].c==j)		//找到了这样的元素
			x=data[k].d;
		else
			x=0;								//在三元组中没有找到表示是零元素
		return true;							//取值成功时返回true
	}
	void DispMat()				//输出三元组
	{
		if (nums<=0) return;					//没有非零元素时返回
		cout << "\t" << rows << "\t" << cols << "\t" << nums << endl;
		cout << "\t------------------\n";
		for (int i=0;i<nums;i++)
			cout << "\t" << data[i].r << "\t" << data[i].c << "\t" << data[i].d << endl;
	}
};
int main()
{
	TupClass t,tb;
	int x;
	int a[MAXR][MAXC]={{0,0,1,0,0,0,0},{0,2,0,0,0,0,0},{3,0,0,0,0,0,0},{0,0,0,5,0,0,0},{0,0,0,0,6,0,0},{0,0,0,0,0,7,4}};
	t.CreateTup(a,6,7);
	cout << "三元组t表示:\n"; t.DispMat();
	cout << "执行A[4][1]=8\n";
	t.Setvalue(4,1,8);
	cout << "三元组t表示:\n"; t.DispMat();
	cout << "求x=A[4][1]\n";
	t.GetValue(4,1,x);
	cout << "x=" << x << endl;
	return 0; 
}

