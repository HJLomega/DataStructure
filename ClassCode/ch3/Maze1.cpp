#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
const int MAX=10;							//迷宫最大的行、列数 
int dx[]={-1,0,1,0};                       	//x方向的偏移量
int dy[]={0,1,0,-1};                       	//y方向的偏移量
int mg[MAX][MAX]={{0,1,0,0},{0,0,1,1},{0,1,0,0},{0,0,0,0}};
int m=4,n=4;
struct Box									//方块结构体类型
{
	int i;									//方块的行号
	int j;									//方块的列号
	int di;									//di是下一个相邻可走方位的方位号
	Box() {}								//构造函数
	Box(int i1,int j1,int d1):i(i1),j(j1),di(d1) {}	//重载构造函数
};

void disppath(stack<Box> &st)				//输出栈中所有方块构成一条迷宫路径
{
	Box b;
	vector<Box> apath;
	while (!st.empty())						//出栈所有的方块
	{
		b=st.top(); st.pop();
		apath.push_back(b);
	}
	reverse(apath.begin(),apath.end());		//逆置apath(也可以直接反向输出apath)
	cout << "一条迷宫路径: ";
	for (int i=0;i<apath.size();i++)
		cout << "[" << apath[i].i << "," << apath[i].j << "]  "; 
	cout << endl;
}

bool mgpath(int xi,int yi,int xe,int ye)	//求一条从(xi,yi)到(xe,ye)的迷宫路径
{
	int i,j,di,i1,j1;
	bool find;
	Box b,b1;
	stack<Box> st;							//建立一个栈
	b=Box(xi,yi,-1);
	st.push(b);								//入口方块进栈
	mg[xi][yi]=-1;							//为避免来回找相邻方块,将进栈方块的mg置为-1
	while (!st.empty())						//栈不空时循环
	{
		b=st.top();							//取栈顶方块,称为当前方块
		if (b.i==xe && b.j==ye)				//找到了出口,输出栈中所有方块构成一条路径
		{
			disppath(st);
			return true;					//找到一条路径后返回true
		}
		find=false;							//否则继续找路径
    	di=b.di;
     	while (di<3 && find==false)			//找b的一个相邻可走方块
      	{	di++;							//找下一个方位的相邻方块
        	i=b.i+dx[di];   				//找b的di方位的相邻方块(i,j)
        	j=b.j+dy[di];
        	if (i>=0 && i<m && j>=0 && j<n && mg[i][j]==0)
				find=true;					//(i,j)方块有效且可走
        }
     	if (find)							//栈顶方块找到一个相邻可走方块(i,j)
        {	st.top().di=di;                 //修改栈顶方块的di为新值
        	b1=Box(i,j,-1);              	//建立相邻可走方块(i,j)的对象b1
        	st.push(b1);                 	//b1进栈 
        	mg[i][j]=-1;					//为避免来回找相邻方块,将进栈的方块置为-1
		}
		else                           		//栈顶方块没有找到任何相邻可走方块
      	{	mg[b.i][b.j]=0;					//恢复栈顶方块的迷宫值
        	st.pop();						//将栈顶方块退栈
        }
	}
	return false;							//没有找到迷宫路径,返回false
}
int main()
{
	int xi=0,yi=0,xe=3,ye=3;
	printf("求(%d,%d)到(%d,%d)的迷宫路径\n",xi,yi,xe,ye);
	if (!mgpath(xi,yi,xe,ye))
		cout << "不存在迷宫路径\n";
	return 0;
}
