

#include "../ClassCode/ch7/BTree.cpp"
#include <queue>
/*
假设二叉树中每个结点值为单个字符，采用二叉链存储结构存储。
设计一个算法，采用层次遍历方法求二叉树bt的宽度。
*/


int width(BTree& bt) {    //算法入口函数
	if (bt.r == NULL) {
		return 0;
	}
	queue<BTNode*> q = queue<BTNode*>();
	q.push(bt.r);
	int rv = 1;
	while (!q.empty()) {
		int n = q.size();		//求出当前层结点个数
		rv = n < rv ? rv : n;
		for (int i = 0; i < n; i++)		//出队当前层的n个结点
		{
			BTNode* p = q.front(); q.pop();	//出队一个结点
			if (p->lchild != NULL)		//有左孩子时将其进队
				q.push(p->lchild);
			if (p->rchild != NULL)		//有右孩子时将其进队
				q.push(p->rchild);
		}
	}
	return rv;
}



void test() { // 测试函数
	string str = "A(B(D(,G)),C(E,F))";
	BTree bt;
	bt.CreateBTree(str);
	cout << "二叉树bt:"; bt.DispBTree(); cout << endl;

	cout << width(bt) << "\n";

	string str2 = "A(B(D(H,G),I),C(E,F))";
	BTree bt2;
	bt2.CreateBTree(str2);
	cout << "二叉树bt:"; bt2.DispBTree(); cout << endl;

	cout << width(bt2) << "\n";
}

int main()
{
	test();
	cin.get();
	return 0;
}