#include <vector>
#include <iostream>
#include "../ClassCode/ch8/AdjGraph.cpp"

/*
��������ͼG�����ڽӱ�洢�����һ���㷨���ͼG��ÿ������ĳ��ȡ�
*/

void out_degrees(AdjGraph& G) {
	int n = G.n;
	for (int i = 0; i < n; i++) {  //����ÿ���ڵ�
		int count = 0;
		ArcNode* arc = G.adjlist[i].firstarc;
		while (arc != NULL) {    //�����i���ڵ�ĳ���
			arc = arc->nextarc;
			count++;
		}
		std::cout << i << "�Žڵ�ĳ���Ϊ" << count <<"\n";
	}
}

void test() {
	AdjGraph G;
	int n = 5, e = 5;
	int A[MAXV][MAXV] = { {0,8,INF,5,INF},{INF,0,3,INF,INF},{INF,INF,0,INF,6},{INF,INF,9,0,INF},{INF,INF,INF,INF,0} };
	G.CreateAdjGraph(A, n, e);
	cout << "ͼ���ڽӱ�:\n"; G.DispAdjGraph();
	out_degrees(G);
}

int main() {
	test();
	std::cin.get();
	return 0;
}