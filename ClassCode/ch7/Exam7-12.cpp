#include"BTree.cpp"	 							//包含二叉链的基本运算算法

int Level1(BTNode *b,char x,int h)				//被Level()算法调用
{	if (b==NULL)
  		return 0;								//空树不能找到该结点
	else if (b->data==x)
  		return h;								//根结点即为所找,返回其层次
 	else
  	{	int l=Level1(b->lchild,x,h+1);			//在左子树中查找
    	if (l!=0)
      		return l;							//左子树中找到了,返回其层次l
    	else
      		return Level1(b->rchild,x,h+1);	  	//左子树中未找到,再在右子树中查找
	}
}
int Level(BTree &bt,char x)             		//求解算法
{
	return Level1(bt.r,x,1);
}

int main()
{
	string str="A(B(D(,G)),C(E,F))";
	BTree bt;
	bt.CreateBTree(str);
	cout << "二叉树bt:"; bt.DispBTree(); cout << endl;
	for (char ch='A';ch<='H';ch++)
		cout << ch << "结点的层次: " << Level(bt,ch) << endl; 
	return 0;
}
