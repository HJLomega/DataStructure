#include "Graph.cpp"							//����ͼ�Ļ��������㷨
int visited[MAXV];								//ȫ�ֱ�������
template <typename T>
void FindaPath(GraphClass<T> &gobj,int u,int v)	//��u��v��һ����·��
{
	int i,path[MAXV],d=-1;		//path���һ��·����d���·������
	for (i=0;i<gobj.G->n;i++) visited[i]=0;	//visited����Ԫ���ó�ֵ0
	FindaPath1(gobj.G,u,v,path,d);
}
template <typename T>
void FindaPath1(ALGraph<T> *G,int u,int v,int path[],int d)	//��Findapath��������
{	ArcNode<T> *p; int w,i;
	visited[u]=1;
	d++; path[d]=u;				//����u���뵽·����
	if (u==v)							//�ҵ�һ��·�������������
	{
		for (i=0;i<=d;i++)
			cout << path[i] << " ";
		cout << endl;
		return;
	}
	p=G->adjlist[u].firstarc;			//pָ��u�ĵ�һ�����ڵ�
	while (p!=NULL)
	{	w=p->adjvex;					//���ڵ�ı��Ϊw
		if (visited[w]==0)
			FindaPath1(G,w,v,path,d);	//�ݹ����
		p=p->nextarc;					//pָ����һ�����ڵ�
	}
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
	cout << "�Ӷ���" << u << "������" << v <<  "��һ����·��:";
	FindaPath(gobj,u,v);
	cout << "�������д�����ͼ\n";
}