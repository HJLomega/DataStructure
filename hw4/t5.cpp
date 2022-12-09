#include <vector>
#include <iostream>
#include "../ClassCode/ch8/AdjGraph.cpp"
using namespace std;
/*
����ͼG�����ڽӱ�洢�����һ���㷨��������ͼ��ʾ������ͼG���ҳ���������������һ��·����
��1���������u���յ�v��
��2������һ��ؾ���{ 1��6 }���������·�����������Щ���㡣
��3������һ��رܵ�{ 7��9 }���������·�����ܰ�����Щ���㡣
*/
bool DFS(AdjGraph& G, int start_node, vector<int> sed, int v, bool pass_1, bool pass_6, vector<int> path);
void search(AdjGraph& G,int u,int v) {
	int n = G.n;
	vector<int > path;
	vector<int > sed(n);
	DFS(G, u, sed, v, false, false, path);
}
bool DFS(AdjGraph& G, int start_node, vector<int> sed, int v,bool pass_1,bool pass_6, vector<int> path) { //������ȱ���
	sed[start_node] = 1;
	pass_1 = pass_1 || (start_node == 1);   // �ж��Ƿ񾭹���1��6
	pass_6 = pass_6 || (start_node == 6);
	if (start_node == 7 || start_node == 9) {
		return false;
	}
	if (start_node == v) {     // �����v
		if (pass_1 && pass_6) {  // ����Ѿ�������1��6
			for (int num : path) {
				cout << num<<" ";
			}
			cout << start_node << "\n";
			return true;
		}
		return false;
	}
	//����������ݹ����
	path.push_back(start_node);
	ArcNode* node = G.adjlist[start_node].firstarc;
	bool find = false;
	while (node != NULL) {
		if(sed[node->adjvex] == 0) {
			find = find || DFS(G, node->adjvex, sed, v, pass_1, pass_6, path);
			if (find) {
				return true;
			}
		}
		node = node->nextarc;
	}
	return find;
}



void createG(AdjGraph& G, int n, int e);
void test() {
	AdjGraph G;
	int n = 15, e = 19;
	createG(G, n, e);
	cout << "ͼ���ڽӱ�:\n"; G.DispAdjGraph();
	search(G, 3, 8);
	search(G, 4, 10);
}

void createG(AdjGraph &G,int n,int e) {
	int A[MAXV][MAXV] ;
	for (int i = 0; i <= 14; i++) {
		for (int j = 0; j <= 14; j++) {
			A[i][j] = INF;
			if (i == j) {
				A[i][j] = 0;
			}
		}
	}
	const int W = 1;
	A[0][1] = A[1][0] = W;
	A[0][2] = A[2][0] = W;
	A[0][3] = A[3][0] = W;
	A[0][4] = A[4][0] = W;
	A[1][8] = A[8][1] = W;
	A[1][6] = A[6][1] = W;
	A[3][6] = A[6][3] = W;
	A[4][7] = A[7][4] = W;
	A[6][7] = A[7][6] = W;
	A[6][9] = A[9][6] = W;
	A[7][10] = A[10][7] = W;
	A[7][11] = A[11][7] = W;
	A[8][5] = A[5][8] = W;
	A[8][12] = A[12][8] = W;
	A[5][9] = A[9][5] = W;
	A[9][12] = A[12][9] = W;
	A[9][10] = A[10][9] = W;
	A[10][13] = A[13][10] = W;
	A[13][11] = A[11][13] = W;
	A[13][14] = A[14][13] = W;
	A[12][14] = A[14][12] = W;
	G.CreateAdjGraph(A, n, e);
}
int main() {
	test();
	std::cin.get();
	return 0;
}