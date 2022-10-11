#include <iostream>
#include<vector>
#include<cstring>
using namespace std; 
const int MAXV=100;							//图中最多的顶点数
const int MAXE=200;							//图中最多的边数
const int INF=0x3f3f3f3f;					//用INF表示
int head[MAXV];								//头结点数组
struct Edge									//边结点类型 
{
	int adjvex;								//邻接点
	int weight;								//权值
	int next;								//下一个边结点在edges数组中的下标
} edges[MAXE];								//边结点数组
int n;										//顶点数
int cnt;									//edges数组元素个数
void addedge(int u,int v,int w)				//添加一条有向边<u,v>:w
{
    edges[cnt].adjvex=v;
    edges[cnt].weight=w;
    edges[cnt].next=head[u];				//将edges[cnt]边结点插入到head[u]的表头 
    head[u]=cnt;
    cnt++;									//edges数组元素个数增1 
}
void init()									//初始化 
{
	cnt=0;									//cnt从0开始 
	memset(head,0xffff,sizeof(head));		//所有元素初始化为-1
}
	
void CreateAdjGraph(vector<vector<int> > a,int n)	//通过边数组a和顶点数n建立简化邻接表
{	//a中每个元素表示一条边<u,v,w>
	init(); 								//初始化简化邻接表 
	for (int i=0;i<a.size();i++)
		addedge(a[i][0],a[i][1],a[i][2]);	//插入一条边 
}
void DispAdjGraph()							//输出图的邻接表
{
	for (int i=0;i<n;i++)					//遍历每个头结点 
	{
		printf("   [%d]",i);
		for(int j=head[i];j!=-1;j=edges[j].next)
			printf(" (%d,%d,%d)",edges[j].adjvex,edges[j].weight,edges[j].next);
		printf("\n");
	}
}
 
int main()
{
	n=5;
	vector<vector<int> > a={{0,1,8},{0,3,5},{1,2,3},{2,4,6},{3,2,9}};
	CreateAdjGraph(a,n);
	cout << "图的邻接表:\n"; DispAdjGraph();
	
	printf("head\n");
	for (int i=0;i<n;i++)
		printf("head[%d]=%d\n",i,head[i]);
	printf("edges\n");
	for (int i=0;i<cnt;i++)
		printf("%d: (%d,%d,%d)\n",i,edges[i].adjvex,edges[i].weight,edges[i].next);
	return 0;
}

