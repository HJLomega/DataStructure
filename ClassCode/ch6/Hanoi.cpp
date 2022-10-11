#include <iostream.h>
const int MaxSize=100;
//�ݹ����Hanoi����
void Hanoi1(int n,char x,char y,char z)
{	if (n==1)
		cout << "  ����" << n << "��Բ�̴�" << x << "�ƶ���" << z << endl;
	else
	{	Hanoi1(n-1,x,z,y);
		cout << "  ����" << n << "��Բ�̴�" << x << "�ƶ���" << z << endl;
		Hanoi1(n-1,y,x,z);
	}
}
//�ǵݹ����Hanoi����
struct SType				//˳��ջ��Ԫ������
{	int n;
	char x,y,z;
	bool flag;				//��ֱ���ƶ�ʱΪtrue,����Ϊfalse
};
class Stack							//˳��ջ��
{
	SType *data;					//���ջ��Ԫ��
	int top;						//ջ��ָ��
public:
	Stack()							//���캯��
	{
		data=new SType[MaxSize];	//����ռ�
		top=-1;
	}
	~Stack()						//��������
	{
		delete [] data;				//�ͷſռ�
	}
	bool StackEmpty()				//��ջ�շ�
	{
		return(top==-1);
	}
	void Push(int n1,char x1,char y1,char z1,bool flag1)	//��ջ
	{
		top++;
		data[top].n=n1; data[top].x=x1; data[top].y=y1;
		data[top].z=z1; data[top].flag=flag1;
	}
	void Pop(int &n1,char &x1,char &y1,char &z1,bool &flag1) //��ջ
	{
		n1=data[top].n; x1=data[top].x; y1=data[top].y;
		z1=data[top].z; flag1=data[top].flag;
		top--;
	}
	void GetTop(int &n1,char &x1,char &y1,char &z1,bool &flag1)	//ȡջ��Ԫ��
	{
		n1=data[top].n; x1=data[top].x; y1=data[top].y;
		z1=data[top].z; flag1=data[top].flag;
	}
};
void Hanoi2(int n, char x, char y, char z)
{
	Stack st;										//����һ��˳��ջ
	int n1; char x1,y1,z1; bool flag1;
	if (n<=0) return;								//�������󷵻�
	else if (n==1)									//ֻ��һ��Բ�̵����
		cout << "  ����" << n << "��Բ�̴�" << x << "�ƶ���" << z << endl;
	else
	{
		st.Push(n,x,y,z,false);						//��ֵ(n,x,y,z,false)��ջ
		while (!st.StackEmpty())					//ջ����ѭ��
		{
			st.GetTop(n1,x1,y1,z1,flag1);			//ȡջ��Ԫ��(n1,x1,y1,z1,flag1)
			if (flag1==false && n1>1)				//������ֱ����ʱ
			{
				st.Pop(n1,x1,y1,z1,flag1);			//��ջ
				if (n1-1==1)						//ֻ��һ����Ƭʱ��ֱ���ƶ�
					st.Push(n1-1,y1,x1,z1,true);	//��(n1-1,y1,x1,z1,true)��ջ
				else
					st.Push(n1-1,y1,x1,z1,false);	//��(n1-1,y1,x1,z1,false)��ջ
				st.Push(n1,x1,y1,z1,true);			//����n1��Բ�̴�x1�Ƶ�z1
				if (n1-1==1)						//�ٽ�(n1-1,x1,z1,y1)��ջ
					st.Push(n1-1,x1,z1,y1,true);
				else
					st.Push(n1-1,x1,z1,y1,false);
			}
			else if (flag1==true)					//������ֱ���ƶ�ʱ
			{
				cout << "  ����" << n1 << "��Բ�̴�" << x1 << "�ƶ���" << z1 << endl;
				st.Pop(n1,x1,y1,z1,flag1);			//�ƶ���Ƭ����ջ
			}
		}
	}
}
void main()
{
	cout << "n=3��Hanoi����ݹ��������:\n";
	Hanoi1(3,'A','B','C');
	cout << "n=3��Hanoi����ǵݹ��������:\n";
	Hanoi2(3,'A','B','C');
}
