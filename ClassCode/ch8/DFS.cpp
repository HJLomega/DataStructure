#include"MatGraph.cpp"					//包含图(邻接矩阵)的基本运算算法
#include"AdjGraph.cpp"					//包含图(邻接表)的基本运算算法
#include<cstring>
//图的深度优先遍历
int visited[MAXV];						//全局数组
void DFS(AdjGraph &G,int v)				//深度优先遍历(邻接表)
{
	visited[v]=1;						//置已访问标记
	cout << v << " ";					//输出被访问顶点的编号
	ArcNode*p=G.adjlist[v].firstarc;	//p指向顶点v的第一个邻接点
	while (p!=NULL)
	{	int w=p->adjvex;				//邻接点为w 
		if (visited[w]==0)
			DFS(G,w);					//若w顶点未访问,递归访问它
		p=p->nextarc;					//p置为下一个邻接点
	}
}

void DFS(MatGraph &g,int v)				//深度优先遍历(邻接矩阵)
{
	visited[v]=1;						//置已访问标记
	cout << v << " ";					//输出被访问顶点的编号
	for (int w=0;w<g.n;w++)
	{	if (g.edges[v][w]!=0 && g.edges[v][w]!=INF) 
		{	if (visited[w]==0)			//存在边<v,w>并且w没有访问过
				DFS(g,w);				//若w顶点未访问,递归访问它
		}
	}
}
int main()
{
	AdjGraph G;
	int n=6,e=7;
	int a[MAXV][MAXV]={{0,1,1,0,0,0},{0,0,0,0,0,1},{0,0,0,1,1,1},{0,0,0,0,0,0},{0,0,0,1,0,0},{0,0,0,0,0,0}};
	G.CreateAdjGraph(a,n,e);
	printf("图G邻接表\n"); G.DispAdjGraph();
	int v=0;
	cout << "从顶点" << v << "出发的DFS序列:";
	memset(visited,0,sizeof(visited));
	DFS(G,v); cout << endl;
	
	
	MatGraph g;
	g.CreateMatGraph(a,n,e);
	printf("图g邻接矩阵\n"); g.DispMatGraph();
	cout << "从顶点" << v << "出发的DFS序列:";
	memset(visited,0,sizeof(visited));
	DFS(g,v); cout << endl;
	return 0;
}


