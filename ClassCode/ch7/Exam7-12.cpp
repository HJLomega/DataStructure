#include"BTree.cpp"	 							//�����������Ļ��������㷨

int Level1(BTNode *b,char x,int h)				//��Level()�㷨����
{	if (b==NULL)
  		return 0;								//���������ҵ��ý��
	else if (b->data==x)
  		return h;								//����㼴Ϊ����,��������
 	else
  	{	int l=Level1(b->lchild,x,h+1);			//���������в���
    	if (l!=0)
      		return l;							//���������ҵ���,��������l
    	else
      		return Level1(b->rchild,x,h+1);	  	//��������δ�ҵ�,�����������в���
	}
}
int Level(BTree &bt,char x)             		//����㷨
{
	return Level1(bt.r,x,1);
}

int main()
{
	string str="A(B(D(,G)),C(E,F))";
	BTree bt;
	bt.CreateBTree(str);
	cout << "������bt:"; bt.DispBTree(); cout << endl;
	for (char ch='A';ch<='H';ch++)
		cout << ch << "���Ĳ��: " << Level(bt,ch) << endl; 
	return 0;
}
