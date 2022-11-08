#include "../ClassCode/ch7/BTree.cpp"

/*
假设二叉树中每个结点值为单个字符，采用二叉链存储结构存储。
设计一个算法按从右到左的次序输出一棵二叉树bt中的所有叶子结点。
*/
bool isLeaf(BTNode *bn);
void RightLeaves_helper(BTNode* bn);

void RightLeaves(BTree &bt) {    //算法函数
	RightLeaves_helper(bt.r);
	cout << "\n";
}

void RightLeaves_helper(BTNode* bn) { //辅助函数，用于递归
	if (bn == NULL) {
		return;
	}
	if (isLeaf(bn)) {
		std::cout << bn->data << " ";
	}
	else {
		RightLeaves_helper(bn->rchild);
		RightLeaves_helper(bn->lchild);
	}
}

bool isLeaf(BTNode *bn) { //辅助函数，判断节点是否为叶子
	return bn != NULL && bn->lchild == NULL && bn->rchild == NULL;
}

void test() {
	string str = "A(B(D(,G)),C(E,F))";
	char x = 'e';
	BTree bt;
	bt.CreateBTree(str);
	cout << "二叉树bt:"; bt.DispBTree(); cout << endl;
	
	RightLeaves(bt);
}

int main()
{
	test();
	cin.get();
	return 0;
}