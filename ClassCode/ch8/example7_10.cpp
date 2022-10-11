#include "Graph.cpp"					//����ͼ�Ļ��������㷨
int visited[MAXV];						//ȫ�ֱ�������
template <typename T>
bool Cycle(GraphClass<T> &gobj)			//�ж�ͼ���Ƿ��л�·
{
	int i,j; bool has=false;
	int d=-1;							//dΪ�ҵ�·������,��ʼΪ-1
	for (i=0;i<gobj.G->n;i++)
	{
		for (j=0;j<gobj.G->n;j++) visited[i]=0; //visited����Ԫ���ó�ֵ0
		Cycle1(gobj.G,i,i,d,has);
		if (has) return true;
	}
	return false;
}
template <typename T>
void Cycle1(ALGraph<T> *G,int u,int v,int d,bool &has) //��Cycle��������
{
	ArcNode<T> *p; int w;
	visited[u]=1; d++;			//·��������1
	if (u==v && d>=1) 			//�ҵ�һ�����ȴ���0�ļ򵥻�·,����
	{
		has=true;
		return;
	}
	p=G->adjlist[u].firstarc;	//pָ��u�ĵ�һ�����ڵ�
	while (p!=NULL)
	{	w=p->adjvex;			//���ڵ�ı��Ϊw
		if (visited[w]==0)
			Cycle1(G,w,v,d,has);
		p=p->nextarc;			//pָ����һ�����ڵ�
	}
	visited[u]=0;
}

void main()
{
	GraphClass<int> gobj;
	int n=6,e=9;
	int A[MAXV][MAXV]={{0,1,0,1,0,0},{0,0,0,0,0,1},{0,1,0,0,0,1},
	{0,1,0,0,1,0},{0,1,0,0,0,1},{0,0,0,0,0,0}}; 	//ͼ7.15�ı�����
	cout << "����gobjͼ���ڽӱ�:\n";
	gobj.CreateALGraph(A,n,e);
	cout << "gobjͼ���ڽӱ�:\n"; gobj.DispALGraph();
	cout << "gobjͼ��" << (Cycle(gobj)?"����":"������") << "��·\n";
	cout << "�������д�����ͼ\n";
}