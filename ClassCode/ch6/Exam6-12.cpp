#include<iostream>
#include<stack>
using namespace std;
struct SNode									//ջԪ������ 
{	int n;
	char x,y,z;
	bool flag;										//�Ƿ����ֱ���ƶ� 
	SNode()	{}										//���캯��
	SNode(int n1,char x1,char y1,char z1,bool f1)	//���ع��캯��
	{
		n=n1;
		x=x1; y=y1; z=z1;
		flag=f1;
	}
};
void Hanoi1(int n,char x,char y,char z)
{
	if (n==1)							//ֻ��һ����Ƭʱֱ���ƶ� 
	{	cout << "��Ƭ" << n << "��" << x << "�ƶ���" << z << endl;
		return;
	}
	SNode e,e1,e2,e3;
	stack<SNode> st;					//����һ��ջst 
	e=SNode(n,x,y,z,false);
	st.push(e);
	while (!st.empty())					//ջ����ʱѭ��
	{
		e=st.top(); st.pop();			//��ջԪ��e,��Ӧ����(n1,x1,y1,z1) 
		bool flag1=e.flag;
		char x1=e.x,y1=e.y,z1=e.z;
		int n1=e.n; 
		if (flag1)						//���������ֱ���ƶ�
			cout << "��Ƭ" << n1 << "��" << x1 << "�ƶ���" << z1 << endl;
		else
		{
			if (n1-1==1)
				e1=SNode(n1-1,y1,x1,z1,true);
			else
				e1=SNode(n1-1,y1,x1,z1,false);
			st.push(e1);
			e2=SNode(n1,x1,' ',z1,true);
			st.push(e2);
			if (n1-1==1)
				e3=SNode(n1-1,x1,z1,y1,true);
			else
				e3=SNode(n1-1,x1,z1,y1,false);
			st.push(e3);
		}
	}
}


int main()
{
	Hanoi1(3,'a','b','c');
	return 0;
}

