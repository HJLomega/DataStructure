/*
若一元稀疏多项式采用有序单链表进行存储，
请给出一元稀疏多项式的存储结构，
并基于此存储结构设计一个算法用于判断两个一元稀疏多项式是否相等。
*/

#include <iostream>
//链表
class Item {
public:
	int pow;//次数
	int factor;//系数
	Item* next;
	//重载比较运算符
	bool operator==(const Item& other) {  
		if (pow != other.pow || factor !=other.factor) {
			return false;
		}
		if (next == nullptr && other.next == nullptr) {
			return true;
		}
		else if (next != nullptr && other.next != nullptr) {
			return *next == *(other.next);
		}
		else {
			return false;
		}
	}
	Item(int p, int f ,Item* n) {
		pow = p;
		factor = f;
		next = n;
	}
};

void test() {
	Item a = Item(1, 5, &Item(2, 4, &Item(3, 5, nullptr)));
	Item b = Item(1, 5, &Item(2, 4, &Item(3, 5, nullptr)));
	std::cout << (a == b)<<"\n";
	a = Item(1, 5, &Item(2, 4, &Item(3, 4, nullptr)));
	b = Item(1, 5, &Item(2, 4, &Item(3, 5, nullptr)));
	std::cout << (a == b)<< "\n";
	a = Item(1, 5, &Item(2, 4,nullptr));
	b = Item(1, 5, &Item(2, 4, &Item(3, 5, nullptr)));
	std::cout << (a == b)<< "\n";
}
int main() {
	test();
}