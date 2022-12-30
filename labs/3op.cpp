#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;
//树节点
struct Node
{
	string value;
	Node* left;
	Node* right;
};
bool is_num(string& s) {
	return s[0]>='0'&&s[0]<='9';
}
Node* exp2tree(vector<string> post_exp) {
	stack<Node*> node_stack;
	for (string s : post_exp) {
		if (is_num(s)) {
			Node* leaf = new Node;
			leaf->left = NULL;
			leaf->right = NULL;
			leaf->value = s;
			node_stack.push(leaf);
		}
		else {
			Node* T1 = node_stack.top(); node_stack.pop();
			Node* T2 = node_stack.top(); node_stack.pop();
			Node* temp = new Node;
			temp->left = T2;
			temp->right = T1;
			temp->value = s;
			node_stack.push(temp);
		}
	}
	return node_stack.top();
}
int evaluate(Node* tree) {
	//叶子
	string& s = tree->value;
	if (is_num(tree->value)) {
		return stoi(tree->value);
	}
	//非叶子
	if (s == "+") {
		return evaluate(tree->left) + evaluate(tree->right);
	}
	if (s == "-") {
		return evaluate(tree->left) - evaluate(tree->right);
	}
	if (s == "*") {
		return evaluate(tree->left) * evaluate(tree->right);
	}
	if (s == "/") {
		return evaluate(tree->left) / evaluate(tree->right);
	}
	return 0;
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
			string temp(1, c);
			while (cin >> c && c >= '0' && c <= '9') {
				temp += c;
			}
			exp.push_back(temp);
			//由于表达式时正确的，数字后必是符号
			if (c == '=') {
				break;
			}
			string temp2(1, c);
			exp.push_back(temp2);
		}
		//读符号
		else {
			string temp(1, c);
			exp.push_back(temp);
		}

	}

	//转为后缀
	vector<string> post_exp;
	stack<string> op_stack;
	for (string s : exp) {

		if (is_num(s)) {
			post_exp.push_back(s);
		}
		//将'('进栈
		else if (s == "(") {
			op_stack.push(s);
		}
		//栈中'('以前的运算符依次出栈,再将'('退栈
		else if (s == ")") {
			while (true) {
				string temp = op_stack.top(); op_stack.pop();
				if (temp == "(") {
					break;
				}
				post_exp.push_back(temp);
			}
		}
		else {
			//考虑符号优先级
			if (op_stack.empty()) {
				op_stack.push(s);
			}
			else {
				string top = op_stack.top();
				//若s优先级低于top,出栈并存放到post_exp中直到该条件成立,再将ch进栈
				while (!(top == "(" || ((s == "*" || s == "/") && (top == "+" || top == "-")))) {
					string temp = op_stack.top(); op_stack.pop();
					post_exp.push_back(temp);
					if (!op_stack.empty()) {
						top = op_stack.top();
					}
					else {
						break;
					}
				}
				op_stack.push(s);
			}
		}
	}
	//字符串exp扫描完毕,则退栈的所有运算符并存放到post_exp中
	while (!op_stack.empty()) {
		string temp = op_stack.top(); op_stack.pop();
		post_exp.push_back(temp);
	}

	//建树
	Node* tree;
	tree = exp2tree(post_exp);
	//输出
	if (tree != NULL) {
		cout << tree->value << " ";
	}
	if (tree->left != NULL) {
		cout << tree->left->value << " ";
	}
	if (tree->right != NULL) {
		cout << tree->right->value << " ";
	}
	cout << "\n";
	//计算
	cout << evaluate(tree);

}



