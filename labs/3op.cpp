#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
//���ڵ�
struct Node
{
	string value;
	Node* left;
	Node* right;
};
Node* exp2tree(queue<string>& exp) {
	Node* tree = new Node;
	//��������ʽ
	if (exp.front() == "(") {
		exp.pop(); //ȥ��
		tree->left = exp2tree(exp);
		exp.pop(); //ȥ��
	}
	else {
		//Ҷ��
		Node* leaf = new Node;
		leaf->left = NULL;
		leaf->right = NULL;
		leaf->value = exp.front(); exp.pop();
		tree->left = leaf;
	}
	//����������
	tree->value = exp.front(); exp.pop();
	//�����ұ��ʽ
	if (exp.front() == "(") {
		exp.pop(); //ȥ��
		tree->right = exp2tree(exp);
		exp.pop(); //ȥ��
	}
	else {
		//Ҷ��
		Node* leaf = new Node;
		leaf->left = NULL;
		leaf->right = NULL;
		leaf->value = exp.front(); exp.pop();
		tree->right = leaf;
	}
	return tree;
}




int main() {
	//�ʷ�����
	queue<string> exp;
	char c;
	while (cin >> c) {
		if (c == '=') {
			break;
		}
		//������
		if (c >= '0' && c <= '9') { 
			string temp(1, c);
			while (cin >> c && c >= '0' && c <= '9') {
				temp += c;
			}
			exp.push(temp);
			//���ڱ��ʽʱ��ȷ�ģ����ֺ���Ƿ���
			if (c == '=') {
				break;
			}
			string temp2(1, c);
			exp.push(temp2);
		}
		//������
		else {
			string temp(1,c);
			exp.push(temp);
		}

	}
	//����
	Node* tree;
	tree = exp2tree(exp);
	int a = 5;
}
