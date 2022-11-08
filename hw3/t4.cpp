#include "../ClassCode/ch7/BTree.cpp"

/*
假设二叉树采用二叉链存储结构，设计一个算法判断一棵二叉树bt是否对称。
所谓对称是指其左右子树的结构是对称的。
*/
bool isLeaf(BTNode* bn) { //辅助函数，判断节点是否为叶子
	return bn != NULL && bn->lchild == NULL && bn->rchild == NULL;
}

bool is_symmetric_helper(BTNode* bn) {//递归函数
	if (bn == NULL || isLeaf(bn)) {
		return true;
	}
	else if (bn->lchild == NULL || bn->rchild == NULL) {
		return false;
	}
	else {
		return is_symmetric_helper(bn->lchild) && is_symmetric_helper(bn->rchild);
	}
}

bool is_symmetric(BTree& bt) {    //算法入口函数
	return is_symmetric_helper(bt.r);
}



void test() { // 测试函数
	string str = "A(B(D(,G)),C(E,F))";
	BTree bt;
	bt.CreateBTree(str);
	cout << "二叉树bt:"; bt.DispBTree(); cout << endl;

	cout<<is_symmetric(bt)<<"\n";

	string str2 = "A(B(D(H,G),I),C(E,F))";
	BTree bt2;
	bt2.CreateBTree(str2);
	cout << "二叉树bt:"; bt2.DispBTree(); cout << endl;

	cout << is_symmetric(bt2) << "\n";
}

int main()
{
	test();
	cin.get();
	return 0;
}