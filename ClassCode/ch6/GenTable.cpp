#include "GenTable.h"				//包括广义表类的声明
#include <string.h>
template <typename T>
GenTableClass<T>::GenTableClass()		//构造函数
{
	ghead=new GLNode<T>();
	ghead->val.sublist=NULL;
	ghead->link=NULL;
}
template <typename T>
GenTableClass<T>::~GenTableClass()		//析构函数
{
	DestroyGL(ghead);
}
template <typename T>
void GenTableClass<T>::DestroyGL(GLNode<T> *g)	//释放广义表所有结点空间
{
	GLNode<T> *g1,*g2;
	g1=g->val.sublist;		//g1指向广义表的第一个元素
	while (g1!=NULL)		//遍历所有元素
	{
		if (g1->tag==0)		//若为原子结点
		{
			g2=g1->link;	//g2临时保存兄弟结点
			delete g1;		//释放g1所指原子结点
			g1=g2;			//g1指向后继兄弟结点
		}
		else				//若为子表
		{
			g2=g1->link;	//g2临时保存兄弟结点
			DestroyGL(g1);	//递归释放g1所指子表的空间
			g1=g2;			//g1指向后继兄弟结点
		}
	}
	delete g;				//释放头结点空间
}
template <typename T>
int GenTableClass<T>::GLLength()//求广义表的长度
{
	int n=0;
	GLNode<T> *g1;
	g1=ghead->val.sublist;		//g1指向广义表的第一个元素
	while (g1!=NULL)
	{
		n++;					//累加元素个数
		g1=g1->link;
	}
	return n;
}
template <typename T>
int GenTableClass<T>::GLDepth()	//求广义表的深度
{
	return GLDepth1(ghead);
}
template <typename T>
int GenTableClass<T>::GLDepth1(GLNode<T> *g) //被GLDepth函数调用
{
	GLNode<T> *g1;
	int max=0,dep;
	if (g->tag==0) return 0;	//为原子时返回0
	g1=g->val.sublist;			//g1指向第一个元素
	if (g1==NULL) return 1;		//为空表时返回1
	while (g1!=NULL)			//遍历表中的每一个元素
	{
		if (g1->tag==1)			//元素为子表的情况
		{
			dep=GLDepth1(g1);	//递归调用求出子表的深度
			if (dep>max) max=dep;//max为同一层所求过的子表中深度的最大值
		}
		g1=g1->link;			//使g1指向下一个元素
	}
	return(max+1);				//返回表的深度
}
template <typename T>
void GenTableClass<T>::DispGL()	//输出广义表
{
	DispGL1(ghead);
}
template <typename T>
void GenTableClass<T>::DispGL1(GLNode<T> *g)//被DispGL调用
{
	if (g!=NULL)						//表不为空判断
	{
		if (g->tag==0)					//g的元素为原子时
			cout << g->val.data;		//输出原子值
		else							//g的元素为子表时
		{
			cout << "(";				//输出'('
			if (g->val.sublist==NULL)	//为空表时
				cout << "#";
			else						//为非空子表时
				DispGL1(g->val.sublist);//递归输出子表
			cout << ")";				//输出')'
		}
		if (g->link!=NULL)				//有兄弟时
		{
			cout << ",";
			DispGL1(g->link);			//递归输出g的兄弟
		}
	}
}
template <typename T>
void GenTableClass<T>::CreateGL(char *&str)	//建立由括号表示法str表示的广义表链式存储结构
{
	ghead=CreateGL1(str);
}
template <typename T>
GLNode<T> *GenTableClass<T>::CreateGL1(char *&s)//被CreateGL()调用
{
	GLNode<T> *g;
	char ch=*s++;						//取一个字符ch
	if (ch!='\0')						//串s未遍历完,先处理(、原子和#字符
	{
		g=new GLNode<T>();				//创建一个新结点
		if (ch=='(')					//ch为左括号时
		{
			g->tag=1;					//新结点作为表头结点
			g->val.sublist=CreateGL1(s);//递归构造子表并链到表头结点
		}
		else if (ch=='#') g=NULL;		//遇到'#'字符,表示空表
		else							//为原子字符
		{
			g->tag=0;					//新结点作为原子结点
			g->val.data=ch;
		}
	}
	else g=NULL;						//串s遍历完毕,g置为空
	ch=*s++;							//取下一个字符ch
	if (g!=NULL)						//前面至少构造了一个结点，再处理')'和','字符
		if (ch==',')					//当前字符为','
			g->link=CreateGL1(s);		//递归构造兄弟结点
		else							//为')'或串s遍历完毕,将*g结点的兄弟指针置为NULL
			g->link=NULL;
		return g;						//返回广义表g
}
/*main用作调试
void main()
{
	char *str="(((#),(a)),b,(((#))))";
	char s[100];
	strcpy(s,str);
	GenTableClass<char> gl;
	gl.CreateGL(str);
	cout << "广义表gl:"; gl.DispGL(); cout << endl;
	cout << "str=     " << s << endl;
	cout << "gl的长度:" << gl.GLLength() << endl;
	cout << "gl的深度:" << gl.GLDepth() << endl;
	cout << "main执行完毕,销毁建立的广义表" << endl;
}

main用作调试
void main()
{
	char *str="((#),((#),c,((#))))";
	GenTableClass<char> gl;
	gl.CreateGL(str);
	cout << "广义表gl:"; gl.DispGL(); cout << endl;
	cout << "gl的长度:" << gl.GLLength() << endl;
	cout << "gl的深度:" << gl.GLDepth() << endl;
	cout << "main执行完毕,销毁建立的广义表" << endl;
}
*/