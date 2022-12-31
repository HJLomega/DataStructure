#include <iostream>
#include<stack>
using namespace std;
struct BTNode									//�������н������
{
	char data;									//����Ԫ��
	BTNode *lchild;								//ָ�����ӽ��
	BTNode *rchild;								//ָ���Һ��ӽ��
	BTNode()									//���캯�� 
	{
		lchild=rchild=NULL;
	}
	BTNode(char d)								//���ع��캯�� 
	{
		data=d;
		lchild=rchild=NULL;
	}
};
class BTree										//��������
{
public:											//Ϊ�˼򵥣����г�Ա���Ϊ�������� 
	BTNode *r;									//�������ĸ����r
	//�������Ļ�������
	BTree()										//���캯��,����һ�ÿ���
	{
		r=NULL;
	}
	~BTree()									//��������
	{
		DestroyBTree(r);						//����DestroyBTree()����
		r=NULL;
	}
	void DestroyBTree(BTNode *b)						//�ͷ����еĽ��ռ�
	{
		if (b!=NULL)
		{
			DestroyBTree(b->lchild);			//�ݹ��ͷ�������
			DestroyBTree(b->rchild);			//�ݹ��ͷ�������
			delete b;							//�ͷŸ����
		}
	}
	void CreateBTree(string str)				//������rΪ�����Ķ������洢�ṹ
	{
		stack<BTNode *> st;						//����һ��ջst
		BTNode *p;
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
				p=new BTNode(str[i]);			//�½�һ�����p
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
	void DispBTree()							//��������ת�������ű�ʾ��
	{
		DispBTree1(r);
	}
	void DispBTree1(BTNode *b)					//��DispBTree��������
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
	BTNode *FindNode(char x)					//����ֵΪx�Ľ���㷨
	{
		return FindNode1(r,x);
	}
	BTNode *FindNode1(BTNode *b,char x)			//��FindNode��������
	{
		BTNode *p;
		if (b==NULL) return NULL;				//bΪ��ʱ����NULL
		else if (b->data==x) return b;			//b��ָ���ֵΪxʱ����t
		else
		{
			p=FindNode1(b->lchild,x);			//���������в���
			if (p!=NULL)
				return p;						//�����������ҵ�p��㣬����p
			else
				return FindNode1(b->rchild,x);	//�������������в��ҽ��
		}
	}
	int Height()								//��������߶ȵ��㷨
	{
		return Height1(r);
	}
	int Height1(BTNode *b)						//��Height��������
	{
		if (b==NULL)							//�����ĸ߶�Ϊ0
			return 0;
		else
			return max(Height1(b->lchild),Height1(b->rchild))+1;
	}
};
/*
int main()
{
	string str="A(B(D(,G)),C(E,F))";
	char x='e';
	BTree bt;
	bt.CreateBTree(str);
	cout << "������bt:"; bt.DispBTree(); cout << endl;
	cout << "bt�ĸ߶�:" << bt.Height() << endl;
	if (bt.FindNode(x))
		cout << "bt���ҵ�ֵΪ" << x << "�Ľ��\n";
	else
		cout << "bt��û���ҵ�ֵΪ" << x << "�Ľ��\n";
	cout << "���ٶ�����\n";
	return 0;
}
*/
