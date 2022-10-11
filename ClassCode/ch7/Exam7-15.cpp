#include"BTree.cpp"	 					//�����������Ļ��������㷨
#include<vector>
#include<algorithm>
//�ⷨ1
bool Ancestor11(BTNode *b, char x,vector<char> &res)	//��Ancestor1��������
{	if (b==NULL)                     	//��������false
  		return false;
	if (b->lchild!=NULL && b->lchild->data==x)
  	{	res.push_back(b->data);		     //���b��x��������
    	return true;
    }
 	if (b->rchild!=NULL && b->rchild->data==x)
  	{	res.push_back(b->data);		     //���b��x��������
    	return true;
    }
 	if (Ancestor11(b->lchild,x,res) || Ancestor11(b->rchild,x,res))
  	{	res.push_back(b->data);			//���b�ĺ�����x�����ȣ�������x������
   		return true;
   	}
	return false;					  	//�����������false
}
void Ancestor1(BTree &bt,char x,vector<char> &res)	//�㷨1������x��������
{
	Ancestor11(bt.r,x,res);
	reverse(res.begin(),res.end());   	//����res
}

//�ⷨ2
void Ancestor21(BTNode *b,char x,vector<char> path,vector<char> &res)
{
	if (b==NULL) return;            	//��������
	path.push_back(b->data);
 	if (b->data==x)
  	{	path.pop_back();				//ɾ��x���
    	res=path;						//����path��res
		return;                     	//�ҵ��󷵻�
	}
 	Ancestor21(b->lchild,x,path,res);	//���������в���
 	Ancestor21(b->rchild,x,path,res);	//���������в���
}
void Ancestor2(BTree &bt,char x,vector<char> &res)   //�㷨2������x��������
{
	vector<char> path;
 	Ancestor21(bt.r,x,path,res);
}

//�ⷨ3
bool Ancestor31(BTNode *b,char x,vector<char> path,vector<char> &res)
{
	if (b==NULL) return false;            	//��������fasle
	path.push_back(b->data);
 	if (b->data==x)
  	{	path.pop_back();				//ɾ��x���
  		res=path;						//����path��res
		return true;                    //�ҵ��󷵻�true
	}
 	if (Ancestor31(b->lchild,x,path,res))	//���������в���
 		return true;
 	else
	 	return Ancestor31(b->rchild,x,path,res);	//���������в���
}
void Ancestor3(BTree &bt,char x,vector<char> &res)  		 //�㷨3������x��������
{
	vector<char> path;
 	Ancestor31(bt.r,x,path,res);
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
		Ancestor2(bt,ch,res);
		for (int i=0;i<res.size();i++)
			cout << " " << res[i];
		cout << endl;
	}
	cout << "���ٶ�����\n";
	return 0;
}
