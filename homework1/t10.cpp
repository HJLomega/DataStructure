#include "../LinkList/DLinkList.h"
/* 有一个非空双链表L，设计一个算法在第i个节点之前插入一个值为x的节点。*/
template<typename T>
void Insret(DLinkList<T> &A, int i, T x) {
	if (i < 0) {
		return;
	}
	int index = 0;
	DLinkNode<int>* p = A.dhead;
	while (p->next != NULL) {
		if (index == i) {
			DLinkNode<int>* node = new DLinkNode<int>(x);
			node->next = p->next;
			node->prior = p;
			p->next->prior = node;
			p->next = node;
			return;
		}
		index += 1;
		p = p->next;
	}
	if (i == index) {
		DLinkNode<int>* node = new DLinkNode<int>(x);
		node->next = p->next;
		node->prior = p;
		p->next = node;
	}
}
void test() {
	DLinkList<int> sl1 = DLinkList<int>();
	int ar1[] = { 1,4,5,1,4,4,8,5 };
	sl1.CreateListR(ar1, 8);
	sl1.DispList();
	Insret(sl1, 0, 100);
	sl1.DispList();
	Insret(sl1, 9, 200);
	sl1.DispList();
	Insret(sl1, 8, 200);
	sl1.DispList();
	
}
int main() {
	test();
	std::cin.get();
}