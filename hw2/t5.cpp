#include <iostream>
#include "../ClassCode/ch3/LinkStack.cpp"
/*
假设有一个链栈st，设计一个算法出栈从栈顶开始的第k个结点。
0 为栈顶
*/
template <typename T>
bool kNode(LinkStack<T>& s, int k, T& e) {
	LinkNode<T> *p = s.head;
	int i = 0;
	while (p->next) {
		if (i == k) {
			e= p->next->data;
			LinkNode<T> *node = p->next;
			p->next = node->next;
			delete node;
			return true;
		}
		p = p->next;
		i++;
	}
	return false;
}
void test() {
	LinkStack<int> s = LinkStack<int>();
	s.push(0);
	s.push(1);
	s.push(2); 
	s.push(3);
	int a;
	std::cout << kNode(s, 0, a);
	std::cout << a;
	std::cout << kNode(s, 0, a);
	std::cout << a;
	std::cout << kNode(s, 0, a);
	std::cout << a;
	std::cout << kNode(s, 0, a);
	std::cout << a;
	std::cout << kNode(s, 0, a);
	std::cout << a;
}
int main() {
	test();
	std::cin.get();
}