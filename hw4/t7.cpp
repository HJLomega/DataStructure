#include <vector>
#include <iostream>
#include "../ClassCode/ch8/AdjGraph.cpp"
using namespace std;
/*
����һ������ͼ�����ڽӱ�G�洢�����һ���㷨�������������ж������Ƿ��л�·��
*/
bool TopSort(AdjGraph& G) {  //�����Ƿ���������ɹ������ɹ����л�·������û�С�
	int count = 0;
	int n = G.n;
	vector <int > st;//�������Ϊ0�ĵ�
	vector <int > ind(n); //����ÿ��������
	for (int& num : ind) { //��ȳ�ʼ��Ϊ0
		num = 0;
	}
	ArcNode* p;
	//�����е�����
	for (int i = 0; i < n; i++) {
		p = G.adjlist[i].firstarc;
		while (p != NULL) {
			ind[p->adjvex] += 1;
			p = p->nextarc;
		}
	}
	for (int i = 0; i < n; i++) {//�����Ϊ0�ĵ㱣��
		if (ind[i] == 0) {
			st.push_back(i);
		}
	}
	while (!st.empty()) {//��ʼ����
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
	return count == G.n; //��ȫ���㱻������ɹ�����
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
	cout << "G1ͼ���ڽӱ�:\n"; G.DispAdjGraph();
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
	cout << "G2ͼ���ڽӱ�:\n"; G2.DispAdjGraph();
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