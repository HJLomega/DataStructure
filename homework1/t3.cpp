#include "../LinkList/LinkList.h"
/* 设计一个算法，
查找带头节点的非空单链表L中第一个最大节点（最大节点可能有多个），
并返回该节点的逻辑序号。*/
int findMax(LinkList<int>& A) {
	if (A.Getlength() == 0) {
		return -1;
	}
	LinkNode<int>* p = A.head->next;
	int max = p->data;
	int index = 0;
	int maxIndex = 0;
	while (p != NULL) {
		if (p->data > max) {
			max = p->data;
			maxIndex = index;
		}
		p = p->next;
		index += 1;
	}
	return maxIndex;
}

void test() {
	LinkList<int> sl = LinkList<int>();
	sl.Add(2);
	sl.Add(1);
	sl.Add(1);
	sl.Add(2);
	sl.Add(5);
	sl.Add(-62);
	sl.Add(-72);
	sl.DispList();
	std::cout << findMax(sl);
}
int main() {
	test();
	std::cin.get();
}