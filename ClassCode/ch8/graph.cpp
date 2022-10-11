#include <stdio.h>
#include <malloc.h>
#define MAXV 100				//最多顶点数
#define MAXE 300				//最多边数
#define INF 0x3f3f3f3f
typedef char ElemType;

typedef char ElemType;
typedef struct
{	int no;						//顶点编号
	ElemType info;				//顶点其他信息
} VertexType;					//顶点类型
typedef struct					//图的定义
{	int edges[MAXV][MAXV];		//邻接矩阵
	int n,e;					//分别为顶点数和边数
	VertexType vexs[MAXV];		//存放顶点信息
} MGraph;						//声明图的邻接矩阵类型

typedef struct ANode			//边结点的类型
{	int adjvex;					//该边的终点位置
	struct ANode *nextarc;		//指向下一条边的指针
	int weight;					//该边的相关信息，带权图可存放权值,假设为int类型
} ArcNode;
typedef struct Vnode			//邻接表头结点的类型
{	ElemType data;				//顶点信息
	int count;					//存放顶点入度,专为拓扑排序设置
	ArcNode *firstarc;			//指向第一条边
} VNode;

typedef VNode AdjList[MAXV];	//AdjList是邻接表类型
typedef struct
{	AdjList adjlist;			//头结点数组
	int n,e;					//分别为图中顶点数和边数
} AGraph;						//声明图的邻接表类型

//-----生成图的邻接矩阵算法------
void CreateMat(MGraph &g,int A[][MAXV],int n)
{	//由数组A[n][n]生成邻接矩阵g
	g.n=n;
	g.e=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
		{	g.edges[i][j]=A[i][j];
			if (A[i][j]!=0 && A[i][j]!=INF)		//存在一条边
				g.e++;							//边数增1
		}
}
//-----输出图的邻接矩阵算法-----
void DispMat(MGraph g)
{	for (int i=0;i<g.n;i++)
	{	for (int j=0;j<g.n;j++)
			if (g.edges[i][j]==INF)
				printf("  ∞");
			else
				printf("%4d",g.edges[i][j]);
		printf("\n");
	}
}


//-----生成图的邻接表算法-----
void CreateAdj(AGraph *&G,int A[][MAXV],int n)
{	//由数组A[n][n]生成邻接表G
	int i,j;
	ArcNode *p;
	G=(AGraph *)malloc(sizeof(AGraph));				//分配邻接表空间
	G->n=n;
	G->e=0;
	for (i=0;i<n;i++)								//给邻接表中所有头结点的指针域置初值
	{
		G->adjlist[i].firstarc=NULL;
		G->adjlist[i].count=0;						//专为拓扑排序设置
	}
	for (i=0;i<n;i++)								//检查邻接矩阵中每个元素
		for (j=n-1;j>=0;j--)
			if (A[i][j]!=0 && A[i][j]!=INF)			//存在一条边
			{	p=(ArcNode *)malloc(sizeof(ArcNode));	//创建一个结点p
				p->adjvex=j;
				p->weight=A[i][j];
				p->nextarc=G->adjlist[i].firstarc;	//将p结点链接到单链表i的表头
				G->adjlist[i].firstarc=p;
				G->e++;								//边数增1
			}
}
//------输出图的邻接表算法-------
void DispAdj(AGraph *G)	
{	int i;
	ArcNode *p;
	for (i=0;i<G->n;i++)
	{	printf("  [%d]->",i);
		p=G->adjlist[i].firstarc;			//找顶点i的第一个邻接点
		while (p!=NULL)						//存在i的邻接点时循环
		{	printf("%d->",p->adjvex);
			p=p->nextarc;					//找下一个邻接点
		}
		printf("∧\n");
	}
}
//------销毁邻接表算法-------
void DestroyAdj(AGraph *G)	
{	ArcNode *pre,*p;
	for (int i=0;i<G->n;i++)				//扫描所有的单链表
	{	pre=G->adjlist[i].firstarc;			//p指向第i个单链表的首结点
		if (pre!=NULL)
		{	p=pre->nextarc;	
			while (p!=NULL)					//释放单链表i的所有边结点
			{	free(pre);
				pre=p; p=p->nextarc;
			}
			free(pre);
		}
	}
	free(G);								//释放头结点数组
}
