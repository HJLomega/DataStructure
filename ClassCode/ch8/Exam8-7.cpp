#include"AdjGraph.cpp"					//包含图(邻接表)的基本运算算法
#include<cstring>
#include<vector>
bool Cycle1(AdjGraph &G,int u,vector<int> path,vector<int> inpath)  //从顶点u出发搜索有向图G中是否存在回路的算法
{
	path.push_back(u);						//将顶点u添加到路径中
	inpath[u]=1; 							//置已访问标记
	ArcNode *p=G.adjlist[u].firstarc;		//p指向顶点u的第一个邻接点
	while (p!=NULL)
	{	int w=p->adjvex;
		if (inpath[w]==0)					//若顶点w不在路径中
		{	if (Cycle1(G,w,path,inpath))	//从顶点w出发搜索存在回路
				return true;
		}
		else return true;					//若顶点w在路径中，则出现回路
		p=p->nextarc;						//找下一个邻接点
	}
	return false;
}

bool Cycle(AdjGraph &G)						//判断有向图G中是否有回路
{
	for (int i=0;i<G.n;i++)
	{
		vector<int> inpath(MAXV,0);         //所有元素初始为0
		vector<int> path;
		if (Cycle1(G,i,path,inpath))		//从顶点i出发搜索
			return true;
	}
	return false;
}

int main()
{
	AdjGraph G1;
	//int n=4,e=4;
	//int a[MAXV][MAXV]={{0,1,1,0},{0,0,1,0},{0,0,0,1},{0,0,0,0}};	

	int n=6,e=9;
	int a[MAXV][MAXV]={{0,1,0,1,0,0},{0,0,0,0,0,1},{0,1,0,0,0,1},{0,1,0,0,1,0},{0,1,0,0,0,0},{0,0,0,0,1,0}};

	//int n=6,e=9;
	//int a[MAXV][MAXV]={{0,1,0,1,0,0},{0,0,0,0,0,1},{0,1,0,0,0,1},{0,1,0,0,1,0},{0,1,0,0,0,1},{0,0,0,0,0,0}};

	G1.CreateAdjGraph(a,n,e);
	printf("图G1邻接表\n"); G1.DispAdjGraph();
	printf("求解结果\n");
	printf("    图G1中是否有回路: %s\n",Cycle(G1)==true?"有":"没有");
	return 0;
}


