#include<iostream>
#include<stack>
using namespace std;
struct BthNode							//�����������������
{
	char data;							//��Ž��ֵ
	BthNode *lchild,*rchild;			//���Һ��ӻ�������ָ��
	int ltag,rtag;						//���ұ��
	BthNode() {}						//���캯�� 
	BthNode(char d)						//���ع��캯��
	{
		data=d;
		ltag=rtag=0;
		lchild=rchild=NULL;
	}
};
class ThreadTree						//����������������ģ��
{
	BthNode *r;							//�������ĸ����ָ��
	BthNode *root;           			//������������ͷ���ָ��
	BthNode *pre;						//��������������,ָ������ǰ�����
public:
	ThreadTree()						//���캯��,���ڳ�ʼ��
	{
		r=NULL;							//��ʼ������Ϊ����
		root=NULL;						//��ʼ����������Ϊ����
	}
	~ThreadTree()						//��������,�����ͷ����������������н��
	{
		if (r!=NULL) DestroyBTree1(r);	//�ͷ�ԭ�����������н��
		if (root!=NULL)	delete root;	//�ͷ�ͷ���
	}
	void DestroyBTree1(BthNode *b)		//�ͷ�ԭ�����������н��
	{
		if (b->ltag==0)					//b������,�ͷ�������
			DestroyBTree1(b->lchild);
		if (b->rtag==0)								//b���Һ���,�ͷ�������
			DestroyBTree1(b->rchild);
		delete b;
	}	
	void CreateBTree(string str)				//������rΪ�����Ķ������洢�ṹ
	{
		stack<BthNode *> st;						//����һ��ջst
		BthNode *p;
		bool flag;
		int i=0;
		while (i<str.length())					//ѭ��ɨ��str��ÿ���ַ�
		{
			switch(str[i])
			{
			case '(':
				st.push(p);						//�ո��½��Ľ���к���,�����ջ
				flag=true;
				break;
			case ')':
				st.pop();						//ջ���������������꣬��ջ
				break;
			case ',':
				flag=false;						//��ʼ����ջ�������Һ���
				break;
			default:
				p=new BthNode(str[i]);			//�½�һ�����p
				if (r==NULL)
					r=p;						//����δ���������,p��Ϊ�����
				else							//�ѽ��������������
				{	if (flag)					//�½��p��Ϊջ����������
					{	if (!st.empty())
							st.top()->lchild=p;
					}
					else						//�½��p��Ϊջ�������Һ���
					{	if (!st.empty())
							st.top()->rchild=p;
					}
				}
				break;
			}
			i++;								//��������
		}
	}
	void DispBTree()							//��������������ű�ʾ��
	{
		DispBTree1(r);
	}
	void DispBTree1(BthNode *b)					//��DispBTree��������
	{
		if (b!=NULL)
		{
			cout << b->data;					//��������ֵ
			if (b->lchild!=NULL || b->rchild!=NULL)
			{
				cout << "(";					//�к��ӽ��ʱ���"("
				DispBTree1(b->lchild);			//�ݹ����������
				if (b->rchild!=NULL)
					cout << ",";				//���Һ��ӽ��ʱ���","
				DispBTree1(b->rchild);			//�ݹ����������
				cout << ")";					//���")"
			}
		}
	}

	void CreateThread()							//������rootΪͷ������������������
	{
		root=new BthNode();						//����ͷ���root
		root->ltag=0; root->rtag=1;				//ͷ������ó�ֵ
		root->rchild=r;
		if (r==NULL)							//rΪ����ʱ
		{
			root->lchild=root;
			root->rchild=NULL;
		}
		else									//r��Ϊ����ʱ
		{
			root->lchild=r;
			pre=root;							//preָ����p��ǰ�����,����������
			Thread(r);							//�������������������
			pre->rchild=root;					//�����,����ָ�����������
			pre->rtag=1;
			root->rchild=pre;					//ͷ�����������
		}
	}
	void Thread(BthNode *&p)					//�Խ��p�Ķ���������������
	{
		if (p!=NULL)
		{
			Thread(p->lchild);					//������������
			if (p->lchild==NULL)				//ǰ������
			{
				p->lchild=pre;					//�����p���ǰ������
				p->ltag=1;
			}
			else p->ltag=0;
			if (pre->rchild==NULL)
			{
				pre->rchild=p;					//�����pre��Ӻ������
				pre->rtag=1;
			}
			else pre->rtag=0;
			pre=p;
			Thread(p->rchild);					//������������
		}
	}
	void ThInOrder()							//�����������������������
	{
		BthNode *p=root->lchild;				//pָ������
		while (p!=root)
		{
			while (p!=root && p->ltag==0)
				p=p->lchild;						//�ҿ�ʼ���p
			cout << p->data;						//���ʽ��p
			while (p->rtag==1 && p->rchild!=root)	//�����������һֱ����ȥ
			{
				p=p->rchild;
				cout << p->data;					//���ʽ��p
			}
			p=p->rchild;							//���������������ת����������
		}
	}
}; 
int main()
{
	string 	str="A(B(D(,G)),C(E,F))";
	ThreadTree tb;
	tb.CreateBTree(str);				//����ԭ������
	cout << "������tb:"; tb.DispBTree(); cout << endl;
	cout << "��������������������\n";
	tb.CreateThread();					//����������
	cout << "�ǵݹ��������:"; tb.ThInOrder(); cout << endl;
	cout << "��������������\n";
	return 0;
}
