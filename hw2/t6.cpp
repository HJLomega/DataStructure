#include <iostream>
#include <stack>
#include <string>
/*
用于列车编组的铁路转轨网络是一种栈结构，如图3.1所示。
其中，右边轨道是输入端，左边轨道是输出瑞。
当右边轨道上的车皮编号顺序为1、2、3、4时，
如果执行操作：进栈、进栈、出栈、进栈、进栈、出栈、出栈、出栈，
则在左边轨道上的车皮编号顺序为2、4、3、l。
设计一个算法，给定n个整数序列a表示右边轨道上的车皮编号顺序，
用上述转轨栈对这些车皮重新编排，
使得编号为奇数的车皮都排在编号为偶数的车皮的前面
，要求产生所有操作的字符串op和最终结果字符串ans。
op: I 表示进栈，O表示出栈
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