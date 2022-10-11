#include "Graph.cpp"							//包含图的基本运算算法
int visited[MAXV];								//全局变量数组
template <typename T>
bool HasPath(GraphClass<T> &gobj,int u,int v)	//返回u到v是否有简单路径的真假值
{
	int i;
	bool has=false;
	for (i=0;i<gobj.G->n;i++) visited[i]=0;	//visited数组元素置初值0
	HasPath1(gobj.G,u,v,has);
	return has;
}
template <typename T>
void HasPath1(ALGraph<T> *G,int u,int v,bool &has)	//被HasPath方法调用
{	ArcNode<T> *p; int w;
	visited[u]=1;
	p=G->adjlist[u].firstarc;	//p指向u的第一个相邻点
	while (p!=NULL)
	{	w=p->adjvex;			//相邻点的编号为w
		if (w==v)				//找到目标顶点后返回
		{	has=true;			//表示u到v有路径
			return;
		}
		if (visited[w]==0)
			HasPath1(G,w,v,has);
		p=p->nextarc;			//p指向下一个相邻点
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
	cout << "从顶点" << u << "到顶点" << v << (HasPath(gobj,u,v)?"存在":"不存在") << "路径\n";
	u=0; v=2;
	cout << "从顶点" << u << "到顶点" << v << (HasPath(gobj,u,v)?"存在":"不存在") << "路径\n";
	cout << "销毁所有创建的图\n";
}