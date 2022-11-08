#include "../ClassCode/ch7/BTree.cpp"

/*
������������ö������洢�ṹ�����һ���㷨�ж�һ�ö�����bt�Ƿ�Գơ�
��ν�Գ���ָ�����������Ľṹ�ǶԳƵġ�
*/
bool isLeaf(BTNode* bn) { //�����������жϽڵ��Ƿ�ΪҶ��
	return bn != NULL && bn->lchild == NULL && bn->rchild == NULL;
}

bool is_symmetric_helper(BTNode* bn) {//�ݹ麯��
	if (bn == NULL || isLeaf(bn)) {
		return true;
	}
	else if (bn->lchild == NULL || bn->rchild == NULL) {
		return false;
	}
	else {
		return is_symmetric_helper(bn->lchild) && is_symmetric_helper(bn->rchild);
	}
}

bool is_symmetric(BTree& bt) {    //�㷨��ں���
	return is_symmetric_helper(bt.r);
}



void test() { // ���Ժ���
	string str = "A(B(D(,G)),C(E,F))";
	BTree bt;
	bt.CreateBTree(str);
	cout << "������bt:"; bt.DispBTree(); cout << endl;

	cout<<is_symmetric(bt)<<"\n";

	string str2 = "A(B(D(H,G),I),C(E,F))";
	BTree bt2;
	bt2.CreateBTree(str2);
	cout << "������bt:"; bt2.DispBTree(); cout << endl;

	cout << is_symmetric(bt2) << "\n";
}

int main()
{
	test();
	cin.get();
	return 0;
}