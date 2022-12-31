/*
��һԪϡ�����ʽ��������������д洢��
�����һԪϡ�����ʽ�Ĵ洢�ṹ��
�����ڴ˴洢�ṹ���һ���㷨�����ж�����һԪϡ�����ʽ�Ƿ���ȡ�
*/

#include <iostream>
//����
class Item {
public:
	int pow;//����
	int factor;//ϵ��
	Item* next;
	//���رȽ������
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