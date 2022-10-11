#include"AdjGraph.cpp"					//����ͼ(�ڽӱ�)�Ļ��������㷨
#include<vector>
#include<cstring>
int visited[MAXV];						//ȫ������ 
void DFS(AdjGraph &G,int v)				//������ȱ���(�ڽӱ�)
{
	visited[v]=1;						//���ѷ��ʱ��
	ArcNode*p=G.adjlist[v].firstarc;	//pָ�򶥵�v�ĵ�һ���ڽӵ�
	while (p!=NULL)
	{	int w=p->adjvex;				//�ڽӵ�Ϊw 
		if (visited[w]==0)
			DFS(G,w);					//��w����δ����,�ݹ������
		p=p->nextarc;					//p��Ϊ��һ���ڽӵ�
	}
}

bool Connect(AdjGraph &G)				//�ж�����ͼG����ͨ��
{
	memset(visited,0,sizeof(visited));
	DFS(G,0);							//��0����������ȱ���
	for (int i=0;i<G.n;i++)
		if (visited[i]==0)				//���ж���û�з��ʹ�
			return false;				//˵���Ƿ���ͨͼ 
	return true;						//˵������ͨͼ
}

int main()
{
	AdjGraph G;
	int n=5,e=8;
	int a[MAXV][MAXV]={{0,1,0,1,1},{1,0,1,1,0},{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0}};
	G.CreateAdjGraph(a,n,e);
	printf("ͼG�ڽӱ�\n"); G.DispAdjGraph();
	cout << "ͼG����ͨ��: " << Connect(G) << endl;
	return 0;
}


