#include <vector>
#include <iostream>
#include "../ClassCode/ch8/AdjGraph.cpp"
using namespace std;
/*
假设一个无向图采用邻接表G作为存储结构，
设计一个算法在存在经过顶点v的回路时输出所有这样的简单回路。
*/
bool DFS(AdjGraph& G, int start_node, vector<int> sed, int depth, int v, vector<int > path);
int find_circuit(AdjGraph& G, int v) {
	int count = 0;
	vector<int> sed = vector<int>(G.n);
	vector<int> path;
	for (int i = 0; i < G.n; i++) {
		sed[i] = 0;
	}
	return DFS(G, v, sed, 0, v, path);//深度优先遍历寻找过v的回路,层数从零开始
}
bool DFS(AdjGraph& G, int start_node, vector<int> sed, int depth, int v,vector<int > path) { //深度优先遍历
	sed[start_node] = 1;
	path.push_back(start_node);
	ArcNode* node = G.adjlist[start_node].firstarc;
	while (node != NULL) {
		if (node->adjvex == v && depth > 1) {  //如果下一个节点为v，并且当前层数大于1，说明有回路
			cout <<"circuit: ";
			for (int num : path) {
				cout << num<<" ";
			}
			cout <<v<< " end ";
			return true;
		}
		if (sed[node->adjvex] == 0) {
			bool has_c = DFS(G, node->adjvex, sed, depth + 1, v, path);
			if (has_c == true)
				return true;
		}
		node = node->nextarc;
	}
	return false;

}

void test() {
	AdjGraph G;
	int n = 5, e = 5;
	int A[MAXV][MAXV] = { {0  , 8 ,INF,  5,INF},
						  {8  ,  0,  3,INF,INF},
						  {INF,  3,  0,  9,  6},
						  {  5,INF,  9,  0,INF},
						  {INF,INF,  6,INF,  0} };
	G.CreateAdjGraph(A, n, e);
	cout << "图的邻接表:\n"; G.DispAdjGraph();
	cout << 0 << " " << find_circuit(G, 0) << "\n";
	cout << 1 << " " << find_circuit(G, 1) << "\n";
	cout << 2 << " " << find_circuit(G, 2) << "\n";
	cout << 3 << " " << find_circuit(G, 3) << "\n";
	cout << 4 << " " << find_circuit(G, 4) << "\n";

}

int main() {
	test();
	std::cin.get();
	return 0;
}