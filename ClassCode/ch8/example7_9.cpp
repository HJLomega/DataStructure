#include "Graph.cpp"							//包含图的基本运算算法
int visited[MAXV];								//全局变量数组
template <typename T>
void FindallLengthPath(GraphClass<T> &gobj,int u,int v,int l)	//求u到v的所有长度为l简单路径
{
	int i; int apath[MAXV],d=-1;
	for (i=0;i<gobj.G->n;i++) visited[i]=0; 	//visited数组元素置初值0
	FindallLengthPath1(gobj.G,u,v,l,apath,d);
}
template <typename T>
void FindallLengthPath1(ALGraph<T> *G,int u,int v,int l,int apath[],int d) //被FindallLengPath函数调用
{
	ArcNode<T> *p; int w,i;
	visited[u]=1;
	d++; apath[d]=u;			//顶点u加入到路径中
	if (u==v && d==l)			//找到一条长度为l的简单路径
	{
		for (i=0;i<=d;i++)
			cout << apath[i] << " ";
		cout << endl;
	}
	p=G->adjlist[u].firstarc;	//p指向u的第一个相邻点
	while (p!=NULL)
	{	w=p->adjvex;			//相邻点的编号为w
		if (visited[w]==0)
			FindallLengthPath1(G,w,v,l,apath,d);
		p=p->nextarc;			//p指向下一个相邻点
	}
	visited[u]=0;
}
void main()
{
	GraphClass<int> gobj;
	int n=6,e=9;
	int u,v,l;
	int A[MAXV][MAXV]={{0,1,0,1,0,0},{0,0,0,0,0,1},{0,1,0,0,0,1},
	{0,1,0,0,1,0},{0,1,0,0,0,1},{0,0,0,0,0,0}}; 	//图7.15的边数组
	cout << "建立gobj图的邻接表:\n";
	gobj.CreateALGraph(A,n,e);
	cout << "gobj图的邻接表:\n"; gobj.DispALGraph();
	u=0; v=5; l=3;
	cout << "从顶点" << u << "到顶点" << v <<  "的所有长度为" << l << "的简单路径:\n";
	FindallLengthPath(gobj,u,v,l);
	cout << "销毁所有创建的图\n";
}