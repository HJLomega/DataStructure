#include "Graph.cpp"					//包含图的基本运算算法
int visited[MAXV];						//全局变量数组
struct QUEUE							//非循环队列类型
{	int no;								//顶点编号
	int parent;							//前一个顶点在队列中的位置
};
template <typename T>
void ShortPath(GraphClass<T> &gobj,int u,int v)
//输出从顶点u到v的一条最短简单路径
{
	ArcNode<T> *p; int w,i;
	int spath[MAXV],d=-1;				//存放u到v的最短路径,d为其路径长度
	QUEUE qu[MAXV];						//非循环队列
	int front=-1,rear=-1;				//队列的头、尾指针
	for (i=0;i<gobj.G->n;i++) visited[i]=0;	//访问标记置初值0
	rear++;								//顶点u进队
	qu[rear].no=u; qu[rear].parent=-1;	//起点的双亲置为-1
	visited[u]=1;						//置顶点u已访问
	while (front!=rear)					//队不空循环
	{	front++;						//出队顶点w
		w=qu[front].no;
		if (w==v)						//找到v时输出路径之逆并退出
		{	i=front;					//通过队列输出逆路径
			while (qu[i].parent!=-1)
			{	d++; spath[d]=qu[i].no;
				i=qu[i].parent;
			}
			d++; spath[d]=qu[i].no;
			for (i=d;i>=0;i--)
				cout << spath[i] << " ";
			cout << endl;
			break;							//找到路径后退出while循环
		}
		p=gobj.G->adjlist[w].firstarc;		//找w的第一个邻接点
		while (p!=NULL)
		{	if (visited[p->adjvex]==0)
			{	visited[p->adjvex]=1;
				rear++;						//将w的未访问过的邻接点进队
				qu[rear].no=p->adjvex;
				qu[rear].parent=front;		//进队顶点的双亲置为front
			}
			p=p->nextarc;					//找w的下一个邻接点
		}
	}
}


void main()
{
	GraphClass<int> gobj;
	int n=6,e=9;
	int u=0,v=5;
	int A[MAXV][MAXV]={{0,1,0,1,0,0},{0,0,0,0,0,1},{0,1,0,0,0,1},
	{0,1,0,0,1,0},{0,1,0,0,0,1},{0,0,0,0,0,0}}; 	//图7.15的边数组
	cout << "建立gobj图的邻接表:\n";
	gobj.CreateALGraph(A,n,e);
	cout << "gobj图的邻接表:\n"; gobj.DispALGraph();
	cout << "gobj图中从顶点" << u << "到顶点" << v << "一条最短路径:";
	ShortPath(gobj,u,v);
	cout << "销毁所有创建的图\n";
}