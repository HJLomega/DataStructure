#include"BTree.cpp"	 					//�����������Ļ��������㷨

void KCount1(BTNode *b,int h,int k,int &cnt)
{
 	if (b==NULL) return;				//��������
 	if (h==k) cnt++;					//��ǰ��Ľ���ڵ�k�㣬cnt��1
 	if (h<k)							//��ǰ���С��k���ݹ鴦����������
  	{	KCount1(b->lchild,h+1,k,cnt);
    	KCount1(b->rchild,h+1,k,cnt);
    }
}

int KCount(BTree &bt,int k)				//����������������k�������
{
	int cnt=0;
 	KCount1(bt.r,1,k,cnt);
 	return cnt;
}

int main()
{
	string str="A(B(D(,G)),C(E,F))";
	BTree bt;
	bt.CreateBTree(str);
	cout << "������bt:"; bt.DispBTree(); cout << endl;
	for (int k=1;k<=5;k++)
		cout << "��" << k << "��Ľ�����: " << KCount(bt,k) << endl; 
	cout << "���ٶ�����\n";
	return 0;
}
