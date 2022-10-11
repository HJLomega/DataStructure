#include"MatGraph.cpp"			//����ͼ���ڽӾ��󣩵Ļ��������㷨
#include"AdjGraph.cpp"			//����ͼ���ڽӱ��Ļ��������㷨
#include<queue>
#include<vector> 
#include<cstring>

void DispAllPath(int dist[],int path[],int S[],int v,int n) //����Ӷ���v�������������·��
{
	for (int i=0;i<n;i++)					//ѭ������Ӷ���v��i��·��
		if (S[i]==1 && i!=v)
		{
			vector<int> apath;				//���һ�������·��		
			printf("  ��%d��%d���·������Ϊ: %d\t·��: ",v,i,dist[i]);
			apath.push_back(i);					//����յ�i
			int pre=path[i];
			while (pre!=v)
			{	apath.push_back(pre);
				pre=path[pre];
			}
			printf("%d",v);					//��������v
			for (int k=apath.size()-1;k>=0;k--)	
				printf("->%d",apath[k]);	//�ٷ������·������������
			printf("\n");
		}
		else printf("  ��%d��%dû��·��\n",v,i);
}

void Dijkstra(MatGraph &g,int v)			//���v��������������·��
{
	int dist[MAXV];							//����dist����
	int path[MAXV];							//����path����
	int S[MAXV];							//����S����
	for (int i=0;i<g.n;i++)
	{	dist[i]=g.edges[v][i];				//�����ʼ��
		S[i]=0;								//S[]�ÿ�
		if (g.edges[v][i]!=0 && g.edges[v][i]<INF)
			path[i]=v;						//v��i�б�ʱ����i��ǰ������Ϊv
		else
			path[i]=-1;						//v��iû��ʱ����i��ǰ������Ϊ-1
	}
	S[v]=1;									//Դ����v����S��
	int mindis,u=-1;
	for (int i=0;i<g.n-1;i++)				//ѭ����S�����n-1������
	{	mindis=INF;							//mindis����С���ȳ�ֵ
		for (int j=0;j<g.n;j++)				//ѡȡ����S���Ҿ�����С����Ķ���u
			if (S[j]==0 && dist[j]<mindis) 
			{	u=j;
				mindis=dist[j];
			}
		S[u]=1;								//����u����S��
		for (int j=0;j<g.n;j++)				//�޸Ĳ���s�еĶ���ľ���
			if (S[j]==0)
				if (g.edges[u][j]<INF && dist[u]+g.edges[u][j]<dist[j])
				{	dist[j]=dist[u]+g.edges[u][j];
					path[j]=u;
				}
	}
	DispAllPath(dist,path,S,v,g.n);			//����������·��������
}
//--------------�Ľ��ĵҿ�˹�����㷨
struct QNode								//���ȶ���Ԫ������ 
{
	int v;									//������
	int dist;								//Դ�㵽v�ľ���
	QNode(int v,int d)						//���캯�� 
	{
		this->v=v;
		this->dist=d;
	}
	bool operator<(const QNode &s) const	//����<�ȽϺ���
	{
		return dist>s.dist;					//��distԽСԽ���ȳ���
	}
}; 
	
void Dijkstra1(AdjGraph &G,int v)			//�Ľ�Dijkstra�㷨���v��������������·��
{
	priority_queue<QNode> pq;				//����һ�����ȶ��� 
	int dist[MAXV];							//����dist����
	int S[MAXV];							//����S����
	memset(dist,INF,sizeof(dist));
	memset(S,0,sizeof(S));
	dist[v]=0;
	pq.push(QNode(v,dist[v]));				//Դ��(v,0)���� 
	for (int i=0;i<G.n;i++)					//ѭ����S�����n������(�����ʼSΪ��)
	{
		QNode e=pq.top(); pq.pop();			//����e1 
		int u=e.v;							//��С����Ķ���Ϊu 
		S[u]=1;								//����u����S��		
		ArcNode *p=G.adjlist[u].firstarc;
		while (p!=NULL)
		{
		 	int w=p->adjvex;        		//����u��һ���ڽӵ�w
        	if (S[w]==0 && dist[u]+p->weight<dist[w])
         	{	dist[w]=dist[u]+p->weight;	//�޸����·������
            	pq.push(QNode(w,dist[w]));	//(w,dist[w])����
			}
			p=p->nextarc;
		}
	}
	printf("��%d������������·����������\n",v);
	for (int i=0;i<G.n;i++)			  		//������
  	{	if (i!=v)
      		printf("  %d��%d���·������Ϊ: %d\n",v,i,dist[i]);
	}
}


int main()
{
	MatGraph g;
	int n=7,e=12;
	int v=0;
	int A[MAXV][MAXV]={
		{0,4,6,6,INF,INF,INF},
		{INF,0,1,INF,7,INF,INF},
		{INF,INF,0,INF,6,4,INF},
		{INF,INF,2,0,INF,5,INF},
		{INF,INF,INF,INF,0,INF,6},
		{INF,INF,INF,INF,1,0,8},
		{INF,INF,INF,INF,INF,INF,0}};
	cout << "����ͼ���ڽӾ���:\n";
	g.CreateMatGraph(A,n,e);
	cout << "ͼ���ڽӾ���:\n"; g.DispMatGraph();
	cout << "ͼ�дӶ���" << v << "���������·��:\n";
	Dijkstra(g,v);
	
	AdjGraph G;
	cout << "����ͼ���ڽӱ�:\n";
	G.CreateAdjGraph(A,n,e);
	cout << "ͼ���ڽӱ�:\n"; G.DispAdjGraph();
	Dijkstra1(G,v);
	
	return 0;
}
