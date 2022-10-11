#include"AdjGraph.cpp"					//包含图(邻接表)的基本运算算法
#include<vector>
#include<cstring>
int visited[MAXV];						//全局数组 
void DFS(AdjGraph &G,int v)				//深度优先遍历(邻接表)
{
	visited[v]=1;						//置已访问标记
	ArcNode*p=G.adjlist[v].firstarc;	//p指向顶点v的第一个邻接点
	while (p!=NULL)
	{	int w=p->adjvex;				//邻接点为w 
		if (visited[w]==0)
			DFS(G,w);					//若w顶点未访问,递归访问它
		p=p->nextarc;					//p置为下一个邻接点
	}
}

bool Connect(AdjGraph &G)				//判断无向图G的连通性
{
	memset(visited,0,sizeof(visited));
	DFS(G,0);							//从0出发深度优先遍历
	for (int i=0;i<G.n;i++)
		if (visited[i]==0)				//若有顶点没有访问过
			return false;				//说明是非连通图 
	return true;						//说明是连通图
}

int main()
{
	AdjGraph G;
	int n=5,e=8;
	int a[MAXV][MAXV]={{0,1,0,1,1},{1,0,1,1,0},{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0}};
	G.CreateAdjGraph(a,n,e);
	printf("图G邻接表\n"); G.DispAdjGraph();
	cout << "图G的连通性: " << Connect(G) << endl;
	return 0;
}


