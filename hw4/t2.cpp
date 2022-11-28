#include <vector>
#include <iostream>
#include "../ClassCode/ch8/MatGraph.cpp"
#include <queue>
using namespace std;
/*
假设图G采用邻接矩阵存储。给出图的广度优先遍历算法，并分析算法的时间复杂度。
*/

void BFS(MatGraph& G, int start_node) {
	vector<bool> searched = vector<bool>(G.n);
	for (int i = 0; i < G.n; i++) {
		searched[i] = false;
	}

	queue<int> q = queue<int>();
	q.push(start_node);    
	searched[start_node] = true;  //起始节点入队

	while (!q.empty()) {   //遍历节点
		int node = q.front(); q.pop();
		cout <<node<< " " << "\n";
		for (int j = 0; j < G.n; j++) {  //后继节点入队
			if (searched[j] == false && G.edges[node][j] != INF) {
				q.push(j);
				searched[j] = true;
			}
		}
	}
}

void test() {
	MatGraph G;
	int n = 5, e = 5;
	int A[MAXV][MAXV] = { {0,8,INF,5,INF},{INF,0,3,INF,INF},{INF,INF,0,INF,6},{INF,INF,9,0,INF},{INF,INF,INF,INF,0} };
	G.CreateMatGraph(A, n, e);
	cout << "图的邻接表:\n"; G.DispMatGraph();
	BFS(G, 0);
}

int main() {
	test();
	std::cin.get();
	return 0;
}