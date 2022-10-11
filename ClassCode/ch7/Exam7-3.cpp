#include<iostream>
#include<vector>
using namespace std;
struct SonNode         	        		//孩子链存储结构结点类
{	char data;                 			//存放结点值,假设为char类型
	vector<SonNode *> sons;				//指向孩子结点的指针向量 
	SonNode() {}						//构造函数 
	SonNode(char d):data(d) {}			//重载构造函数 
};
int Height(SonNode *t)                	//求t的高度
{	if (t==NULL)              			//空树高度为0
  		return 0;
 	int maxsh=0;
	for (int i=0;i<t->sons.size();i++)  //遍历所有子树
  	{	int sh=Height(t->sons[i]);     	//求子树t.sons[i]的高度
    	maxsh=max(maxsh,sh);         	//求所有子树的最大高度
    }
 	return maxsh+1;
}
int main()
{
	SonNode *t,*b,*c,*d,*e,*f,*g;
	t=new SonNode('A');					//根结点 
	b=new SonNode('B');
	c=new SonNode('C');
	d=new SonNode('D');
	e=new SonNode('E');
	f=new SonNode('F');
	g=new SonNode('G');
	t->sons.push_back(b);
	t->sons.push_back(c);
	b->sons.push_back(d);
	b->sons.push_back(e);
	b->sons.push_back(f);
	e->sons.push_back(g);
	cout << "树高度: " << Height(t) << endl;
	return 0;
}
	

