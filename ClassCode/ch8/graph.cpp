#include <stdio.h>
#include <malloc.h>
#define MAXV 100				//��ඥ����
#define MAXE 300				//������
#define INF 0x3f3f3f3f
typedef char ElemType;

typedef char ElemType;
typedef struct
{	int no;						//������
	ElemType info;				//����������Ϣ
} VertexType;					//��������
typedef struct					//ͼ�Ķ���
{	int edges[MAXV][MAXV];		//�ڽӾ���
	int n,e;					//�ֱ�Ϊ�������ͱ���
	VertexType vexs[MAXV];		//��Ŷ�����Ϣ
} MGraph;						//����ͼ���ڽӾ�������

typedef struct ANode			//�߽�������
{	int adjvex;					//�ñߵ��յ�λ��
	struct ANode *nextarc;		//ָ����һ���ߵ�ָ��
	int weight;					//�ñߵ������Ϣ����Ȩͼ�ɴ��Ȩֵ,����Ϊint����
} ArcNode;
typedef struct Vnode			//�ڽӱ�ͷ��������
{	ElemType data;				//������Ϣ
	int count;					//��Ŷ������,רΪ������������
	ArcNode *firstarc;			//ָ���һ����
} VNode;

typedef VNode AdjList[MAXV];	//AdjList���ڽӱ�����
typedef struct
{	AdjList adjlist;			//ͷ�������
	int n,e;					//�ֱ�Ϊͼ�ж������ͱ���
} AGraph;						//����ͼ���ڽӱ�����

//-----����ͼ���ڽӾ����㷨------
void CreateMat(MGraph &g,int A[][MAXV],int n)
{	//������A[n][n]�����ڽӾ���g
	g.n=n;
	g.e=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
		{	g.edges[i][j]=A[i][j];
			if (A[i][j]!=0 && A[i][j]!=INF)		//����һ����
				g.e++;							//������1
		}
}
//-----���ͼ���ڽӾ����㷨-----
void DispMat(MGraph g)
{	for (int i=0;i<g.n;i++)
	{	for (int j=0;j<g.n;j++)
			if (g.edges[i][j]==INF)
				printf("  ��");
			else
				printf("%4d",g.edges[i][j]);
		printf("\n");
	}
}


//-----����ͼ���ڽӱ��㷨-----
void CreateAdj(AGraph *&G,int A[][MAXV],int n)
{	//������A[n][n]�����ڽӱ�G
	int i,j;
	ArcNode *p;
	G=(AGraph *)malloc(sizeof(AGraph));				//�����ڽӱ�ռ�
	G->n=n;
	G->e=0;
	for (i=0;i<n;i++)								//���ڽӱ�������ͷ����ָ�����ó�ֵ
	{
		G->adjlist[i].firstarc=NULL;
		G->adjlist[i].count=0;						//רΪ������������
	}
	for (i=0;i<n;i++)								//����ڽӾ�����ÿ��Ԫ��
		for (j=n-1;j>=0;j--)
			if (A[i][j]!=0 && A[i][j]!=INF)			//����һ����
			{	p=(ArcNode *)malloc(sizeof(ArcNode));	//����һ�����p
				p->adjvex=j;
				p->weight=A[i][j];
				p->nextarc=G->adjlist[i].firstarc;	//��p������ӵ�������i�ı�ͷ
				G->adjlist[i].firstarc=p;
				G->e++;								//������1
			}
}
//------���ͼ���ڽӱ��㷨-------
void DispAdj(AGraph *G)	
{	int i;
	ArcNode *p;
	for (i=0;i<G->n;i++)
	{	printf("  [%d]->",i);
		p=G->adjlist[i].firstarc;			//�Ҷ���i�ĵ�һ���ڽӵ�
		while (p!=NULL)						//����i���ڽӵ�ʱѭ��
		{	printf("%d->",p->adjvex);
			p=p->nextarc;					//����һ���ڽӵ�
		}
		printf("��\n");
	}
}
//------�����ڽӱ��㷨-------
void DestroyAdj(AGraph *G)	
{	ArcNode *pre,*p;
	for (int i=0;i<G->n;i++)				//ɨ�����еĵ�����
	{	pre=G->adjlist[i].firstarc;			//pָ���i����������׽��
		if (pre!=NULL)
		{	p=pre->nextarc;	
			while (p!=NULL)					//�ͷŵ�����i�����б߽��
			{	free(pre);
				pre=p; p=p->nextarc;
			}
			free(pre);
		}
	}
	free(G);								//�ͷ�ͷ�������
}
