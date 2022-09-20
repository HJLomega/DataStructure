#include "../SLList/SLList.h"

void movePositive(SLList<int>& A) {
	LinkNode<int>* lastNegtive = A.head;
	while (lastNegtive->next != NULL && lastNegtive->next->data < 0) {
		lastNegtive = lastNegtive->next;
	}
	LinkNode<int>* p = lastNegtive->next;
	LinkNode<int>* toBeInsert = NULL;
	LinkNode<int>* End = lastNegtive;
	while (p != NULL) {
		if (p->data < 0) {
			toBeInsert = p;
			p = p->next;
			toBeInsert->next = lastNegtive->next;
			lastNegtive->next = toBeInsert;
			lastNegtive = toBeInsert;
		} else {
			End = p;
			p = p->next;
		}
	}
	End->next = NULL;
}
void test() {
	SLList<int> sl = SLList<int>();
	sl.Add(-1);
	sl.Add(1);
	sl.Add(2);
	sl.Add(-62);
	sl.Add(-72);
	sl.DispList();
	movePositive(sl);
	sl.DispList();
}
int main() {
	test();
	std::cin.get();
}