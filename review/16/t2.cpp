//���������ÿ������ŵ����ַ��������������£�

#include <iostream>
#include "../../ClassCode/ch7/BTree.cpp"
/*
typedef struct node
{
	char data;
	struct node* lchild;
	struct node* rchild;
} BTNode;
*/
//���һ���㷨�����е���֧�Ľ�����


int count_single(BTNode* bt) {
	if (bt == nullptr) {
		return 0;
	}
	//��ⵥ��֧
	if ((bt->lchild==nullptr&& bt->rchild != nullptr)|| (bt->lchild != nullptr && bt->rchild == nullptr)) {
		return 1 + count_single(bt->lchild) + count_single(bt->rchild);
	}
	else {
		return count_single(bt->lchild) + count_single(bt->rchild);
	}
}
void test() {
	string str = "E(C(A(,B),D),H(F,))";

	BTree bt;
	bt.CreateBTree(str);
	cout << "������bt:"; bt.DispBTree(); cout << endl;
	cout << "bt�ĸ߶�:" << bt.Height() << endl;
	cout<<count_single(bt.r);
}
int main() {
	test();
}

