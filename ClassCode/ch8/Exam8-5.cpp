#include"AdjGraph.cpp"					//包含图(邻接表)的基本运算算法
#include<cstring>
int visited[MAXV];						//全局数组 
bool HasPath1(AdjGraph &G,int u,int v)	//被HasPath方法调用
{
	visited[u]=1;
	ArcNode *p=G.adjlist[u].firstarc;
	while (p!=NULL)
	{
		int w=p->adjvex;				//找到u的邻接点w
    	if (w==v)						//找到目标点后返回真
      		return true;	    		//表示u到v有路径
     	else if (visited[w]==0)			//若顶点w 
		{	if (HasPath1(G,w,v))
				return true;
		}
		p=p->nextarc;
	}
	return false;
}

bool HasPath(AdjGraph &G,int u,int v)  	//判断u到v是否有简单路径
{
	memset(visited,0,sizeof(visited));
	return HasPath1(G,u,v);
}
int main()
{
	AdjGraph G;
	int n=6,e=9;
	int a[MAXV][MAXV]={{0,1,0,1,0,0},{0,0,0,0,0,1},{0,1,0,0,0,1},{0,1,0,0,1,0},{0,1,0,0,0,1},{0,0,0,0,0,0}};
	G.CreateAdjGraph(a,n,e);
	printf("图G邻接表\n"); G.DispAdjGraph();
	int u=0,v=5;
	printf("求解结果\n");
	printf("  顶点%d到顶点%d路径: %s\n",u,v,HasPath(G,u,v)?"有":"没有");
	u=0; v=2;
	printf("  顶点%d到顶点%d路径: %s\n",u,v,HasPath(G,u,v)?"有":"没有");
	return 0;
}


