#include"BTree.cpp"				//包含二叉树BTree类
#include<vector>
#include<queue>
//---------------先序遍历算法-----------------------
void PreOrder11(BTNode *b)			//被PreOrder函数调用
{
	if (b!=NULL)
	{
		cout << b->data;			//访问根结点
		PreOrder11(b->lchild);		//先序遍历左子树
		PreOrder11(b->rchild);		//先序遍历右子树
	}
}
void PreOrder1(BTree &bt)			//先序遍历的递归算法
{
	if (bt.r==NULL) return;			//空树直接返回
	PreOrder11(bt.r);
}

void PreOrder2(BTree &bt)			//先序遍历的非递归算法1
{
	if (bt.r==NULL) return;			//空树直接返回
	stack<BTNode *> st;				//定义一个栈
	BTNode *p;
	st.push(bt.r);					//根结点r进栈
	while (!st.empty())				//栈不为空时循环
	{
		p=st.top(); st.pop();		//出栈结点p
		cout << p->data;			//访问结点p
		if (p->rchild!=NULL)		//结点p有右孩子时将右孩子进栈
			st.push(p->rchild);
		if (p->lchild!=NULL)		//结点p有左孩子时将左孩子进栈
			st.push(p->lchild);
	}
}

void PreOrder3(BTree &bt)			//先序遍历的非递归算法2
{
	if (bt.r==NULL) return;			//空树直接返回 
	stack<BTNode *> st;				//定义一个栈
	BTNode *p=bt.r;
	while (!st.empty() || p!=NULL)
	{
		while (p!=NULL)				//p不空时访问所有左下结点并进栈
		{
			cout << p->data;		//访问结点p
			st.push(p);
			p=p->lchild;
		}
		if (!st.empty())			//若栈不空
		{
			p=st.top(); st.pop();	//出栈结点p
			p=p->rchild;			//转向处理其右子树
		}
	}
}

//---------------中序遍历算法-----------------------
void InOrder11(BTNode *b)			//被InOrder函数调用
{
	if (b!=NULL)
	{
		InOrder11(b->lchild);		//中序遍历左子树
		cout << b->data;			//访问根结点
		InOrder11(b->rchild);		//中序遍历右子树
	}
}
void InOrder1(BTree &bt)			//中序遍历的递归算法
{
	if (bt.r==NULL) return;			//空树直接返回 
	InOrder11(bt.r);
}

void InOrder2(BTree &bt)			//中序遍历的非递归算法
{
	if (bt.r==NULL) return;			//空树直接返回 
	stack<BTNode *> st;				//定义一个栈
	BTNode *p=bt.r;
	while (!st.empty() || p!=NULL)	//栈不空或者p不空时循环
	{
		while (p!=NULL) 			//p不空时将所有左下结点进栈
		{
			st.push(p);
			p=p->lchild;
		}
		if (!st.empty())			//若栈不空
		{
			p=st.top(); st.pop();	//出栈结点p
			cout << p->data;		//访问结点p
			p=p->rchild;			//转向处理右子树
		}
	}
}

//---------------后序遍历算法-----------------------
void PostOrder11(BTNode *b)			//被PostOrder函数调用
{
	if (b!=NULL)
	{
		PostOrder11(b->lchild);		//后序遍历左子树
		PostOrder11(b->rchild);		//后序遍历右子树
		cout << b->data;			//访问根结点
	}
}
void PostOrder1(BTree &bt)			//后序遍历的递归算法
{
	if (bt.r==NULL) return;			//空树直接返回 
	PostOrder11(bt.r);
}

void PostOrder2(BTree &bt)			//后序遍历的非递归算法1
{
	if (bt.r==NULL) return;			//空树直接返回 
	BTNode *p; 
	stack<BTNode *> st;				//定义一个栈
    vector<char> res;
	st.push(bt.r);					//根结点进栈 
    while(!st.empty())				//栈不空循环 
	{		
		p=st.top(); st.pop();		//出栈结点p 
		res.push_back(p->data);
		if (p->lchild!=NULL)		//结点p有左孩子时将左孩子进栈
			st.push(p->lchild);
		if (p->rchild!=NULL)		//结点p有右孩子时将右孩子进栈
			st.push(p->rchild);
	}
	vector<char>::reverse_iterator rit;
	for (rit=res.rbegin();rit!=res.rend();rit++)
		cout << *rit;
}

void PostOrder3(BTree &bt)			//后序遍历的非递归算法2
{
	stack<BTNode *> st;				//定义一个栈
	BTNode *p=bt.r,*q;
	bool flag;						//是否在处理栈顶结点，是为true,否则为false
	do
	{
		while (p!=NULL)				//p不空时将所有左下结点进栈
		{
			st.push(p);
			p=p->lchild;
		}
		q=NULL;						//q指向栈顶结点的前一个刚访问的结点
		flag=true;					//表示开始处理栈顶结点
		while (!st.empty() && flag)
		{
			p=st.top();				//取出栈顶结点p
			if (p->rchild==q)		//若结点p的右子树已访问或为空
			{
				cout << p->data;	//访问结点p
				st.pop();			//将结点p退栈
				q=p;				//让q指向则访问的结点
			}
			else					//若结点p的右子树尚未遍历
			{
				p=p->rchild;		//转向处理其右子树
				flag=false;			//表示不再处理栈顶结点
			}
		}
	} while (!st.empty());
}


void PostOrder4(BTree &bt)					//后序遍历的非递归算法2
{
	stack<BTNode *> st;						//定义一个栈
	BTNode *p=bt.r; 
	BTNode *q;								//存放刚刚访问的结点 
	while (!st.empty() || p!=NULL)			//栈不空或者p不空时循环
	{
		if (p!=NULL)						//p不空时将所有左下结点进栈
		{
			st.push(p);
			p=p->lchild;
		}
		else								//p!=NULL
		{
			p=st.top();						//取出栈顶结点p
			if (p->rchild && p->rchild!=q)	//若结点p的右子树非空且尚未遍历
				p=p->rchild;				//转向处理其右子树
			else
			{
				cout << p->data;			//访问结点p
				st.pop();					//将结点p退栈
				q=p;						//让q指向则访问的结点
				p=NULL;						//该结点的左右子树都已出栈，所以要继续出栈
			}
		}
	}
}

//二叉树的层次遍历算法
void LevelOrder(BTree &bt)				//二叉树的层次遍历
{
	BTNode *p;
	queue<BTNode *> qu;					//定义一个队列
	qu.push(bt.r);						//根结点r进队
	while (!qu.empty())					//队不空时循环 
	{
		p=qu.front(); qu.pop();			//出队结点p 
		cout << p->data;				//访问结点p
		if (p->lchild!=NULL)			//有左孩子时将其进队
			qu.push(p->lchild);
		if (p->rchild!=NULL)			//有右孩子时将其进队
			qu.push(p->rchild);
	}
}

int main()
{
	string str="A(B(D(,G)),C(E,F))";
	char x='e';
	BTree bt;
	bt.CreateBTree(str);
	cout << "\n  二叉树bt:"; bt.DispBTree(); cout << endl;
	cout << "  先序遍历\n";
	cout << "       递归先序遍历: ";PreOrder1(bt); cout << endl;
	cout << "    非递归先序遍历1: ";PreOrder2(bt); cout << endl;
	cout << "    非递归先序遍历2: ";PreOrder3(bt); cout << endl;
	cout << "  中序遍历\n";
	cout << "       递归中序遍历: ";InOrder1(bt); cout << endl;
	cout << "    非递归中序遍历1: ";InOrder2(bt); cout << endl;
	cout << "  后序遍历\n";
	cout << "       递归后序遍历: ";PostOrder1(bt); cout << endl;
	cout << "    非递归后序遍历1: ";PostOrder2(bt); cout << endl;
	cout << "    非递归后序遍历2: ";PostOrder4(bt); cout << endl;
	cout << "  层次遍历\n";
	cout << "      层次遍历序列:  ";LevelOrder(bt); cout << endl;
	cout << "  销毁二叉树\n";
	return 0;
}
