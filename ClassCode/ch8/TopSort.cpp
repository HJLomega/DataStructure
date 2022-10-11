#include"AdjGraph.cpp"					//����ͼ���ڽӱ��Ļ��������㷨
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
void TopSort(AdjGraph &G)				//��������
{
	stack<int> st;						//����һ��ջ
	int ind[MAXV];            			//��¼ÿ����������
	memset(ind,0,sizeof(ind));
	ArcNode *p;
	for (int i=0;i<G.n;i++)					//�����ж�������
	{
		p=G.adjlist[i].firstarc;
		while (p!=NULL)					//������i�����г���
		{
			int w=p->adjvex;			//���������<i,w>
			ind[w]++;					//����w�������1
			p=p->nextarc;
		}
	}
	for (int i=0;i<G.n;i++)				//���������Ϊ0�Ķ����ջ
		if (ind[i]==0)
			st.push(i);
	while (!st.empty())					//ջ��Ϊ��ʱѭ��
	{	int i=st.top(); st.pop();			//��ջһ������i
		printf("%d ",i);				//������������е�һ������i
		p=G.adjlist[i].firstarc;		//�Ҷ���i�ĵ�һ���ڽӵ�
		while (p!=NULL)
		{	int w=p->adjvex;			//�ڽӵ�Ϊw 
			ind[w]--;					//����w����ȼ�1 
			if (ind[w]==0)				//���Ϊ0���ڽӵ�w��ջ
				st.push(w);
			p=p->nextarc;				//����һ���ڽӵ�
		}
	}
}

int main()
{
	AdjGraph G;
	int n=6,e=6;
	int A[MAXV][MAXV]={{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,0,0},{0,1,0,0,0,1},{0,0,0,1,0,0}};
	cout << "����Gͼ���ڽӱ�:\n";
	G.CreateAdjGraph(A,n,e);
	cout << "ͼG���ڽӱ�:\n"; G.DispAdjGraph();
	cout << "ͼG����������:\n";
	TopSort(G);
	return 0;
}
