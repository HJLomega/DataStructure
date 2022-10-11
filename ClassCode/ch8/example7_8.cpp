#include "Graph.cpp"							//����ͼ�Ļ��������㷨
int visited[MAXV];								//ȫ�ֱ�������
template <typename T>
void FindallPath(GraphClass<T> &gobj,int u,int v)	//��u��v�����м�·��
{
	int i; int apath[MAXV],d=-1;
	for (i=0;i<gobj.G->n;i++) visited[i]=0; 	//visited����Ԫ���ó�ֵ0
	FindallPath1(gobj.G,u,v,apath,d);
}
template <typename T>
void FindallPath1(ALGraph<T> *G,int u,int v,int apath[],int d)	//��FindallPath��������
{	ArcNode<T> *p; int w,i;
	visited[u]=1;
	d++; apath[d]=u;			//����u���뵽·����
	if (u==v)					//�ҵ�һ��·���������·��
	{
		for (i=0;i<=d;i++)
			cout << apath[i] << " ";
		cout << endl;
	}
	p=G->adjlist[u].firstarc;			//pָ��u�ĵ�һ�����ڵ�
	while (p!=NULL)
	{	w=p->adjvex;					//���ڵ�ı��Ϊw
		if (visited[w]==0)
			FindallPath1(G,w,v,apath,d);	//�ݹ����
		p=p->nextarc;					//pָ����һ�����ڵ�
	}
	visited[u]=0;						//����,����visited[u]Ϊ0
}


void main()
{
	GraphClass<int> gobj;
	int n=6,e=9;
	int u,v;
	int A[MAXV][MAXV]={{0,1,0,1,0,0},{0,0,0,0,0,1},{0,1,0,0,0,1},
	{0,1,0,0,1,0},{0,1,0,0,0,1},{0,0,0,0,0,0}}; 	//ͼ7.15�ı�����
	cout << "����gobjͼ���ڽӱ�:\n";
	gobj.CreateALGraph(A,n,e);
	cout << "gobjͼ���ڽӱ�:\n"; gobj.DispALGraph();
	u=0; v=5;
	cout << "�Ӷ���" << u << "������" << v <<  "�����м�·��:\n";
	FindallPath(gobj,u,v);
	cout << "�������д�����ͼ\n";
}