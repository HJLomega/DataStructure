#include "../ClassCode/ch7/BTree.cpp"

/*
�����������ÿ�����ֵΪ�����ַ������ö������洢�ṹ�洢��
���һ���㷨�����ҵ���Ĵ������һ�ö�����bt�е�����Ҷ�ӽ�㡣
*/
bool isLeaf(BTNode *bn);
void RightLeaves_helper(BTNode* bn);

void RightLeaves(BTree &bt) {    //�㷨����
	RightLeaves_helper(bt.r);
	cout << "\n";
}

void RightLeaves_helper(BTNode* bn) { //�������������ڵݹ�
	if (bn == NULL) {
		return;
	}
	if (isLeaf(bn)) {
		std::cout << bn->data << " ";
	}
	else {
		RightLeaves_helper(bn->rchild);
		RightLeaves_helper(bn->lchild);
	}
}

bool isLeaf(BTNode *bn) { //�����������жϽڵ��Ƿ�ΪҶ��
	return bn != NULL && bn->lchild == NULL && bn->rchild == NULL;
}

void test() {
	string str = "A(B(D(,G)),C(E,F))";
	char x = 'e';
	BTree bt;
	bt.CreateBTree(str);
	cout << "������bt:"; bt.DispBTree(); cout << endl;
	
	RightLeaves(bt);
}

int main()
{
	test();
	cin.get();
	return 0;
}