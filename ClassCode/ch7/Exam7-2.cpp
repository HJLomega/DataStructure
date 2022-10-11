#include<iostream>
#include<vector>
using namespace std;
struct PNode 						//双亲存储结构元素类型
{	char data;						//存放结点值,假设为char类型 
	int parent;						//存放双亲索引
	PNode(char d,int p)				//构造函数 
	{
		data=d;
		parent=p;
	}
};

int Level(vector<PNode> t,int i)	//求t中索引i的结点的层次
{
	if (i<0 || i>=t.size())			//参数错误返回0 
		return 0;
	int cnt=1;
 	while (t[i].parent!=-1)			//没有到达根结点时循环
  	{	cnt++;
    	i=t[i].parent;             //移动到双亲结点
 	}
	return cnt;
}
int main()
{
	vector<PNode> t;
	t.push_back(PNode('A',-1));
	t.push_back(PNode('B',0));
	t.push_back(PNode('C',0));
	t.push_back(PNode('D',1));
	t.push_back(PNode('E',1));
	t.push_back(PNode('F',1));
	t.push_back(PNode('G',4));
	for (int i=0;i<t.size();i++)
		cout << "结点" << t[i].data << "的层次: " << Level(t,i) << endl;
	return 0;
}
	

