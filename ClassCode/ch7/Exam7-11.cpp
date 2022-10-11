#include"BTree.cpp"	 					//包含二叉链的基本运算算法
#include<vector>
#include<algorithm>

void Swap11(BTNode *&b)						//基于先序遍历
{
	if (b!=NULL)
	{	swap(b->lchild,b->rchild);			//交换根结点b的左右孩子指针 
		Swap11(b->lchild);					//递归交换左子树
		Swap11(b->rchild); 					//递归交换右子树
	}
}
void Swap1(BTree &bt)						//求解算法1
{
	Swap11(bt.r);
}
void Swap21(BTNode *&b)						//基于后序遍历
{
	if (b!=NULL)
	{
		Swap21(b->lchild);					//递归交换左子树
		Swap21(b->rchild); 					//递归交换右子树
		swap(b->lchild,b->rchild);			//交换根结点b的左右孩子指针 
	}
}
void Swap2(BTree &bt)						//求解算法2 
{
	Swap21(bt.r);
}
void Swap31(BTNode *&b)						//基于中序遍历
{
	if (b!=NULL)
	{
		Swap31(b->lchild);					//递归交换左子树
		swap(b->lchild,b->rchild);			//交换根结点b的左右孩子指针 
		Swap31(b->rchild); 					//递归交换右子树
	}
}
void Swap3(BTree &bt)						//求解算法3
{
	Swap31(bt.r);
}


int main()
{
	string str="A(B(D(,G)),C(E,F))";
	BTree bt1,bt2,bt3;
	bt1.CreateBTree(str);
	cout << "二叉树bt1:"; bt1.DispBTree(); cout << endl;
	cout << "解法1：交换bt1的左右子树" << endl; 
	Swap1(bt1);
	cout << "二叉树bt1:"; bt1.DispBTree(); cout << endl;

	bt2.CreateBTree(str);
	cout << "二叉树bt2:"; bt2.DispBTree(); cout << endl;
	cout << "解法2：交换bt2的左右子树" << endl; 
	Swap2(bt2);
	cout << "二叉树bt2:"; bt2.DispBTree(); cout << endl;

	bt3.CreateBTree(str);
	cout << "二叉树bt3:"; bt3.DispBTree(); cout << endl;
	cout << "解法3：交换bt3的左右子树" << endl; 
	Swap3(bt3);
	cout << "二叉树bt3:"; bt3.DispBTree(); cout << endl;
	return 0;
}
