#include "AdjGraph.cpp"					//包含图的基本运算算法
void TopSort(AdjGraph gobj)		//拓扑排序
{	int i,n=0;							//n为拓扑序列中顶点个数
	int topseq[MAXV];					//存放拓扑序列
	TopSort1(gobj.G,topseq,n);
	if (n<gobj.G->n)					//拓扑序列中不含所有顶点时
	{
		cout << "图中存在回路,不能进行拓扑排序\n";
		return;
	}
	else
	{
		for (i=0;i<n;i++)
			cout << (char)(topseq[i]+'A') << " "; 
		cout << endl;
	}
}
void TopSort1(ALGraph *G,int topseq[],int &n)
//被TopSort方法调用,产生含有n个顶点编号的拓扑序列topseq
{
	int i,j;
	int st[MAXV];						//定义一个顺序栈
	int top=-1;							//栈顶指针为top
	ArcNode<T> *p;
	for (i=0;i<G->n;i++)				//所有顶点的入度置初值0
		G->adjlist[i].indegree=0;
	for (i=0;i<G->n;i++)				//求所有顶点的入度
	{	p=G->adjlist[i].firstarc;
		while (p!=NULL)
		{	G->adjlist[p->adjvex].indegree++;
			p=p->nextarc;
		}
	}
	for (i=0;i<G->n;i++)
		if (G->adjlist[i].indegree==0)	//入度为0的顶点进栈
		{	top++;
			st[top]=i;
		}
	while (top>-1)						//栈不为空时循环
	{	i=st[top];top--;				//出栈
		topseq[n]=i; n++;
		p=G->adjlist[i].firstarc;		//找第一个相邻点
		while (p!=NULL)
		{	j=p->adjvex;
			G->adjlist[j].indegree--;
			if (G->adjlist[j].indegree==0)	//入度为0的相邻顶点进栈
			{	top++;
				st[top]=j;
			}
			p=p->nextarc;					//找下一个相邻点
		}
	}
}
template <typename T>
bool KeyPath(ALGraph<T> *G,int &inode,int &enode,KeyNode keynode[],int &d)
//从图邻接表G中求出从源点inode到汇点enode的关键活动keynode[0..d]
{	int topseq[MAXV];						//topseq用于存放拓扑序列
	int n=0;								//n为拓扑序列中的顶点数
	int i,w;
	ArcNode<T> *p;
	TopSort1(G,topseq,n);					//调用前面的拓扑排序算法产生拓扑序列
	if (n<G->n) return false;				//不能产生拓扑序列时返回false
	inode=topseq[0];						//求出源点
	enode=topseq[n-1];						//求出汇点
	int ve[MAXV];							//事件的最早开始时间
	int vl[MAXV];							//事件的最迟开始时间
	for (i=0;i<n;i++) ve[i]=0;				//先将所有事件的ve置初值为0
	for (i=0;i<n;i++)						//从左向右求所有事件的最早开始时间
	{	p=G->adjlist[i].firstarc;
		while (p!=NULL)						//遍历每一条边即活动
		{	w=p->adjvex;
			if (ve[i]+p->weight>ve[w])		//求最大者
				ve[w]=ve[i]+p->weight;
			p=p->nextarc;
		}
	 }
	for (i=0;i<n;i++)						//先将所有事件的vl值置为最大值
		vl[i]=ve[enode];
	for (i=n-2;i>=0;i--)					//从右向左求所有事件的最迟开始时间
	{	p=G->adjlist[i].firstarc;
		while (p!=NULL)
		{	w=p->adjvex;
			if (vl[w]-p->weight<vl[i])		//求最小者
				vl[i]=vl[w]-p->weight; 
			p=p->nextarc;
		}
	}
	d=-1;									//d存放keynode中的关键活动下标,置初置为-1
	for (i=0;i<n;i++)						//求关键活动
	{	p=G->adjlist[i].firstarc;
		while (p!=NULL)
		{	w=p->adjvex;
			if (ve[i]==vl[w]-p->weight)		//(i→w)是一个关键活动
			{
				d++; keynode[d].ino=i; keynode[d].eno=w;
			}
			p=p->nextarc;
		}
	}
	return true;
}
template <typename T>
void DispKeynode(GraphClass<T> &gobj)
{
	int inode,enode,d,i;
	KeyNode keynode[MAXV];
	if (KeyPath(gobj.G,inode,enode,keynode,d))
	{
		cout << "从源点" << inode << "到汇点" << enode << "的关键活动:";
		for (i=0;i<=d;i++)
			cout << "(" << char(keynode[i].ino+'A') << "," << char(keynode[i].eno+'A') << ")  ";
		cout << endl;
	}
	else cout << "不能求关键活动\n";
}
void main()
{
	GraphClass<int> gobj;
	int n=9,e=11;
	int A[MAXV][MAXV]={
		{ 0,  6,  4,  5 ,INF,INF,INF,INF,INF},
		{INF, 0, INF,INF, 1 ,INF,INF,INF,INF},
		{INF,INF, 0 ,INF, 1 ,INF,INF,INF,INF},
		{INF,INF,INF, 0 ,INF,INF,INF, 2 ,INF},
		{INF,INF,INF,INF, 0 , 9 , 7 ,INF,INF},
		{INF,INF,INF,INF,INF, 0 ,INF,INF, 2 },
		{INF,INF,INF,INF,INF,INF, 0 ,INF, 4 },
		{INF,INF,INF,INF,INF,INF,INF, 0 , 4 },
		{INF,INF,INF,INF,INF,INF,INF,INF, 0 }};	//图7.32的边数组
	cout << "建立gobj图的邻接表:\n";
	gobj.CreateALGraph(A,n,e);
	cout << "gobj图的邻接表:\n"; gobj.DispALGraph();
	DispKeynode(gobj);
	cout << "销毁所有创建的图\n";
}
