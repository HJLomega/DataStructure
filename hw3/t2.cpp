#include "./PNode.cpp"
#include <vector>
#include <iostream>

/*
����ǿն���������˳��洢�ṹ��ÿ���ڵ�ֵΪ�����ַ���
���һ���㷨������Ϊi�Ľڵ���������Ƚڵ�ֵ��
*/
void ancestors_helper(std::vector<PNode>& t, int i) { //���������������i��ʼ�����нڵ�
	if (t[i].parent == -1) {
		std::cout << t[i].data << "\n";
		return;
	}
	std::cout << t[i].data << " ";
	ancestors_helper(t, t[i].parent);
}

void ancestors(std::vector<PNode>& t, int i) { //�㷨����
	if (t[i].parent == -1) { //��Ϊ����û������
		std::cout << "\n";
		return;
	}
	ancestors_helper(t, t[i].parent); //�����������
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
	std::cout << "B�ı��Ϊ1��������: ";
	ancestors(t, 1);
	std::cout << "A�ı��Ϊ0��������: ";
	ancestors(t, 0);
	std::cout << "G�ı��Ϊ3��������: ";
	ancestors(t, 3);
}

int main() {
	test();
	std::cin.get();
	return 0;
}