#include"AdjGraph.cpp"					//����ͼ(�ڽӱ�)�Ļ��������㷨
#include<cstring>
#include<vector>

int visited[MAXV];						//ȫ������ 
void FindaPath11(AdjGraph &G,int u,int v,vector<int> path)	//��FindaPath1����
{
	visited[u]=1;
	path.push_back(u);                  //����u���뵽·����
	if (u==v)							//�ҵ�һ��·�������������
  	{	for (int i=0;i<path.size();i++)
      		printf("%d ",path[i]);
     	printf("\n");
     	return;
	}
	ArcNode *p=G.adjlist[u].firstarc;
	while (p!=NULL)
	{
		int w=p->adjvex;				//�ҵ�u���ڽӵ�w
		if (visited[w]==0)				//������wû�з���
			FindaPath11(G,w,v,path);	//��w������������ 
		p=p->nextarc;
	}
}

void FindaPath1(AdjGraph &G,int u,int v)	//�ⷨ1����u��v��һ����·��
{
	memset(visited,0,sizeof(visited));
 	vector<int> path;						//path���һ��·��
 	FindaPath11(G,u,v,path);
}


void FindaPath21(AdjGraph &G,int u,int v,vector<int> path,vector<int> &res)	//��FindaPath2����
{
	visited[u]=1;
	path.push_back(u);                  //����u���뵽·����
	if (u==v)							//�ҵ�һ��·�������������
  	{
  		res=path;
     	return;
	}
	ArcNode *p=G.adjlist[u].firstarc;
	while (p!=NULL)
	{
		int w=p->adjvex;				//�ҵ�u���ڽӵ�w
		if (visited[w]==0)				//������wû�з���
			FindaPath11(G,w,v,path);	//��w������������ 
		p=p->nextarc;
	}
}

void FindaPath2(AdjGraph &G,int u,int v)	//�ⷨ2����u��v��һ����·��
{
	memset(visited,0,sizeof(visited));
 	vector<int> path;						//path���һ��·��
 	vector<int> res;
 	FindaPath21(G,u,v,path,res);
	for (int i=0;i<res.size();i++)
      	printf("%d ",res[i]);
    printf("\n");
}

int main()
{
	AdjGraph G;
	int n=6,e=9;
	int a[MAXV][MAXV]={{0,1,0,1,0,0},{0,0,0,0,0,1},{0,1,0,0,0,1},{0,1,0,0,1,0},{0,1,0,0,0,1},{0,0,0,0,0,0}};
	G.CreateAdjGraph(a,n,e);
	printf("ͼG�ڽӱ�\n"); G.DispAdjGraph();
	int u=0,v=5;
	printf("�����\n");
	printf("  ����%d������%d·��: ",u,v); FindaPath1(G,u,v);
	u=0; v=4;
	printf("  ����%d������%d·��: ",u,v); FindaPath2(G,u,v);
	return 0;
}


