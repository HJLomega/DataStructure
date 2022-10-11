#include"MatGraph.cpp"								//����ͼ(�ڽӾ���)�Ļ��������㷨
#include<vector>
int Degree1(MatGraph &g,int v)	   					//����ͼ�ڽӾ���g���󶥵�v�Ķ�
{	int d=0;
	for (int j=0;j<g.n;j++)        					//ͳ�Ƶ�v�еķ�0�ǡ�Ԫ�ظ���
  		if (g.edges[v][j]!=0 && g.edges[v][j]!=INF)
      		d++;
	return d;
}
	
vector<int> Degree2(MatGraph &g,int v) 				//����ͼ�ڽӾ���g���󶥵�v�ĳ��Ⱥ����
{
	vector<int> ans={0,0};                       	//ans[0]�ۼƳ���,ans[1]�ۼ����
	for (int j=0;j<g.n;j++)        	    			//ͳ�Ƶ�v�еķ�0�ǡ�Ԫ�ظ���Ϊ����
  		if (g.edges[v][j]!=0 && g.edges[v][j]!=INF)
      		ans[0]++;
	for (int i=0;i<g.n;i++)            				//ͳ�Ƶ�v�еķ�0�ǡ�Ԫ�ظ���Ϊ���
  		if (g.edges[i][v]!=0 && g.edges[i][v]!=INF)
      		ans[1]++;
 	return ans;						    			//���س��Ⱥ����
}

int main()
{
	MatGraph g1,g2;
	int n=5,e=8;
	int a[MAXV][MAXV]={{0,1,0,1,1},{1,0,1,1,0},{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0}};
	g1.CreateMatGraph(a,n,e);
	printf("ͼG1(����ͼ)\n"); g1.DispMatGraph();
	printf("�����\n");
	for (int i=0;i<g1.n;i++)
		printf("  ����%d�Ķ�: %d\n",i,Degree1(g1,i));

	n=5; e=5;
	int b[MAXV][MAXV]={{0,8,INF,5,INF},{INF,0,3,INF,INF},{INF,INF,0,INF,6},{INF,INF,9,0,INF},{INF,INF,INF,INF,0}};	
	g2.CreateMatGraph(b,n,e);
	printf("ͼG2(����ͼ)\n"); g2.DispMatGraph();
	printf("�����\n");
	for (int i=0;i<g2.n;i++)
	{
		vector<int> ans=Degree2(g2,i);
		printf("  ����%d: ����=%d ���=%d ��=%d\n",i,ans[0],ans[1],ans[0]+ans[1]);
	}
	return 0;
}


