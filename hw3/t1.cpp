#include "./PNode.cpp"
#include <vector>
#include <iostream>

/*
����ǿն���������˳��洢�ṹ��ÿ���ڵ�ֵΪ�����ַ���
���һ���㷨����Ϊi�Ľڵ�Ĳ�Ρ�
*/
int level(std::vector<PNode> &t,int i) {
	if (t[i].parent == -1) {
		return 1;
	}
	return level(t, t[i].parent) + 1;
}


void test() {
	std::vector<PNode> t = std::vector<PNode>();
	t.push_back(PNode('A', -1)); //0:A, -1��ʾ�Ǹ�
	t.push_back(PNode('B', 0));  //1:B
	t.push_back(PNode('D', 1)); // 2:D
	t.push_back(PNode('G', 2));//3:G
	t.push_back(PNode('C', 0));//4:C
	t.push_back(PNode('E', 4));//5:E
	t.push_back(PNode('F', 5));//6:F
	std::cout << "������bt:" << "A(B(D(,G)),C(E,F))" << "\n";
	std::cout << "B�ı��Ϊ1�����Ϊ" << level(t, 1) << "\n";
	std::cout << "D�ı��Ϊ2�����Ϊ" << level(t, 2) << "\n";
}

int main() {
	test();
	std::cin.get();
	return 0;
}