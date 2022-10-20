#include <iostream>
#include <queue>
/*
��һ����������a�����һ���㷨������ż��λ��Ԫ���ƶ�����������λԪ�ص�ǰ�棬Ҫ�����ǵ���Դ��򲻸ı䡣
���磬a={1��2��3��4��5��6��7��8}���ƶ���a={2��4��6��8��1��3��5��7}��
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