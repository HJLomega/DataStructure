//设二叉树中每个结点存放单个字符，其结点类型如下：

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
//设计一个算法求其中单分支的结点个数


int count_single(BTNode* bt) {
	if (bt == nullptr) {
		return 0;
	}
	//检测单分支
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
	cout << "二叉树bt:"; bt.DispBTree(); cout << endl;
	cout << "bt的高度:" << bt.Height() << endl;
	cout<<count_single(bt.r);
}
int main() {
	test();
}

