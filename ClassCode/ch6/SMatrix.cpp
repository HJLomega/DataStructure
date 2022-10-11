#include "SMatrix.h"				//包括稀疏矩阵三元组表示的类声明
SMatrixClass::SMatrixClass()		//构造函数
{
	data=new TupNode[MaxSize];		//分配空间
}
SMatrixClass::~SMatrixClass()		//析构函数
{	delete [] data;	}		//释放空间
void SMatrixClass::CreateTSMatrix(int A[][MAXC],int m,int n)	//创建三元组
{
	int i,j;
	rows=m; cols=n; nums=0;
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
			if (A[i][j]!=0)		//只存储非零元素
			{
				data[nums].r=i;
				data[nums].c=j;
				data[nums].d=A[i][j];
				nums++;
			}
	}
}
bool SMatrixClass::Setvalue(int i,int j,int x)	//三元组元素赋值A[i][j]=x
{
	int k=0,k1;
	if (i<0 || i>=rows || j<0 || j>=cols)
		return false;						//下标错误时返回false
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
bool SMatrixClass::GetValue(int i,int j,int &x)	//将指定位置的元素值赋给变量x=A[i][j]
{
	int k=0;
	if (i<0 || i>=rows || j<0 || j>=cols)
		return false;						//下标错误时返回false
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
void SMatrixClass::DispMat()				//输出三元组
{
	int i;
	if (nums<=0) return;					//没有非零元素时返回
	cout << "\t" << rows << "\t" << cols << "\t" << nums << endl;
	cout << "\t------------------\n";
	for (i=0;i<nums;i++)
		cout << "\t" << data[i].r << "\t" << data[i].c << "\t" << data[i].d << endl;
}
void SMatrixClass::Transpose(SMatrixClass &tb)	//矩阵转置
{
	int p,q=0,v;							//q为tb.data的下标
	tb.rows=cols;
	tb.cols=rows;
	tb.nums=nums;
	if (nums!=0)							//当前三元组表示中存在非零元素时执行转置
	{
		for (v=0;v<cols;v++)				//tb.data[q]中的记录以c域的次序排列
			for (p=0;p<nums;p++)			//p为data的下标
				if (data[p].c==v)
				{
					tb.data[q].r=data[p].c;
					tb.data[q].c=data[p].r;
					tb.data[q].d=data[p].d;
					q++;
				}
	}
}
//main函数用作调试
/*void main()
{
	SMatrixClass t,tb;
	int x;
	int a[MAXR][MAXC]={{0,0,1,0,0,0,0},{0,2,0,0,0,0,0},{3,0,0,0,0,0,0},{0,0,0,5,0,0,0},{0,0,0,0,6,0,0},{0,0,0,0,0,7,4}};
	t.CreateTSMatrix(a,6,7);
	cout << "三元组t表示:\n"; t.DispMat();
	cout << "执行A[4][1]=8\n";
	t.Setvalue(4,1,8);
	cout << "三元组t表示:\n"; t.DispMat();
	cout << "求x=A[4][1]\n";
	t.GetValue(4,1,x);
	cout << "x=" << x << endl;
	cout << "t转置为tb\n";
	t.Transpose(tb);
	cout << "三元组tb表示:\n"; tb.DispMat();
	cout << "main函数结束,销毁所有的三元组对象" << endl;
}
*/