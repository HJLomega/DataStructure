#include"AdjGraph.cpp"					//����ͼ(�ڽӱ�)�Ļ��������㷨
#include<cstring>
#include<vector>
bool Cycle1(AdjGraph &G,int u,vector<int> path,vector<int> inpath)  //�Ӷ���u������������ͼG���Ƿ���ڻ�·���㷨
{
	path.push_back(u);						//������u��ӵ�·����
	inpath[u]=1; 							//���ѷ��ʱ��
	ArcNode *p=G.adjlist[u].firstarc;		//pָ�򶥵�u�ĵ�һ���ڽӵ�
	while (p!=NULL)
	{	int w=p->adjvex;
		if (inpath[w]==0)					//������w����·����
		{	if (Cycle1(G,w,path,inpath))	//�Ӷ���w�����������ڻ�·
				return true;
		}
		else return true;					//������w��·���У�����ֻ�·
		p=p->nextarc;						//����һ���ڽӵ�
	}
	return false;
}

bool Cycle(AdjGraph &G)						//�ж�����ͼG���Ƿ��л�·
{
	for (int i=0;i<G.n;i++)
	{
		vector<int> inpath(MAXV,0);         //����Ԫ�س�ʼΪ0
		vector<int> path;
		if (Cycle1(G,i,path,inpath))		//�Ӷ���i��������
			return true;
	}
	return false;
}

int main()
{
	AdjGraph G1;
	//int n=4,e=4;
	//int a[MAXV][MAXV]={{0,1,1,0},{0,0,1,0},{0,0,0,1},{0,0,0,0}};	

	int n=6,e=9;
	int a[MAXV][MAXV]={{0,1,0,1,0,0},{0,0,0,0,0,1},{0,1,0,0,0,1},{0,1,0,0,1,0},{0,1,0,0,0,0},{0,0,0,0,1,0}};

	//int n=6,e=9;
	//int a[MAXV][MAXV]={{0,1,0,1,0,0},{0,0,0,0,0,1},{0,1,0,0,0,1},{0,1,0,0,1,0},{0,1,0,0,0,1},{0,0,0,0,0,0}};

	G1.CreateAdjGraph(a,n,e);
	printf("ͼG1�ڽӱ�\n"); G1.DispAdjGraph();
	printf("�����\n");
	printf("    ͼG1���Ƿ��л�·: %s\n",Cycle(G1)==true?"��":"û��");
	return 0;
}


