#include <iostream>
using namespace std; 
#ifndef MAXV
#define MAXV 100										//ͼ�����Ķ�����
#define INF 0x3f3f3f3f								//��INF��ʾ
#endif 
class MatGraph						//ͼ�ڽӾ�����
{
public:
	int edges[MAXV][MAXV];			//�ڽӾ������飬����Ԫ��Ϊint����
	int n,e;						//������������
	string vexs[MAXV];				//��Ŷ�����Ϣ
	void CreateMatGraph(int a[][MAXV],int n,int e) //ͨ��������a��������n�ͱ���e������ͼ���ڽӾ���
	{
		this->n=n; this->e=e;				//�ö������ͱ���
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				this->edges[i][j]=a[i][j];
	}
	void DispMatGraph()						//���ͼ���ڽӾ���
	{	for (int i=0;i<n;i++)
		{	for (int j=0;j<n;j++)
				if (edges[i][j]==INF)
					printf("%4s","��");
				else
					printf("%4d",edges[i][j]);
			printf("\n");
		}
	}
};

