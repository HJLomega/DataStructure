/*
������������ö������洢�ṹ�����һ���㷨��ָ��Ԫ���ڶ����������еĲ�Ρ�
*/

#include "../../ClassCode/ch7/BTree.cpp"

int layer_helper(BTNode* bn, char x, int n);
int layer(BTNode* bn,char x) {
	return layer_helper(bn, x, 1 );
}
int layer_helper(BTNode* bn, char x, int n) {
	if (bn == NULL) {
		return -1;
	}
	if (x < bn->data) {
		return layer_helper(bn->lchild, x, n + 1);
	}
	else if (x > bn->data) {
		return layer_helper(bn->rchild, x, n + 1);
	}
	else {
		return n;
	}
}


void test() {
	string str = "E(C(A(,B),D),H(F,))";
	
	BTree bt;
	bt.CreateBTree(str);
	cout << "������bt:"; bt.DispBTree(); cout << endl;
	cout << "bt�ĸ߶�:" << bt.Height() << endl;
	char x = 'A';
	cout << x << layer(bt.r, x) << "\n";
	x = 'E';
	cout << x << layer(bt.r, x) << "\n";
	x = 'B';
	cout << x << layer(bt.r, x) << "\n";
	x = 'H';
	cout << x << layer(bt.r, x) << "\n";
}
int main()
{
	test();

}