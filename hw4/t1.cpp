#include <vector>
#include <iostream>
#include "../ClassCode/ch8/AdjGraph.cpp"

/*
假设有向图G采用邻接表存储，设计一个算法求出图G中每个顶点的出度。
*/

void out_degrees(AdjGraph& G) {
	int n = G.n;
	for (int i = 0; i < n; i++) {  //遍历每个节点
		int count = 0;
		ArcNode* arc = G.adjlist[i].firstarc;
		while (arc != NULL) {    //计算第i个节点的出度
			arc = arc->nextarc;
			count++;
		}
		std::cout << i << "号节点的出度为" << count <<"\n";
	}
}

void test() {
	AdjGraph G;
	int n = 5, e = 5;
	int A[MAXV][MAXV] = { {0,8,INF,5,INF},{INF,0,3,INF,INF},{INF,INF,0,INF,6},{INF,INF,9,0,INF},{INF,INF,INF,INF,0} };
	G.CreateAdjGraph(A, n, e);
	cout << "图的邻接表:\n"; G.DispAdjGraph();
	out_degrees(G);
}

int main() {
	test();
	std::cin.get();
	return 0;
}