#include"AdjGraph.cpp"						//包含图(邻接表)的基本运算算法
#include<vector>
int Degree1(AdjGraph &G,int v)	   			//无向图邻接表G中求顶点v的度
{	int d=0;
	ArcNode *p=G.adjlist[v].firstarc;
	while (p!=NULL)       					//统计单链表v中边结点个数
  	{	d++;
  		p=p->nextarc;
  	}
	return d;
}
	
vector<int> Degree2(AdjGraph &G,int v) 		//有向图邻接表G中求顶点v的出度和入度
{
	vector<int> ans={0,0};                  //ans[0]累计出度,ans[1]累计入度
	ArcNode *p=G.adjlist[v].firstarc;
	while (p!=NULL)       					//统计单链表v中边结点个数
  	{	ans[0]++;
  		p=p->nextarc;
  	}
  	for (int i=0;i<G.n;i++)					//统计所有adjvex为v的边结点个数为v的入度
  	{
  		p=G.adjlist[i].firstarc;
  		while (p!=NULL)
  		{
  			if (p->adjvex==v)
  			{
  				ans[1]++;
  				break;						//一个单链表最多只有一个这样的结点 
  			}
  			p=p->nextarc;
  		}
  	}
 	return ans;						   		//返回出度和入度
}

int main()
{
	AdjGraph G1,G2;
	int n=5,e=8;
	int a[MAXV][MAXV]={{0,1,0,1,1},{1,0,1,1,0},{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0}};
	G1.CreateAdjGraph(a,n,e);
	printf("图G1(无向图)\n"); G1.DispAdjGraph();
	printf("求解结果\n");
	for (int i=0;i<G1.n;i++)
		printf("  顶点%d的度: %d\n",i,Degree1(G1,i));

	n=5; e=5;
	int b[MAXV][MAXV]={{0,8,INF,5,INF},{INF,0,3,INF,INF},{INF,INF,0,INF,6},{INF,INF,9,0,INF},{INF,INF,INF,INF,0}};	
	G2.CreateAdjGraph(b,n,e);
	printf("图G2(有向图)\n"); G2.DispAdjGraph();
	printf("求解结果\n");
	for (int i=0;i<G2.n;i++)
	{
		vector<int> ans=Degree2(G2,i);
		printf("  顶点%d: 出度=%d 入度=%d 度=%d\n",i,ans[0],ans[1],ans[0]+ans[1]);
	}
	return 0;
}


