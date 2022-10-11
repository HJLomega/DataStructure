#include "Graph.cpp"							//包含图的基本运算算法
int visited[MAXV];								//全局变量数组
template <typename T>
void FindaPath(GraphClass<T> &gobj,int u,int v)	//求u到v的一条简单路径
{
	int i,path[MAXV],d=-1;		//path存放一条路径，d存放路径长度
	for (i=0;i<gobj.G->n;i++) visited[i]=0;	//visited数组元素置初值0
	FindaPath1(gobj.G,u,v,path,d);
}
template <typename T>
void FindaPath1(ALGraph<T> *G,int u,int v,int path[],int d)	//被Findapath方法调用
{	ArcNode<T> *p; int w,i;
	visited[u]=1;
	d++; path[d]=u;				//顶点u加入到路径中
	if (u==v)							//找到一条路径后输出并返回
	{
		for (i=0;i<=d;i++)
			cout << path[i] << " ";
		cout << endl;
		return;
	}
	p=G->adjlist[u].firstarc;			//p指向u的第一个相邻点
	while (p!=NULL)
	{	w=p->adjvex;					//相邻点的编号为w
		if (visited[w]==0)
			FindaPath1(G,w,v,path,d);	//递归调用
		p=p->nextarc;					//p指向下一个相邻点
	}
}

void main()
{
	GraphClass<int> gobj;
	int n=6,e=9;
	int u,v;
	int A[MAXV][MAXV]={{0,1,0,1,0,0},{0,0,0,0,0,1},{0,1,0,0,0,1},
	{0,1,0,0,1,0},{0,1,0,0,0,1},{0,0,0,0,0,0}}; 	//图7.15的边数组
	cout << "建立gobj图的邻接表:\n";
	gobj.CreateALGraph(A,n,e);
	cout << "gobj图的邻接表:\n"; gobj.DispALGraph();
	u=0; v=5;
	cout << "从顶点" << u << "到顶点" << v <<  "的一条简单路径:";
	FindaPath(gobj,u,v);
	cout << "销毁所有创建的图\n";
}