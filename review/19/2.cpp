#include <iostream>

class HNode {
public:
	char ch;
	int w;
	HNode* lchild;
	HNode* rchild;
};

int WPL(HNode* b) {
	WPL_helper(b, 1);
}
int WPL_helper(HNode* b, int n) {
	if (b == nullptr) {
		return 0;
	}
	return (b->w * n) + WPL_helper(b->lchild, n+1) + WPL_helper(b->rchild, n + 1);
}