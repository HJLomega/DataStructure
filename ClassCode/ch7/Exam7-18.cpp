#include"BTree.cpp"	 						//�����������Ļ��������㷨
#include<vector>
#include<queue>
#include<algorithm>

struct QNode								//QNode����
{	BTNode *node;					       	//��ǰ�������
    QNode *pre;                     		//��ǰ����˫�׽�� 
	QNode(BTNode *p1,QNode *p2)     		//���캯��
	{
		node=p1;
		pre=p2;
	}
};

void Ancestor4(BTree &bt,char x,vector<char> &res) 	//��α�����x��������
{
 	queue<QNode *> qu;                         		//����һ������qu
 	qu.push(new QNode(bt.r,NULL));					//�����(˫��ΪNULL)����
 	while (!qu.empty())                   			//�Ӳ���ѭ��
  	{	QNode *p=qu.front(); qu.pop();				//����һ�����
    	if (p->node->data==x)						//��ǰ���Ϊx���
      	{	QNode *q=p->pre;							//qΪ˫��
        	while (q!=NULL)							//�ҵ������Ϊֹ
         	{	res.push_back(q->node->data);
           		q=q->pre;
           	}
           	reverse(res.begin(),res.end());
           	return;
    	}
   		if (p->node->lchild!=NULL)					//������ʱ�������
      		qu.push(new QNode(p->node->lchild,p));	//����˫��Ϊp
     	if (p->node->rchild!=NULL)					//���Һ���ʱ�������
      		qu.push(new QNode(p->node->rchild,p));	//����˫��Ϊp
	}
	while (!qu.empty())								//�ͷŶ���qu��ÿ��Ԫ��ָ��Ľ�� 
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
	cout << "������bt:"; bt.DispBTree(); cout << endl;
	for (char ch='A';ch<='G';ch++)
	{
		cout <<  ch << "������������:";
		vector<char> res;				//�������
		Ancestor4(bt,ch,res);
		for (int i=0;i<res.size();i++)
			cout << " " << res[i];
		cout << endl;
	}
	cout << "���ٶ�����\n";
	return 0;
}
