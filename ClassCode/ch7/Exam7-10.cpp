#include"BTree.cpp"	 				//�����������Ļ��������㷨
//---������������������Ҷ�ӽ��
void DispLeaf11(BTNode *b)
{
	if (b!=NULL)
	{
		if (b->lchild==NULL && b->rchild==NULL)	//�����ΪҶ�ӽ��ʱ���
			cout << b->data << " ";		
		DispLeaf11(b->lchild);		//�����������Ҷ�ӽ��
		DispLeaf11(b->rchild);		//�����������Ҷ�ӽ��
	}
}
void DispLeaf1(BTree &bt)
{
	DispLeaf11(bt.r);
}
//---������������������Ҷ�ӽ��
void DispLeaf21(BTNode *b)
{
	if (b!=NULL)
	{
		DispLeaf21(b->lchild);		//�����������Ҷ�ӽ��
		if (b->lchild==NULL && b->rchild==NULL)	//�����ΪҶ�ӽ��ʱ���
			cout << b->data << " ";		
		DispLeaf21(b->rchild);		//�����������Ҷ�ӽ��
	}
}
void DispLeaf2(BTree &bt)
{
	DispLeaf21(bt.r);
}
//---���ں�������������Ҷ�ӽ��
void DispLeaf31(BTNode *b)
{
	if (b!=NULL)
	{
		DispLeaf31(b->lchild);		//�����������Ҷ�ӽ��
		DispLeaf31(b->rchild);		//�����������Ҷ�ӽ��
		if (b->lchild==NULL && b->rchild==NULL)	//�����ΪҶ�ӽ��ʱ���
			cout << b->data << " ";		
	}
}
void DispLeaf3(BTree &bt)
{
	DispLeaf31(bt.r);
}

//---���ڵݹ���Ʒ����������Ҷ�ӽ��
void DispLeaf41(BTNode *b)
{
	if (b!=NULL)
	{
		if (b->lchild==NULL && b->rchild==NULL)	//�����ΪҶ�ӽ��ʱ���
			cout << b->data << " ";		
		DispLeaf41(b->lchild);		//�����������Ҷ�ӽ��
		DispLeaf41(b->rchild);		//�����������Ҷ�ӽ��
	}
}
void DispLeaf4(BTree &bt)
{
	DispLeaf41(bt.r);
}

int main()
{
	string str="A(B(D(,G)),C(E,F))";
	char x='e';
	BTree bt;
	bt.CreateBTree(str);
	cout << "������bt:"; bt.DispBTree(); cout << endl;
	cout << "DispLeaf1:bt��Ҷ�ӽ��:"; DispLeaf1(bt); cout << endl;
	cout << "DispLeaf2:bt��Ҷ�ӽ��:"; DispLeaf2(bt); cout << endl;
	cout << "DispLeaf3:bt��Ҷ�ӽ��:"; DispLeaf3(bt); cout << endl;
	cout << "DispLeaf4:bt��Ҷ�ӽ��:"; DispLeaf4(bt); cout << endl;
	cout << "���ٶ�����\n";
	return 0;
}
