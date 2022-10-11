#include"MatGraph.cpp"					//����ͼ���ڽӾ��󣩵Ļ��������㷨
#include<vector>
 
void Dispath(int A[][MAXV],int path[][MAXV],int n)    //������е����·���ͳ���
{
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
		{
			if (A[i][j]!=INF && i!=j)			//������i��j֮�����·��
			{
				vector<int> apath;				//���һ��i��j�������·��
				printf("  ����%d��%d�����·������: %d\t·��: ",i,j,A[i][j]);
				apath.push_back(j);				//·��������յ�j
				int pre=path[i][j];
				while (pre!=i)					//·��������м��
				{
					apath.push_back(pre);		//����pre���뵽·����
					pre=path[i][pre];
				}
				cout << i;					//������i
				for (int k=apath.size()-1;k>=0;k--)		//�������·���ϵ���������
					printf("->%d",apath[k]); 
				printf("\n");
			}
		}
}

void Floyd(MatGraph &g)					//Floyd���Դ���·��
{	int A[MAXV][MAXV];					//����A����
	int path[MAXV][MAXV];				//����path����
	for (int i=0;i<g.n;i++)					//������A��path�ó�ֵ����A-1[i][j]
		for (int j=0;j<g.n;j++) 
		{	A[i][j]=g.edges[i][j];
			if (i!=j && g.edges[i][j]<INF)
				path[i][j]=i;			//i��j����֮����һ����ʱ
			else	
				path[i][j]=-1;			//i��j����֮��û��һ����ʱ
		}
	for (int k=0;k<g.n;k++)					//��Ak[i][j]
	{	for (int i=0;i<g.n;i++)
			for (int j=0;j<g.n;j++)
				if (A[i][j]>A[i][k]+A[k][j])
				{	A[i][j]=A[i][k]+A[k][j];
					path[i][j]= path[k][j];	//�޸����·��
				}
	}
	Dispath(A,path,g.n);					//������·���ͳ���
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
		{INF,INF,INF,INF,INF,INF,0}};	//ͼ7.25�ı�����
	cout << "����gobjͼ���ڽӾ���:\n";
	g.CreateMatGraph(A,n,e);
	cout << "ͼ���ڽӾ���:\n"; g.DispMatGraph();
	cout << "ͼ�����ж���֮������·��:\n";
	Floyd(g);
	return 0;
}
