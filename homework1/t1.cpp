#include "../SLList/SLList.h"
/* 有一个由整数元素构成的非空单链表A，设计一个算法，
将其拆分成两个单链表A和B，使得A单链表中含有所有的偶数节点，
B单链表中含有所有的奇数节点，且保持原来的相对次序。 */
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