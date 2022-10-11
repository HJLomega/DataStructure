#include "Graph.cpp"					//包含图的基本运算算法
int visited[MAXV];						//全局变量数组
template <typename T>
int Maxdist(GraphClass<T> &gobj,int v)	//返回离顶点v最远的顶点
{
	ArcNode<T> *p; int i,w,k=0;
	int qu[MAXV];						//定义循环队列
	int front=0,rear=0;					//队列及首、尾指针
	for (i=0;i<gobj.G->n;i++) visited[i]=0;	//初始化访问标志数组
	rear++; qu[rear]=v;					//顶点v进队
	visited[v]=1;						//标记v已访问
	while (rear!=front)
	{	front=(front+1) % MAXV;
		k=qu[front];					//顶点出队
		p=gobj.G->adjlist[k].firstarc;	//找第1个邻接点
		while (p!=NULL)					//所有未访问过的邻接点进队
		{	w=p->adjvex;
			if (visited[w]==0)			//若w未访问过
			{	visited[w]=1;			//将顶点w进队
				rear=(rear+1) % MAXV;
				qu[rear]=w; 
			}
			p=p->nextarc;				//找下一个邻接点
		}
	}
	return k;
}

void main()
{
	GraphClass<int> gobj,gobj1;
	int n=6,e=9;
	int v=0;
	int A[MAXV][MAXV]={{0,1,0,1,0,0},{0,0,0,0,0,1},{0,1,0,0,0,1},
		{0,1,0,0,1,0},{0,1,0,0,0,1},{0,0,0,0,0,0}}; 	//图7.15的边数组
	int B[MAXV][MAXV]={{0,1,0,1,0,0},{1,0,1,1,1,1},{0,1,0,0,0,1},
		{1,1,0,0,1,0},{0,1,0,1,0,1},{0,0,1,0,1,0}}; 	//图7.15的边数组
	cout << "建立gobj图的邻接表:\n";
	gobj.CreateALGraph(A,n,e);
	cout << "gobj图的邻接表:\n"; gobj.DispALGraph();
	cout << "gobj图中距离顶点" << v << "最远的顶点是" << Maxdist(gobj,v) << endl;
	cout << "建立gobj1图的邻接表:\n";
	gobj1.CreateALGraph(B,n,e);
	cout << "gobj1图的邻接表:\n"; gobj1.DispALGraph();
	cout << "gobj1图中距离顶点" << v << "最远的顶点是" << Maxdist(gobj1,v) << endl;
	cout << "销毁所有创建的图\n";
}