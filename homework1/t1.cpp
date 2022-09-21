#include "../LinkList/LinkList.h"
/* 有一个由整数元素构成的非空单链表A，设计一个算法，
将其拆分成两个单链表A和B，使得A单链表中含有所有的偶数节点，
B单链表中含有所有的奇数节点，且保持原来的相对次序。 */
void dePart(LinkList<int>& A, LinkList<int>& B) {
	LinkNode<int> *p = A.head->next;
	if (B.Getlength() != 0) {
		//清空B
		LinkNode<int>* pre, * p;
		pre = B.head->next; p = pre->next;
		while (p != NULL)		//用p遍历结点并释放其前驱结点 
		{
			delete pre;		//释放pre结点 
			pre = p; p = p->next;	//pre,p同步后移一个结点 
		}
		delete pre;			//p为空时pre指向尾结点,此时释放尾结点
		B.head->next = NULL;
	}
	LinkNode<int>* bEnd = B.head;
	LinkNode<int>* aEnd = A.head;
	while (p != NULL) {
		aEnd->next = p;
		aEnd = p;
		p = p->next;
		if (p != NULL) {
			bEnd->next = p;
			bEnd = p;
			p = p->next;
		}
	}
	bEnd->next = NULL;
	aEnd->next = NULL;
}

void test() {
	LinkList<int> sl = LinkList<int>();
	LinkList<int> sl2 = LinkList<int>();
	for (int i = 0; i < 2; i++) {
		sl.Add(i);
	}
	sl.DispList();
	dePart(sl, sl2);
	sl.DispList();
	sl2.DispList();
}
int main() {
	test();
	std::cin.get();
}