#include "./PNode.cpp"
#include <vector>
#include <iostream>

/*
假设非空二叉树采用顺序存储结构，每个节点值为单个字符。
设计一个算法输出编号为i的节点的所有祖先节点值。
*/
void ancestors_helper(std::vector<PNode>& t, int i) { //辅助函数，输出从i开始的所有节点
	if (t[i].parent == -1) {
		std::cout << t[i].data << "\n";
		return;
	}
	std::cout << t[i].data << " ";
	ancestors_helper(t, t[i].parent);
}

void ancestors(std::vector<PNode>& t, int i) { //算法函数
	if (t[i].parent == -1) { //若为根，没有祖先
		std::cout << "\n";
		return;
	}
	ancestors_helper(t, t[i].parent); //输出所有祖先
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
	std::cout << "B的编号为1，祖先是: ";
	ancestors(t, 1);
	std::cout << "A的编号为0，祖先是: ";
	ancestors(t, 0);
	std::cout << "G的编号为3，祖先是: ";
	ancestors(t, 3);
}

int main() {
	test();
	std::cin.get();
	return 0;
}