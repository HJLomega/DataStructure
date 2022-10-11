#include"MatGraph.cpp"								//包含图(邻接矩阵)的基本运算算法
#include"AdjGraph.cpp"								//包含图(邻接表)的基本运算算法
#include<cstring>
#include<queue>
//图的广度优先遍历
void BFS(AdjGraph &G,int v)					//广度优先遍历(邻接表)
{
	int visited[MAXV];
	memset(visited,0,sizeof(visited));		//初始化visited数组 
	queue<int> qu;							//定义一个队列 
	cout << v << " ";						//访问顶点v
	visited[v]=1;							//置已访问标记
	qu.push(v);								//顶点v进队 
	while (!qu.empty())						//队列不空循环
	{
		int u=qu.front(); qu.pop();			//出队顶点u
		ArcNode *p=G.adjlist[u].firstarc;	//找顶点u的第一个邻接点
		while (p!=NULL)
		{	if (visited[p->adjvex]==0)		//若u的邻接点未访问
			{	cout << p->adjvex << " ";	//访问邻接点
				visited[p->adjvex]=1;		//置已访问标记
				qu.push(p->adjvex);			//邻接点进队
			}
			p=p->nextarc;					//找下一个邻接点
		}
	}
}


void BFS(MatGraph &g,int v)					//广度优先遍历(邻接矩阵)
{
	int visited[MAXV];
	memset(visited,0,sizeof(visited));		//初始化visited数组 
	queue<int> qu;							//定义一个队列 
	cout << v << " ";						//访问顶点v
	visited[v]=1;							//置已访问标记
	qu.push(v);								//顶点v进队 
	while (!qu.empty())						//队列不空循环
	{
		int u=qu.front(); qu.pop();			//出队顶点u
		for (int i=0;i<g.n;i++)
			if (g.edges[u][i]!=0 && g.edges[u][i]!=INF)
			{
				if (visited[i]==0)
				{	cout << i << " ";		//访问邻接点
					visited[i]=1;			//置已访问标记
					qu.push(i);				//邻接点进队
				}
			}
	}
}

/*
//非连通无向图的遍历算法
template <typename T>
void DFSA(GraphClass<T> &gobj)		//非连通图的DFS
{	int i;
	for (i=0;i<gobj.G->n;i++) visited[i]=0;	//visited数组元素均置为0
	for (i=0;i<gobj.G->n;i++)
		if (visited[i]==0)
			DFS1(gobj.G,i);
}
template <typename T>
void BFSA(GraphClass<T> &gobj)		//非连通图的BFS
{	int i;
	for (i=0;i<gobj.G->n;i++) visited[i]=0;	//visited数组元素均置为0
	for (i=0;i<gobj.G->n;i++)
		if (visited[i]==0)
			BFS1(G,i);
}
*/

int main()
{
	AdjGraph G;
	int n=6,e=7;
	int a[MAXV][MAXV]={{0,1,1,0,0,0},{0,0,0,0,0,1},{0,0,0,1,1,1},{0,0,0,0,0,0},{0,0,0,1,0,0},{0,0,0,0,0,0}};
	G.CreateAdjGraph(a,n,e);
	printf("图G邻接表\n"); G.DispAdjGraph();
	int v=0;
	cout << "从顶点" << v << "出发的BFS序列:";
	BFS(G,v); cout << endl;
	
	
	MatGraph g;
	g.CreateMatGraph(a,n,e);
	printf("图g邻接矩阵\n"); g.DispMatGraph();
	cout << "从顶点" << v << "出发的BFS序列:";
	BFS(g,v); cout << endl;
	return 0;
}


