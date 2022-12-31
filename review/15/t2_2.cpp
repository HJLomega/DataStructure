/*
假设二叉排序树采用中序线索链表作为存储结构进行存储，请写出该线索链表的存储结构，并编写算法输出该二叉排序树中所有值在a，b之间的关键字，其中a < b，二叉排序树左子树结点的值小于根结点的值，右子树结点的值大于根结点的值，树中没有关键字相重的结点。
*/
#include <iostream>
class BTNode {
public:
	char data;
	BTNode* lchild;
	BTNode* rchild;
	bool ltag;//0  表示lchild指向结点的左孩子,1  表示lchild指向结点的前驱结点即为线索
	bool rtag;

	BTNode(char d, BTNode* lc, BTNode* rc, bool lt = 0, bool rt = 0) {
		data = d;
		lchild = lc;
		rchild = rc;
		ltag = lt;
		rtag = rt;
	}
};

void report(BTNode* T, int a, int b) {
	BTNode* p = T->lchild;       // p指向根结点
	while (p != T) {     // 空树或遍历结束时，p==T
		while (p->ltag == 0)  p = p->lchild;  // 中序遍历（进入最左结点）
		if (p->data > a && p->data < b)
			std::cout << p->data;

		while (p->rtag == 1 && p->rchild != T) { //中序遍历（返回双亲）直到有右孩子或者到最右边
			p = p->rchild;
			if (p->data > b) return;    // 结点的值大于b，算法结束
			if (p->data > a && p->data < b)
				std::cout << p->data;
		}
		p = p->rchild;          // 中序遍历（p进至其右子树根）
	}
}
