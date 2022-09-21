#include "../SLList/SLList.h"
/* 设计一个高效算法，将顺序表的所有元素逆置，要求算法空间复杂度为O(1)。*/
template<typename T>
void reverse(SLList<T> &A) {
	if (A.GetLength() <= 1) {
		return;
	}
	LinkNode<T>* reversedFirst = NULL;
	LinkNode<T>* rsetFirst = A.head->next;
	LinkNode<T>* nodeToAdd = NULL;
	while (rsetFirst != NULL) {
		nodeToAdd = rsetFirst;
		rsetFirst = rsetFirst->next;
		nodeToAdd->next = reversedFirst;
		reversedFirst = nodeToAdd;
	}
	A.head->next = reversedFirst;
}


void test() {
	SLList<int> sl = SLList<int>();
	sl.Add(1);
	sl.Add(2);
	sl.Add(-62);
	sl.Add(-72);
	sl.DispList();
	reverse<int>(sl);
	sl.DispList();
}
int main() {
	test();
	std::cin.get();
}