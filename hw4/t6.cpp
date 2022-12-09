#include <vector>
#include <iostream>
#include "../ClassCode/ch8/AdjGraph.cpp"
using namespace std;
/*
����һ������ͼ�����ڽӱ�G��Ϊ�洢�ṹ��
���һ���㷨�ڴ��ھ�������v�Ļ�·ʱ������������ļ򵥻�·��
*/
bool DFS(AdjGraph& G, int start_node, vector<int> sed, int depth, int v, vector<int > path);
int find_circuit(AdjGraph& G, int v) {
	int count = 0;
	vector<int> sed = vector<int>(G.n);
	vector<int> path;
	for (int i = 0; i < G.n; i++) {
		sed[i] = 0;
	}
	return DFS(G, v, sed, 0, v, path);//������ȱ���Ѱ�ҹ�v�Ļ�·,�������㿪ʼ
}
bool DFS(AdjGraph& G, int start_node, vector<int> sed, int depth, int v,vector<int > path) { //������ȱ���
	sed[start_node] = 1;
	path.push_back(start_node);
	ArcNode* node = G.adjlist[start_node].firstarc;
	while (node != NULL) {
		if (node->adjvex == v && depth > 1) {  //�����һ���ڵ�Ϊv�����ҵ�ǰ��������1��˵���л�·
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
	cout << "ͼ���ڽӱ�:\n"; G.DispAdjGraph();
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