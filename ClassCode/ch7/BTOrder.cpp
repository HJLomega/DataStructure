#include"BTree.cpp"				//����������BTree��
#include<vector>
#include<queue>
//---------------��������㷨-----------------------
void PreOrder11(BTNode *b)			//��PreOrder��������
{
	if (b!=NULL)
	{
		cout << b->data;			//���ʸ����
		PreOrder11(b->lchild);		//�������������
		PreOrder11(b->rchild);		//�������������
	}
}
void PreOrder1(BTree &bt)			//��������ĵݹ��㷨
{
	if (bt.r==NULL) return;			//����ֱ�ӷ���
	PreOrder11(bt.r);
}

void PreOrder2(BTree &bt)			//��������ķǵݹ��㷨1
{
	if (bt.r==NULL) return;			//����ֱ�ӷ���
	stack<BTNode *> st;				//����һ��ջ
	BTNode *p;
	st.push(bt.r);					//�����r��ջ
	while (!st.empty())				//ջ��Ϊ��ʱѭ��
	{
		p=st.top(); st.pop();		//��ջ���p
		cout << p->data;			//���ʽ��p
		if (p->rchild!=NULL)		//���p���Һ���ʱ���Һ��ӽ�ջ
			st.push(p->rchild);
		if (p->lchild!=NULL)		//���p������ʱ�����ӽ�ջ
			st.push(p->lchild);
	}
}

void PreOrder3(BTree &bt)			//��������ķǵݹ��㷨2
{
	if (bt.r==NULL) return;			//����ֱ�ӷ��� 
	stack<BTNode *> st;				//����һ��ջ
	BTNode *p=bt.r;
	while (!st.empty() || p!=NULL)
	{
		while (p!=NULL)				//p����ʱ�����������½�㲢��ջ
		{
			cout << p->data;		//���ʽ��p
			st.push(p);
			p=p->lchild;
		}
		if (!st.empty())			//��ջ����
		{
			p=st.top(); st.pop();	//��ջ���p
			p=p->rchild;			//ת������������
		}
	}
}

//---------------��������㷨-----------------------
void InOrder11(BTNode *b)			//��InOrder��������
{
	if (b!=NULL)
	{
		InOrder11(b->lchild);		//�������������
		cout << b->data;			//���ʸ����
		InOrder11(b->rchild);		//�������������
	}
}
void InOrder1(BTree &bt)			//��������ĵݹ��㷨
{
	if (bt.r==NULL) return;			//����ֱ�ӷ��� 
	InOrder11(bt.r);
}

void InOrder2(BTree &bt)			//��������ķǵݹ��㷨
{
	if (bt.r==NULL) return;			//����ֱ�ӷ��� 
	stack<BTNode *> st;				//����һ��ջ
	BTNode *p=bt.r;
	while (!st.empty() || p!=NULL)	//ջ���ջ���p����ʱѭ��
	{
		while (p!=NULL) 			//p����ʱ���������½���ջ
		{
			st.push(p);
			p=p->lchild;
		}
		if (!st.empty())			//��ջ����
		{
			p=st.top(); st.pop();	//��ջ���p
			cout << p->data;		//���ʽ��p
			p=p->rchild;			//ת����������
		}
	}
}

//---------------��������㷨-----------------------
void PostOrder11(BTNode *b)			//��PostOrder��������
{
	if (b!=NULL)
	{
		PostOrder11(b->lchild);		//�������������
		PostOrder11(b->rchild);		//�������������
		cout << b->data;			//���ʸ����
	}
}
void PostOrder1(BTree &bt)			//��������ĵݹ��㷨
{
	if (bt.r==NULL) return;			//����ֱ�ӷ��� 
	PostOrder11(bt.r);
}

void PostOrder2(BTree &bt)			//��������ķǵݹ��㷨1
{
	if (bt.r==NULL) return;			//����ֱ�ӷ��� 
	BTNode *p; 
	stack<BTNode *> st;				//����һ��ջ
    vector<char> res;
	st.push(bt.r);					//������ջ 
    while(!st.empty())				//ջ����ѭ�� 
	{		
		p=st.top(); st.pop();		//��ջ���p 
		res.push_back(p->data);
		if (p->lchild!=NULL)		//���p������ʱ�����ӽ�ջ
			st.push(p->lchild);
		if (p->rchild!=NULL)		//���p���Һ���ʱ���Һ��ӽ�ջ
			st.push(p->rchild);
	}
	vector<char>::reverse_iterator rit;
	for (rit=res.rbegin();rit!=res.rend();rit++)
		cout << *rit;
}

void PostOrder3(BTree &bt)			//��������ķǵݹ��㷨2
{
	stack<BTNode *> st;				//����һ��ջ
	BTNode *p=bt.r,*q;
	bool flag;						//�Ƿ��ڴ���ջ����㣬��Ϊtrue,����Ϊfalse
	do
	{
		while (p!=NULL)				//p����ʱ���������½���ջ
		{
			st.push(p);
			p=p->lchild;
		}
		q=NULL;						//qָ��ջ������ǰһ���շ��ʵĽ��
		flag=true;					//��ʾ��ʼ����ջ�����
		while (!st.empty() && flag)
		{
			p=st.top();				//ȡ��ջ�����p
			if (p->rchild==q)		//�����p���������ѷ��ʻ�Ϊ��
			{
				cout << p->data;	//���ʽ��p
				st.pop();			//�����p��ջ
				q=p;				//��qָ������ʵĽ��
			}
			else					//�����p����������δ����
			{
				p=p->rchild;		//ת������������
				flag=false;			//��ʾ���ٴ���ջ�����
			}
		}
	} while (!st.empty());
}


void PostOrder4(BTree &bt)					//��������ķǵݹ��㷨2
{
	stack<BTNode *> st;						//����һ��ջ
	BTNode *p=bt.r; 
	BTNode *q;								//��Ÿոշ��ʵĽ�� 
	while (!st.empty() || p!=NULL)			//ջ���ջ���p����ʱѭ��
	{
		if (p!=NULL)						//p����ʱ���������½���ջ
		{
			st.push(p);
			p=p->lchild;
		}
		else								//p!=NULL
		{
			p=st.top();						//ȡ��ջ�����p
			if (p->rchild && p->rchild!=q)	//�����p���������ǿ�����δ����
				p=p->rchild;				//ת������������
			else
			{
				cout << p->data;			//���ʽ��p
				st.pop();					//�����p��ջ
				q=p;						//��qָ������ʵĽ��
				p=NULL;						//�ý��������������ѳ�ջ������Ҫ������ջ
			}
		}
	}
}

//�������Ĳ�α����㷨
void LevelOrder(BTree &bt)				//�������Ĳ�α���
{
	BTNode *p;
	queue<BTNode *> qu;					//����һ������
	qu.push(bt.r);						//�����r����
	while (!qu.empty())					//�Ӳ���ʱѭ�� 
	{
		p=qu.front(); qu.pop();			//���ӽ��p 
		cout << p->data;				//���ʽ��p
		if (p->lchild!=NULL)			//������ʱ�������
			qu.push(p->lchild);
		if (p->rchild!=NULL)			//���Һ���ʱ�������
			qu.push(p->rchild);
	}
}

int main()
{
	string str="A(B(D(,G)),C(E,F))";
	char x='e';
	BTree bt;
	bt.CreateBTree(str);
	cout << "\n  ������bt:"; bt.DispBTree(); cout << endl;
	cout << "  �������\n";
	cout << "       �ݹ��������: ";PreOrder1(bt); cout << endl;
	cout << "    �ǵݹ��������1: ";PreOrder2(bt); cout << endl;
	cout << "    �ǵݹ��������2: ";PreOrder3(bt); cout << endl;
	cout << "  �������\n";
	cout << "       �ݹ��������: ";InOrder1(bt); cout << endl;
	cout << "    �ǵݹ��������1: ";InOrder2(bt); cout << endl;
	cout << "  �������\n";
	cout << "       �ݹ�������: ";PostOrder1(bt); cout << endl;
	cout << "    �ǵݹ�������1: ";PostOrder2(bt); cout << endl;
	cout << "    �ǵݹ�������2: ";PostOrder4(bt); cout << endl;
	cout << "  ��α���\n";
	cout << "      ��α�������:  ";LevelOrder(bt); cout << endl;
	cout << "  ���ٶ�����\n";
	return 0;
}
