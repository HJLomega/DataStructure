#include"MatGraph.cpp"			//包含图（邻接矩阵）的基本运算算法
#include"AdjGraph.cpp"			//包含图（邻接表）的基本运算算法
#include<queue>
#include<vector> 
#include<cstring>

void DispAllPath(int dist[],int path[],int S[],int v,int n) //输出从顶点v出发的所有最短路径
{
	for (int i=0;i<n;i++)					//循环输出从顶点v到i的路径
		if (S[i]==1 && i!=v)
		{
			vector<int> apath;				//存放一条最短逆路径		
			printf("  从%d到%d最短路径长度为: %d\t路径: ",v,i,dist[i]);
			apath.push_back(i);					//添加终点i
			int pre=path[i];
			while (pre!=v)
			{	apath.push_back(pre);
				pre=path[pre];
			}
			printf("%d",v);					//先输出起点v
			for (int k=apath.size()-1;k>=0;k--)	
				printf("->%d",apath[k]);	//再反向输出路径中其他顶点
			printf("\n");
		}
		else printf("  从%d到%d没有路径\n",v,i);
}

void Dijkstra(MatGraph &g,int v)			//求从v到其他顶点的最短路径
{
	int dist[MAXV];							//建立dist数组
	int path[MAXV];							//建立path数组
	int S[MAXV];							//建立S数组
	for (int i=0;i<g.n;i++)
	{	dist[i]=g.edges[v][i];				//距离初始化
		S[i]=0;								//S[]置空
		if (g.edges[v][i]!=0 && g.edges[v][i]<INF)
			path[i]=v;						//v到i有边时，置i的前驱顶点为v
		else
			path[i]=-1;						//v到i没边时，置i的前驱顶点为-1
	}
	S[v]=1;									//源点编号v放入S中
	int mindis,u=-1;
	for (int i=0;i<g.n-1;i++)				//循环向S中添加n-1个顶点
	{	mindis=INF;							//mindis置最小长度初值
		for (int j=0;j<g.n;j++)				//选取不在S中且具有最小距离的顶点u
			if (S[j]==0 && dist[j]<mindis) 
			{	u=j;
				mindis=dist[j];
			}
		S[u]=1;								//顶点u加入S中
		for (int j=0;j<g.n;j++)				//修改不在s中的顶点的距离
			if (S[j]==0)
				if (g.edges[u][j]<INF && dist[u]+g.edges[u][j]<dist[j])
				{	dist[j]=dist[u]+g.edges[u][j];
					path[j]=u;
				}
	}
	DispAllPath(dist,path,S,v,g.n);			//输出所有最短路径及长度
}
//--------------改进的狄克斯特拉算法
struct QNode								//优先队列元素类型 
{
	int v;									//顶点编号
	int dist;								//源点到v的距离
	QNode(int v,int d)						//构造函数 
	{
		this->v=v;
		this->dist=d;
	}
	bool operator<(const QNode &s) const	//重载<比较函数
	{
		return dist>s.dist;					//按dist越小越优先出队
	}
}; 
	
void Dijkstra1(AdjGraph &G,int v)			//改进Dijkstra算法求从v到其他顶点的最短路径
{
	priority_queue<QNode> pq;				//定义一个优先队列 
	int dist[MAXV];							//建立dist数组
	int S[MAXV];							//建立S数组
	memset(dist,INF,sizeof(dist));
	memset(S,0,sizeof(S));
	dist[v]=0;
	pq.push(QNode(v,dist[v]));				//源点(v,0)进队 
	for (int i=0;i<G.n;i++)					//循环向S中添加n个顶点(这里初始S为空)
	{
		QNode e=pq.top(); pq.pop();			//出队e1 
		int u=e.v;							//最小距离的顶点为u 
		S[u]=1;								//顶点u加入S中		
		ArcNode *p=G.adjlist[u].firstarc;
		while (p!=NULL)
		{
		 	int w=p->adjvex;        		//顶点u的一个邻接点w
        	if (S[w]==0 && dist[u]+p->weight<dist[w])
         	{	dist[w]=dist[u]+p->weight;	//修改最短路径长度
            	pq.push(QNode(w,dist[w]));	//(w,dist[w])进队
			}
			p=p->nextarc;
		}
	}
	printf("从%d顶点出发的最短路径长度如下\n",v);
	for (int i=0;i<G.n;i++)			  		//输出结果
  	{	if (i!=v)
      		printf("  %d到%d最短路径长度为: %d\n",v,i,dist[i]);
	}
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
		{INF,INF,INF,INF,INF,INF,0}};
	cout << "建立图的邻接矩阵:\n";
	g.CreateMatGraph(A,n,e);
	cout << "图的邻接矩阵:\n"; g.DispMatGraph();
	cout << "图中从顶点" << v << "出发的最短路径:\n";
	Dijkstra(g,v);
	
	AdjGraph G;
	cout << "建立图的邻接表:\n";
	G.CreateAdjGraph(A,n,e);
	cout << "图的邻接表:\n"; G.DispAdjGraph();
	Dijkstra1(G,v);
	
	return 0;
}
