#include "../SLList/SLList.h"

void dePart(SLList<int>& A, SLList<int>& B) {
	LinkNode<int> *p = A.head->next;
	if (B.GetLength() != 0) {
		B.clear();
	}
	LinkNode<int>* bEnd = B.head;
	LinkNode<int>* aEnd = A.head;
	A.length = 0;
	B.length = 0;
	while (p != NULL) {
		aEnd->next = p;
		aEnd = p;
		p = p->next;
		A.length++;
		if (p != NULL) {
			bEnd->next = p;
			bEnd = p;
			p = p->next;
			B.length++;
		}
	}
	bEnd->next = NULL;
	aEnd->next = NULL;
}

void test() {
	SLList<int> sl = SLList<int>();
	SLList<int> sl2 = SLList<int>();
	for (int i = 0; i < 100; i++) {
		sl.Add(i);
	}
	sl.DispList();
	dePart(sl, sl2);
	sl.DispList();
	sl2.DispList();
}
//int main() {
//	test();
//	std::cin.get();
//}