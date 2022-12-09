#include <vector>
#include <iostream>
#include "../ClassCode/ch8/MatGraph.cpp"

/*
����һ����ȨͼG�����ڽӾ���洢��
���һ���㷨���õҿ�˹�����㷨˼·�󶥵�s������t�����·�����ȣ����趥��s��t����G�еĶ��㣩��
*/
void DispPath(vector<int >& dist, vector<int >& path, int s, int t) {
s	if (s == t) {
		cout << s << " ";
		return;
	}
	DispPath(dist, path, s, path[t]);
	cout << t<<" ";
}
void Dijkstra(MatGraph& G,int s,int t) {
	int n = G.n;
	vector<int > dist(n);
	vector<int > path(n);
	vector<int > S (n);
	for (int i = 0; i < n; i++) { //��ʼ��
		dist[i] = G.edges[s][i];
		S[i] = 0;
		if (dist[i] != 0 && dist[i] < INF)
			path[i] = s;
		else
			path[i] = -1;
	}
	S[s] = 1;  //��v���뵽����S��
	int  u = -1;
	for (int i = 0; i <= n - 2; i++) {
		int min = INF;
		for (int j = 0; j < n; j++) { //�ҵ�����S���Ҿ�����С�ĵ�
			if (S[j] == 0 && dist[j] < min) {
				u = j;
				min = dist[j];
			}
		}
		S[u] = 1;
		for (int j = 0; j < n; j++) {
			if (S[j]==0){
				if (  G.edges[u][j]<INF && dist[u]+G.edges[u][j] <dist[j]) { //���ɳ�
					dist[j] = dist[u] + G.edges[u][j];
					path[j] = u;
				}
			}
		}
	}
	cout << "���·����Ϊ" << dist[t]<<"\n";
	cout << "���·��Ϊ:";
	DispPath(dist, path, s, t);
}

void test() {
	MatGraph G;
	int n = 5, e = 5;
	int A[MAXV][MAXV] = { {0,8,INF,5,INF},{INF,0,3,INF,INF},{INF,INF,0,INF,6},{INF,INF,9,0,INF},{INF,INF,INF,INF,0} };
	G.CreateMatGraph(A, n, e);
	cout << "ͼ���ڽӾ���:\n"; G.DispMatGraph();
	Dijkstra(G, 0, 4);
}

int main() {
	test();
	std::cin.get();
	return 0;
}