#include"MatGraph.cpp"								//����ͼ(�ڽӾ���)�Ļ��������㷨
#include"AdjGraph.cpp"								//����ͼ(�ڽӱ�)�Ļ��������㷨
#include<cstring>
#include<queue>
//ͼ�Ĺ�����ȱ���
void BFS(AdjGraph &G,int v)					//������ȱ���(�ڽӱ�)
{
	int visited[MAXV];
	memset(visited,0,sizeof(visited));		//��ʼ��visited���� 
	queue<int> qu;							//����һ������ 
	cout << v << " ";						//���ʶ���v
	visited[v]=1;							//���ѷ��ʱ��
	qu.push(v);								//����v���� 
	while (!qu.empty())						//���в���ѭ��
	{
		int u=qu.front(); qu.pop();			//���Ӷ���u
		ArcNode *p=G.adjlist[u].firstarc;	//�Ҷ���u�ĵ�һ���ڽӵ�
		while (p!=NULL)
		{	if (visited[p->adjvex]==0)		//��u���ڽӵ�δ����
			{	cout << p->adjvex << " ";	//�����ڽӵ�
				visited[p->adjvex]=1;		//���ѷ��ʱ��
				qu.push(p->adjvex);			//�ڽӵ����
			}
			p=p->nextarc;					//����һ���ڽӵ�
		}
	}
}


void BFS(MatGraph &g,int v)					//������ȱ���(�ڽӾ���)
{
	int visited[MAXV];
	memset(visited,0,sizeof(visited));		//��ʼ��visited���� 
	queue<int> qu;							//����һ������ 
	cout << v << " ";						//���ʶ���v
	visited[v]=1;							//���ѷ��ʱ��
	qu.push(v);								//����v���� 
	while (!qu.empty())						//���в���ѭ��
	{
		int u=qu.front(); qu.pop();			//���Ӷ���u
		for (int i=0;i<g.n;i++)
			if (g.edges[u][i]!=0 && g.edges[u][i]!=INF)
			{
				if (visited[i]==0)
				{	cout << i << " ";		//�����ڽӵ�
					visited[i]=1;			//���ѷ��ʱ��
					qu.push(i);				//�ڽӵ����
				}
			}
	}
}

/*
//����ͨ����ͼ�ı����㷨
template <typename T>
void DFSA(GraphClass<T> &gobj)		//����ͨͼ��DFS
{	int i;
	for (i=0;i<gobj.G->n;i++) visited[i]=0;	//visited����Ԫ�ؾ���Ϊ0
	for (i=0;i<gobj.G->n;i++)
		if (visited[i]==0)
			DFS1(gobj.G,i);
}
template <typename T>
void BFSA(GraphClass<T> &gobj)		//����ͨͼ��BFS
{	int i;
	for (i=0;i<gobj.G->n;i++) visited[i]=0;	//visited����Ԫ�ؾ���Ϊ0
	for (i=0;i<gobj.G->n;i++)
		if (visited[i]==0)
			BFS1(G,i);
}
*/

int main()
{
	AdjGraph G;
	int n=6,e=7;
	int a[MAXV][MAXV]={{0,1,1,0,0,0},{0,0,0,0,0,1},{0,0,0,1,1,1},{0,0,0,0,0,0},{0,0,0,1,0,0},{0,0,0,0,0,0}};
	G.CreateAdjGraph(a,n,e);
	printf("ͼG�ڽӱ�\n"); G.DispAdjGraph();
	int v=0;
	cout << "�Ӷ���" << v << "������BFS����:";
	BFS(G,v); cout << endl;
	
	
	MatGraph g;
	g.CreateMatGraph(a,n,e);
	printf("ͼg�ڽӾ���\n"); g.DispMatGraph();
	cout << "�Ӷ���" << v << "������BFS����:";
	BFS(g,v); cout << endl;
	return 0;
}


