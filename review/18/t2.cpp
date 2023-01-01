//判断给定的关字序列是否可能来自对某棵二叉排序树的查找
#include <iostream>
#include <vector>
#define	MAX (0x7fffffff)
#define	MIN (-0x7fffffff)

using namespace std;
bool bst(vector<int> &ar) {
	if (ar.size() <= 1) {
		return true;
	}

	int max = MAX;
	int min = MIN;
	int pre = ar[0];
	for (int i = 1; i < ar.size();i++) {
		int num = ar[i];
		if (num >= max || num <= min) {
			return false;
		}
		if (num > pre) {
			min = pre;
		}
		else {
			max = pre;
		}
		pre = num;
	}
	return true;
}

void test() {
	vector<int > ar = { 2,3,10,4,8,5 };
	cout << bst(ar) << "\n";
	ar = { 2,8,6,3,7,4,5 };
	cout << bst(ar) << "\n";
}
int main() {
	test();
}