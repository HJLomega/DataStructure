#include "Graph.cpp"					//����ͼ�Ļ��������㷨
//ͼ��������ȱ���
int visited[MAXV];						//ȫ������
template <typename T>
void DFS(GraphClass<T> &gobj,int v)		//ͼ����gobj��������ȱ���
{
	int i;
	for (i=0;i<gobj.G->n;i++) visited[i]=0;	//visited����Ԫ�ؾ���Ϊ0
	DFS1(gobj.G,v);
}
template <typename T>
void DFS1(ALGraph<T> *G,int v)			//��DFS���ý���������ȱ���
{
	int w;
	ArcNode<T> *p;
	visited[v]=1;						//���ѷ��ʱ��
	//cout << v << " ";					//��������ʶ���ı��
	p=G->adjlist[v].firstarc;			//pָ�򶥵�v�ĵ�һ���ڽӵ�
	while (p!=NULL)
	{	w=p->adjvex;
		if (visited[w]==0) DFS1(G,w);	//��w����δ����,�ݹ������
		p=p->nextarc;					//p��Ϊ��һ���ڽӵ�
	}
}
//ͼ�Ĺ�����ȱ���
template <typename T>
void BFS(GraphClass<T> &gobj,int v)			//ͼ����gobj�Ĺ�����ȱ���
{
	int i;
	for (i=0;i<gobj.G->n;i++) visited[i]=0;	//visited����Ԫ�ؾ���Ϊ0
	BFS1(gobj.G,v);
}
template <typename T>
void BFS1(ALGraph<T> *G,int v)				//��BFS���ý��й�����ȱ���
{	ArcNode<T> *p; int w;
	int qu[MAXV];							//����һ��ѭ������
	int front=0,rear=0;						//ѭ�����ж�ͷ��β��ʼ��
	//cout << v << " "; visited[v]=1;			//������ʶ��㲢���ѷ��ʱ��
	rear=(rear+1) % MAXV; qu[rear]=v;		//v����
	while (front!=rear)						//�����в���ʱѭ��
	{	front=(front+1) % MAXV;
		w=qu[front];						//���Ӳ�����w
		p=G->adjlist[w].firstarc;			//���붥��w�ڽӵĵ�һ������
		while (p!=NULL)
		{	if (visited[p->adjvex] == 0)	//����ǰ�ڽӶ���δ������
			{	cout << p->adjvex << " ";	//�������ڶ���
				visited[p->adjvex]=1;		//�øö����ѱ����ʵı�־
				rear=(rear+1) % MAXV;		//�ö������
				qu[rear]=p->adjvex;
			}
			p=p->nextarc;					//����һ���ڽӶ���
		}
	}
}
template <typename T>
bool Connect(GraphClass<T> &gobj)		//�ж�����ͼG����ͨ��
{	int i;
	bool flag=true;
	for (i=0;i<gobj.G->n;i++) visited[i]=0;	//visited����Ԫ�ؾ���Ϊ0
	DFS1(gobj.G,0);				//����DSF1�㷨,�Ӷ���0��ʼ������ȱ���
	for (i=0;i<gobj.G->n;i++)
		if (visited[i]==0)
		{	flag=false;
			break;
		}
	return flag;
}
void main()
{
	GraphClass<int> gobj;
	int n=5,e=8;
	int v=2;
	int A[MAXV][MAXV]={{0,1,0,1,1},{1,0,1,1,0},{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0}};
	cout << "����gobjͼ���ڽӱ�:\n";
	gobj.CreateALGraph(A,n,e);
	cout << "gobjͼ���ڽӱ�:\n"; gobj.DispALGraph();
	cout << "gobjͼ" << (Connect(gobj)?"��":"�Ƿ�") << "��ͨ��\n";
	cout << "�������д�����ͼ\n";
}