#include<iostream>
#include<vector>
using namespace std;
const int MAX=10;								//迷宫最大的行、列数 
int dx[]={-1,0,1,0};                       		//x方向的偏移量
int dy[]={0,1,0,-1};                       		//y方向的偏移量
int mg[MAX][MAX]={{0,1,0,0},{0,0,1,1},{0,1,0,0},{0,0,0,0}};
int m=4,n=4;
int cnt=0;                               		//累计迷宫路径数
class Box										//方块结构体类型
{
public:
	int i;										//方块的行号
	int j;										//方块的列号
	Box(int i1,int j1):i(i1),j(j1) {}			//重载构造函数
};

void mgpath(int xi,int yi,int xe,int ye,vector<Box> path)   //求解迷宫路径为:(xi,yi)->(xe,ye)
{
	Box b(xi,yi);								//建立入口方块的对象b 
	path.push_back(b);							//将b添加的路径path中 
 	mg[xi][yi]=-1;						  		//mg[xi][yi]=-1
 	if (xi==xe && yi==ye)				    	//找到了出口,输出一个迷宫路径
  	{	cnt++;
   		printf("  迷宫路径%d: ",cnt);				//输出第cnt条迷宫路径
    	for (int k=0;k<path.size();k++)
    		printf("(%d,%d) ",path[k].i,path[k].j);
     	printf("\n");
   		mg[xi][yi]=0;                     		//从出口回退，恢复其mg值
     	return;
	}
 	else								  		//(xi,yi)不是出口
  	{	int di=0;
    	while (di<4)							//处理(xi,yi)四周的每个相邻方块(i,j)
      	{
		  	int i=xi+dx[di];					//找(xi,yi)的di方位的相邻方块(i,j)
			int j=yi+dy[di];
			if (i>=0 && i<m && j>=0 && j<n && mg[i][j]==0)
        		mgpath(i,j,xe,ye,path);   		//若(i,j)可走时,从(i,j)出发查找迷宫路径
			di++;								//继续处理(xi,yi)的下一个相邻方块
		}
		mg[xi][yi]=0;                    		//(xi,yi)的所有相邻方块处理完，回退并恢复mg值
	}
}
int main()
{
	int xi=0,yi=0,xe=3,ye=3;
	printf("(%d,%d)到(%d,%d)的所有迷宫路径\n",xi,yi,xe,ye);
	vector<Box> path;
	mgpath(xi,yi,xe,ye,path); 
	return 0;
}

