#include<iostream>
#include<vector>
using namespace std;
const int MAX=10;								//�Թ������С����� 
int dx[]={-1,0,1,0};                       		//x�����ƫ����
int dy[]={0,1,0,-1};                       		//y�����ƫ����
int mg[MAX][MAX]={{0,1,0,0},{0,0,1,1},{0,1,0,0},{0,0,0,0}};
int m=4,n=4;
int cnt=0;                               		//�ۼ��Թ�·����
class Box										//����ṹ������
{
public:
	int i;										//������к�
	int j;										//������к�
	Box(int i1,int j1):i(i1),j(j1) {}			//���ع��캯��
};

void mgpath(int xi,int yi,int xe,int ye,vector<Box> path)   //����Թ�·��Ϊ:(xi,yi)->(xe,ye)
{
	Box b(xi,yi);								//������ڷ���Ķ���b 
	path.push_back(b);							//��b��ӵ�·��path�� 
 	mg[xi][yi]=-1;						  		//mg[xi][yi]=-1
 	if (xi==xe && yi==ye)				    	//�ҵ��˳���,���һ���Թ�·��
  	{	cnt++;
   		printf("  �Թ�·��%d: ",cnt);				//�����cnt���Թ�·��
    	for (int k=0;k<path.size();k++)
    		printf("(%d,%d) ",path[k].i,path[k].j);
     	printf("\n");
   		mg[xi][yi]=0;                     		//�ӳ��ڻ��ˣ��ָ���mgֵ
     	return;
	}
 	else								  		//(xi,yi)���ǳ���
  	{	int di=0;
    	while (di<4)							//����(xi,yi)���ܵ�ÿ�����ڷ���(i,j)
      	{
		  	int i=xi+dx[di];					//��(xi,yi)��di��λ�����ڷ���(i,j)
			int j=yi+dy[di];
			if (i>=0 && i<m && j>=0 && j<n && mg[i][j]==0)
        		mgpath(i,j,xe,ye,path);   		//��(i,j)����ʱ,��(i,j)���������Թ�·��
			di++;								//��������(xi,yi)����һ�����ڷ���
		}
		mg[xi][yi]=0;                    		//(xi,yi)���������ڷ��鴦���꣬���˲��ָ�mgֵ
	}
}
int main()
{
	int xi=0,yi=0,xe=3,ye=3;
	printf("(%d,%d)��(%d,%d)�������Թ�·��\n",xi,yi,xe,ye);
	vector<Box> path;
	mgpath(xi,yi,xe,ye,path); 
	return 0;
}

