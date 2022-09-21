#include "../LinkList/LinkList.h"
/* ��֪�������ȷֱ�Ϊm��n��m��n������0������������L1��L2��
���һ���㷨�����ǵ����нڵ�ϲ�Ϊһ������Ϊm+n�Ľ�������L��*/
template<typename T>
LinkList<T>& reverse_merge(LinkList<T> &A, LinkList<T>& B) {
	LinkList<T> *L = new LinkList<T>();
	LinkNode<T> *head = L->head;
	LinkNode<T>* pa = A.head->next;
	LinkNode<T>* pb = B.head->next;
	LinkNode<T>* nodeToAdd = NULL;
	while (pa && pb) {
		if (pa->data < pb->data) {
			nodeToAdd = pa;
			pa = pa->next;
		}
		else {
			nodeToAdd = pb;
			pb = pb->next;
		}
		nodeToAdd->next = head->next;
		head->next = nodeToAdd;
	}
	while (pa) {
		nodeToAdd = pa;
		pa = pa->next;
		nodeToAdd->next = head->next;
		head->next = nodeToAdd;
	}
	while (pb) {
		nodeToAdd = pb;
		pb = pb->next;
		nodeToAdd->next = head->next;
		head->next = nodeToAdd;
	}
	A.head->next = NULL; //��ABΪ��
	B.head->next = NULL;
	return *L;
}
void test() {
	LinkList<int> sl1 = LinkList<int>();
	int ar1[] = { 1,4,5 };
	sl1.CreateListR(ar1, 3);
	sl1.DispList();

	LinkList<int> sl2 = LinkList<int>();
	int ar2[] = { 2,3,6 };
	sl2.CreateListR(ar2, 3);
	sl2.DispList();

	reverse_merge<int>(sl1, sl2).DispList();
}
int main() {
	test();
	std::cin.get();
}