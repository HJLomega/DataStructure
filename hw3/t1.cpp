#include "./PNode.cpp"
#include <vector>
#include <iostream>

/*
假设非空二叉树采用顺序存储结构，每个节点值为单个字符。
设计一个算法求编号为i的节点的层次。
*/
int level(std::vector<PNode> &t,int i) {
	if (t[i].parent == -1) {
		return 1;
	}
	return level(t, t[i].parent) + 1;
}


void test() {
	std::vector<PNode> t = std::vector<PNode>();
	t.push_back(PNode('A', -1)); //0:A, -1表示是根
	t.push_back(PNode('B', 0));  //1:B
	t.push_back(PNode('D', 1)); // 2:D
	t.push_back(PNode('G', 2));//3:G
	t.push_back(PNode('C', 0));//4:C
	t.push_back(PNode('E', 4));//5:E
	t.push_back(PNode('F', 5));//6:F
	std::cout << "二叉树bt:" << "A(B(D(,G)),C(E,F))" << "\n";
	std::cout << "B的编号为1，层次为" << level(t, 1) << "\n";
	std::cout << "D的编号为2，层次为" << level(t, 2) << "\n";
}

int main() {
	test();
	std::cin.get();
	return 0;
}