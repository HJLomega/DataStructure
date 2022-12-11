#include <iostream>
#include <string>
#include <vector>

using namespace std;
//树节点
struct Node
{
	char value;
	Node* left;
	Node* right;
};
Node* exp2tree(string exp) {
	//没有输入
	if (exp =="") {
		return NULL;
	}
	exp2tree(exp);//解析左操作数
	//解析操作符
	exp2tree(exp);//解析操作数
}

//读数字的辅助函数
void read_num(vector<string>& exp,char c) { //c为首字符
	//处理数字
	if (c >= '0' && c <= '9') { 
		string temp(1, c);
		char digit;
		while (cin >> digit && digit >= '0' && digit <= '9') {
			temp = temp + digit;
		}
		exp.push_back(temp);
		read_num(exp, digit);//递归调用处理最后一个读入的字符
	}
	//处理符号
	else{
		string temp(1, c);
		exp.push_back(temp);
	}
}


int main() {
	//词法分析
	vector<string> exp;
	char c;
	while (cin >> c) {
		if (c == '=') {
			break;
		}
		//读数字
		if (c >= '0' && c <= '9') { 
			read_num(exp,c);
		}
		//读符号
		else {
			string temp(1,c);
			exp.push_back(temp);
		}

	}
	//
	Node* tree;
}
