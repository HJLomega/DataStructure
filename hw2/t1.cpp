#include <iostream>
/*
������1��O�ֱ��ʾ��ջ�ͳ�ջ������ջ�ĳ�̬����̬��Ϊ�գ�
��ջ�ͳ�ջ�Ĳ������пɱ�ʾΪ����1��O��ɵ����С�
д��һ���㷨�ж������Ĳ��������Ƿ�Ϸ������Ϸ�����true��
���򷵻�false�����豻�ж��Ĳ��������Ѵ���һά�����У�
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