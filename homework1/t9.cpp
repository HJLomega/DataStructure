#include "../LinkList/DLinkList.h"
/* 有一个非空双链表L，设计一个算法删除第一个值为x的节点。*/
template<typename T>
bool remove(DLinkList<T> &A,T x) {
	DLinkNode<T>* p = A.dhead->next;
	while (p != NULL) {
		if (p->data == x) {
			p->prior->next = p->next;
			p->next->prior = p->prior;
			delete p;
			return true;
		}
		p = p->next;
	}
	return false;
}

void test() {
	DLinkList<int> sl1 = DLinkList<int>();
	int ar1[] = { 1,4,5,1,4,4,8,5 };
	sl1.CreateListR(ar1, 8);
	sl1.DispList();
	remove<int>(sl1,4);
	sl1.DispList();
	remove<int>(sl1,1);
	sl1.DispList();
	remove<int>(sl1, 8);
	sl1.DispList();
}
int main() {
	test();
	std::cin.get();
}