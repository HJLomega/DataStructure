#include "../ClassCode/ch7/BTree.cpp"
#define VERY_LARGE_INT (1 << 30)
/*
�����������ÿ�����ֵΪ�����ַ������ö������洢�ṹ�洢��
���һ���㷨�������bt����С֦����
��ν��С֦����ָ���Ǹ���㵽���Ҷ�ӽ���·�����ȡ�
*/
bool isLeaf(BTNode* bn) { //�����������жϽڵ��Ƿ�ΪҶ��
	return bn != NULL && bn->lchild == NULL && bn->rchild == NULL;
}

int min_length_helper(BTNode* bn,int min_length,int length) {//�ݹ麯��
	if (bn == NULL) {
		return VERY_LARGE_INT;
	}
	
	if (length > min_length) {               //����ǰ���ȴ�����С���ȣ�ֱ�ӷ���
		return VERY_LARGE_INT;
	}
	else if (isLeaf(bn)) {
		return length;
	}
	else {                                    //�ݹ����
		int left = min_length_helper(bn->lchild, min_length, length+1);
		int right = min_length_helper(bn->rchild, min_length, length+1);
		return left > right ? right : left;     //��Сֵ
	}
}

int min_length(BTree& bt) {    //�㷨��ں���
	return min_length_helper(bt.r, VERY_LARGE_INT,0);
}



void test() { // ���Ժ���
	string str = "A(B(D(,G)),C(E,F))";
	BTree bt;
	bt.CreateBTree(str);
	cout << "������bt:"; bt.DispBTree(); cout << endl;

	cout << min_length(bt) << "\n";

	string str2 = "A(B,C(E,F))";
	BTree bt2;
	bt2.CreateBTree(str2);
	cout << "������bt:"; bt2.DispBTree(); cout << endl;

	cout << min_length(bt2) << "\n";
}

int main()
{
	test();
	cin.get();
	return 0;
}