#include"BTree.cpp"	 					//�����������Ļ��������㷨
#include<vector>
#include<algorithm>

void Swap11(BTNode *&b)						//�����������
{
	if (b!=NULL)
	{	swap(b->lchild,b->rchild);			//���������b�����Һ���ָ�� 
		Swap11(b->lchild);					//�ݹ齻��������
		Swap11(b->rchild); 					//�ݹ齻��������
	}
}
void Swap1(BTree &bt)						//����㷨1
{
	Swap11(bt.r);
}
void Swap21(BTNode *&b)						//���ں������
{
	if (b!=NULL)
	{
		Swap21(b->lchild);					//�ݹ齻��������
		Swap21(b->rchild); 					//�ݹ齻��������
		swap(b->lchild,b->rchild);			//���������b�����Һ���ָ�� 
	}
}
void Swap2(BTree &bt)						//����㷨2 
{
	Swap21(bt.r);
}
void Swap31(BTNode *&b)						//�����������
{
	if (b!=NULL)
	{
		Swap31(b->lchild);					//�ݹ齻��������
		swap(b->lchild,b->rchild);			//���������b�����Һ���ָ�� 
		Swap31(b->rchild); 					//�ݹ齻��������
	}
}
void Swap3(BTree &bt)						//����㷨3
{
	Swap31(bt.r);
}


int main()
{
	string str="A(B(D(,G)),C(E,F))";
	BTree bt1,bt2,bt3;
	bt1.CreateBTree(str);
	cout << "������bt1:"; bt1.DispBTree(); cout << endl;
	cout << "�ⷨ1������bt1����������" << endl; 
	Swap1(bt1);
	cout << "������bt1:"; bt1.DispBTree(); cout << endl;

	bt2.CreateBTree(str);
	cout << "������bt2:"; bt2.DispBTree(); cout << endl;
	cout << "�ⷨ2������bt2����������" << endl; 
	Swap2(bt2);
	cout << "������bt2:"; bt2.DispBTree(); cout << endl;

	bt3.CreateBTree(str);
	cout << "������bt3:"; bt3.DispBTree(); cout << endl;
	cout << "�ⷨ3������bt3����������" << endl; 
	Swap3(bt3);
	cout << "������bt3:"; bt3.DispBTree(); cout << endl;
	return 0;
}
