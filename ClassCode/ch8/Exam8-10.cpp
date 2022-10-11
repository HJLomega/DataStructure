#include"AdjGraph.cpp"					//包含图(邻接表)的基本运算算法
#include<cstring>
#include<vector>
#include<queue>
//--------------解法1开始------------------ 
struct QNode								//队列元素类型
{
	int v;									//顶点编号 
	int dis;								//源点到当前顶点的最短路径长度 
	QNode() {}								//构造函数 
	QNode(int v,int dis)					//重载构造函数
	{
		this->v=v;
		this->dis=dis;
	}
};
int Shortdist1(AdjGraph &G,int u,int v)      	//求u到v的最短路径长度 
{
	int visited[MAXV];							//访问标记数组
	memset(visited,0,sizeof(visited));
	queue<QNode> qu;                     		//定义一个队列qu
 	visited[u]=1;                          		//置已访问标记
	qu.push(QNode(u,0));				  		//起始点u(距离为0)进队
 	while (!qu.empty())                    	  	//队不空循环
  	{	QNode e=qu.front(); qu.pop();		   	//出队一个元素e
     	if (e.v==v)						    	//找到顶点v
        	return e.dis;						//返回u到v的最短路径长度
		ArcNode *p=G.adjlist[e.v].firstarc;
		while (p!=NULL)
		{	int w=p->adjvex;					//找到u的邻接点w
			if (visited[w]==0)					//若顶点w没有访问
			{
				visited[w]=1;                  	//置已访问标记
				qu.push(QNode(w,e.dis+1));		//邻接点w进队 
			}
			p=p->nextarc;
		}
	}
	return INF;									//没有路径的情况 
}
//--------------解法1结束------------------ 


//--------------解法2开始------------------ 

int Shortdist2(AdjGraph& G,int u,int v)		//解法2：求u到v的最短路径长度
{	int visited[MAXV];							//访问标记数组
	memset(visited,0,sizeof(visited));
	int ans=0;									//存放最短路径长度(初始时为0)
	queue<int> qu;								//定义一个队列qu
	visited[u]=1;									//置已访问标记
	qu.push(u);										//起始点u进队
	while (!qu.empty())							//队不空循环
	{
		int n=qu.size();					//求队列qu中元素个数n
		for(int i=0;i<n;i++)					//循环n次 
		{
			u=qu.front(); qu.pop();				//出队一个顶点u 
			if (u==v)								//找到顶点v
				return ans;							//返回u到v的最短路径长度
			ArcNode* p=G.adjlist[u].firstarc;
			while (p!=NULL)
			{	int w=p->adjvex;					//找到u的邻接点w
				if (visited[w]==0)					//若顶点w没有访问
				{	visited[w]=1; 					//置已访问标记
					qu.push(w);					//邻接点w进队
				}
				p=p->nextarc;
			}
		}
		ans++; 							//一层的顶点扩展后ans增1
	}
	return INF;									//没有路径的情况 
}

//--------------解法2结束------------------ 



//--------------多起点广度优先遍历算法------------------ 


int Shortdist3(AdjGraph& G,vector<int>&U,int v)		//求U中顶点到v的最短路径长度
{
	int visited[MAXV];							//访问标记数组
	memset(visited,0,sizeof(visited));
	int ans=0;									//存放最短路径长度(初始时为0)
	queue<int> qu;								//定义一个队列qu
	for(int i=0;i<U.size();i++)					//将U集合中所有顶点作为起点进队 
	{	visited[U[i]]=1;						//置已访问标记
		qu.push(U[i]);							//起始点U[i]进队
	}
	while (!qu.empty())							//队不空循环
	{
		int n=qu.size();					//求队列qu中元素个数n
		for(int i=0;i<n;i++)					//循环n次 
		{
			int u=qu.front(); qu.pop();				//出队一个顶点u 
			if (u==v)								//找到顶点v
				return ans;							//返回u到v的最短路径长度
			ArcNode* p=G.adjlist[u].firstarc;
			while (p!=NULL)
			{	int w=p->adjvex;					//找到u的邻接点w
				if (visited[w]==0)					//若顶点w没有访问
				{	visited[w]=1; 					//置已访问标记
					qu.push(w);					//邻接点w进队
				}
				p=p->nextarc;
			}
		}
		ans++; 							//一层的顶点扩展后ans增1
	}
	return INF;									//没有路径的情况 
}
	
//--------------解法2结束------------------ 

int main()
{
	AdjGraph G;
	int n=6,e=9;
	int a[MAXV][MAXV]={{0,1,0,1,0,0},{0,0,0,0,0,1},{0,1,0,0,0,1},{0,1,0,0,1,0},{0,1,0,0,0,1},{0,0,0,0,0,0}};
	G.CreateAdjGraph(a,n,e);
	printf("图G邻接表\n"); G.DispAdjGraph();
	printf("求解结果\n");
	int u=0;
	printf("解法1\n");
	for (int v=0;v<n;v++)
		printf("  顶点%d到%d的最短路径长度: %d\n",u,v,Shortdist1(G,u,v));
	printf("解法2\n");
	for (int v=0;v<n;v++)
		printf("  顶点%d到%d的最短路径长度: %d\n",u,v,Shortdist2(G,u,v));
		
	printf("顶点集->一个顶点\n");
	vector<int> U={0,2,3};
	int v=5;
	printf("  U顶点集到%d的最短路径长度: %d\n",v,Shortdist3(G,U,v));
	
	return 0;
}


