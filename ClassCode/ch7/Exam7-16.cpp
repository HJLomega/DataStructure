#include"BTree.cpp"	 					//�����������Ļ��������㷨
#include<vector>
#include<algorithm>

void Ancestor4(BTree &bt,char x,vector<char> &res)	//��������ķǵݹ��㷨��x������ 
{
	stack<BTNode *> st;					//����һ��ջ
	BTNode *p=bt.r,*q;
	bool flag;							//�Ƿ��ڴ���ջ����㣬��Ϊtrue,����Ϊfalse
	do
	{
		while (p!=NULL)					//p����ʱ���������½���ջ
		{
			st.push(p);
			p=p->lchild;
		}
		q=NULL;							//qָ��ջ������ǰһ���շ��ʵĽ��
		flag=true;						//��ʾ��ʼ����ջ�����
		while (!st.empty() && flag)
		{
			p=st.top();					//ȡ��ջ�����p
			if (p->rchild==q)			//�����p���������ѷ��ʻ�Ϊ��
			{
				if (p->data==x)			//���ʵĽ��pǡ���ǽ��x 
				{
					st.pop();			//��ջ���x 
					while (!st.empty())
					{
						res.push_back(st.top()->data);
						st.pop();
					}
					reverse(res.begin(),res.end());		//����res 
					return;
				}
				st.pop();				//�����p��ջ
				q=p;					//��qָ������ʵĽ��
			}
			else						//�����p����������δ����
			{
				p=p->rchild;			//ת������������
				flag=false;				//��ʾ���ٴ���ջ�����
			}
		}
	} while (!st.empty());
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
