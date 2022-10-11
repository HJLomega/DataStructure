#include <iostream>
using namespace std; 
#ifndef MAXV
#define MAXV 100										//图中最多的顶点数
#define INF 0x3f3f3f3f								//用INF表示
#endif 
class MatGraph						//图邻接矩阵类
{
public:
	int edges[MAXV][MAXV];			//邻接矩阵数组，假设元素为int类型
	int n,e;						//顶点数，边数
	string vexs[MAXV];				//存放顶点信息
	void CreateMatGraph(int a[][MAXV],int n,int e) //通过边数组a、顶点数n和边数e来建立图的邻接矩阵
	{
		this->n=n; this->e=e;				//置顶点数和边数
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				this->edges[i][j]=a[i][j];
	}
	void DispMatGraph()						//输出图的邻接矩阵
	{	for (int i=0;i<n;i++)
		{	for (int j=0;j<n;j++)
				if (edges[i][j]==INF)
					printf("%4s","∞");
				else
					printf("%4d",edges[i][j]);
			printf("\n");
		}
	}
};

