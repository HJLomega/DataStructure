#include <iostream>
#include <stack>
/*
������ʽ���������3�����ţ�Բ���š������źʹ����š�
���һ���㷨����˳��ջ�жϱ��ʽ�е������Ƿ���ȷ��ԡ�
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