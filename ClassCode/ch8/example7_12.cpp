#include "Graph.cpp"					//����ͼ�Ļ��������㷨
int visited[MAXV];						//ȫ�ֱ�������
template <typename T>
int Maxdist(GraphClass<T> &gobj,int v)	//�����붥��v��Զ�Ķ���
{
	ArcNode<T> *p; int i,w,k=0;
	int qu[MAXV];						//����ѭ������
	int front=0,rear=0;					//���м��ס�βָ��
	for (i=0;i<gobj.G->n;i++) visited[i]=0;	//��ʼ�����ʱ�־����
	rear++; qu[rear]=v;					//����v����
	visited[v]=1;						//���v�ѷ���
	while (rear!=front)
	{	front=(front+1) % MAXV;
		k=qu[front];					//�������
		p=gobj.G->adjlist[k].firstarc;	//�ҵ�1���ڽӵ�
		while (p!=NULL)					//����δ���ʹ����ڽӵ����
		{	w=p->adjvex;
			if (visited[w]==0)			//��wδ���ʹ�
			{	visited[w]=1;			//������w����
				rear=(rear+1) % MAXV;
				qu[rear]=w; 
			}
			p=p->nextarc;				//����һ���ڽӵ�
		}
	}
	return k;
}

void main()
{
	GraphClass<int> gobj,gobj1;
	int n=6,e=9;
	int v=0;
	int A[MAXV][MAXV]={{0,1,0,1,0,0},{0,0,0,0,0,1},{0,1,0,0,0,1},
		{0,1,0,0,1,0},{0,1,0,0,0,1},{0,0,0,0,0,0}}; 	//ͼ7.15�ı�����
	int B[MAXV][MAXV]={{0,1,0,1,0,0},{1,0,1,1,1,1},{0,1,0,0,0,1},
		{1,1,0,0,1,0},{0,1,0,1,0,1},{0,0,1,0,1,0}}; 	//ͼ7.15�ı�����
	cout << "����gobjͼ���ڽӱ�:\n";
	gobj.CreateALGraph(A,n,e);
	cout << "gobjͼ���ڽӱ�:\n"; gobj.DispALGraph();
	cout << "gobjͼ�о��붥��" << v << "��Զ�Ķ�����" << Maxdist(gobj,v) << endl;
	cout << "����gobj1ͼ���ڽӱ�:\n";
	gobj1.CreateALGraph(B,n,e);
	cout << "gobj1ͼ���ڽӱ�:\n"; gobj1.DispALGraph();
	cout << "gobj1ͼ�о��붥��" << v << "��Զ�Ķ�����" << Maxdist(gobj1,v) << endl;
	cout << "�������д�����ͼ\n";
}