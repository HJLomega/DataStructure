#include "Graph.cpp"					//包含图的基本运算算法
int visited[MAXV];						//全局变量数组
template <typename T>
bool Cycle(GraphClass<T> &gobj)			//判断图中是否有回路
{
	int i,j; bool has=false;
	int d=-1;							//d为找到路径长度,初始为-1
	for (i=0;i<gobj.G->n;i++)
	{
		for (j=0;j<gobj.G->n;j++) visited[i]=0; //visited数组元素置初值0
		Cycle1(gobj.G,i,i,d,has);
		if (has) return true;
	}
	return false;
}
template <typename T>
void Cycle1(ALGraph<T> *G,int u,int v,int d,bool &has) //被Cycle函数调用
{
	ArcNode<T> *p; int w;
	visited[u]=1; d++;			//路径长度增1
	if (u==v && d>=1) 			//找到一条长度大于0的简单回路,返回
	{
		has=true;
		return;
	}
	p=G->adjlist[u].firstarc;	//p指向u的第一个相邻点
	while (p!=NULL)
	{	w=p->adjvex;			//相邻点的编号为w
		if (visited[w]==0)
			Cycle1(G,w,v,d,has);
		p=p->nextarc;			//p指向下一个相邻点
	}
	visited[u]=0;
}

void main()
{
	GraphClass<int> gobj;
	int n=6,e=9;
	int A[MAXV][MAXV]={{0,1,0,1,0,0},{0,0,0,0,0,1},{0,1,0,0,0,1},
	{0,1,0,0,1,0},{0,1,0,0,0,1},{0,0,0,0,0,0}}; 	//图7.15的边数组
	cout << "建立gobj图的邻接表:\n";
	gobj.CreateALGraph(A,n,e);
	cout << "gobj图的邻接表:\n"; gobj.DispALGraph();
	cout << "gobj图中" << (Cycle(gobj)?"存在":"不存在") << "回路\n";
	cout << "销毁所有创建的图\n";
}