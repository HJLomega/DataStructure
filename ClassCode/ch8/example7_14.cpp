#include "Graph.cpp"					//����ͼ�Ļ��������㷨
int visited[MAXV];						//ȫ�ֱ�������
template <typename T>
void DFSTree(GraphClass<T> &gobj,int v)			//����ͼ���������������
{
	int i;
	for (i=0;i<gobj.G->n;i++) visited[i]=0; 	//��ʼ�����ʱ�־����
	DFS2(gobj.G,v);
}
template <typename T>
void DFS2(ALGraph<T> *G,int v)			//��DFSTree���ò����������������
{
	ArcNode<T> *p; int w;
	visited[v]=1;						//���ѷ��ʱ��
	p=G->adjlist[v].firstarc;			//pָ�򶥵�v�ĵ�һ���ڽӵ�
	while (p!=NULL)
	{	w=p->adjvex; 
		if (visited[w]==0)				//��w����δ����,�ݹ������
		{
			cout << "(" << v << "," << w << ")  ";	//���DFS��������һ����
			DFS2(G,w);
		}
		p=p->nextarc;					//p��Ϊ����v����һ���ڽӵ�
	}
}
template <typename T>
void BFSTree(GraphClass<T> &gobj,int v)			//����ͼ�Ĺ������������
{
	int i;
	for (i=0;i<gobj.G->n;i++) visited[i]=0; 	//��ʼ�����ʱ�־����
	BFS2(gobj.G,v);
}
template <typename T>
void BFS2(ALGraph<T> *G,int v)			//��BFSTree���ò����������������
{	ArcNode<T> *p; int w,i;
	int qu[MAXV];
	int front=0,rear=0;				//����ѭ�����в���ʼ����ͷ��β
	for (i=0;i<G->n;i++) visited[i]=0;	//���ʱ�־�����ʼ��
	visited[v]=1; 						//���ѷ��ʱ��
	rear=(rear+1) % MAXV; qu[rear]=v;	//����v����
	while (front!=rear)					//�����в���ʱѭ��
	{	front=(front+1) % MAXV;
		w=qu[front];						//���Ӳ�����w
		p=G->adjlist[w].firstarc;			//���붥��w�ڽӵĵ�һ������
		while (p!=NULL)
		{	
			if (visited[p->adjvex]==0)		//����ǰ�ڽӶ���δ������
			{
				cout << "(" << w << "," << p->adjvex << ")  ";	//���BFS��������һ����
				visited[p->adjvex]=1;		//�øö����ѱ����ʵı�־
				rear=(rear+1) % MAXV;		//�ö������
				qu[rear]=p->adjvex;
			}
			p=p->nextarc;					//����һ���ڽӶ���
		}
	}
}
void main()
{
	GraphClass<int> gobj;
	int n=10,e=12;
	int v=0;
	int A[MAXV][MAXV]={
		{0,1,1,1,0,0,0,0,0,0},
		{1,0,0,0,1,1,0,0,0,0},
		{1,0,0,1,0,1,1,0,0,0},
		{1,0,1,0,0,0,0,1,0,0},
		{0,1,0,0,0,0,0,0,0,0},
		{0,1,1,0,0,0,0,0,0,0},
		{0,0,1,0,0,0,0,1,1,1},
		{0,0,0,1,0,0,1,0,0,0},
		{0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,0,1,0,0,0}};  //ͼ7.21�ı�����
	cout << "����gobjͼ���ڽӱ�:\n";
	gobj.CreateALGraph(A,n,e);
	cout << "gobjͼ���ڽӱ�:\n"; gobj.DispALGraph();
	cout << "�Ӷ���" << v << "�������������������:"; DFSTree(gobj,v); cout << endl;
	cout << "�Ӷ���" << v << "�����Ĺ������������:"; BFSTree(gobj,v); cout << endl;
	cout << "�������д�����ͼ\n";
}