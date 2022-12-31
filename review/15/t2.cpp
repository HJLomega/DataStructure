/*
假设二叉排序树采用中序线索链表作为存储结构进行存储，请写出该线索链表的存储结构，并编写算法输出该二叉排序树中所有值在a，b之间的关键字，其中a < b，二叉排序树左子树结点的值小于根结点的值，右子树结点的值大于根结点的值，树中没有关键字相重的结点。
*/
#include <iostream>
#include "../../ClassCode/ch7/BTree.cpp"

void a_b(BTNode *bt, char a, char b){
	static bool out = false;

	if (bt == nullptr) {
		return;
	}

	//中序遍历
	a_b( bt->lchild, a,  b);//递归作用于左子树
	if (bt->data == b) {
		out = false;
	}
	if (out == true) {
		std::cout << bt->data;
	}
	if (bt->data == a) {
		out = true;
	}
	a_b(bt->rchild, a, b);//递归作用于右子树
}

void test() {
	string str = "E(C(A(,B),D),H(F,))";

	BTree bt;
	bt.CreateBTree(str);
	cout << "二叉树bt:"; bt.DispBTree(); cout << endl;
	cout << "bt的高度:" << bt.Height() << endl;
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