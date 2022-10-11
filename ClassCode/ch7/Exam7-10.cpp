#include"BTree.cpp"	 				//包含二叉链的基本运算算法
//---基于先序遍历输出所有叶子结点
void DispLeaf11(BTNode *b)
{
	if (b!=NULL)
	{
		if (b->lchild==NULL && b->rchild==NULL)	//根结点为叶子结点时输出
			cout << b->data << " ";		
		DispLeaf11(b->lchild);		//输出左子树的叶子结点
		DispLeaf11(b->rchild);		//输出右子树的叶子结点
	}
}
void DispLeaf1(BTree &bt)
{
	DispLeaf11(bt.r);
}
//---基于中序遍历输出所有叶子结点
void DispLeaf21(BTNode *b)
{
	if (b!=NULL)
	{
		DispLeaf21(b->lchild);		//输出左子树的叶子结点
		if (b->lchild==NULL && b->rchild==NULL)	//根结点为叶子结点时输出
			cout << b->data << " ";		
		DispLeaf21(b->rchild);		//输出右子树的叶子结点
	}
}
void DispLeaf2(BTree &bt)
{
	DispLeaf21(bt.r);
}
//---基于后序遍历输出所有叶子结点
void DispLeaf31(BTNode *b)
{
	if (b!=NULL)
	{
		DispLeaf31(b->lchild);		//输出左子树的叶子结点
		DispLeaf31(b->rchild);		//输出右子树的叶子结点
		if (b->lchild==NULL && b->rchild==NULL)	//根结点为叶子结点时输出
			cout << b->data << " ";		
	}
}
void DispLeaf3(BTree &bt)
{
	DispLeaf31(bt.r);
}

//---基于递归设计方法输出所有叶子结点
void DispLeaf41(BTNode *b)
{
	if (b!=NULL)
	{
		if (b->lchild==NULL && b->rchild==NULL)	//根结点为叶子结点时输出
			cout << b->data << " ";		
		DispLeaf41(b->lchild);		//输出左子树的叶子结点
		DispLeaf41(b->rchild);		//输出右子树的叶子结点
	}
}
void DispLeaf4(BTree &bt)
{
	DispLeaf41(bt.r);
}

int main()
{
	string str="A(B(D(,G)),C(E,F))";
	char x='e';
	BTree bt;
	bt.CreateBTree(str);
	cout << "二叉树bt:"; bt.DispBTree(); cout << endl;
	cout << "DispLeaf1:bt的叶子结点:"; DispLeaf1(bt); cout << endl;
	cout << "DispLeaf2:bt的叶子结点:"; DispLeaf2(bt); cout << endl;
	cout << "DispLeaf3:bt的叶子结点:"; DispLeaf3(bt); cout << endl;
	cout << "DispLeaf4:bt的叶子结点:"; DispLeaf4(bt); cout << endl;
	cout << "销毁二叉树\n";
	return 0;
}
