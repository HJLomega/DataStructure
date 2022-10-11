#include <iostream>
#include<vector>
#include<cstring>
using namespace std; 
const int MAXV=100;							//ͼ�����Ķ�����
const int MAXE=200;							//ͼ�����ı���
const int INF=0x3f3f3f3f;					//��INF��ʾ
int head[MAXV];								//ͷ�������
struct Edge									//�߽������ 
{
	int adjvex;								//�ڽӵ�
	int weight;								//Ȩֵ
	int next;								//��һ���߽����edges�����е��±�
} edges[MAXE];								//�߽������
int n;										//������
int cnt;									//edges����Ԫ�ظ���
void addedge(int u,int v,int w)				//���һ�������<u,v>:w
{
    edges[cnt].adjvex=v;
    edges[cnt].weight=w;
    edges[cnt].next=head[u];				//��edges[cnt]�߽����뵽head[u]�ı�ͷ 
    head[u]=cnt;
    cnt++;									//edges����Ԫ�ظ�����1 
}
void init()									//��ʼ�� 
{
	cnt=0;									//cnt��0��ʼ 
	memset(head,0xffff,sizeof(head));		//����Ԫ�س�ʼ��Ϊ-1
}
	
void CreateAdjGraph(vector<vector<int> > a,int n)	//ͨ��������a�Ͷ�����n�������ڽӱ�
{	//a��ÿ��Ԫ�ر�ʾһ����<u,v,w>
	init(); 								//��ʼ�����ڽӱ� 
	for (int i=0;i<a.size();i++)
		addedge(a[i][0],a[i][1],a[i][2]);	//����һ���� 
}
void DispAdjGraph()							//���ͼ���ڽӱ�
{
	for (int i=0;i<n;i++)					//����ÿ��ͷ��� 
	{
		printf("   [%d]",i);
		for(int j=head[i];j!=-1;j=edges[j].next)
			printf(" (%d,%d,%d)",edges[j].adjvex,edges[j].weight,edges[j].next);
		printf("\n");
	}
}
 
int main()
{
	n=5;
	vector<vector<int> > a={{0,1,8},{0,3,5},{1,2,3},{2,4,6},{3,2,9}};
	CreateAdjGraph(a,n);
	cout << "ͼ���ڽӱ�:\n"; DispAdjGraph();
	
	printf("head\n");
	for (int i=0;i<n;i++)
		printf("head[%d]=%d\n",i,head[i]);
	printf("edges\n");
	for (int i=0;i<cnt;i++)
		printf("%d: (%d,%d,%d)\n",i,edges[i].adjvex,edges[i].weight,edges[i].next);
	return 0;
}

