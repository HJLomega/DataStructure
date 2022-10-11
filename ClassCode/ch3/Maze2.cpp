#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MAX=10;							//迷宫最大的行、列数 
int dx[]={-1,0,1,0};                       	//x方向的偏移量
int dy[]={0,1,0,-1};                       	//y方向的偏移量
int mg[MAX][MAX]={{0,1,0,0},{0,0,1,1},{0,1,0,0},{0,0,0,0}};
int m=4,n=4;
struct Box									//队列中方块元素类型 
{
	int i;									//方块的行号
	int j;									//方块的列号
	Box *pre;								//本路径中上一方块的地址
	Box() {}								//构造函数
	Box(int i1,int j1)						//重载构造函数
	{
		i=i1;
		j=j1;
		pre=NULL;
	}
};
void disppath(queue<Box *> &qu)				//输出一条迷宫路径
{	vector<Box> apath;							//存放一条迷宫路径
	Box *b;
	b=qu.front();									//从队头开始向入口方向搜索
	while (b!=NULL)
	{	apath.push_back(Box(b->i,b->j));			//将搜索的方块添加到apath中
		b=b->pre;
	}
	cout << "一条迷宫路径: ";
	for (int i=apath.size()-1;i>=0;i--)				//反向输出构成一条正向迷宫路径
		cout << "[" << apath[i].i << "," << apath[i].j << "]  "; 
	cout << endl;
}
bool mgpath(int xi,int yi,int xe,int ye)			//求一条从(xi,yi)到(xe,ye)的迷宫路径
{	Box *b,*b1;
	queue<Box *> qu;							//定义一个队列qu
	b=new Box(xi,yi);							//建立入口的对象b
	qu.push(b);									//入口对象b进队,其pre置为NULL
	mg[xi][yi]=-1;								//为避免来回找相邻方块置mg值为-1
	while (!qu.empty())							//队不空时循环
	{	b=qu.front();								//取队头方块b
		if (b->i==xe && b->j==ye)				//找到了出口,输出路径
		{	disppath(qu);						//输出一条迷宫路径
			return true;							//找到一条迷宫路径后返回true
		}
		qu.pop();								//出队方块b
		for (int di=0;di<4;di++)					//循环扫描每个方位,把每个可走的方块进队
		{	int i=b->i+dx[di];   				//找b的di方位的相邻方块(i,j)
			int j=b->j+dy[di];
			if (i>=0 && i<m && j>=0 && j<n && mg[i][j]==0)
			{	b1=new Box(i,j);					//(i,j)方块有效且可走，建立其队列对象b1
				b1->pre=b;						//将该相邻方块进队,并置pre指向前驱方块
				qu.push(b1);
				mg[i][j]=-1;						//为避免来回找相邻方块置mg值为-1
			}
		}
	}
	return false;									//未找到任何路径时返回false
}
int main()
{
	int xi=0,yi=0,xe=3,ye=3;
	printf("求(%d,%d)到(%d,%d)的迷宫路径\n",xi,yi,xe,ye);
	if (!mgpath(xi,yi,xe,ye))
		cout << "不存在迷宫路径\n";
	return 0;
}

