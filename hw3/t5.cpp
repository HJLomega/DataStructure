#include "../ClassCode/ch7/BTree.cpp"
#define VERY_LARGE_INT (1 << 30)
/*
假设二叉树中每个结点值为单个字符，采用二叉链存储结构存储。
设计一个算法求二叉树bt的最小枝长。
所谓最小枝长是指的是根结点到最近叶子结点的路径长度。
*/
bool isLeaf(BTNode* bn) { //辅助函数，判断节点是否为叶子
	return bn != NULL && bn->lchild == NULL && bn->rchild == NULL;
}

int min_length_helper(BTNode* bn,int min_length,int length) {//递归函数
	if (bn == NULL) {
		return VERY_LARGE_INT;
	}
	
	if (length > min_length) {               //若当前长度大于最小长度，直接返回
		return VERY_LARGE_INT;
	}
	else if (isLeaf(bn)) {
		return length;
	}
	else {                                    //递归调用
		int left = min_length_helper(bn->lchild, min_length, length+1);
		int right = min_length_helper(bn->rchild, min_length, length+1);
		return left > right ? right : left;     //最小值
	}
}

int min_length(BTree& bt) {    //算法入口函数
	return min_length_helper(bt.r, VERY_LARGE_INT,0);
}



void test() { // 测试函数
	string str = "A(B(D(,G)),C(E,F))";
	BTree bt;
	bt.CreateBTree(str);
	cout << "二叉树bt:"; bt.DispBTree(); cout << endl;

	cout << min_length(bt) << "\n";

	string str2 = "A(B,C(E,F))";
	BTree bt2;
	bt2.CreateBTree(str2);
	cout << "二叉树bt:"; bt2.DispBTree(); cout << endl;

	cout << min_length(bt2) << "\n";
}

int main()
{
	test();
	cin.get();
	return 0;
}