/*
�������������������������������Ϊ�洢�ṹ���д洢����д������������Ĵ洢�ṹ������д�㷨����ö���������������ֵ��a��b֮��Ĺؼ��֣�����a < b����������������������ֵС�ڸ�����ֵ������������ֵ���ڸ�����ֵ������û�йؼ������صĽ�㡣
*/
#include <iostream>
class BTNode {
public:
	char data;
	BTNode* lchild;
	BTNode* rchild;
	bool ltag;//0  ��ʾlchildָ���������,1  ��ʾlchildָ�����ǰ����㼴Ϊ����
	bool rtag;

	BTNode(char d, BTNode* lc, BTNode* rc, bool lt = 0, bool rt = 0) {
		data = d;
		lchild = lc;
		rchild = rc;
		ltag = lt;
		rtag = rt;
	}
};

void report(BTNode* T, int a, int b) {
	BTNode* p = T->lchild;       // pָ������
	while (p != T) {     // �������������ʱ��p==T
		while (p->ltag == 0)  p = p->lchild;  // ������������������㣩
		if (p->data > a && p->data < b)
			std::cout << p->data;

		while (p->rtag == 1 && p->rchild != T) { //�������������˫�ף�ֱ�����Һ��ӻ��ߵ����ұ�
			p = p->rchild;
			if (p->data > b) return;    // ����ֵ����b���㷨����
			if (p->data > a && p->data < b)
				std::cout << p->data;
		}
		p = p->rchild;          // ���������p����������������
	}
}
