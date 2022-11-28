

#include "../ClassCode/ch7/BTree.cpp"
#include <queue>
/*
�����������ÿ�����ֵΪ�����ַ������ö������洢�ṹ�洢��
���һ���㷨�����ò�α��������������bt�Ŀ�ȡ�
*/


int width(BTree& bt) {    //�㷨��ں���
	if (bt.r == NULL) {
		return 0;
	}
	queue<BTNode*> q = queue<BTNode*>();
	q.push(bt.r);
	int rv = 1;
	while (!q.empty()) {
		int n = q.size();		//�����ǰ�������
		rv = n < rv ? rv : n;
		for (int i = 0; i < n; i++)		//���ӵ�ǰ���n�����
		{
			BTNode* p = q.front(); q.pop();	//����һ�����
			if (p->lchild != NULL)		//������ʱ�������
				q.push(p->lchild);
			if (p->rchild != NULL)		//���Һ���ʱ�������
				q.push(p->rchild);
		}
	}
	return rv;
}



void test() { // ���Ժ���
	string str = "A(B(D(,G)),C(E,F))";
	BTree bt;
	bt.CreateBTree(str);
	cout << "������bt:"; bt.DispBTree(); cout << endl;

	cout << width(bt) << "\n";

	string str2 = "A(B(D(H,G),I),C(E,F))";
	BTree bt2;
	bt2.CreateBTree(str2);
	cout << "������bt:"; bt2.DispBTree(); cout << endl;

	cout << width(bt2) << "\n";
}

int main()
{
	test();
	cin.get();
	return 0;
}