#include"BTree.cpp"	 						//�����������Ļ��������㷨

void Trans1(string sb,int i,BTNode *&b)		//��Trans��������
{
	if (i<sb.length())
	{
		if (sb[i]!='#')
		{
			b=new BTNode(sb[i]);			//���������
			Trans1(sb,2*i+1,b->lchild);		//�ݹ�ת��������
			Trans1(sb,2*i+2,b->rchild);		//�ݹ�ת��������
		}
		else b=NULL;						//��Ч��㽨��һ���ս��
	}
	else b=NULL;							//��Ч��㽨��һ���ս��
}
void Trans(string sb, BTree &bt)			//��˳��洢�ṹ�����������洢�ṹ
{
	
	Trans1(sb,0,bt.r);
}

int main()
{
	string str="ABCDE#F##GH##I";
	BTree bt;
	cout << "��˳��洢�ṹת���ɶ�����bt\n";
	Trans(str,bt);
	cout << "������bt:"; bt.DispBTree(); cout << endl;
	return 0;
}
