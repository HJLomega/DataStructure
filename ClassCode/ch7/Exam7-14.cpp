#include"BTree.cpp"	 					//包含二叉链的基本运算算法

void KCount1(BTNode *b,int h,int k,int &cnt)
{
 	if (b==NULL) return;				//空树返回
 	if (h==k) cnt++;					//当前层的结点在第k层，cnt增1
 	if (h<k)							//当前层次小于k，递归处理左、右子树
  	{	KCount1(b->lchild,h+1,k,cnt);
    	KCount1(b->rchild,h+1,k,cnt);
    }
}

int KCount(BTree &bt,int k)				//先序遍历求二叉树第k层结点个数
{
	int cnt=0;
 	KCount1(bt.r,1,k,cnt);
 	return cnt;
}

int main()
{
	string str="A(B(D(,G)),C(E,F))";
	BTree bt;
	bt.CreateBTree(str);
	cout << "二叉树bt:"; bt.DispBTree(); cout << endl;
	for (int k=1;k<=5;k++)
		cout << "第" << k << "层的结点个数: " << KCount(bt,k) << endl; 
	cout << "销毁二叉树\n";
	return 0;
}
