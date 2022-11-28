#include <vector>
#include <iostream>
#include "../ClassCode/ch8/MatGraph.cpp"
#include <queue>
using namespace std;
/*
����ͼG�����ڽӾ���洢������ͼ�Ĺ�����ȱ����㷨���������㷨��ʱ�临�Ӷȡ�
*/

void BFS(MatGraph& G, int start_node) {
	vector<bool> searched = vector<bool>(G.n);
	for (int i = 0; i < G.n; i++) {
		searched[i] = false;
	}

	queue<int> q = queue<int>();
	q.push(start_node);    
	searched[start_node] = true;  //��ʼ�ڵ����

	while (!q.empty()) {   //�����ڵ�
		int node = q.front(); q.pop();
		cout <<node<< " " << "\n";
		for (int j = 0; j < G.n; j++) {  //��̽ڵ����
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
	cout << "ͼ���ڽӱ�:\n"; G.DispMatGraph();
	BFS(G, 0);
}

int main() {
	test();
	std::cin.get();
	return 0;
}