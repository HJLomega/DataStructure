#include"AdjGraph.cpp"					//包含图(邻接表)的基本运算算法
#include<cstring>
#include<vector>

int visited[MAXV];							//全局数组 
void FindallPath11(AdjGraph &G,int u,int v,vector<int> path)	//被FindallPath1调用
{
	visited[u]=1;
	path.push_back(u);                  	//顶点u加入到路径中
	if (u==v)								//找到一条路径后输出并返回
  	{	for (int i=0;i<path.size();i++)
      		printf("  %d",path[i]);
     	printf("\n");
		visited[u]=0;						//回溯,重置visited[u]为0 	
     	return;
	}
	ArcNode *p=G.adjlist[u].firstarc;
	while (p!=NULL)
	{
		int w=p->adjvex;					//找到u的邻接点w
		if (visited[w]==0)					//若顶点w没有访问
			FindallPath11(G,w,v,path);		//从w出发继续查找 
		p=p->nextarc;
	}
	visited[u]=0;							//回溯,重置visited[u]为0
}

void FindallPath1(AdjGraph &G,int u,int v)	//解法1：求u到v的所有简单路径
{
	memset(visited,0,sizeof(visited));
 	vector<int> path;						//path存放一条路径
 	FindallPath11(G,u,v,path);
}

int inpath[MAXV];                        		//全局数组
vector<int> path;								//全局变量
void FindallPath21(AdjGraph &G,int u,int v)   	//被Findapath2函数调用
{
	if (u==v)									//叶子结点：找到一条路径后输出
  	{	for (int i=0;i<path.size();i++)			//输出路径 
      		printf("  %d",path[i]);
     	printf("\n");
     	return;
	}
	ArcNode *p=G.adjlist[u].firstarc;			//扩展u 
	while (p!=NULL)
	{
		int w=p->adjvex;						//找到u的邻接点w
		if (inpath[w]==0)						//若顶点w不在path中
		{
      		path.push_back(w);             		//将顶点w添加的path中
        	inpath[w]=1;                     	//置w已经在path中
        	FindallPath21(G,w,v);      		 	//递归调用
        	path.pop_back();					//path回退 
        	inpath[w]=0;                    	//置w不在path中
		}
		p=p->nextarc;
	}
}

void FindallPath2(AdjGraph &G,int u,int v) 	//解法2:求u到v的所有简单路径
{
	memset(inpath,0,sizeof(inpath));		//初始化inpath
 	path.push_back(u);                     	//将顶点u添加的path中
 	inpath[u]=1;                           	//置u已经在path中
 	FindallPath21(G,u,v);
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
	printf("  顶点%d到顶点%d的所有路径:\n",u,v); FindallPath2(G,u,v);
	u=0; v=4;
	printf("  顶点%d到顶点%d的所有路径:\n",u,v); FindallPath2(G,u,v);
	return 0;
}


