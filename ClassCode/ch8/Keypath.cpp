#include "AdjGraph.cpp"					//����ͼ�Ļ��������㷨
void TopSort(AdjGraph gobj)		//��������
{	int i,n=0;							//nΪ���������ж������
	int topseq[MAXV];					//�����������
	TopSort1(gobj.G,topseq,n);
	if (n<gobj.G->n)					//���������в������ж���ʱ
	{
		cout << "ͼ�д��ڻ�·,���ܽ�����������\n";
		return;
	}
	else
	{
		for (i=0;i<n;i++)
			cout << (char)(topseq[i]+'A') << " "; 
		cout << endl;
	}
}
void TopSort1(ALGraph *G,int topseq[],int &n)
//��TopSort��������,��������n�������ŵ���������topseq
{
	int i,j;
	int st[MAXV];						//����һ��˳��ջ
	int top=-1;							//ջ��ָ��Ϊtop
	ArcNode<T> *p;
	for (i=0;i<G->n;i++)				//���ж��������ó�ֵ0
		G->adjlist[i].indegree=0;
	for (i=0;i<G->n;i++)				//�����ж�������
	{	p=G->adjlist[i].firstarc;
		while (p!=NULL)
		{	G->adjlist[p->adjvex].indegree++;
			p=p->nextarc;
		}
	}
	for (i=0;i<G->n;i++)
		if (G->adjlist[i].indegree==0)	//���Ϊ0�Ķ����ջ
		{	top++;
			st[top]=i;
		}
	while (top>-1)						//ջ��Ϊ��ʱѭ��
	{	i=st[top];top--;				//��ջ
		topseq[n]=i; n++;
		p=G->adjlist[i].firstarc;		//�ҵ�һ�����ڵ�
		while (p!=NULL)
		{	j=p->adjvex;
			G->adjlist[j].indegree--;
			if (G->adjlist[j].indegree==0)	//���Ϊ0�����ڶ����ջ
			{	top++;
				st[top]=j;
			}
			p=p->nextarc;					//����һ�����ڵ�
		}
	}
}
template <typename T>
bool KeyPath(ALGraph<T> *G,int &inode,int &enode,KeyNode keynode[],int &d)
//��ͼ�ڽӱ�G�������Դ��inode�����enode�Ĺؼ��keynode[0..d]
{	int topseq[MAXV];						//topseq���ڴ����������
	int n=0;								//nΪ���������еĶ�����
	int i,w;
	ArcNode<T> *p;
	TopSort1(G,topseq,n);					//����ǰ������������㷨������������
	if (n<G->n) return false;				//���ܲ�����������ʱ����false
	inode=topseq[0];						//���Դ��
	enode=topseq[n-1];						//������
	int ve[MAXV];							//�¼������翪ʼʱ��
	int vl[MAXV];							//�¼�����ٿ�ʼʱ��
	for (i=0;i<n;i++) ve[i]=0;				//�Ƚ������¼���ve�ó�ֵΪ0
	for (i=0;i<n;i++)						//���������������¼������翪ʼʱ��
	{	p=G->adjlist[i].firstarc;
		while (p!=NULL)						//����ÿһ���߼��
		{	w=p->adjvex;
			if (ve[i]+p->weight>ve[w])		//�������
				ve[w]=ve[i]+p->weight;
			p=p->nextarc;
		}
	 }
	for (i=0;i<n;i++)						//�Ƚ������¼���vlֵ��Ϊ���ֵ
		vl[i]=ve[enode];
	for (i=n-2;i>=0;i--)					//���������������¼�����ٿ�ʼʱ��
	{	p=G->adjlist[i].firstarc;
		while (p!=NULL)
		{	w=p->adjvex;
			if (vl[w]-p->weight<vl[i])		//����С��
				vl[i]=vl[w]-p->weight; 
			p=p->nextarc;
		}
	}
	d=-1;									//d���keynode�еĹؼ���±�,�ó���Ϊ-1
	for (i=0;i<n;i++)						//��ؼ��
	{	p=G->adjlist[i].firstarc;
		while (p!=NULL)
		{	w=p->adjvex;
			if (ve[i]==vl[w]-p->weight)		//(i��w)��һ���ؼ��
			{
				d++; keynode[d].ino=i; keynode[d].eno=w;
			}
			p=p->nextarc;
		}
	}
	return true;
}
template <typename T>
void DispKeynode(GraphClass<T> &gobj)
{
	int inode,enode,d,i;
	KeyNode keynode[MAXV];
	if (KeyPath(gobj.G,inode,enode,keynode,d))
	{
		cout << "��Դ��" << inode << "�����" << enode << "�Ĺؼ��:";
		for (i=0;i<=d;i++)
			cout << "(" << char(keynode[i].ino+'A') << "," << char(keynode[i].eno+'A') << ")  ";
		cout << endl;
	}
	else cout << "������ؼ��\n";
}
void main()
{
	GraphClass<int> gobj;
	int n=9,e=11;
	int A[MAXV][MAXV]={
		{ 0,  6,  4,  5 ,INF,INF,INF,INF,INF},
		{INF, 0, INF,INF, 1 ,INF,INF,INF,INF},
		{INF,INF, 0 ,INF, 1 ,INF,INF,INF,INF},
		{INF,INF,INF, 0 ,INF,INF,INF, 2 ,INF},
		{INF,INF,INF,INF, 0 , 9 , 7 ,INF,INF},
		{INF,INF,INF,INF,INF, 0 ,INF,INF, 2 },
		{INF,INF,INF,INF,INF,INF, 0 ,INF, 4 },
		{INF,INF,INF,INF,INF,INF,INF, 0 , 4 },
		{INF,INF,INF,INF,INF,INF,INF,INF, 0 }};	//ͼ7.32�ı�����
	cout << "����gobjͼ���ڽӱ�:\n";
	gobj.CreateALGraph(A,n,e);
	cout << "gobjͼ���ڽӱ�:\n"; gobj.DispALGraph();
	DispKeynode(gobj);
	cout << "�������д�����ͼ\n";
}
