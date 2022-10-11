#include"MatGraph.cpp"			//包含图（邻矩阵）的基本运算算法
void Prim(MatGraph g,int v)				//Prim算法输出的最小生树
{
	int lowcost[MAXV];					//建立数组lowcost
	int closest[MAXV];					//建立数组closest
	for (int i=0;i<g.n;i++)				//给lowcost[]和closest[]置初值
	{	lowcost[i]=g.edges[v][i];
		closest[i]=v;
	}
	for (int i=1;i<g.n;i++)				//找出(n-1)个顶点
	{	int min=INF;
		int k=-1;						//k记录最近顶点的编号
		for (int j=0;j<g.n;j++)			//在(V-U)中找出离U最近的顶点k
			if (lowcost[j]!=0 && lowcost[j]<min)
			{	min=lowcost[j];
				k=j;
			}
		cout << "  边(" << closest[k] << "," << k << "),权为" << min << endl;
		lowcost[k]=0;					//标记k已经加入U
		for (int j=0;j<g.n;j++)			//修改数组lowcost和closest
		if (g.edges[k][j]!=0 && g.edges[k][j]<lowcost[j])
		{	lowcost[j]=g.edges[k][j];
			closest[j]=k;
		}
	}
}
int main()
{
	MatGraph g;
	int n=6,e=10;
	int v=0;
	int A[MAXV][MAXV]={{0,6,1,5,INF,INF}, {6,0,5,INF,3,INF}, {1,5,0,5,6,4}, 
		{5,INF,5,0,INF,2}, {INF,3,6,INF,0,6}, {INF,INF,4,2,6,0}};
	cout << "建立gobj图的邻接矩阵:\n";
	g.CreateMatGraph(A,n,e);
	cout << "图的邻接矩阵:\n"; g.DispMatGraph();
	cout << "从顶点" << v << "出发构造的最小生成树:\n";
	Prim(g,v);
	return 0;
}
