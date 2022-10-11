#include "Graph.cpp"					//包含图的基本运算算法
int visited[MAXV];						//全局变量数组
template <typename T>
void DFSTree(GraphClass<T> &gobj,int v)			//产生图的深度优先生成树
{
	int i;
	for (i=0;i<gobj.G->n;i++) visited[i]=0; 	//初始化访问标志数组
	DFS2(gobj.G,v);
}
template <typename T>
void DFS2(ALGraph<T> *G,int v)			//被DFSTree调用产生深度优先生成树
{
	ArcNode<T> *p; int w;
	visited[v]=1;						//置已访问标记
	p=G->adjlist[v].firstarc;			//p指向顶点v的第一个邻接点
	while (p!=NULL)
	{	w=p->adjvex; 
		if (visited[w]==0)				//若w顶点未访问,递归访问它
		{
			cout << "(" << v << "," << w << ")  ";	//输出DFS生成树的一条边
			DFS2(G,w);
		}
		p=p->nextarc;					//p置为顶点v的下一个邻接点
	}
}
template <typename T>
void BFSTree(GraphClass<T> &gobj,int v)			//产生图的广度优先生成树
{
	int i;
	for (i=0;i<gobj.G->n;i++) visited[i]=0; 	//初始化访问标志数组
	BFS2(gobj.G,v);
}
template <typename T>
void BFS2(ALGraph<T> *G,int v)			//被BFSTree调用产生广度优先生成树
{	ArcNode<T> *p; int w,i;
	int qu[MAXV];
	int front=0,rear=0;				//定义循环队列并初始化队头队尾
	for (i=0;i<G->n;i++) visited[i]=0;	//访问标志数组初始化
	visited[v]=1; 						//置已访问标记
	rear=(rear+1) % MAXV; qu[rear]=v;	//顶点v进队
	while (front!=rear)					//若队列不空时循环
	{	front=(front+1) % MAXV;
		w=qu[front];						//出队并赋给w
		p=G->adjlist[w].firstarc;			//找与顶点w邻接的第一个顶点
		while (p!=NULL)
		{	
			if (visited[p->adjvex]==0)		//若当前邻接顶点未被访问
			{
				cout << "(" << w << "," << p->adjvex << ")  ";	//输出BFS生成树的一条边
				visited[p->adjvex]=1;		//置该顶点已被访问的标志
				rear=(rear+1) % MAXV;		//该顶点进队
				qu[rear]=p->adjvex;
			}
			p=p->nextarc;					//找下一个邻接顶点
		}
	}
}
void main()
{
	GraphClass<int> gobj;
	int n=10,e=12;
	int v=0;
	int A[MAXV][MAXV]={
		{0,1,1,1,0,0,0,0,0,0},
		{1,0,0,0,1,1,0,0,0,0},
		{1,0,0,1,0,1,1,0,0,0},
		{1,0,1,0,0,0,0,1,0,0},
		{0,1,0,0,0,0,0,0,0,0},
		{0,1,1,0,0,0,0,0,0,0},
		{0,0,1,0,0,0,0,1,1,1},
		{0,0,0,1,0,0,1,0,0,0},
		{0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,0,1,0,0,0}};  //图7.21的边数组
	cout << "建立gobj图的邻接表:\n";
	gobj.CreateALGraph(A,n,e);
	cout << "gobj图的邻接表:\n"; gobj.DispALGraph();
	cout << "从顶点" << v << "出发的深度优先生成树:"; DFSTree(gobj,v); cout << endl;
	cout << "从顶点" << v << "出发的广度优先生成树:"; BFSTree(gobj,v); cout << endl;
	cout << "销毁所有创建的图\n";
}