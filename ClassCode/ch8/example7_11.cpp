#include "Graph.cpp"					//����ͼ�Ļ��������㷨
int visited[MAXV];						//ȫ�ֱ�������
struct QUEUE							//��ѭ����������
{	int no;								//������
	int parent;							//ǰһ�������ڶ����е�λ��
};
template <typename T>
void ShortPath(GraphClass<T> &gobj,int u,int v)
//����Ӷ���u��v��һ����̼�·��
{
	ArcNode<T> *p; int w,i;
	int spath[MAXV],d=-1;				//���u��v�����·��,dΪ��·������
	QUEUE qu[MAXV];						//��ѭ������
	int front=-1,rear=-1;				//���е�ͷ��βָ��
	for (i=0;i<gobj.G->n;i++) visited[i]=0;	//���ʱ���ó�ֵ0
	rear++;								//����u����
	qu[rear].no=u; qu[rear].parent=-1;	//����˫����Ϊ-1
	visited[u]=1;						//�ö���u�ѷ���
	while (front!=rear)					//�Ӳ���ѭ��
	{	front++;						//���Ӷ���w
		w=qu[front].no;
		if (w==v)						//�ҵ�vʱ���·��֮�沢�˳�
		{	i=front;					//ͨ�����������·��
			while (qu[i].parent!=-1)
			{	d++; spath[d]=qu[i].no;
				i=qu[i].parent;
			}
			d++; spath[d]=qu[i].no;
			for (i=d;i>=0;i--)
				cout << spath[i] << " ";
			cout << endl;
			break;							//�ҵ�·�����˳�whileѭ��
		}
		p=gobj.G->adjlist[w].firstarc;		//��w�ĵ�һ���ڽӵ�
		while (p!=NULL)
		{	if (visited[p->adjvex]==0)
			{	visited[p->adjvex]=1;
				rear++;						//��w��δ���ʹ����ڽӵ����
				qu[rear].no=p->adjvex;
				qu[rear].parent=front;		//���Ӷ����˫����Ϊfront
			}
			p=p->nextarc;					//��w����һ���ڽӵ�
		}
	}
}


void main()
{
	GraphClass<int> gobj;
	int n=6,e=9;
	int u=0,v=5;
	int A[MAXV][MAXV]={{0,1,0,1,0,0},{0,0,0,0,0,1},{0,1,0,0,0,1},
	{0,1,0,0,1,0},{0,1,0,0,0,1},{0,0,0,0,0,0}}; 	//ͼ7.15�ı�����
	cout << "����gobjͼ���ڽӱ�:\n";
	gobj.CreateALGraph(A,n,e);
	cout << "gobjͼ���ڽӱ�:\n"; gobj.DispALGraph();
	cout << "gobjͼ�дӶ���" << u << "������" << v << "һ�����·��:";
	ShortPath(gobj,u,v);
	cout << "�������д�����ͼ\n";
}