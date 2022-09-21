#include "../LinkList/LinkList.h"










void test() {
	LinkList<int> sl1 = LinkList<int>();
	int ar1[] = { 1,1,1,1,4,4,5,5 };
	sl1.CreateListR(ar1, 8);
	sl1.DispList();
	remove_same<int>(sl1);
	sl1.DispList();
}
int main() {
	test();
	std::cin.get();
}