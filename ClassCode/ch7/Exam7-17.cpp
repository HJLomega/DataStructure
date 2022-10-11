#include"BTree.cpp"	 							//包含二叉链的基本运算算法
#include<queue>
struct QNode									//队列元素类
{
	int lev;									//结点的层次
    BTNode *node;					     		//结点指针
	QNode(int l,BTNode *p)						//构造函数 
	{	lev=l;
    	node=p;
	}
};
int KCount1(BTree &bt,int k)           			//解法1：求二叉树第k层结点个数
{	int cnt=0;							  		//累计第k层结点个数
	queue<QNode> qu;                      		//定义一个队列qu
 	qu.push(QNode(1,bt.r));						//根结点(层次为1)进队
 	while (!qu.empty())                    		//队不空循环
  	{	QNode p=qu.front(); qu.pop();			//出队一个结点
    	if (p.lev>k)							//当前结点的层次大于k，返回cnt
      		return cnt;
     	if (p.lev==k)
      		cnt++;								//当前结点是第k层的结点,cnt增1
    	else									//当前结点的层次小于k
      	{	if (p.node->lchild!=NULL)			//有左孩子时将其进队
         		qu.push(QNode(p.lev+1,p.node->lchild));
         	if (p.node->rchild!=NULL)			//有右孩子时将其进队
         		qu.push(QNode(p.lev+1,p.node->rchild));
    	}
	}
	return cnt;
}

int KCount2(BTree &bt,int k)	          		//解法2：求二叉树第k层结点个数
{	int cnt=0;									//累计第k层结点个数
	queue<BTNode *> qu;                        	//定义一个队列qu
	int curl=1;								  	//当前层次,从1开始
 	BTNode *last=bt.r,*p,*q;					//第1层最右结点
 	qu.push(bt.r);								//根结点进队
 	while (!qu.empty())                    		//队不空循环
  	{	if (curl>k)								//当层号大于k时返回cnt,不再继续
       		return cnt;
    	p=qu.front(); qu.pop();					//出队一个结点p
    	if (curl==k)
      		cnt++;								//当前结点是第k层的结点,cnt增1
     	if (p->lchild!=NULL)					//有左孩子时将其进队
      	{	q=p->lchild;
        	qu.push(q);
    	}
     	if (p->rchild!=NULL)					//有右孩子时将其进队
      	{	q=p->rchild;
       		qu.push(q);
       	}
    	if (p==last)							//当前层的所有结点处理完毕
      	{	last=q;								//让last指向下一层的最右结点
       		curl++;
       	}
	}
	return cnt;
}

int KCount3(BTree &bt,int k)			       	//解法3：求二叉树第k层结点个数
{	if (k<1) return 0;							//k<1返回0
  	queue<BTNode *> qu;                    		//定义一个队列qu
 	int curl=1;								    //当前层次,从1开始
	qu.push(bt.r);								//根结点进队
	while (!qu.empty())                    		//队不空循环
  	{	if (curl==k)							//当前层为第k层，返回队中元素个数
      		return qu.size();
		int n=qu.size();						//求出当前层结点个数
    	for (int i=0;i<n;i++)					//出队当前层的n个结点
      	{	BTNode *p=qu.front(); qu.pop();		//出队一个结点
       		if (p->lchild!=NULL)				//有左孩子时将其进队
         		qu.push(p->lchild);
         	if (p->rchild!=NULL)				//有右孩子时将其进队
         		qu.push(p->rchild);
    	}
    	curl++;
	}											//转向下一层
 	return 0;
}

int main()
{
	string str="A(B(D(,G)),C(E,F))";
	BTree bt;
	bt.CreateBTree(str);
	cout << "二叉树bt:"; bt.DispBTree(); cout << endl;
	for (int k=1;k<=5;k++)
		cout << "第" << k << "层的结点个数: " << KCount3(bt,k) << endl; 
	cout << "销毁二叉树\n";
	return 0;
}
