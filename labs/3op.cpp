#include <iostream>
#include <string>
#include <vector>

using namespace std;
//���ڵ�
struct Node
{
	char value;
	Node* left;
	Node* right;
};
Node* exp2tree(string exp) {
	//û������
	if (exp =="") {
		return NULL;
	}
	exp2tree(exp);//�����������
	//����������
	exp2tree(exp);//����������
}

//�����ֵĸ�������
void read_num(vector<string>& exp,char c) { //cΪ���ַ�
	//��������
	if (c >= '0' && c <= '9') { 
		string temp(1, c);
		char digit;
		while (cin >> digit && digit >= '0' && digit <= '9') {
			temp = temp + digit;
		}
		exp.push_back(temp);
		read_num(exp, digit);//�ݹ���ô������һ��������ַ�
	}
	//�������
	else{
		string temp(1, c);
		exp.push_back(temp);
	}
}


int main() {
	//�ʷ�����
	vector<string> exp;
	char c;
	while (cin >> c) {
		if (c == '=') {
			break;
		}
		//������
		if (c >= '0' && c <= '9') { 
			read_num(exp,c);
		}
		//������
		else {
			string temp(1,c);
			exp.push_back(temp);
		}

	}
	//
	Node* tree;
}
