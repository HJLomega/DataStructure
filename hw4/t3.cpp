#include <vector>
#include <iostream>
#include "../ClassCode/ch8/AdjGraph.cpp"
using namespace std;
/*
����һ������ͼ�Ƿ���ͨ�ģ������ڽӱ���Ϊ�洢�ṹ��
���һ���㷨������������ȱ������������ͼ��ͨ����������
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
			if (sed[i] == 0) //�ҵ�δ�����Ľڵ�i
				break;
		}
		if (i == G.n) { //������нڵ㶼������������
			return count;
		}
		DFS(G, i, sed);//��i��ʼ��������ȱ���
		count++;
	}
}
void DFS(AdjGraph& G, int start_node , vector<int>& sed) { //������ȱ���
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
	cout << "ͼ���ڽӱ�:\n"; G.DispAdjGraph();
	cout<<"��ͨ��������Ϊ" << connected_components(G) << "\n";

	AdjGraph G2;
	int n2 = 5, e2 = 5;
	int A2[MAXV][MAXV] = {{0  ,INF,INF,INF,INF},
						  {INF,  0,INF,INF,INF},
						  {INF,INF,  0,INF,INF},
						  {INF,INF,INF,  0,INF},
						  {INF,INF,INF,INF,  0} };
	G2.CreateAdjGraph(A2, n2, e2);
	cout << "ͼ���ڽӱ�:\n"; G2.DispAdjGraph();
	cout << "��ͨ��������Ϊ" << connected_components(G2) << "\n";
}

int main() {
	test();
	std::cin.get();
	return 0;
}