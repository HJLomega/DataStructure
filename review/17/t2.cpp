/*
设二叉树中每个结点存放单个字符（每个结点值是唯一的），其结点类型
如下：
typedef struct node
{
	char data;
	struct node* lchild，* rchild;
} BTNode;
设计一个算法求二叉树 b 中结点值为 x 的结点的兄弟，当 b 中不存在值为 x 的结点或
者它不存在兄弟时返回 NULL
*/

#include <iostream>
#include "../../ClassCode/ch7/BTree.cpp"

void brother_helper(BTNode* bt, char x, BTNode** result);
BTNode* brother(BTNode* bt, char x) {
	BTNode* result = NULL;
	brother_helper(bt,  x, &result);
	return result;
}

void brother_helper(BTNode* bt, char x,BTNode**result) {
	if (bt == NULL) {
		return;
	}
	if (bt->lchild != NULL && bt->lchild->data == x) {
		*result = bt->rchild;
		return;
	}
	else if(bt->rchild != NULL && bt->rchild->data == x) {
		*result = bt->lchild;
		return;
	}
	else {
		brother_helper(bt->lchild, x, result);
		brother_helper(bt->rchild, x, result);
	}
}

void test() {
	string str = "E(C(A(,B),D),H(F,))";

	BTree bt;
	bt.CreateBTree(str);
	cout << "二叉树bt:"; bt.DispBTree(); cout << endl;
	cout << "bt的高度:" << bt.Height() << endl;
	char x = 'G';
	brother(bt.r,x);
	int bp=0;
}
int main() {
	test();
}