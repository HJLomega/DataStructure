#include "../ClassCode/ch7/BTree.cpp"

/*
���躬��n�����Ķ�������ÿ�����ֵΪ�����ַ�������ͬ��
���һ���㷨���ö������Ĳ�α�������level[]����������in[]������������洢�ṹ��
*/


BTNode* CreateBTree(char level[], char in[], int l1, int r1, int l2, int r2)  //�ݹ鹹��
{
	if (l2 > r2)
	{
		return NULL;
	}
	else
	{
		BTNode* bt = new BTNode();

		int i, j;//�ֱ�ָ��level��in�������Ԫ��
		int flag = 0;

		//Ѱ�Ҹ���㣬��level�е�һ����in��Ԫ��ƥ��ļ�Ϊ�����
		for (i = l1; i <= r1; ++i)
		{
			for (j = l2; j <= r2; ++j)
			{
				if (level[i] == in[j])
				{
					flag = 1;
					break;
				}
			}

			if (flag == 1)
				break;
		}

		bt->data = level[i];
		bt->lchild = CreateBTree(level, in, l1 + 1, r1, l2, j - 1);
		bt->rchild = CreateBTree(level, in, l1 + 1, r1, j + 1, r2);

		return bt;
	}
}

BTree* contruct(char level[], char in[],int len) {    //�㷨��ں���
	BTree *t =  new BTree();
	t->r = CreateBTree(level, in, 0, len - 1, 0, len - 1);
	return t;
}



void test() { // ���Ժ���
	string str = "A(B(D(,G)),C(E,F))";
	BTree bt;
	bt.CreateBTree(str);
	cout << "������bt:"; bt.DispBTree(); cout << endl;

	char level[] = { 'A','B','C','D','E','F','G','\0'};
	char in[] = { 'D','G','B','A','E','C','F','\0' };
	cout <<"level[]: "<< level << "\n";
	cout << "in[]:" << in << "\n";
	contruct(level, in, 7)->DispBTree();
	
}

int main()
{
	test();
	cin.get();
	return 0;
}