#include"BTree.cpp"	 				//�����������Ļ��������㷨
//---������������������
int NodeCount11(BTNode *b)
{
	int m,n,k;
	if (b!=NULL)
	{
		k=1;						//��������1
		m=NodeCount11(b->lchild);	//�������������Ľ�����
		n=NodeCount11(b->rchild);	//�������������Ľ�����
		return k+m+n;
	}
	else return 0;		//����������Ϊ0
}
int NodeCount1(BTree &bt)			//������������������
{
	return NodeCount11(bt.r);
}
//---������������������
int NodeCount21(BTNode *b)
{
	int m,n,k;
	if (b!=NULL)
	{
		m=NodeCount21(b->lchild);	//�������������Ľ�����
		k=1;						//��������1
		n=NodeCount21(b->rchild);	//�������������Ľ�����
		return k+m+n;
	}
	else return 0;					//����������Ϊ0
}
int NodeCount2(BTree &bt)			//������������������
{
	return NodeCount21(bt.r);
}
//---���ں�������������
int NodeCount31(BTNode *b)
{
	int m,n,k;
	if (b!=NULL)
	{
		m=NodeCount31(b->lchild);	//�������������Ľ�����
		n=NodeCount31(b->rchild);	//�������������Ľ�����
		k=1;						//��������1
		return k+m+n;
	}
	else return 0;					//����������Ϊ0
}
int NodeCount3(BTree &bt)			//���ں�������������
{
	return NodeCount31(bt.r);
}
//---���ڵݹ���Ʒ����������
int NodeCount41(BTNode *b)
{
	if (b==NULL) return 0;			//����������Ϊ0
	else
		return(NodeCount41(b->lchild)+NodeCount41(b->rchild)+1);
}
int NodeCount4(BTree &bt)			//���ڵݹ���Ʒ���������� 
{
	return NodeCount41(bt.r);
}

int main()
{
	string str="A(B(D(,G)),C(E,F))";
	char x='e';
	BTree bt;
	bt.CreateBTree(str);
	cout << "������bt:"; bt.DispBTree(); cout << endl;
	cout << "NodeCount1:bt�Ľ�����:" << NodeCount1(bt) << endl;
	cout << "NodeCount2:bt�Ľ�����:" << NodeCount2(bt) << endl;
	cout << "NodeCount3:bt�Ľ�����:" << NodeCount3(bt) << endl;
	cout << "NodeCount4:bt�Ľ�����:" << NodeCount4(bt) << endl;
	cout << "���ٶ�����\n";
	return 0;
}
