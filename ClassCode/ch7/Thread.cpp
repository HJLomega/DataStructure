#include<iostream>
#include<stack>
using namespace std;
struct BthNode							//线索二叉树结点类型
{
	char data;							//存放结点值
	BthNode *lchild,*rchild;			//左、右孩子或线索的指针
	int ltag,rtag;						//左、右标记
	BthNode() {}						//构造函数 
	BthNode(char d)						//重载构造函数
	{
		data=d;
		ltag=rtag=0;
		lchild=rchild=NULL;
	}
};
class ThreadTree						//中序线索二叉树类模板
{
	BthNode *r;							//二叉树的根结点指针
	BthNode *root;           			//线索二叉树的头结点指针
	BthNode *pre;						//用于中序线索化,指向中序前驱结点
public:
	ThreadTree()						//构造函数,用于初始化
	{
		r=NULL;							//初始二叉树为空树
		root=NULL;						//初始线索二叉树为空树
	}
	~ThreadTree()						//析构函数,用于释放线索二叉树的所有结点
	{
		if (r!=NULL) DestroyBTree1(r);	//释放原二叉树的所有结点
		if (root!=NULL)	delete root;	//释放头结点
	}
	void DestroyBTree1(BthNode *b)		//释放原二叉树的所有结点
	{
		if (b->ltag==0)					//b有左孩子,释放左子树
			DestroyBTree1(b->lchild);
		if (b->rtag==0)								//b有右孩子,释放右子树
			DestroyBTree1(b->rchild);
		delete b;
	}	
	void CreateBTree(string str)				//创建以r为根结点的二叉链存储结构
	{
		stack<BthNode *> st;						//建立一个栈st
		BthNode *p;
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
				p=new BthNode(str[i]);			//新建一个结点p
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
	void DispBTree()							//输出二叉树的括号表示串
	{
		DispBTree1(r);
	}
	void DispBTree1(BthNode *b)					//被DispBTree函数调用
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

	void CreateThread()							//建立以root为头结点的中序线索二叉树
	{
		root=new BthNode();						//创建头结点root
		root->ltag=0; root->rtag=1;				//头结点域置初值
		root->rchild=r;
		if (r==NULL)							//r为空树时
		{
			root->lchild=root;
			root->rchild=NULL;
		}
		else									//r不为空树时
		{
			root->lchild=r;
			pre=root;							//pre指向结点p的前驱结点,供加线索用
			Thread(r);							//中序遍历线索化二叉树
			pre->rchild=root;					//最后处理,加入指向根结点的线索
			pre->rtag=1;
			root->rchild=pre;					//头结点右线索化
		}
	}
	void Thread(BthNode *&p)					//对结点p的二叉树中序线索化
	{
		if (p!=NULL)
		{
			Thread(p->lchild);					//左子树线索化
			if (p->lchild==NULL)				//前驱线索
			{
				p->lchild=pre;					//给结点p添加前驱线索
				p->ltag=1;
			}
			else p->ltag=0;
			if (pre->rchild==NULL)
			{
				pre->rchild=p;					//给结点pre添加后继线索
				pre->rtag=1;
			}
			else pre->rtag=0;
			pre=p;
			Thread(p->rchild);					//右子树线索化
		}
	}
	void ThInOrder()							//中序线索二叉树的中序遍历
	{
		BthNode *p=root->lchild;				//p指向根结点
		while (p!=root)
		{
			while (p!=root && p->ltag==0)
				p=p->lchild;						//找开始结点p
			cout << p->data;						//访问结点p
			while (p->rtag==1 && p->rchild!=root)	//如果是线索，一直找下去
			{
				p=p->rchild;
				cout << p->data;					//访问结点p
			}
			p=p->rchild;							//如果不再是线索，转向其右子树
		}
	}
}; 
int main()
{
	string 	str="A(B(D(,G)),C(E,F))";
	ThreadTree tb;
	tb.CreateBTree(str);				//建立原二叉树
	cout << "二叉树tb:"; tb.DispBTree(); cout << endl;
	cout << "构造中序线索化二叉树\n";
	tb.CreateThread();					//中序线索化
	cout << "非递归中序遍历:"; tb.ThInOrder(); cout << endl;
	cout << "销毁线索二叉树\n";
	return 0;
}
