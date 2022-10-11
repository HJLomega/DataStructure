#include <iostream>
using namespace std; 
#ifndef MAXV
#define MAXV 100										//ͼ�����Ķ�����
#define INF 0x3f3f3f3f								//��INF��ʾ
#endif 

struct ArcNode										//�߽������ 
{	int adjvex;										//�ڽӵ� 
	int weight;										//Ȩֵ 
	ArcNode *nextarc;								//ָ����һ���ߵı߽�� 
};
struct HNode										//ͷ������� 
{
	string info;									//������Ϣ
	ArcNode *firstarc;								//ָ���һ���ߵı߽��
};
class AdjGraph										//ͼ�ڽӱ���
{
public:
	HNode adjlist[MAXV];							//ͷ�������
	int n,e;										//������������
	AdjGraph()										//���캯��
	{
		for (int i=0;i<MAXV;i++)					//ͷ����firstarc��Ϊ�� 
			adjlist[i].firstarc=NULL;
	}
	~AdjGraph()										//��������,�ͷ�ͼ���ڽӱ�ռ�
	{
		ArcNode *pre,*p;
		for (int i=0;i<n;i++)						//�������е�ͷ���
		{
			pre=adjlist[i].firstarc;
			if (pre!=NULL)
			{
				p=pre->nextarc;
				while (p!=NULL)						//�ͷ�adjlist[i]�����б߽��ռ�
				{
					delete pre;
					pre=p; p=p->nextarc; 			//pre��pָ��ͬ������ 
				}
				delete pre;
			}
		}
	}
	void CreateAdjGraph(int a[][MAXV],int n,int e)	//ͨ��������a��������n�ͱ���e������ͼ���ڽӱ�
	{
		ArcNode *p;
		this->n=n; this->e=e;						//�ö������ͱ���
		for (int i=0;i<n;i++)						//����ڽӾ�����ÿ��Ԫ��
			for (int j=n-1;j>=0;j--)
				if (a[i][j]!=0 && a[i][j]!=INF)		//����һ����
				{
					p=new ArcNode();				//����һ�����p
					p->adjvex=j;
					p->weight=a[i][j]; 
					p->nextarc=adjlist[i].firstarc;	//����ͷ�巨����p
					adjlist[i].firstarc=p;
				}
	}
	void DispAdjGraph()								//���ͼ���ڽӱ�
	{
		ArcNode *p;
		for (int i=0;i<n;i++)						//����ÿ��ͷ��� 
		{
			printf("   [%d]",i);
			p=adjlist[i].firstarc;					//pָ���һ���ڽӵ�
			if (p!=NULL)  printf("��");
			while (p!=NULL)							//������i�������� 
			{
				printf(" (%d,%d)",p->adjvex,p->weight);
				p=p->nextarc;						//p������һ���ڽӵ�
			}
			printf("\n");
		}
	}
};
/* 
int main()
{
	AdjGraph G;
	int n=5,e=5;
	int A[MAXV][MAXV]={{0,8,INF,5,INF},{INF,0,3,INF,INF},{INF,INF,0,INF,6},{INF,INF,9,0,INF},{INF,INF,INF,INF,0}};	
	G.CreateAdjGraph(A,n,e);
	cout << "ͼ���ڽӱ�:\n"; G.DispAdjGraph();
	cout << "����ͼ\n";
	return 0;
}
*/
