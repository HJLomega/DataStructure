#include "../LinkList/DLinkList.h"
/* ��һ���ǿ�˫����L�����һ���㷨ɾ����һ��ֵΪx�Ľڵ㡣*/
template<typename T>
void remove(DLinkList<T> &A,T x) {
	DLinkNode<T>* p = A.dhead->next;
	while (p != NULL) {
		if (p->data == x) {
			p->prior->next = p->next;
			p->next->prior = p->prior;
			delete p;
			break;
		}
		p = p->next;
	}
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