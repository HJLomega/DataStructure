#include"BTree.cpp"	 						//包含二叉链的基本运算算法
#include<vector>
#include<queue>
#include<algorithm>

struct QNode								//QNode类型
{	BTNode *node;					       	//当前结点引用
    QNode *pre;                     		//当前结点的双亲结点 
	QNode(BTNode *p1,QNode *p2)     		//构造函数
	{
		node=p1;
		pre=p2;
	}
};

void Ancestor4(BTree &bt,char x,vector<char> &res) 	//层次遍历求x结点的祖先
{
 	queue<QNode *> qu;                         		//定义一个队列qu
 	qu.push(new QNode(bt.r,NULL));					//根结点(双亲为NULL)进队
 	while (!qu.empty())                   			//队不空循环
  	{	QNode *p=qu.front(); qu.pop();				//出队一个结点
    	if (p->node->data==x)						//当前结点为x结点
      	{	QNode *q=p->pre;							//q为双亲
        	while (q!=NULL)							//找到根结点为止
         	{	res.push_back(q->node->data);
           		q=q->pre;
           	}
           	reverse(res.begin(),res.end());
           	return;
    	}
   		if (p->node->lchild!=NULL)					//有左孩子时将其进队
      		qu.push(new QNode(p->node->lchild,p));	//置其双亲为p
     	if (p->node->rchild!=NULL)					//有右孩子时将其进队
      		qu.push(new QNode(p->node->rchild,p));	//置其双亲为p
	}
	while (!qu.empty())								//释放队列qu中每个元素指向的结点 
	{
		QNode *p=qu.front(); qu.pop();
		delete p;
	}
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
