#include "../../ClassCode/ch2/LinkList.cpp"
//�����������ȥ��
template <typename T>
void delete_repeate(LinkNode<T> *head) {
	LinkNode<T>* pre = head->next;
	if (pre == NULL) {
		return;
	}
	LinkNode<T>* p =pre->next;
	while (p != NULL) {
		if (p->data == pre->data) {
			pre->next = p->next;
		}
	}
}