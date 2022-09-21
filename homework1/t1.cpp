#include "../LinkList/LinkList.h"
/* ��һ��������Ԫ�ع��ɵķǿյ�����A�����һ���㷨��
�����ֳ�����������A��B��ʹ��A�������к������е�ż���ڵ㣬
B�������к������е������ڵ㣬�ұ���ԭ������Դ��� */
void dePart(LinkList<int>& A, LinkList<int>& B) {
	LinkNode<int> *p = A.head->next;
	if (B.Getlength() != 0) {
		//���B
		LinkNode<int>* pre, * p;
		pre = B.head->next; p = pre->next;
		while (p != NULL)		//��p������㲢�ͷ���ǰ����� 
		{
			delete pre;		//�ͷ�pre��� 
			pre = p; p = p->next;	//pre,pͬ������һ����� 
		}
		delete pre;			//pΪ��ʱpreָ��β���,��ʱ�ͷ�β���
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