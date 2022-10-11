#include"AdjGraph.cpp"					//����ͼ(�ڽӱ�)�Ļ��������㷨
#include<cstring>
#include<vector>
#include<queue>
//--------------�ⷨ1��ʼ------------------ 
struct QNode								//����Ԫ������
{
	int v;									//������ 
	int dis;								//Դ�㵽��ǰ��������·������ 
	QNode() {}								//���캯�� 
	QNode(int v,int dis)					//���ع��캯��
	{
		this->v=v;
		this->dis=dis;
	}
};
int Shortdist1(AdjGraph &G,int u,int v)      	//��u��v�����·������ 
{
	int visited[MAXV];							//���ʱ������
	memset(visited,0,sizeof(visited));
	queue<QNode> qu;                     		//����һ������qu
 	visited[u]=1;                          		//���ѷ��ʱ��
	qu.push(QNode(u,0));				  		//��ʼ��u(����Ϊ0)����
 	while (!qu.empty())                    	  	//�Ӳ���ѭ��
  	{	QNode e=qu.front(); qu.pop();		   	//����һ��Ԫ��e
     	if (e.v==v)						    	//�ҵ�����v
        	return e.dis;						//����u��v�����·������
		ArcNode *p=G.adjlist[e.v].firstarc;
		while (p!=NULL)
		{	int w=p->adjvex;					//�ҵ�u���ڽӵ�w
			if (visited[w]==0)					//������wû�з���
			{
				visited[w]=1;                  	//���ѷ��ʱ��
				qu.push(QNode(w,e.dis+1));		//�ڽӵ�w���� 
			}
			p=p->nextarc;
		}
	}
	return INF;									//û��·������� 
}
//--------------�ⷨ1����------------------ 


//--------------�ⷨ2��ʼ------------------ 

int Shortdist2(AdjGraph& G,int u,int v)		//�ⷨ2����u��v�����·������
{	int visited[MAXV];							//���ʱ������
	memset(visited,0,sizeof(visited));
	int ans=0;									//������·������(��ʼʱΪ0)
	queue<int> qu;								//����һ������qu
	visited[u]=1;									//���ѷ��ʱ��
	qu.push(u);										//��ʼ��u����
	while (!qu.empty())							//�Ӳ���ѭ��
	{
		int n=qu.size();					//�����qu��Ԫ�ظ���n
		for(int i=0;i<n;i++)					//ѭ��n�� 
		{
			u=qu.front(); qu.pop();				//����һ������u 
			if (u==v)								//�ҵ�����v
				return ans;							//����u��v�����·������
			ArcNode* p=G.adjlist[u].firstarc;
			while (p!=NULL)
			{	int w=p->adjvex;					//�ҵ�u���ڽӵ�w
				if (visited[w]==0)					//������wû�з���
				{	visited[w]=1; 					//���ѷ��ʱ��
					qu.push(w);					//�ڽӵ�w����
				}
				p=p->nextarc;
			}
		}
		ans++; 							//һ��Ķ�����չ��ans��1
	}
	return INF;									//û��·������� 
}

//--------------�ⷨ2����------------------ 



//--------------����������ȱ����㷨------------------ 


int Shortdist3(AdjGraph& G,vector<int>&U,int v)		//��U�ж��㵽v�����·������
{
	int visited[MAXV];							//���ʱ������
	memset(visited,0,sizeof(visited));
	int ans=0;									//������·������(��ʼʱΪ0)
	queue<int> qu;								//����һ������qu
	for(int i=0;i<U.size();i++)					//��U���������ж�����Ϊ������ 
	{	visited[U[i]]=1;						//���ѷ��ʱ��
		qu.push(U[i]);							//��ʼ��U[i]����
	}
	while (!qu.empty())							//�Ӳ���ѭ��
	{
		int n=qu.size();					//�����qu��Ԫ�ظ���n
		for(int i=0;i<n;i++)					//ѭ��n�� 
		{
			int u=qu.front(); qu.pop();				//����һ������u 
			if (u==v)								//�ҵ�����v
				return ans;							//����u��v�����·������
			ArcNode* p=G.adjlist[u].firstarc;
			while (p!=NULL)
			{	int w=p->adjvex;					//�ҵ�u���ڽӵ�w
				if (visited[w]==0)					//������wû�з���
				{	visited[w]=1; 					//���ѷ��ʱ��
					qu.push(w);					//�ڽӵ�w����
				}
				p=p->nextarc;
			}
		}
		ans++; 							//һ��Ķ�����չ��ans��1
	}
	return INF;									//û��·������� 
}
	
//--------------�ⷨ2����------------------ 

int main()
{
	AdjGraph G;
	int n=6,e=9;
	int a[MAXV][MAXV]={{0,1,0,1,0,0},{0,0,0,0,0,1},{0,1,0,0,0,1},{0,1,0,0,1,0},{0,1,0,0,0,1},{0,0,0,0,0,0}};
	G.CreateAdjGraph(a,n,e);
	printf("ͼG�ڽӱ�\n"); G.DispAdjGraph();
	printf("�����\n");
	int u=0;
	printf("�ⷨ1\n");
	for (int v=0;v<n;v++)
		printf("  ����%d��%d�����·������: %d\n",u,v,Shortdist1(G,u,v));
	printf("�ⷨ2\n");
	for (int v=0;v<n;v++)
		printf("  ����%d��%d�����·������: %d\n",u,v,Shortdist2(G,u,v));
		
	printf("���㼯->һ������\n");
	vector<int> U={0,2,3};
	int v=5;
	printf("  U���㼯��%d�����·������: %d\n",v,Shortdist3(G,U,v));
	
	return 0;
}


