/*
�������������������������������Ϊ�洢�ṹ���д洢����д������������Ĵ洢�ṹ������д�㷨����ö���������������ֵ��a��b֮��Ĺؼ��֣�����a < b����������������������ֵС�ڸ�����ֵ������������ֵ���ڸ�����ֵ������û�йؼ������صĽ�㡣
*/
#include <iostream>
#include "../../ClassCode/ch7/BTree.cpp"

void a_b(BTNode *bt, char a, char b){
	static bool out = false;

	if (bt == nullptr) {
		return;
	}

	//�������
	a_b( bt->lchild, a,  b);//�ݹ�������������
	if (bt->data == b) {
		out = false;
	}
	if (out == true) {
		std::cout << bt->data;
	}
	if (bt->data == a) {
		out = true;
	}
	a_b(bt->rchild, a, b);//�ݹ�������������
}

void test() {
	string str = "E(C(A(,B),D),H(F,))";

	BTree bt;
	bt.CreateBTree(str);
	cout << "������bt:"; bt.DispBTree(); cout << endl;
	cout << "bt�ĸ߶�:" << bt.Height() << endl;
	char a = 'A';
	char b = 'H';
	a_b(bt.r, a, b);
	cout << "\n";
	a = 'C';
	b = 'F';
	a_b(bt.r, a, b);
}
int main() {
	test();
}