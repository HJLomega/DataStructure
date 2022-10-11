#include"MatGraph.cpp"			//����ͼ���ھ��󣩵Ļ��������㷨
#include<vector>
#include<algorithm>

struct Edge							//������Ԫ������
{	int u;							//�ߵ���ʼ����
	int v;							//�ߵ���ֹ����
	int w;							//�ߵ�Ȩֵ
	Edge(int u,int v,int w)			//���캯�� 
	{
		this->u=u;
		this->v=v;
		this->w=w;
	}
	bool operator<(const Edge &s) const	//����<�����
	{
		return w<s.w;					//���ڰ�w��������
	}
};
void Kruskal(MatGraph &g)				//Kruskal�㷨�����С������
{
	int vset[MAXV];						//��������vset
	vector<Edge> E;						//����������бߵ�����E
	for (int i=0;i<g.n;i++)				//��ͼ���ڽӾ���g����������E
		for (int j=0;j<g.n;j++)
			if (g.edges[i][j]!=0 && g.edges[i][j]!=INF && i<j)
				E.push_back(Edge(i,j,g.edges[i][j]));
	sort(E.begin(),E.end());			//��E��Ȩֵ��������
	for (int i=0;i<g.n;i++) vset[i]=i;	//��ʼ����������
	int k=1;							//k��ʾ��ǰ�����������ĵڼ�����,��ֵΪ1
	int j=0;							//E�бߵ��±�,��ֵΪ0
	while (k<g.n)						//���ɵı���С��nʱѭ��
	{	int u1=E[j].u;
		int v1=E[j].v;					//ȡһ���ߵ���ʼ����ֹ����
		int sn1=vset[u1];
		int sn2=vset[v1];				//�ֱ�õ��������������ļ��ϱ��
		if (sn1!=sn2)					//���������ڲ�ͬ�ļ���,�ñ�����С��������һ����
		{
			cout << "  ��(" << u1 << "," << v1 << "),ȨΪ" << E[j].w << endl;
			k++;						//���ɱ�����1
			for (int i=0;i<g.n;i++)		//��������ͳһ���
				if (vset[i]==sn2)		//���ϱ��Ϊsn2�ĸ�Ϊsn1
					vset[i]=sn1;
		}
		j++;							//ɨ����һ����
	}
}
//---------------------------------------------------------------------
//-----------------�Ľ��Ŀ�³˹�����㷨
//---------------------------------------------------------------------
int parent[MAXV];		         		//���鼯�洢�ṹ
int rnk[MAXV];			         		//�洢������
void Init(int n)				        //���鼯��ʼ��
{
 	for (int i=0;i<n;i++)				//������0��n-1 
  	{	parent[i]=i;
    	rnk[i]=0;
	}
}

int Find(int x)				      		//���鼯�в���x���ĸ����
{
 	if (x!=parent[x])
  		parent[x]=Find(parent[x]);		//·��ѹ�� 
  	return parent[x];
}
void Union(int x,int y)		         	//���鼯��x��y���������ϵĺϲ�
{  	int rx=Find(x);
  	int ry=Find(y);
  	if (rx==ry)							//x��y����ͬһ��������� 
  		return;
 	if (rnk[rx]<rnk[ry])
  		parent[rx]=ry;					//rx�����Ϊry�ĺ��� 
  	else
  	{	if (rnk[rx]==rnk[ry])			//����ͬ���ϲ���rx������1
      		rnk[rx]++;
    	parent[ry]=rx;					//ry�����Ϊrx�ĺ���  
	}
}
void Kruskal1(MatGraph &g)				//�Ľ���Kruskal�㷨�����С������
{
	vector<Edge> E;						//����������бߵ�����E
	for (int i=0;i<g.n;i++)				//��ͼ���ڽӾ���g����������E
		for (int j=0;j<g.n;j++)
			if (g.edges[i][j]!=0 && g.edges[i][j]!=INF && i<j)
				E.push_back(Edge(i,j,g.edges[i][j]));
	sort(E.begin(),E.end());			//��E��Ȩֵ��������
	Init(g.n);				       			//���鼯��ʼ��
	int k=1;							//k��ʾ��ǰ�����������ĵڼ�����,��ֵΪ1
	int j=0;							//E�бߵ��±�,��ֵΪ0
	while (k<g.n)					//���ɵı���С��nʱѭ��
	{	
		int u1=E[j].u;
		int v1=E[j].v;					//ȡһ���ߵ���ʼ����ֹ����
		int sn1=Find(u1);
		int sn2=Find(v1);				//�ֱ�õ��������������ļ��ϱ��
		if (sn1!=sn2)				//���������ڲ�ͬ�ļ���,�ñ�����С��������һ����
		{
			cout << "  ��(" << u1 << "," << v1 << "),ȨΪ" << E[j].w << endl;
			k++;					//���ɱ�����1
			Union(sn1,sn2);			//�ϲ�
		}
		j++;						//ɨ����һ����
	}
}

int main()
{
	MatGraph g;
	int n=6,e=10;
	int v=0;
	int A[MAXV][MAXV]={{0,6,1,5,INF,INF}, {6,0,5,INF,3,INF}, {1,5,0,5,6,4}, 
		{5,INF,5,0,INF,2}, {INF,3,6,INF,0,6}, {INF,INF,4,2,6,0}};  //ͼ7.21(a)�ı�����
	cout << "����ͼ���ڽӾ���:\n";
	g.CreateMatGraph(A,n,e);
	cout << "ͼ���ڽӾ���:\n"; g.DispMatGraph();
	cout << "ͼ����С������:\n";
	Kruskal1(g);
	return 0;
}
