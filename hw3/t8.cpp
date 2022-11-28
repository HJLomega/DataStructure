#include "../ClassCode/ch7/BTree.cpp"

/*
假设含有n个结点的二叉树中每个结点值为单个字符并不相同。
设计一个算法采用二叉树的层次遍历序列level[]和中序序列in[]构造其二叉链存储结构。
*/


BTNode* CreateBTree(char level[], char in[], int l1, int r1, int l2, int r2)  //递归构造
{
	if (l2 > r2)
	{
		return NULL;
	}
	else
	{
		BTNode* bt = new BTNode();

		int i, j;//分别指向level和in中数组的元素
		int flag = 0;

		//寻找根结点，若level中第一个与in中元素匹配的即为根结点
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

BTree* contruct(char level[], char in[],int len) {    //算法入口函数
	BTree *t =  new BTree();
	t->r = CreateBTree(level, in, 0, len - 1, 0, len - 1);
	return t;
}



void test() { // 测试函数
	string str = "A(B(D(,G)),C(E,F))";
	BTree bt;
	bt.CreateBTree(str);
	cout << "二叉树bt:"; bt.DispBTree(); cout << endl;

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