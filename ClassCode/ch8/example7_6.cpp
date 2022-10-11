#include "Graph.cpp"							//����ͼ�Ļ��������㷨
int visited[MAXV];								//ȫ�ֱ�������
template <typename T>
bool HasPath(GraphClass<T> &gobj,int u,int v)	//����u��v�Ƿ��м�·�������ֵ
{
	int i;
	bool has=false;
	for (i=0;i<gobj.G->n;i++) visited[i]=0;	//visited����Ԫ���ó�ֵ0
	HasPath1(gobj.G,u,v,has);
	return has;
}
template <typename T>
void HasPath1(ALGraph<T> *G,int u,int v,bool &has)	//��HasPath��������
{	ArcNode<T> *p; int w;
	visited[u]=1;
	p=G->adjlist[u].firstarc;	//pָ��u�ĵ�һ�����ڵ�
	while (p!=NULL)
	{	w=p->adjvex;			//���ڵ�ı��Ϊw
		if (w==v)				//�ҵ�Ŀ�궥��󷵻�
		{	has=true;			//��ʾu��v��·��
			return;
		}
		if (visited[w]==0)
			HasPath1(G,w,v,has);
		p=p->nextarc;			//pָ����һ�����ڵ�
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
	cout << "�Ӷ���" << u << "������" << v << (HasPath(gobj,u,v)?"����":"������") << "·��\n";
	u=0; v=2;
	cout << "�Ӷ���" << u << "������" << v << (HasPath(gobj,u,v)?"����":"������") << "·��\n";
	cout << "�������д�����ͼ\n";
}