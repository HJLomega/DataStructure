#include <vector>
#include <iostream>
#include "../ClassCode/ch8/AdjGraph.cpp"
using namespace std;
/*
假设一个有向图采用邻接表G存储。设计一个算法采用拓扑排序判断其中是否有回路。
*/
bool TopSort(AdjGraph& G) {  //返回是否拓扑排序成功，若成功则有回路，否则没有。
	int count = 0;
	int n = G.n;
	vector <int > st;//保存入度为0的点
	vector <int > ind(n); //保存每个点的入度
	for (int& num : ind) { //入度初始化为0
		num = 0;
	}
	ArcNode* p;
	//求所有点的入度
	for (int i = 0; i < n; i++) {
		p = G.adjlist[i].firstarc;
		while (p != NULL) {
			ind[p->adjvex] += 1;
			p = p->nextarc;
		}
	}
	for (int i = 0; i < n; i++) {//将入度为0的点保存
		if (ind[i] == 0) {
			st.push_back(i);
		}
	}
	while (!st.empty()) {//开始排序
		int i = st.back(); st.pop_back();
		count += 1;
		p = G.adjlist[i].firstarc;
		while (p != NULL) {
			int w = p->adjvex;
			ind[w] -= 1;
			if (ind[w] == 0) {
				st.push_back(w);
			}
			p = p->nextarc;
		}
	}
	return count == G.n; //若全部点被排序，则成功排序
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
	cout << "G1图的邻接表:\n"; G.DispAdjGraph();
	int secucess = TopSort(G);
	if (secucess) {
		cout << "no circuit" << "\n";
	}
	else {
		cout << "has circuit" << "\n";
	}

	AdjGraph G2;
	int n2 = 5, e2 = 5;
	int A2[MAXV][MAXV] = { {0,8,INF,5,INF},{INF,0,3,INF,INF},{INF,INF,0,INF,6},{INF,INF,9,0,INF},{INF,INF,INF,INF,0} };
	G2.CreateAdjGraph(A2, n2, e2);
	cout << "G2图的邻接表:\n"; G2.DispAdjGraph();
	TopSort(G2);
	secucess = TopSort(G2);
	if (secucess) {
		cout << "no circuit"<<"\n";
	}
	else {
		cout << "has circuit" << "\n";
	}
}

int main() {
	test();
	std::cin.get();
	return 0;
}