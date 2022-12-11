#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
//树节点
struct Node
{
	string value;
	Node* left;
	Node* right;
};
Node* exp2tree(queue<string>& exp) {
	Node* tree = new Node;
	//解析左表达式
	if (exp.front() == "(") {
		exp.pop(); //去（
		tree->left = exp2tree(exp);
		exp.pop(); //去）
	}
	else {
		//叶子
		Node* leaf = new Node;
		leaf->left = NULL;
		leaf->right = NULL;
		leaf->value = exp.front(); exp.pop();
		tree->left = leaf;
	}
	//解析操作符
	tree->value = exp.front(); exp.pop();
	//解析右表达式
	if (exp.front() == "(") {
		exp.pop(); //去（
		tree->right = exp2tree(exp);
		exp.pop(); //去）
	}
	else {
		//叶子
		Node* leaf = new Node;
		leaf->left = NULL;
		leaf->right = NULL;
		leaf->value = exp.front(); exp.pop();
		tree->right = leaf;
	}
	return tree;
}




int main() {
	//词法分析
	queue<string> exp;
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
			exp.push(temp);
			//由于表达式时正确的，数字后必是符号
			if (c == '=') {
				break;
			}
			string temp2(1, c);
			exp.push(temp2);
		}
		//读符号
		else {
			string temp(1,c);
			exp.push(temp);
		}

	}
	//建树
	Node* tree;
	tree = exp2tree(exp);
	int a = 5;
}
