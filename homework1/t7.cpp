#include "../LinkList/CLinkList.h"
template<typename T>
void remove_same(CLinkList<T> &A) {
	if (A.Getlength() <= 1) {
		return;
	}
	LinkNode<T>* pre = A.head->next;
	LinkNode<T>* p = pre->next;
	while (p != A.head) {
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
	CLinkList<int> sl1 = CLinkList<int>();
	int ar1[] = { 1,1,1,1,4,4,5,5 };
	sl1.CreateListR(ar1, 8);
	sl1.DispList();
	remove_same<int>(sl1);
	sl1.DispList();

	CLinkList<int> sl2 = CLinkList<int>();
	int ar2[] = { 5 };
	sl2.CreateListR(ar2, 1);
	sl2.DispList();
	remove_same<int>(sl2);
	sl2.DispList();
}
int main() {
	test();
	std::cin.get();
}