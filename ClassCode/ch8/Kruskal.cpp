#include"MatGraph.cpp"			//包含图（邻矩阵）的基本运算算法
#include<vector>
#include<algorithm>

struct Edge							//边向量元素类型
{	int u;							//边的起始顶点
	int v;							//边的终止顶点
	int w;							//边的权值
	Edge(int u,int v,int w)			//构造函数 
	{
		this->u=u;
		this->v=v;
		this->w=w;
	}
	bool operator<(const Edge &s) const	//重载<运算符
	{
		return w<s.w;					//用于按w递增排序
	}
};
void Kruskal(MatGraph &g)				//Kruskal算法输出最小生成树
{
	int vset[MAXV];						//建立数组vset
	vector<Edge> E;						//建立存放所有边的向量E
	for (int i=0;i<g.n;i++)				//由图的邻接矩阵g产生边向量E
		for (int j=0;j<g.n;j++)
			if (g.edges[i][j]!=0 && g.edges[i][j]!=INF && i<j)
				E.push_back(Edge(i,j,g.edges[i][j]));
	sort(E.begin(),E.end());			//对E按权值递增排序
	for (int i=0;i<g.n;i++) vset[i]=i;	//初始化辅助数组
	int k=1;							//k表示当前构造生成树的第几条边,初值为1
	int j=0;							//E中边的下标,初值为0
	while (k<g.n)						//生成的边数小于n时循环
	{	int u1=E[j].u;
		int v1=E[j].v;					//取一条边的起始和终止顶点
		int sn1=vset[u1];
		int sn2=vset[v1];				//分别得到两个顶点所属的集合编号
		if (sn1!=sn2)					//两顶点属于不同的集合,该边是最小生成树的一条边
		{
			cout << "  边(" << u1 << "," << v1 << "),权为" << E[j].w << endl;
			k++;						//生成边数增1
			for (int i=0;i<g.n;i++)		//两个集合统一编号
				if (vset[i]==sn2)		//集合编号为sn2的改为sn1
					vset[i]=sn1;
		}
		j++;							//扫描下一条边
	}
}
//---------------------------------------------------------------------
//-----------------改进的克鲁斯卡尔算法
//---------------------------------------------------------------------
int parent[MAXV];		         		//并查集存储结构
int rnk[MAXV];			         		//存储结点的秩
void Init(int n)				        //并查集初始化
{
 	for (int i=0;i<n;i++)				//顶点编号0到n-1 
  	{	parent[i]=i;
    	rnk[i]=0;
	}
}

int Find(int x)				      		//并查集中查找x结点的根结点
{
 	if (x!=parent[x])
  		parent[x]=Find(parent[x]);		//路径压缩 
  	return parent[x];
}
void Union(int x,int y)		         	//并查集中x和y的两个集合的合并
{  	int rx=Find(x);
  	int ry=Find(y);
  	if (rx==ry)							//x和y属于同一棵树的情况 
  		return;
 	if (rnk[rx]<rnk[ry])
  		parent[rx]=ry;					//rx结点作为ry的孩子 
  	else
  	{	if (rnk[rx]==rnk[ry])			//秩相同，合并后rx的秩增1
      		rnk[rx]++;
    	parent[ry]=rx;					//ry结点作为rx的孩子  
	}
}
void Kruskal1(MatGraph &g)				//改进的Kruskal算法输出最小生成树
{
	vector<Edge> E;						//建立存放所有边的向量E
	for (int i=0;i<g.n;i++)				//由图的邻接矩阵g产生边向量E
		for (int j=0;j<g.n;j++)
			if (g.edges[i][j]!=0 && g.edges[i][j]!=INF && i<j)
				E.push_back(Edge(i,j,g.edges[i][j]));
	sort(E.begin(),E.end());			//对E按权值递增排序
	Init(g.n);				       			//并查集初始化
	int k=1;							//k表示当前构造生成树的第几条边,初值为1
	int j=0;							//E中边的下标,初值为0
	while (k<g.n)					//生成的边数小于n时循环
	{	
		int u1=E[j].u;
		int v1=E[j].v;					//取一条边的起始和终止顶点
		int sn1=Find(u1);
		int sn2=Find(v1);				//分别得到两个顶点所属的集合编号
		if (sn1!=sn2)				//两顶点属于不同的集合,该边是最小生成树的一条边
		{
			cout << "  边(" << u1 << "," << v1 << "),权为" << E[j].w << endl;
			k++;					//生成边数增1
			Union(sn1,sn2);			//合并
		}
		j++;						//扫描下一条边
	}
}

int main()
{
	MatGraph g;
	int n=6,e=10;
	int v=0;
	int A[MAXV][MAXV]={{0,6,1,5,INF,INF}, {6,0,5,INF,3,INF}, {1,5,0,5,6,4}, 
		{5,INF,5,0,INF,2}, {INF,3,6,INF,0,6}, {INF,INF,4,2,6,0}};  //图7.21(a)的边数组
	cout << "建立图的邻接矩阵:\n";
	g.CreateMatGraph(A,n,e);
	cout << "图的邻接矩阵:\n"; g.DispMatGraph();
	cout << "图的最小生成树:\n";
	Kruskal1(g);
	return 0;
}
