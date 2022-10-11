#include"BTree.cpp"	 						//包含二叉链的基本运算算法

void Trans1(string sb,int i,BTNode *&b)		//被Trans方法调用
{
	if (i<sb.length())
	{
		if (sb[i]!='#')
		{
			b=new BTNode(sb[i]);			//建立根结点
			Trans1(sb,2*i+1,b->lchild);		//递归转换左子树
			Trans1(sb,2*i+2,b->rchild);		//递归转换右子树
		}
		else b=NULL;						//无效结点建立一个空结点
	}
	else b=NULL;							//无效结点建立一个空结点
}
void Trans(string sb, BTree &bt)			//由顺序存储结构产生二叉链存储结构
{
	
	Trans1(sb,0,bt.r);
}

int main()
{
	string str="ABCDE#F##GH##I";
	BTree bt;
	cout << "由顺序存储结构转换成二叉链bt\n";
	Trans(str,bt);
	cout << "二叉树bt:"; bt.DispBTree(); cout << endl;
	return 0;
}
