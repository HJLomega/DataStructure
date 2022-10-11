#include"AdjGraph.cpp"					//����ͼ(�ڽӱ�)�Ļ��������㷨
#include<cstring>
int visited[MAXV];						//ȫ������ 
bool HasPath1(AdjGraph &G,int u,int v)	//��HasPath��������
{
	visited[u]=1;
	ArcNode *p=G.adjlist[u].firstarc;
	while (p!=NULL)
	{
		int w=p->adjvex;				//�ҵ�u���ڽӵ�w
    	if (w==v)						//�ҵ�Ŀ���󷵻���
      		return true;	    		//��ʾu��v��·��
     	else if (visited[w]==0)			//������w 
		{	if (HasPath1(G,w,v))
				return true;
		}
		p=p->nextarc;
	}
	return false;
}

bool HasPath(AdjGraph &G,int u,int v)  	//�ж�u��v�Ƿ��м�·��
{
	memset(visited,0,sizeof(visited));
	return HasPath1(G,u,v);
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
	printf("  ����%d������%d·��: %s\n",u,v,HasPath(G,u,v)?"��":"û��");
	u=0; v=2;
	printf("  ����%d������%d·��: %s\n",u,v,HasPath(G,u,v)?"��":"û��");
	return 0;
}


