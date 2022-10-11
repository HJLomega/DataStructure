#include"MatGraph.cpp"					//包含图（邻接矩阵）的基本运算算法
#include<vector>
 
void Dispath(int A[][MAXV],int path[][MAXV],int n)    //输出所有的最短路径和长度
{
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
		{
			if (A[i][j]!=INF && i!=j)			//若顶点i和j之间存在路径
			{
				vector<int> apath;				//存放一条i到j的最短逆路径
				printf("  顶点%d到%d的最短路径长度: %d\t路径: ",i,j,A[i][j]);
				apath.push_back(j);				//路径上添加终点j
				int pre=path[i][j];
				while (pre!=i)					//路径上添加中间点
				{
					apath.push_back(pre);		//顶点pre加入到路径中
					pre=path[i][pre];
				}
				cout << i;					//输出起点i
				for (int k=apath.size()-1;k>=0;k--)		//反向输出路径上的其他顶点
					printf("->%d",apath[k]); 
				printf("\n");
			}
		}
}

void Floyd(MatGraph &g)					//Floyd求多源最短路径
{	int A[MAXV][MAXV];					//建立A数组
	int path[MAXV][MAXV];				//建立path数组
	for (int i=0;i<g.n;i++)					//给数组A和path置初值即求A-1[i][j]
		for (int j=0;j<g.n;j++) 
		{	A[i][j]=g.edges[i][j];
			if (i!=j && g.edges[i][j]<INF)
				path[i][j]=i;			//i和j顶点之间有一条边时
			else	
				path[i][j]=-1;			//i和j顶点之间没有一条边时
		}
	for (int k=0;k<g.n;k++)					//求Ak[i][j]
	{	for (int i=0;i<g.n;i++)
			for (int j=0;j<g.n;j++)
				if (A[i][j]>A[i][k]+A[k][j])
				{	A[i][j]=A[i][k]+A[k][j];
					path[i][j]= path[k][j];	//修改最短路径
				}
	}
	Dispath(A,path,g.n);					//输出最短路径和长度
}
int main()
{
	MatGraph g;
	int n=7,e=12;
	int v=0;
	int A[MAXV][MAXV]={
		{0,4,6,6,INF,INF,INF},
		{INF,0,1,INF,7,INF,INF},
		{INF,INF,0,INF,6,4,INF},
		{INF,INF,2,0,INF,5,INF},
		{INF,INF,INF,INF,0,INF,6},
		{INF,INF,INF,INF,1,0,8},
		{INF,INF,INF,INF,INF,INF,0}};	//图7.25的边数组
	cout << "建立gobj图的邻接矩阵:\n";
	g.CreateMatGraph(A,n,e);
	cout << "图的邻接矩阵:\n"; g.DispMatGraph();
	cout << "图中所有顶点之间的最短路径:\n";
	Floyd(g);
	return 0;
}
