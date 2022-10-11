#include"BTree.cpp"	 				//包含二叉链的基本运算算法
//---基于先序遍历求结点个数
int NodeCount11(BTNode *b)
{
	int m,n,k;
	if (b!=NULL)
	{
		k=1;						//根结点计数1
		m=NodeCount11(b->lchild);	//遍历求左子树的结点个数
		n=NodeCount11(b->rchild);	//遍历求右子树的结点个数
		return k+m+n;
	}
	else return 0;		//空树结点个数为0
}
int NodeCount1(BTree &bt)			//基于先序遍历求结点个数
{
	return NodeCount11(bt.r);
}
//---基于中序遍历求结点个数
int NodeCount21(BTNode *b)
{
	int m,n,k;
	if (b!=NULL)
	{
		m=NodeCount21(b->lchild);	//遍历求左子树的结点个数
		k=1;						//根结点计数1
		n=NodeCount21(b->rchild);	//遍历求右子树的结点个数
		return k+m+n;
	}
	else return 0;					//空树结点个数为0
}
int NodeCount2(BTree &bt)			//基于中序遍历求结点个数
{
	return NodeCount21(bt.r);
}
//---基于后序遍历求结点个数
int NodeCount31(BTNode *b)
{
	int m,n,k;
	if (b!=NULL)
	{
		m=NodeCount31(b->lchild);	//遍历求左子树的结点个数
		n=NodeCount31(b->rchild);	//遍历求右子树的结点个数
		k=1;						//根结点计数1
		return k+m+n;
	}
	else return 0;					//空树结点个数为0
}
int NodeCount3(BTree &bt)			//基于后序遍历求结点个数
{
	return NodeCount31(bt.r);
}
//---基于递归设计方法求结点个数
int NodeCount41(BTNode *b)
{
	if (b==NULL) return 0;			//空树结点个数为0
	else
		return(NodeCount41(b->lchild)+NodeCount41(b->rchild)+1);
}
int NodeCount4(BTree &bt)			//基于递归设计方法求结点个数 
{
	return NodeCount41(bt.r);
}

int main()
{
	string str="A(B(D(,G)),C(E,F))";
	char x='e';
	BTree bt;
	bt.CreateBTree(str);
	cout << "二叉树bt:"; bt.DispBTree(); cout << endl;
	cout << "NodeCount1:bt的结点个数:" << NodeCount1(bt) << endl;
	cout << "NodeCount2:bt的结点个数:" << NodeCount2(bt) << endl;
	cout << "NodeCount3:bt的结点个数:" << NodeCount3(bt) << endl;
	cout << "NodeCount4:bt的结点个数:" << NodeCount4(bt) << endl;
	cout << "销毁二叉树\n";
	return 0;
}
