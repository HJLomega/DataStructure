#include <iostream>
#include <stack>
#include <string>
/*
�����г��������·ת��������һ��ջ�ṹ����ͼ3.1��ʾ��
���У��ұ߹��������ˣ���߹���������
���ұ߹���ϵĳ�Ƥ���˳��Ϊ1��2��3��4ʱ��
���ִ�в�������ջ����ջ����ջ����ջ����ջ����ջ����ջ����ջ��
������߹���ϵĳ�Ƥ���˳��Ϊ2��4��3��l��
���һ���㷨������n����������a��ʾ�ұ߹���ϵĳ�Ƥ���˳��
������ת��ջ����Щ��Ƥ���±��ţ�
ʹ�ñ��Ϊ�����ĳ�Ƥ�����ڱ��Ϊż���ĳ�Ƥ��ǰ��
��Ҫ��������в������ַ���op�����ս���ַ���ans��
op: I ��ʾ��ջ��O��ʾ��ջ
*/
void trnasform(int* ar, int n) {
	std::stack<int> s = std::stack<int>();
	std::string op = "";
	std::string ans = "";
	for (int i = 0; i < n; i++) {
		int num = ar[i];
		if (num % 2 == 0) {
			s.push(num);
			op = op + "I";
		}
		else {
			ans = ans + ' ' + std::to_string(num);
			op = op + "IO";
		}
	}
	while (!s.empty()) {
		int num = s.top();
		s.pop();
		ans = ans + ' ' + std::to_string(num);
		op = op + "O";
	}
	std::cout << op << "\n";
	std::cout<< ans << "\n";
}
void test() {
	int ar[] = { 1,2,3,4};
	int n = 4;
	trnasform(ar, n);
	int ar2[] = { 7,5,8,2,1,4,62,4,6,7,2 };
	int n2 =11;
	trnasform( ar2,  n2);
}
int main() {
	test();
	std::cin.get();
}