#include <iostream>
#include <stack>
/*
假设表达式中允许包含3种括号：圆括号、方括号和大括号。
设计一个算法采用顺序栈判断表达式中的括号是否正确配对。
*/
bool bracketsLeagal(char* ar) {
	std::stack<int> s;
	char* p = ar;
	while (*p != '\0') {
		switch (*p)
		{
		case '(':
		case '[':
		case '{':
			s.push(*p);
			break;
		case ')':
			if (s.empty()) {
				return false;
			}
			else if (s.top() != '(') {
				return false;
			}
			s.pop();
			break;
		case ']':
			if (s.empty()) {
				return false;
			}
			else if (s.top() != '[') {
				return false;
			}
			s.pop();
			break;
		case '}':
			if (s.empty()) {
				return false;
			}
			else if (s.top() != '{') {
				return false;
			}
			s.pop();
			break;

		default:
			break;
		}
		p++;
	}
	return true;
}
void test() {
	char* ar = "(){}[]";
	std::cout << ar << bracketsLeagal(ar)<<"\n";
	 ar = "([sad{sada}00]as)";
	std::cout << ar << bracketsLeagal(ar) << "\n";
	ar = "[(sad{sada}00]as)";
	std::cout << ar << bracketsLeagal(ar) << "\n";
}
int main() {
	test();
	std::cin.get();
}