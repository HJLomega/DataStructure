/*
编写程序输入一个办公区域分布图及建筑物之间的距离，
计算出用料最少的铺设方案（只有一组最优解，不用考虑多组解)
。要求采用Prim或Kruskal算法实现。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define INF (0x700000)
using namespace std;

class Edge {
public:
	int id;
	int weight;
	int point1;
	int point2;
	Edge(int i, int w, int p1 = -1,int p2 =-2 ) {
		id = i;
		weight = w;
		if (p1 < p2) {
			point1 = p1;
			point2 = p2;
		}
		else {
			point1 = p2;
			point2 = p1;
		}
	}
	bool operator <(const Edge& rhs) const{
		return this->id < rhs.id;
	}
};

void Prim (vector<vector<Edge>> &mat,int v){
	//为了记录V - U中每个顶点j（j∈V - U）到U的最小边，建立两个数组closest和lowcost
	int n = mat.size();
	vector<int > low_cost(n, INF);
	vector<int > close_point(n, -1);
	vector<Edge> edges;
	int cost = 0;
	//初始化
	for (int i = 0; i < n; i++) {
		low_cost[i] = mat[i][v].weight;
		close_point[i] = v;
	}
	
	for (int i = 0; i < n-1; i++) {//n-1次循环添加n-1个点
		int min = INF;
		int index = -1;
		for (int i = 0; i < n; i++) {
			if (low_cost[i] != 0 && low_cost[i] < min) {
				min = low_cost[i];
				index = i;
			}
		}
		low_cost[index] = 0;
		Edge temp_edge = mat[index][close_point[index]];
		cost += temp_edge.weight;
		edges.push_back(temp_edge);

		for (int j = 0; j < n; j++) {
			int d =  mat[index][j].weight;
			if (low_cost[j]!=0 && d < low_cost[j]) {//边松弛
				low_cost[j] = d;
				close_point[j] = index;
			}
		}
	}
	
	sort(edges.begin(),edges.end());
	cout << cost << "\n";
	for (Edge &e : edges) {
		cout << e.id<<" ";
	}
}

int main() {
	//读取输入
	int e, n;
	cin >> n >> e;
	//建立邻接矩阵
	Edge tempEdge(-1, INF);
	vector<Edge> temp(n, tempEdge);
	vector<vector<Edge> > mat(n, temp);
	for (int i = 0; i < e; i++) {
		int id, p1, p2, weight;
		cin >> id >> p1 >> p2 >> weight;
		Edge tempEdge(id, weight,p1,p2);
		mat[p1][p2] = tempEdge;
		mat[p2][p1] = tempEdge;
	}
	for (int i = 0; i < n; i++) {
		mat[i][i].weight = 0;
	}
	Prim(mat, 0);
	
}