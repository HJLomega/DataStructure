#include"MatGraph.cpp"					//����ͼ(�ڽӾ���)�Ļ��������㷨
#include"AdjGraph.cpp"					//����ͼ(�ڽӱ�)�Ļ��������㷨
#include<cstring>
//ͼ��������ȱ���
int visited[MAXV];						//ȫ������
void DFS(AdjGraph &G,int v)				//������ȱ���(�ڽӱ�)
{
	visited[v]=1;						//���ѷ��ʱ��
	cout << v << " ";					//��������ʶ���ı��
	ArcNode*p=G.adjlist[v].firstarc;	//pָ�򶥵�v�ĵ�һ���ڽӵ�
	while (p!=NULL)
	{	int w=p->adjvex;				//�ڽӵ�Ϊw 
		if (visited[w]==0)
			DFS(G,w);					//��w����δ����,�ݹ������
		p=p->nextarc;					//p��Ϊ��һ���ڽӵ�
	}
}

void DFS(MatGraph &g,int v)				//������ȱ���(�ڽӾ���)
{
	visited[v]=1;						//���ѷ��ʱ��
	cout << v << " ";					//��������ʶ���ı��
	for (int w=0;w<g.n;w++)
	{	if (g.edges[v][w]!=0 && g.edges[v][w]!=INF) 
		{	if (visited[w]==0)			//���ڱ�<v,w>����wû�з��ʹ�
				DFS(g,w);				//��w����δ����,�ݹ������
		}
	}
}
int main()
{
	AdjGraph G;
	int n=6,e=7;
	int a[MAXV][MAXV]={{0,1,1,0,0,0},{0,0,0,0,0,1},{0,0,0,1,1,1},{0,0,0,0,0,0},{0,0,0,1,0,0},{0,0,0,0,0,0}};
	G.CreateAdjGraph(a,n,e);
	printf("ͼG�ڽӱ�\n"); G.DispAdjGraph();
	int v=0;
	cout << "�Ӷ���" << v << "������DFS����:";
	memset(visited,0,sizeof(visited));
	DFS(G,v); cout << endl;
	
	
	MatGraph g;
	g.CreateMatGraph(a,n,e);
	printf("ͼg�ڽӾ���\n"); g.DispMatGraph();
	cout << "�Ӷ���" << v << "������DFS����:";
	memset(visited,0,sizeof(visited));
	DFS(g,v); cout << endl;
	return 0;
}


