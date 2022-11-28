#include <vector>
#include <iostream>
#include "../ClassCode/ch8/AdjGraph.cpp"
using namespace std;
/*
假设一个无向图是非连通的，采用邻接表作为存储结构。
设计一个算法，利用深度优先遍历方法求出该图连通分量个数。
*/
void DFS(AdjGraph& G, int start_node, vector<int>& sed);
int connected_components(AdjGraph& G) {
	int count = 0;
	vector<int> sed = vector<int>(G.n);
	for (int i = 0; i < G.n; i++) {
		sed[i] = 0;
	}
	while (true) {
		int i = 0;
		for ( i = 0; i < G.n; i++) {
			if (sed[i] == 0) //找到未遍历的节点i
				break;
		}
		if (i == G.n) { //如果所有节点都被遍历，返回
			return count;
		}
		DFS(G, i, sed);//从i开始，深度优先遍历
		count++;
	}
}
void DFS(AdjGraph& G, int start_node , vector<int>& sed) { //深度优先遍历
	sed[start_node] = 1;
	ArcNode* node = G.adjlist[start_node].firstarc;
	while (node != NULL  ) {
		if(sed[node->adjvex] == 0)
			DFS(G, node->adjvex, sed);
		node = node->nextarc;
	}
}

void test() {
	AdjGraph G;
	int n = 5, e = 5;
	int A[MAXV][MAXV] = { {0  , 8 ,INF,  5,INF},
						  {8  ,  0,  3,INF,INF},
						  {INF,  3,  0,  9,  6},
						  {  5,INF,  9,  0,INF},
						  {INF,INF,  6,INF,  0}};
	G.CreateAdjGraph(A, n, e);
	cout << "图的邻接表:\n"; G.DispAdjGraph();
	cout<<"连通分量个数为" << connected_components(G) << "\n";

	AdjGraph G2;
	int n2 = 5, e2 = 5;
	int A2[MAXV][MAXV] = {{0  ,INF,INF,INF,INF},
						  {INF,  0,INF,INF,INF},
						  {INF,INF,  0,INF,INF},
						  {INF,INF,INF,  0,INF},
						  {INF,INF,INF,INF,  0} };
	G2.CreateAdjGraph(A2, n2, e2);
	cout << "图的邻接表:\n"; G2.DispAdjGraph();
	cout << "连通分量个数为" << connected_components(G2) << "\n";
}

int main() {
	test();
	std::cin.get();
	return 0;
}