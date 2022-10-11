#include"BTree.cpp"	 							//�����������Ļ��������㷨
#include<queue>
struct QNode									//����Ԫ����
{
	int lev;									//���Ĳ��
    BTNode *node;					     		//���ָ��
	QNode(int l,BTNode *p)						//���캯�� 
	{	lev=l;
    	node=p;
	}
};
int KCount1(BTree &bt,int k)           			//�ⷨ1�����������k�������
{	int cnt=0;							  		//�ۼƵ�k�������
	queue<QNode> qu;                      		//����һ������qu
 	qu.push(QNode(1,bt.r));						//�����(���Ϊ1)����
 	while (!qu.empty())                    		//�Ӳ���ѭ��
  	{	QNode p=qu.front(); qu.pop();			//����һ�����
    	if (p.lev>k)							//��ǰ���Ĳ�δ���k������cnt
      		return cnt;
     	if (p.lev==k)
      		cnt++;								//��ǰ����ǵ�k��Ľ��,cnt��1
    	else									//��ǰ���Ĳ��С��k
      	{	if (p.node->lchild!=NULL)			//������ʱ�������
         		qu.push(QNode(p.lev+1,p.node->lchild));
         	if (p.node->rchild!=NULL)			//���Һ���ʱ�������
         		qu.push(QNode(p.lev+1,p.node->rchild));
    	}
	}
	return cnt;
}

int KCount2(BTree &bt,int k)	          		//�ⷨ2�����������k�������
{	int cnt=0;									//�ۼƵ�k�������
	queue<BTNode *> qu;                        	//����һ������qu
	int curl=1;								  	//��ǰ���,��1��ʼ
 	BTNode *last=bt.r,*p,*q;					//��1�����ҽ��
 	qu.push(bt.r);								//��������
 	while (!qu.empty())                    		//�Ӳ���ѭ��
  	{	if (curl>k)								//����Ŵ���kʱ����cnt,���ټ���
       		return cnt;
    	p=qu.front(); qu.pop();					//����һ�����p
    	if (curl==k)
      		cnt++;								//��ǰ����ǵ�k��Ľ��,cnt��1
     	if (p->lchild!=NULL)					//������ʱ�������
      	{	q=p->lchild;
        	qu.push(q);
    	}
     	if (p->rchild!=NULL)					//���Һ���ʱ�������
      	{	q=p->rchild;
       		qu.push(q);
       	}
    	if (p==last)							//��ǰ������н�㴦�����
      	{	last=q;								//��lastָ����һ������ҽ��
       		curl++;
       	}
	}
	return cnt;
}

int KCount3(BTree &bt,int k)			       	//�ⷨ3�����������k�������
{	if (k<1) return 0;							//k<1����0
  	queue<BTNode *> qu;                    		//����һ������qu
 	int curl=1;								    //��ǰ���,��1��ʼ
	qu.push(bt.r);								//��������
	while (!qu.empty())                    		//�Ӳ���ѭ��
  	{	if (curl==k)							//��ǰ��Ϊ��k�㣬���ض���Ԫ�ظ���
      		return qu.size();
		int n=qu.size();						//�����ǰ�������
    	for (int i=0;i<n;i++)					//���ӵ�ǰ���n�����
      	{	BTNode *p=qu.front(); qu.pop();		//����һ�����
       		if (p->lchild!=NULL)				//������ʱ�������
         		qu.push(p->lchild);
         	if (p->rchild!=NULL)				//���Һ���ʱ�������
         		qu.push(p->rchild);
    	}
    	curl++;
	}											//ת����һ��
 	return 0;
}

int main()
{
	string str="A(B(D(,G)),C(E,F))";
	BTree bt;
	bt.CreateBTree(str);
	cout << "������bt:"; bt.DispBTree(); cout << endl;
	for (int k=1;k<=5;k++)
		cout << "��" << k << "��Ľ�����: " << KCount3(bt,k) << endl; 
	cout << "���ٶ�����\n";
	return 0;
}
