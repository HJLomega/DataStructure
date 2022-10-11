#include"BTree.cpp"										//包含二叉链的基本运算算法
#include<vector>
#include<algorithm>
BTNode *CreateBTree11(vector<char> pres,int i,vector<char> ins,int j,int n)	//被CreateBTree1调用
{
	if (n<=0) return NULL;
 	char d=pres[i];										//取根结点值d
 	BTNode *b=new BTNode(d);							//创建根结点(结点值为d)
 	int p=j;
 	while (ins[p]!=d) p++;								//在ins中找到根结点的索引p
	int k=p-j;											//确定左子树中结点个数k
 	b->lchild=CreateBTree11(pres,i+1,ins,j,k);		  	//递归构造左子树
 	b->rchild=CreateBTree11(pres,i+k+1,ins,p+1,n-k-1);	//递归构造右子树
 	return b;
}

void CreateBTree1(BTree &bt,vector<char> pres,vector<char> ins) //由先序序列pres和中序序列ins构造二叉链
{
	int n=pres.size();
	bt.r=CreateBTree11(pres,0,ins,0,n);
}


BTNode *CreateBTree21(vector<char> posts,int i,vector<char> ins,int j,int n)	//被CreateBTree2调用
{ 	if (n<=0) return NULL;
 	char d=posts[i+n-1];						     	//取后序序列尾元素即根结点值d
	BTNode *b=new BTNode(d);			         		//创建根结点(结点值为d)
 	int p=j;
 	while (ins[p]!=d) p++;								//在ins中找到根结点的索引p
	int k=p-j;											//确定左子树中结点个数k
	b->lchild=CreateBTree21(posts,i,ins,j,k);			//递归构造左子树
 	b->rchild=CreateBTree21(posts,i+k,ins,p+1,n-k-1);	//递归构造右子树
 	return b;
}

void CreateBTree2(BTree &bt,vector<char> posts,vector<char> ins) //由后序序列posts和中序序列ins构造二叉链
{
	int n=posts.size();
	bt.r=CreateBTree21(posts,0,ins,0,n);
}


//序列化
string PreOrderSeq1(BTNode *b)
{
	if (b==NULL) return "#";
 	string s(1,b->data);							//含根结点
 	s+=PreOrderSeq1(b->lchild);						//产生左子树的序列化序列
 	s+=PreOrderSeq1(b->rchild);						//产生右子树的序列化序列
 	return s;
}
string PreOrderSeq(BTree &bt)                		//二叉树bt的序列化
{
	return PreOrderSeq1(bt.r);
}

//反序列化
BTNode *CreateBTree31(string s,int &i)				//引用参数i相当于全局变量 
{
	if (i>=s.length()) return NULL;					//i超界返回NULL 
	char d=s[i]; i++; 								//取s[i]的值d 
	if (d=='#') return NULL;						//若为"#"，返回NULL
    BTNode *b=new BTNode(d);    					//创建根结点(结点值为d
	b->lchild=CreateBTree31(s,i);					//递归构造左子树
    b->rchild=CreateBTree31(s,i);					//递归构造右子树
    return b;
}
void CreateBTree3(BTree &bt,string s)				//由序列化序列s创建二叉链：反序列化
{
	int i=0;
 	bt.r=CreateBTree31(s,i);
}


/*
int main()
{
	string a="ABDGCEF";
	vector<char> pres(a.begin(),a.end());
	string b="DGBAECF";
	vector<char> ins(b.begin(),b.end());
	string c="GDBEFCA"; 
	vector<char> posts(c.begin(),c.end());
	BTree bt1;
	cout << "由" << a << "先序序列和" << b << "中序序列创建bt1" << endl; 
	CreateBTree1(bt1,pres,ins);
	cout << "二叉树bt1:"; bt1.DispBTree(); cout << endl;
	cout << "销毁二叉树bt1\n";

	BTree bt2;
	cout << "由" << b << "中序序列和" << c << "后序序列创建bt2" << endl; 
	CreateBTree2(bt2,posts,ins);
	cout << "二叉树bt2:"; bt2.DispBTree(); cout << endl;
	cout << "销毁二叉树bt2\n";
	return 0;
}
*/
int main()
{
	string str="A(B(D(,G)),C(E,F))";
	BTree bt;
	bt.CreateBTree(str);
	cout << "二叉树bt:"; bt.DispBTree(); cout << endl;
	string s= PreOrderSeq(bt);
	cout << "序列化序列s: " << s << endl; 
	cout << "反序列化" << endl;
	BTree bt1;
	CreateBTree3(bt1,s);
	cout << "二叉树bt1:"; bt1.DispBTree(); cout << endl;
	return 0;
}
