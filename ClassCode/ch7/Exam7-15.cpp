#include"BTree.cpp"	 					//包含二叉链的基本运算算法
#include<vector>
#include<algorithm>
//解法1
bool Ancestor11(BTNode *b, char x,vector<char> &res)	//被Ancestor1函数调用
{	if (b==NULL)                     	//空树返回false
  		return false;
	if (b->lchild!=NULL && b->lchild->data==x)
  	{	res.push_back(b->data);		     //结点b是x结点的祖先
    	return true;
    }
 	if (b->rchild!=NULL && b->rchild->data==x)
  	{	res.push_back(b->data);		     //结点b是x结点的祖先
    	return true;
    }
 	if (Ancestor11(b->lchild,x,res) || Ancestor11(b->rchild,x,res))
  	{	res.push_back(b->data);			//结点b的孩子是x的祖先，则它是x的祖先
   		return true;
   	}
	return false;					  	//其他情况返回false
}
void Ancestor1(BTree &bt,char x,vector<char> &res)	//算法1：返回x结点的祖先
{
	Ancestor11(bt.r,x,res);
	reverse(res.begin(),res.end());   	//逆置res
}

//解法2
void Ancestor21(BTNode *b,char x,vector<char> path,vector<char> &res)
{
	if (b==NULL) return;            	//空树返回
	path.push_back(b->data);
 	if (b->data==x)
  	{	path.pop_back();				//删除x结点
    	res=path;						//复制path到res
		return;                     	//找到后返回
	}
 	Ancestor21(b->lchild,x,path,res);	//在左子树中查找
 	Ancestor21(b->rchild,x,path,res);	//在右子树中查找
}
void Ancestor2(BTree &bt,char x,vector<char> &res)   //算法2：返回x结点的祖先
{
	vector<char> path;
 	Ancestor21(bt.r,x,path,res);
}

//解法3
bool Ancestor31(BTNode *b,char x,vector<char> path,vector<char> &res)
{
	if (b==NULL) return false;            	//空树返回fasle
	path.push_back(b->data);
 	if (b->data==x)
  	{	path.pop_back();				//删除x结点
  		res=path;						//复制path到res
		return true;                    //找到后返回true
	}
 	if (Ancestor31(b->lchild,x,path,res))	//在左子树中查找
 		return true;
 	else
	 	return Ancestor31(b->rchild,x,path,res);	//在右子树中查找
}
void Ancestor3(BTree &bt,char x,vector<char> &res)  		 //算法3：返回x结点的祖先
{
	vector<char> path;
 	Ancestor31(bt.r,x,path,res);
}

int main()
{
	string str="A(B(D(,G)),C(E,F))";
	BTree bt;
	bt.CreateBTree(str);
	cout << "二叉树bt:"; bt.DispBTree(); cout << endl;
	for (char ch='A';ch<='G';ch++)
	{
		cout <<  ch << "结点的所有祖先:";
		vector<char> res;				//存放祖先
		Ancestor2(bt,ch,res);
		for (int i=0;i<res.size();i++)
			cout << " " << res[i];
		cout << endl;
	}
	cout << "销毁二叉树\n";
	return 0;
}
