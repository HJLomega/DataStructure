#include"AdjGraph.cpp"					//包含图（邻接表）的基本运算算法
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
void TopSort(AdjGraph &G)				//拓扑排序
{
	stack<int> st;						//定义一个栈
	int ind[MAXV];            			//记录每个顶点的入度
	memset(ind,0,sizeof(ind));
	ArcNode *p;
	for (int i=0;i<G.n;i++)					//求所有顶点的入度
	{
		p=G.adjlist[i].firstarc;
		while (p!=NULL)					//处理顶点i的所有出边
		{
			int w=p->adjvex;			//存在有向边<i,w>
			ind[w]++;					//顶点w的入度增1
			p=p->nextarc;
		}
	}
	for (int i=0;i<G.n;i++)				//将所有入度为0的顶点进栈
		if (ind[i]==0)
			st.push(i);
	while (!st.empty())					//栈不为空时循环
	{	int i=st.top(); st.pop();			//出栈一个顶点i
		printf("%d ",i);				//输出拓扑序列中的一个顶点i
		p=G.adjlist[i].firstarc;		//找顶点i的第一个邻接点
		while (p!=NULL)
		{	int w=p->adjvex;			//邻接点为w 
			ind[w]--;					//顶点w的入度减1 
			if (ind[w]==0)				//入度为0的邻接点w进栈
				st.push(w);
			p=p->nextarc;				//找下一个邻接点
		}
	}
}

int main()
{
	AdjGraph G;
	int n=6,e=6;
	int A[MAXV][MAXV]={{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,0,0},{0,1,0,0,0,1},{0,0,0,1,0,0}};
	cout << "建立G图的邻接表:\n";
	G.CreateAdjGraph(A,n,e);
	cout << "图G的邻接表:\n"; G.DispAdjGraph();
	cout << "图G的拓扑序列:\n";
	TopSort(G);
	return 0;
}
