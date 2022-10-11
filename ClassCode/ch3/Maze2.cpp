#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MAX=10;							//�Թ������С����� 
int dx[]={-1,0,1,0};                       	//x�����ƫ����
int dy[]={0,1,0,-1};                       	//y�����ƫ����
int mg[MAX][MAX]={{0,1,0,0},{0,0,1,1},{0,1,0,0},{0,0,0,0}};
int m=4,n=4;
struct Box									//�����з���Ԫ������ 
{
	int i;									//������к�
	int j;									//������к�
	Box *pre;								//��·������һ����ĵ�ַ
	Box() {}								//���캯��
	Box(int i1,int j1)						//���ع��캯��
	{
		i=i1;
		j=j1;
		pre=NULL;
	}
};
void disppath(queue<Box *> &qu)				//���һ���Թ�·��
{	vector<Box> apath;							//���һ���Թ�·��
	Box *b;
	b=qu.front();									//�Ӷ�ͷ��ʼ����ڷ�������
	while (b!=NULL)
	{	apath.push_back(Box(b->i,b->j));			//�������ķ�����ӵ�apath��
		b=b->pre;
	}
	cout << "һ���Թ�·��: ";
	for (int i=apath.size()-1;i>=0;i--)				//�����������һ�������Թ�·��
		cout << "[" << apath[i].i << "," << apath[i].j << "]  "; 
	cout << endl;
}
bool mgpath(int xi,int yi,int xe,int ye)			//��һ����(xi,yi)��(xe,ye)���Թ�·��
{	Box *b,*b1;
	queue<Box *> qu;							//����һ������qu
	b=new Box(xi,yi);							//������ڵĶ���b
	qu.push(b);									//��ڶ���b����,��pre��ΪNULL
	mg[xi][yi]=-1;								//Ϊ�������������ڷ�����mgֵΪ-1
	while (!qu.empty())							//�Ӳ���ʱѭ��
	{	b=qu.front();								//ȡ��ͷ����b
		if (b->i==xe && b->j==ye)				//�ҵ��˳���,���·��
		{	disppath(qu);						//���һ���Թ�·��
			return true;							//�ҵ�һ���Թ�·���󷵻�true
		}
		qu.pop();								//���ӷ���b
		for (int di=0;di<4;di++)					//ѭ��ɨ��ÿ����λ,��ÿ�����ߵķ������
		{	int i=b->i+dx[di];   				//��b��di��λ�����ڷ���(i,j)
			int j=b->j+dy[di];
			if (i>=0 && i<m && j>=0 && j<n && mg[i][j]==0)
			{	b1=new Box(i,j);					//(i,j)������Ч�ҿ��ߣ���������ж���b1
				b1->pre=b;						//�������ڷ������,����preָ��ǰ������
				qu.push(b1);
				mg[i][j]=-1;						//Ϊ�������������ڷ�����mgֵΪ-1
			}
		}
	}
	return false;									//δ�ҵ��κ�·��ʱ����false
}
int main()
{
	int xi=0,yi=0,xe=3,ye=3;
	printf("��(%d,%d)��(%d,%d)���Թ�·��\n",xi,yi,xe,ye);
	if (!mgpath(xi,yi,xe,ye))
		cout << "�������Թ�·��\n";
	return 0;
}

