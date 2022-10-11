#include"MatGraph.cpp"			//����ͼ���ھ��󣩵Ļ��������㷨
void Prim(MatGraph g,int v)				//Prim�㷨�������С����
{
	int lowcost[MAXV];					//��������lowcost
	int closest[MAXV];					//��������closest
	for (int i=0;i<g.n;i++)				//��lowcost[]��closest[]�ó�ֵ
	{	lowcost[i]=g.edges[v][i];
		closest[i]=v;
	}
	for (int i=1;i<g.n;i++)				//�ҳ�(n-1)������
	{	int min=INF;
		int k=-1;						//k��¼�������ı��
		for (int j=0;j<g.n;j++)			//��(V-U)���ҳ���U����Ķ���k
			if (lowcost[j]!=0 && lowcost[j]<min)
			{	min=lowcost[j];
				k=j;
			}
		cout << "  ��(" << closest[k] << "," << k << "),ȨΪ" << min << endl;
		lowcost[k]=0;					//���k�Ѿ�����U
		for (int j=0;j<g.n;j++)			//�޸�����lowcost��closest
		if (g.edges[k][j]!=0 && g.edges[k][j]<lowcost[j])
		{	lowcost[j]=g.edges[k][j];
			closest[j]=k;
		}
	}
}
int main()
{
	MatGraph g;
	int n=6,e=10;
	int v=0;
	int A[MAXV][MAXV]={{0,6,1,5,INF,INF}, {6,0,5,INF,3,INF}, {1,5,0,5,6,4}, 
		{5,INF,5,0,INF,2}, {INF,3,6,INF,0,6}, {INF,INF,4,2,6,0}};
	cout << "����gobjͼ���ڽӾ���:\n";
	g.CreateMatGraph(A,n,e);
	cout << "ͼ���ڽӾ���:\n"; g.DispMatGraph();
	cout << "�Ӷ���" << v << "�����������С������:\n";
	Prim(g,v);
	return 0;
}
