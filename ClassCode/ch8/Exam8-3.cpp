#include"AdjGraph.cpp"						//����ͼ(�ڽӱ�)�Ļ��������㷨
#include<vector>
int Degree1(AdjGraph &G,int v)	   			//����ͼ�ڽӱ�G���󶥵�v�Ķ�
{	int d=0;
	ArcNode *p=G.adjlist[v].firstarc;
	while (p!=NULL)       					//ͳ�Ƶ�����v�б߽�����
  	{	d++;
  		p=p->nextarc;
  	}
	return d;
}
	
vector<int> Degree2(AdjGraph &G,int v) 		//����ͼ�ڽӱ�G���󶥵�v�ĳ��Ⱥ����
{
	vector<int> ans={0,0};                  //ans[0]�ۼƳ���,ans[1]�ۼ����
	ArcNode *p=G.adjlist[v].firstarc;
	while (p!=NULL)       					//ͳ�Ƶ�����v�б߽�����
  	{	ans[0]++;
  		p=p->nextarc;
  	}
  	for (int i=0;i<G.n;i++)					//ͳ������adjvexΪv�ı߽�����Ϊv�����
  	{
  		p=G.adjlist[i].firstarc;
  		while (p!=NULL)
  		{
  			if (p->adjvex==v)
  			{
  				ans[1]++;
  				break;						//һ�����������ֻ��һ�������Ľ�� 
  			}
  			p=p->nextarc;
  		}
  	}
 	return ans;						   		//���س��Ⱥ����
}

int main()
{
	AdjGraph G1,G2;
	int n=5,e=8;
	int a[MAXV][MAXV]={{0,1,0,1,1},{1,0,1,1,0},{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0}};
	G1.CreateAdjGraph(a,n,e);
	printf("ͼG1(����ͼ)\n"); G1.DispAdjGraph();
	printf("�����\n");
	for (int i=0;i<G1.n;i++)
		printf("  ����%d�Ķ�: %d\n",i,Degree1(G1,i));

	n=5; e=5;
	int b[MAXV][MAXV]={{0,8,INF,5,INF},{INF,0,3,INF,INF},{INF,INF,0,INF,6},{INF,INF,9,0,INF},{INF,INF,INF,INF,0}};	
	G2.CreateAdjGraph(b,n,e);
	printf("ͼG2(����ͼ)\n"); G2.DispAdjGraph();
	printf("�����\n");
	for (int i=0;i<G2.n;i++)
	{
		vector<int> ans=Degree2(G2,i);
		printf("  ����%d: ����=%d ���=%d ��=%d\n",i,ans[0],ans[1],ans[0]+ans[1]);
	}
	return 0;
}


