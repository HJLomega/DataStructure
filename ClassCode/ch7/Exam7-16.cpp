#include"BTree.cpp"	 					//包含二叉链的基本运算算法
#include<vector>
#include<algorithm>

void Ancestor4(BTree &bt,char x,vector<char> &res)	//后序遍历的非递归算法求x的祖先 
{
	stack<BTNode *> st;					//定义一个栈
	BTNode *p=bt.r,*q;
	bool flag;							//是否在处理栈顶结点，是为true,否则为false
	do
	{
		while (p!=NULL)					//p不空时将所有左下结点进栈
		{
			st.push(p);
			p=p->lchild;
		}
		q=NULL;							//q指向栈顶结点的前一个刚访问的结点
		flag=true;						//表示开始处理栈顶结点
		while (!st.empty() && flag)
		{
			p=st.top();					//取出栈顶结点p
			if (p->rchild==q)			//若结点p的右子树已访问或为空
			{
				if (p->data==x)			//访问的结点p恰好是结点x 
				{
					st.pop();			//出栈结点x 
					while (!st.empty())
					{
						res.push_back(st.top()->data);
						st.pop();
					}
					reverse(res.begin(),res.end());		//逆置res 
					return;
				}
				st.pop();				//将结点p退栈
				q=p;					//让q指向则访问的结点
			}
			else						//若结点p的右子树尚未遍历
			{
				p=p->rchild;			//转向处理其右子树
				flag=false;				//表示不再处理栈顶结点
			}
		}
	} while (!st.empty());
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
		Ancestor4(bt,ch,res);
		for (int i=0;i<res.size();i++)
			cout << " " << res[i];
		cout << endl;
	}
	cout << "销毁二叉树\n";
	return 0;
}
