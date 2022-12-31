/*
���������ÿ������ŵ����ַ���ÿ�����ֵ��Ψһ�ģ�����������
���£�
typedef struct node
{
	char data;
	struct node* lchild��* rchild;
} BTNode;
���һ���㷨������� b �н��ֵΪ x �Ľ����ֵܣ��� b �в�����ֵΪ x �Ľ���
�����������ֵ�ʱ���� NULL
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
	cout << "������bt:"; bt.DispBTree(); cout << endl;
	cout << "bt�ĸ߶�:" << bt.Height() << endl;
	char x = 'G';
	brother(bt.r,x);
	int bp=0;
}
int main() {
	test();
}