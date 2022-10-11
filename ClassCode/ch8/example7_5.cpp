#include "Graph.cpp"					//包含图的基本运算算法
//图的深度优先遍历
int visited[MAXV];						//全局数组
template <typename T>
void DFS(GraphClass<T> &gobj,int v)		//图对象gobj的深度优先遍历
{
	int i;
	for (i=0;i<gobj.G->n;i++) visited[i]=0;	//visited数组元素均置为0
	DFS1(gobj.G,v);
}
template <typename T>
void DFS1(ALGraph<T> *G,int v)			//被DFS调用进行深度优先遍历
{
	int w;
	ArcNode<T> *p;
	visited[v]=1;						//置已访问标记
	//cout << v << " ";					//输出被访问顶点的编号
	p=G->adjlist[v].firstarc;			//p指向顶点v的第一个邻接点
	while (p!=NULL)
	{	w=p->adjvex;
		if (visited[w]==0) DFS1(G,w);	//若w顶点未访问,递归访问它
		p=p->nextarc;					//p置为下一个邻接点
	}
}
//图的广度优先遍历
template <typename T>
void BFS(GraphClass<T> &gobj,int v)			//图对象gobj的广度优先遍历
{
	int i;
	for (i=0;i<gobj.G->n;i++) visited[i]=0;	//visited数组元素均置为0
	BFS1(gobj.G,v);
}
template <typename T>
void BFS1(ALGraph<T> *G,int v)				//被BFS调用进行广度优先遍历
{	ArcNode<T> *p; int w;
	int qu[MAXV];							//定义一个循环队列
	int front=0,rear=0;						//循环队列队头队尾初始化
	//cout << v << " "; visited[v]=1;			//输出访问顶点并置已访问标记
	rear=(rear+1) % MAXV; qu[rear]=v;		//v进队
	while (front!=rear)						//若队列不空时循环
	{	front=(front+1) % MAXV;
		w=qu[front];						//出队并赋给w
		p=G->adjlist[w].firstarc;			//找与顶点w邻接的第一个顶点
		while (p!=NULL)
		{	if (visited[p->adjvex] == 0)	//若当前邻接顶点未被访问
			{	cout << p->adjvex << " ";	//访问相邻顶点
				visited[p->adjvex]=1;		//置该顶点已被访问的标志
				rear=(rear+1) % MAXV;		//该顶点进队
				qu[rear]=p->adjvex;
			}
			p=p->nextarc;					//找下一个邻接顶点
		}
	}
}
template <typename T>
bool Connect(GraphClass<T> &gobj)		//判断无向图G的连通性
{	int i;
	bool flag=true;
	for (i=0;i<gobj.G->n;i++) visited[i]=0;	//visited数组元素均置为0
	DFS1(gobj.G,0);				//调用DSF1算法,从顶点0开始深度优先遍历
	for (i=0;i<gobj.G->n;i++)
		if (visited[i]==0)
		{	flag=false;
			break;
		}
	return flag;
}
void main()
{
	GraphClass<int> gobj;
	int n=5,e=8;
	int v=2;
	int A[MAXV][MAXV]={{0,1,0,1,1},{1,0,1,1,0},{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0}};
	cout << "建立gobj图的邻接表:\n";
	gobj.CreateALGraph(A,n,e);
	cout << "gobj图的邻接表:\n"; gobj.DispALGraph();
	cout << "gobj图" << (Connect(gobj)?"是":"是非") << "连通的\n";
	cout << "销毁所有创建的图\n";
}