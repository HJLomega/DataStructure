#include "../ClassCode/ch7/BTree.cpp"
#include <queue>
/*
假设二叉树中每个结点值为单个字符，采用二叉链存储结构存储。
设计一个算法，判断一棵二叉树bt是否为完全二叉树。
*/
bool is_complete(BTree& bt) {    //算法入口函数
	if (bt.r == NULL) {
		return false;
	}
	queue<BTNode*> q = queue<BTNode*>();
	q.push(bt.r);
	bool full = true;   //标记层序遍历时，二叉树是否是满的
	while (!q.empty()) {           //层序遍历
		int n = q.size();		
		for (int i = 0; i < n; i++)		
		{
			BTNode* p = q.front(); q.pop();	
			bool l = p->lchild != NULL;
			bool r = p->rchild != NULL;
			if (full) {            //当前为满树
				if (l && r) {
					q.push(p->lchild);
					q.push(p->rchild);
				}
				else if (!l && r) {
					return false;
				}
				else {
					full = false;
				}
			}
			else {  //当前不是满树
				if (l && r) {
					return false;
				}
			}
		}
	}
	return true;
}

void test() { // 测试函数
	string str = "A(B(D(,G)),C(E,F))";
	BTree bt;
	bt.CreateBTree(str);
	cout << "二叉树bt:"; bt.DispBTree(); cout << endl;

	cout << is_complete(bt) << "\n";

	string str2 = "A(B(D(H,G),I),C(E,F))";
	BTree bt2;
	bt2.CreateBTree(str2);
	cout << "二叉树bt:"; bt2.DispBTree(); cout << endl;

	cout << is_complete(bt2) << "\n";
}

int main()
{
	test();
	cin.get();
	return 0;
}