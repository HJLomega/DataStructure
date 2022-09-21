#include "../LinkList/DLinkList.h"
/* ��һ���ǿ�˫����L�����һ���㷨�ڵ�i���ڵ�֮ǰ����һ��ֵΪx�Ľڵ㡣*/
template<typename T>
bool Insret(DLinkList<T> &A, int i, T x) {
	if (i < 0) {
		return false;
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
			return true;
		}
		index += 1;
		p = p->next;
	}
	if (i == index) { // �� i ����������ʱ
		DLinkNode<int>* node = new DLinkNode<int>(x);
		node->next = p->next;
		node->prior = p;
		p->next = node;
		return true;
	}
	return false;
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