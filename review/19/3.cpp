#include <iostream>
#include "../../ClassCode/ch7/BTree.cpp"

bool Brother(BTNode *b, char x, char y) {
	if (b == nullptr) {
		return false;
	}
	if (b->lchild != nullptr && b->rchild != nullptr) {
		if ((b->lchild->data==x && b->rchild->data==y ) || (b->lchild->data == y && b->rchild->data == x)) {
			return true;
		}
	}
	return Brother(b->rchild, x, y) || Brother(b->lchild, x, y);
	
}

void test() {
	string str = "A(B(D(,G)),C(E,F))";
	BTree bt;
	bt.CreateBTree(str);
	cout << "¶þ²æÊ÷bt:"; bt.DispBTree(); cout << endl;

	cout << "²âÊÔBrother,0¼Ù£¬1Õæ\n";
	char x, y;

	x = 'E';
	y = 'F';
	cout << x << " " << y << ":" << Brother(bt.r, x, y) << "\n";

	x = 'C';
	y = 'F';
	cout << x << " " << y << ":" << Brother(bt.r, x, y) << "\n";

	x = 'F';
	y = 'G';
	cout << x << " " << y << ":" << Brother(bt.r, x, y) << "\n";

	x = 'C';
	y = 'B';
	cout << x << " " << y << ":" << Brother(bt.r, x, y) << "\n";
}

int main() {
	test();
	return 0;
}