#include "../LinkList/LinkList.h"
template<typename T>
void remove_same(LinkList<T> &A) {
	if (A.Getlength() <= 1) {
		return;
	}
	LinkNode<T>* pre = A.head->next;
	LinkNode<T>* p = pre->next;
	while (p) {
		if (p->data == pre->data) {
			pre->next = p->next;
			delete p;
			p = pre->next;
		}
		else {
			pre = p;
			p = pre->next;
		}
	}
}

void test() {
	LinkList<int> sl1 = LinkList<int>();
	int ar1[] = { 1,1,1,1,4,4,5,5 };
	sl1.CreateListR(ar1, 8);
	sl1.DispList();
	remove_same<int>(sl1);
	sl1.DispList();

	LinkList<int> sl2 = LinkList<int>();
	sl2.Add(5);
	sl2.DispList();
	remove_same<int>(sl2);
	sl2.DispList();
}
int main() {
	test();
	std::cin.get();
}