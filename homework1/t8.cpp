#include "../LinkList/CLinkList.h"
/* 设计一个算法，求一个非空循环单链表L中最后一个最大节点的逻辑序号。*/
template<typename T>
int last_max(CLinkList<T> &A) {
	if (A.Getlength() == 0) {
		return -1;
	}
	LinkNode<int>* p = A.head->next;
	int max = p->data;
	int index = 0;
	int maxIndex = 0;
	while (p != A.head) {
		if (p->data >= max) {
			max = p->data;
			maxIndex = index;
		}
		p = p->next;
		index += 1;
	}
	return maxIndex;
}

void test() {
	CLinkList<int> sl1 = CLinkList<int>();
	int ar1[] = { 1,1,5,1,4,4,8,5 };
	sl1.CreateListR(ar1, 8);
	sl1.DispList();
	std::cout<<last_max<int>(sl1)<<"\n";
	sl1.DispList();
}
int main() {
	test();
	std::cin.get();
}