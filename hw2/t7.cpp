#include <iostream>
#include <queue>
/*
有一个整数数组a，设计一个算法将所有偶数位的元素移动到所有奇数位元素的前面，要求它们的相对次序不改变。
例如，a={1，2，3，4，5，6，7，8}，移动后，a={2，4，6，8，1，3，5，7}。
*/
void move(int* ar, int size) {
	std::queue<int> q = std::queue<int>();
	int num_in = 0;
	for (int i = 0; i < size; i++) {
		int num = ar[i];
		if (num % 2 == 0) {
			ar[num_in] = num;
			num_in++;
		}
		else {
			q.push(num);
		}
	}
	while (!q.empty()) {
		int num = q.front();
		q.pop();
		ar[num_in] = num;
		num_in++;
	}
}
void test() {
	int* ar;
	int ar1[] = { 1,2,3,4 };
	int size = 4;

	ar = ar1;
	
	for (int i = 0; i < size; i++) {
		std::cout << ar[i]<<" ";
	}
	std::cout << "\n";
	move(ar,  size);
	for (int i = 0; i < size; i++) {
		std::cout << ar[i] << " ";
	}
	std::cout << "\n";
	
	int ar2[] = { 1,2,3,4,5,6,7,8 };
	ar = ar2;
	size = 8;

	for (int i = 0; i < size; i++) {
		std::cout << ar[i] << " ";
	}
	std::cout << "\n";
	move(ar, size);
	for (int i = 0; i < size; i++) {
		std::cout << ar[i] << " ";
	}
	std::cout << "\n";
}
int main() {
	test();
	std::cin.get();
}