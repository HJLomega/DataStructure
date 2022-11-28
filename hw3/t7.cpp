#include "../ClassCode/ch7/BTree.cpp"
#include <queue>
/*
�����������ÿ�����ֵΪ�����ַ������ö������洢�ṹ�洢��
���һ���㷨���ж�һ�ö�����bt�Ƿ�Ϊ��ȫ��������
*/
bool is_complete(BTree& bt) {    //�㷨��ں���
	if (bt.r == NULL) {
		return false;
	}
	queue<BTNode*> q = queue<BTNode*>();
	q.push(bt.r);
	bool full = true;   //��ǲ������ʱ���������Ƿ�������
	while (!q.empty()) {           //�������
		int n = q.size();		
		for (int i = 0; i < n; i++)		
		{
			BTNode* p = q.front(); q.pop();	
			bool l = p->lchild != NULL;
			bool r = p->rchild != NULL;
			if (full) {            //��ǰΪ����
				if (l && r) {
					q.push(p->lchild);
					q.push(p->rchild);
				}
				else if (!l && r) {
					return false;
				}
				else {
					full = false;
				}
			}
			else {  //��ǰ��������
				if (l && r) {
					return false;
				}
			}
		}
	}
	return true;
}

void test() { // ���Ժ���
	string str = "A(B(D(,G)),C(E,F))";
	BTree bt;
	bt.CreateBTree(str);
	cout << "������bt:"; bt.DispBTree(); cout << endl;

	cout << is_complete(bt) << "\n";

	string str2 = "A(B(D(H,G),I),C(E,F))";
	BTree bt2;
	bt2.CreateBTree(str2);
	cout << "������bt:"; bt2.DispBTree(); cout << endl;

	cout << is_complete(bt2) << "\n";
}

int main()
{
	test();
	cin.get();
	return 0;
}