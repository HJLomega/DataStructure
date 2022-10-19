#include <iostream>
/*
假设以1和O分别表示入栈和出栈操作，栈的初态和终态均为空，
进栈和出栈的操作序列可表示为仅由1和O组成的序列。
写出一个算法判定所给的操作序列是否合法。若合法返回true；
否则返回false（假设被判定的操作序列已存入一维数组中）
*/
bool opLeagal(int* ar, int size) {
	int s = 0;
	for (int i = 0; i < size; i++) {
		int op = ar[i];
		if (op == 1) {
			s++;
		}
		else {
			if (s == 0) {
				return false;
			}
			else {
				s--;
			}
		}
	}
	return true;
}
void test() {
	int size = 8;
	int a1[] = { 1,0,1,1,0,1,0,0 };
	int a2[] = { 1,0,0,1,0,1,1,0 };
	int a3[] = { 1,1,1,0,1,0,1,0 };
	int a4[] = { 1,1,1,0,0,1,0,0 };
	std::cout << "a1,should be true,get" << opLeagal(a1, size) << "\n";
	std::cout << "a2,should be false,get" << opLeagal(a2, size) << "\n";
	std::cout << "a3,should be true,get" << opLeagal(a3, size) << "\n";
	std::cout << "a4,should be true,get" << opLeagal(a4, size) << "\n";
}
int main() {
	test();
	std::cin.get();
}