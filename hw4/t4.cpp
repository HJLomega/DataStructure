#include <vector>
#include <iostream>
#include "../ClassCode/ch8/AdjGraph.cpp"
using namespace std;
/*
����һ����ͨͼ�����ڽӱ���Ϊ�洢�ṹ�������һ���㷨��
�ж������Ƿ���ھ�������v�Ļ�·��
*/
bool DFS(AdjGraph& G, int start_node, vector<int>& sed, int depth, int v);
int has_circuit(AdjGraph& G,int v) {
	int count = 0;
	vector<int> sed = vector<int>(G.n);
	for (int i = 0; i < G.n; i++) {
		sed[i] = 0;
	}
	return DFS(G, v, sed, 0,v);//������ȱ���Ѱ�ҹ�v�Ļ�·,�������㿪ʼ
}
bool DFS(AdjGraph& G, int start_node, vector<int>& sed, int depth,int v) { //������ȱ���
	sed[start_node] = 1;
	ArcNode* node = G.adjlist[start_node].firstarc;
	while (node != NULL) {
		if (node->adjvex == v && depth > 1) {  //�����һ���ڵ�Ϊv�����ҵ�ǰ��������1��˵���л�·
			return true;
		}
		if (sed[node->adjvex] == 0) {
			bool has_c = DFS(G, node->adjvex, sed, depth + 1, v);
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
	cout << "ͼ���ڽӱ�:\n"; G.DispAdjGraph();
	cout <<0<<" " << has_circuit(G, 0) << "\n";
	cout << 1 << " " << has_circuit(G, 1) << "\n";
	cout << 2 << " " << has_circuit(G, 2) << "\n";
	cout << 3 << " " << has_circuit(G, 3) << "\n";
	cout <<4<<" " << has_circuit(G, 4) << "\n";

}

int main() {
	test();
	std::cin.get();
	return 0;
}