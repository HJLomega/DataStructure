#include"MatGraph.cpp"								//包含图(邻接矩阵)的基本运算算法
#include<vector>
int Degree1(MatGraph &g,int v)	   					//无向图邻接矩阵g中求顶点v的度
{	int d=0;
	for (int j=0;j<g.n;j++)        					//统计第v行的非0非∞元素个数
  		if (g.edges[v][j]!=0 && g.edges[v][j]!=INF)
      		d++;
	return d;
}
	
vector<int> Degree2(MatGraph &g,int v) 				//有向图邻接矩阵g中求顶点v的出度和入度
{
	vector<int> ans={0,0};                       	//ans[0]累计出度,ans[1]累计入度
	for (int j=0;j<g.n;j++)        	    			//统计第v行的非0非∞元素个数为出度
  		if (g.edges[v][j]!=0 && g.edges[v][j]!=INF)
      		ans[0]++;
	for (int i=0;i<g.n;i++)            				//统计第v列的非0非∞元素个数为入度
  		if (g.edges[i][v]!=0 && g.edges[i][v]!=INF)
      		ans[1]++;
 	return ans;						    			//返回出度和入度
}

int main()
{
	MatGraph g1,g2;
	int n=5,e=8;
	int a[MAXV][MAXV]={{0,1,0,1,1},{1,0,1,1,0},{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0}};
	g1.CreateMatGraph(a,n,e);
	printf("图G1(无向图)\n"); g1.DispMatGraph();
	printf("求解结果\n");
	for (int i=0;i<g1.n;i++)
		printf("  顶点%d的度: %d\n",i,Degree1(g1,i));

	n=5; e=5;
	int b[MAXV][MAXV]={{0,8,INF,5,INF},{INF,0,3,INF,INF},{INF,INF,0,INF,6},{INF,INF,9,0,INF},{INF,INF,INF,INF,0}};	
	g2.CreateMatGraph(b,n,e);
	printf("图G2(有向图)\n"); g2.DispMatGraph();
	printf("求解结果\n");
	for (int i=0;i<g2.n;i++)
	{
		vector<int> ans=Degree2(g2,i);
		printf("  顶点%d: 出度=%d 入度=%d 度=%d\n",i,ans[0],ans[1],ans[0]+ans[1]);
	}
	return 0;
}


