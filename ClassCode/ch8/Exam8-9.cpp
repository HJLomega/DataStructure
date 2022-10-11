#include"AdjGraph.cpp"					//����ͼ(�ڽӱ�)�Ļ��������㷨
#include<cstring>
#include<vector>

int visited[MAXV];							//ȫ������ 
void FindallPath11(AdjGraph &G,int u,int v,vector<int> path)	//��FindallPath1����
{
	visited[u]=1;
	path.push_back(u);                  	//����u���뵽·����
	if (u==v)								//�ҵ�һ��·�������������
  	{	for (int i=0;i<path.size();i++)
      		printf("  %d",path[i]);
     	printf("\n");
		visited[u]=0;						//����,����visited[u]Ϊ0 	
     	return;
	}
	ArcNode *p=G.adjlist[u].firstarc;
	while (p!=NULL)
	{
		int w=p->adjvex;					//�ҵ�u���ڽӵ�w
		if (visited[w]==0)					//������wû�з���
			FindallPath11(G,w,v,path);		//��w������������ 
		p=p->nextarc;
	}
	visited[u]=0;							//����,����visited[u]Ϊ0
}

void FindallPath1(AdjGraph &G,int u,int v)	//�ⷨ1����u��v�����м�·��
{
	memset(visited,0,sizeof(visited));
 	vector<int> path;						//path���һ��·��
 	FindallPath11(G,u,v,path);
}

int inpath[MAXV];                        		//ȫ������
vector<int> path;								//ȫ�ֱ���
void FindallPath21(AdjGraph &G,int u,int v)   	//��Findapath2��������
{
	if (u==v)									//Ҷ�ӽ�㣺�ҵ�һ��·�������
  	{	for (int i=0;i<path.size();i++)			//���·�� 
      		printf("  %d",path[i]);
     	printf("\n");
     	return;
	}
	ArcNode *p=G.adjlist[u].firstarc;			//��չu 
	while (p!=NULL)
	{
		int w=p->adjvex;						//�ҵ�u���ڽӵ�w
		if (inpath[w]==0)						//������w����path��
		{
      		path.push_back(w);             		//������w��ӵ�path��
        	inpath[w]=1;                     	//��w�Ѿ���path��
        	FindallPath21(G,w,v);      		 	//�ݹ����
        	path.pop_back();					//path���� 
        	inpath[w]=0;                    	//��w����path��
		}
		p=p->nextarc;
	}
}

void FindallPath2(AdjGraph &G,int u,int v) 	//�ⷨ2:��u��v�����м�·��
{
	memset(inpath,0,sizeof(inpath));		//��ʼ��inpath
 	path.push_back(u);                     	//������u��ӵ�path��
 	inpath[u]=1;                           	//��u�Ѿ���path��
 	FindallPath21(G,u,v);
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
	printf("  ����%d������%d������·��:\n",u,v); FindallPath2(G,u,v);
	u=0; v=4;
	printf("  ����%d������%d������·��:\n",u,v); FindallPath2(G,u,v);
	return 0;
}


