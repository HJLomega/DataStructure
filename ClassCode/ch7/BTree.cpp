#include <iostream>
#include<stack>
using namespace std;
struct BTNode									//二叉链中结点类型
{
	char data;									//数据元素
	BTNode *lchild;								//指向左孩子结点
	BTNode *rchild;								//指向右孩子结点
	BTNode()									//构造函数 
	{
		lchild=rchild=NULL;
	}
	BTNode(char d)								//重载构造函数 
	{
		data=d;
		lchild=rchild=NULL;
	}
};
class BTree										//二叉树类
{
public:											//为了简单，所有成员设计为公有属性 
	BTNode *r;									//二叉树的根结点r
	//二叉树的基本运算
	BTree()										//构造函数,建立一棵空树
	{
		r=NULL;
	}
	~BTree()									//析构函数
	{
		DestroyBTree(r);						//调用DestroyBTree()函数
		r=NULL;
	}
	DestroyBTree(BTNode *b)						//释放所有的结点空间
	{
		if (b!=NULL)
		{
			DestroyBTree(b->lchild);			//递归释放左子树
			DestroyBTree(b->rchild);			//递归释放右子树
			delete b;							//释放根结点
		}
	}
	void CreateBTree(string str)				//创建以r为根结点的二叉链存储结构
	{
		stack<BTNode *> st;						//建立一个栈st
		BTNode *p;
		bool flag;
		int i=0;
		while (i<str.length())					//循环扫描str中每个字符
		{
			switch(str[i])
			{
			case '(':
				st.push(p);						//刚刚新建的结点有孩子,将其进栈
				flag=true;
				break;
			case ')':
				st.pop();						//栈顶结点的子树处理完，出栈
				break;
			case ',':
				flag=false;						//开始处理栈顶结点的右孩子
				break;
			default:
				p=new BTNode(str[i]);			//新建一个结点p
				if (r==NULL)
					r=p;						//若尚未建立根结点,p作为根结点
				else							//已建立二叉树根结点
				{	if (flag)					//新结点p作为栈顶结点的左孩子
					{	if (!st.empty())
							st.top()->lchild=p;
					}
					else						//新结点p作为栈顶结点的右孩子
					{	if (!st.empty())
							st.top()->rchild=p;
					}
				}
				break;
			}
			i++;								//继续遍历
		}
	}
	void DispBTree()							//将二叉链转换成括号表示法
	{
		DispBTree1(r);
	}
	void DispBTree1(BTNode *b)					//被DispBTree函数调用
	{
		if (b!=NULL)
		{
			cout << b->data;					//输出根结点值
			if (b->lchild!=NULL || b->rchild!=NULL)
			{
				cout << "(";					//有孩子结点时输出"("
				DispBTree1(b->lchild);			//递归输出左子树
				if (b->rchild!=NULL)
					cout << ",";				//有右孩子结点时输出","
				DispBTree1(b->rchild);			//递归输出右子树
				cout << ")";					//输出")"
			}
		}
	}
	BTNode *FindNode(char x)					//查找值为x的结点算法
	{
		return FindNode1(r,x);
	}
	BTNode *FindNode1(BTNode *b,char x)			//被FindNode函数调用
	{
		BTNode *p;
		if (b==NULL) return NULL;				//b为空时返回NULL
		else if (b->data==x) return b;			//b所指结点值为x时返回t
		else
		{
			p=FindNode1(b->lchild,x);			//在左子树中查找
			if (p!=NULL)
				return p;						//在左子树中找到p结点，返回p
			else
				return FindNode1(b->rchild,x);	//返回在右子树中查找结果
		}
	}
	int Height()								//求二叉树高度的算法
	{
		return Height1(r);
	}
	int Height1(BTNode *b)						//被Height函数调用
	{
		if (b==NULL)							//空树的高度为0
			return 0;
		else
			return max(Height1(b->lchild),Height1(b->rchild))+1;
	}
};
/*
int main()
{
	string str="A(B(D(,G)),C(E,F))";
	char x='e';
	BTree bt;
	bt.CreateBTree(str);
	cout << "二叉树bt:"; bt.DispBTree(); cout << endl;
	cout << "bt的高度:" << bt.Height() << endl;
	if (bt.FindNode(x))
		cout << "bt中找到值为" << x << "的结点\n";
	else
		cout << "bt中没有找到值为" << x << "的结点\n";
	cout << "销毁二叉树\n";
	return 0;
}
*/
