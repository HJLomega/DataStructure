#include <iostream>
#include <stack>
/*
设计一个算法利用顺序栈将一个十进制正整数d转换为r（2≤r≤16）进制的数，
要求r进制数采用字符串string表示。
*/
std::string d2r(int d,int r) {
	if (r < 2 || r>16) {
		return "";
	}
	std::stack<int> s;
	std::string str = "";
	int rest = 0;
	int q = d;
	while (q != 0) {
		rest = q % r;
		s.push(rest);
		q = q / r;
	}
	char ch;
	int num;
	while (!s.empty()) {
		num = s.top();
		if (num <= 9) {
			ch = '0' + num;
		}
		else {
			ch = num - 10 + 'a';
		}
		s.pop();
		str = str + ch;
	}
	return str;
}

void test() {
	int d = 100;
	int r = 2;
	std::cout << "d=" << d << " r=" << r << " d2r=" << d2r(d, r) << "\n";
	r = 4;
	std::cout << "d=" << d << " r=" << r << " d2r=" << d2r(d, r) << "\n";
	r = 8;
	std::cout << "d=" << d << " r=" << r << " d2r=" << d2r(d, r) << "\n";
	r = 16;
	std::cout << "d=" << d << " r=" << r << " d2r=" << d2r(d, r) << "\n";
}
int main() {
	test();
	std::cin.get();
}