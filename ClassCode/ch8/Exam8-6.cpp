#include"AdjGraph.cpp"					//包含图(邻接表)的基本运算算法
#include<cstring>
#include<vector>

int visited[MAXV];						//全局数组 
void FindaPath11(AdjGraph &G,int u,int v,vector<int> path)	//被FindaPath1调用
{
	visited[u]=1;
	path.push_back(u);                  //顶点u加入到路径中
	if (u==v)							//找到一条路径后输出并返回
  	{	for (int i=0;i<path.size();i++)
      		printf("%d ",path[i]);
     	printf("\n");
     	return;
	}
	ArcNode *p=G.adjlist[u].firstarc;
	while (p!=NULL)
	{
		int w=p->adjvex;				//找到u的邻接点w
		if (visited[w]==0)				//若顶点w没有访问
			FindaPath11(G,w,v,path);	//从w出发继续查找 
		p=p->nextarc;
	}
}

void FindaPath1(AdjGraph &G,int u,int v)	//解法1：求u到v的一条简单路径
{
	memset(visited,0,sizeof(visited));
 	vector<int> path;						//path存放一条路径
 	FindaPath11(G,u,v,path);
}


void FindaPath21(AdjGraph &G,int u,int v,vector<int> path,vector<int> &res)	//被FindaPath2调用
{
	visited[u]=1;
	path.push_back(u);                  //顶点u加入到路径中
	if (u==v)							//找到一条路径后输出并返回
  	{
  		res=path;
     	return;
	}
	ArcNode *p=G.adjlist[u].firstarc;
	while (p!=NULL)
	{
		int w=p->adjvex;				//找到u的邻接点w
		if (visited[w]==0)				//若顶点w没有访问
			FindaPath11(G,w,v,path);	//从w出发继续查找 
		p=p->nextarc;
	}
}

void FindaPath2(AdjGraph &G,int u,int v)	//解法2：求u到v的一条简单路径
{
	memset(visited,0,sizeof(visited));
 	vector<int> path;						//path存放一条路径
 	vector<int> res;
 	FindaPath21(G,u,v,path,res);
	for (int i=0;i<res.size();i++)
      	printf("%d ",res[i]);
    printf("\n");
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
	printf("  顶点%d到顶点%d路径: ",u,v); FindaPath1(G,u,v);
	u=0; v=4;
	printf("  顶点%d到顶点%d路径: ",u,v); FindaPath2(G,u,v);
	return 0;
}


