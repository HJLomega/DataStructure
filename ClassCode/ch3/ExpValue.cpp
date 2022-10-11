#include <iostream>
#include <stack>
using namespace std;
class Express									//����ʽֵ��
{
	string exp;									//�����׺���ʽ
	string postexp;								//��ź�׺���ʽ
public:
	Express(string str)							//���캯��
	{
		exp=str; 
		postexp="";
	}
	string getpostexp()							//����postexp 
	{
		return postexp;
	}
	void Trans()								//���������ʽexpת���ɺ�׺���ʽpostexp
	{
		stack<char> opor;						//�����ջ
		int i=0;								//iΪexp���±�
		char ch,e;
		while (i<exp.length())					//exp���ʽδɨ����ʱѭ��
		{
			ch=exp[i];
			if (ch=='(')						//����������
				opor.push(ch);					//��������ֱ�ӽ�ջ
			else if (ch==')')					//����������
			{
				while (!opor.empty() && opor.top()!='(')
				{	e=opor.top();				//��ջ��'('֮ǰ���������ջ������postexp
					opor.pop();
					postexp+=e;
				}
				opor.pop();						//��(��ջ
			}
			else if (ch=='+' || ch=='-')		//�����ӻ����
			{
				while (!opor.empty() && opor.top()!='(')
				{	
					e=opor.top();				//��ջ��(֮ǰ�������������ջ������postexp
					opor.pop();
					postexp+=e;
				}
				opor.push(ch);					//�ٽ�'+'��'-'��ջ
			}
			else if (ch=='*' || ch=='/')		//����'*'��'/'��
			{
				while (!opor.empty() && opor.top()!='(' && (opor.top()=='*' || opor.top()=='/'))
				{	e=opor.top();				//��ջ��(֮ǰ������*��/���γ�ջ������postexp
					opor.pop();
					postexp+=e;
				}
				opor.push(ch);					//�ٽ�'*'��'/'��ջ
			}
			else								//���������ַ�
			{
				string d="";
       			while (ch>='0' && ch<='9') 		//��������
         		{	d+=ch;                  	//��ȡ���������������ַ�
           			i++;
          			if (i<exp.length())
             			ch=exp[i];
           			else
             			break;
             	}
           		i--;							//��һ���ַ�
           		postexp+=d;						//�����ִ�����postexp
				postexp+="#";					//��#��ʶһ�����ִ�����
			}
			i++;								//�������������ַ�
		}
		while (!opor.empty())					//��ʱexpɨ�����,ջ����ʱѭ��
		{
			e=opor.top();
			opor.pop();							//��ջ�������������ջ������postexp
			postexp+=e;
		}
	}
	double GetValue()							//�����׺���ʽpostexp��ֵ
	{
		stack<double> opand;					//����������ջopand
		double a,b,c,d;
		char ch;
		int i=0;
		while (i<postexp.length())				//postexp�ַ���δɨ����ʱѭ��
		{
			ch=postexp[i];
			switch (ch)
			{
			case '+':							//����+
				a=opand.top(); opand.pop();		//��ջ������a
				b=opand.top(); opand.pop();		//��ջ������b 
				c=b+a;							//����c
				opand.push(c);					//����������ջ
				break;
			case '-':							//����-
				a=opand.top(); opand.pop();		//��ջ������a
				b=opand.top(); opand.pop();		//��ջ������b 
				c=b-a;							//����c
				opand.push(c);					//����������ջ
				break;
			case '*':							//����*
				a=opand.top(); opand.pop();		//��ջ������a
				b=opand.top(); opand.pop();		//��ջ������b 
				c=b*a;							//����c
				opand.push(c);					//����������ջ
				break;
			case '/':							//����/
				a=opand.top(); opand.pop();		//��ջ������a
				b=opand.top(); opand.pop();		//��ջ������b 
				c=b/a;							//����c
				opand.push(c);					//����������ջ
				break;
			default:							//���������ַ�
				d=0;							//�����������ַ�ת������ֵ��ŵ�d��
				while (ch>='0' && ch<='9')
				{	d=10*d+(ch-'0');
					i++;
					ch=postexp[i];
				}
				opand.push(d);					//����ֵd��ջ
				break;
			}
			i++;								//�������������ַ�
		}
		return opand.top();						//ջ��Ԫ�ؼ�Ϊ��ֵ���
	}
};
/*
void Express::Disppostexp()		//�����׺���ʽ
{
	int i;
	for (i=0; i < pnum; i++)
		cout << postexp[i];
	cout << endl;
}
//----------��ʾ������------------------------------------------
void Express::Trans1()				//������������ʽexpת���ɺ�׺���ʽpostexp�Ĺ���
{
	SqStackClass<char> op;				//�����ջop
	int i=0, j=0;						//i��j��Ϊexp��postexp���±�
	char ch,e;
	while (exp[i])						//exp���ʽδɨ����ʱѭ��
	{
		ch=exp[i];
		if (ch=='(')					//�ж�Ϊ������
		{
			op.Push(ch);
			cout << "  �����'" << ch << "'��ջ\n";
		}
		else if (ch==')')				//�ж�Ϊ������
		{
			while (!op.StackEmpty() && op.GetTop(e) && e!='(')
			{	//��opջ��'('֮ǰ���������ջ����ŵ�postexp��
				op.Pop(e);
				postexp[j++]=e;
				cout << "  �����'" << e <<	"'��ջ��postexp\n";
			}
			op.Pop(e);					//��(��ջ
			cout << "  �����')'��ջ\n";
		}
		else if (ch=='+' || ch=='-')	//�ж�Ϊ�ӻ����
		{
			while (!op.StackEmpty() && op.GetTop(e) && e!='(')
			{	//��opջ��'('֮ǰ���������ջ����ŵ�postexp��
				op.Pop(e);
				postexp[j++]=e;
				cout << "  �����'" << e <<	"'��ջ��postexp\n";
			}
			op.Push(ch);				//��'+'��'-'��ջ
			cout << "  �����'" << ch << "'��ջ\n";
		}
		else if (ch=='*' || ch=='/')	//�ж�Ϊ'*'��'/'��
		{
			while (!op.StackEmpty() && op.GetTop(e) && e!='(' && (e=='*' || e=='/'))
			{	//��opջ��'('֮ǰ��'*'��'/'��������γ�ջ����ŵ�postexp��
				op.Pop(e);
				postexp[j++]=e;
				cout << "  �����'" << e <<	"'��ջ��postexp\n";
			}
			op.Push(ch);				//��'*'��'/'��ջ
			cout << "  �����'" << ch << "'��ջ\n";
		}
		else							//���������ַ�
		{
			while (ch>='0' && ch<='9')	//�ж�Ϊ����
			{
				postexp[j++]=ch;
				cout << "  "  << ch << "��postexp\t";
				i++;
				if (exp[i]) ch=exp[i];	//exp���ʽδɨ����ʱȡ��һ���ַ�
				else  break;
			}
			i--;
			postexp[j++]='#';			//��#��ʶһ����ֵ������
			cout << "  postexp�м�#\n";
		}
		i++;							//�������������ַ�
	}
	while (!op.StackEmpty())			//��ʱexpɨ�����,ջ����ʱѭ��
	{
		op.Pop(e);
		postexp[j++]=e;
		cout << "  �����'" << e <<	"'��ջ��postexp\n";
	}
	pnum=j;
}
bool Express::GetValue1(double &v)	//��������׺���ʽpostexp��ֵ�Ĺ���
{
	SqStackClass<double> st;			//������ջ
	double a,b,c,d; int i=0; char ch;
	while (i < pnum)					//postexp�ַ���δɨ����ʱѭ��
	{
		ch=postexp[i];
		switch (ch)
		{
		case '+':						//�ж�Ϊ'+'��
			opand.Pop(a);					//��ջȡ��ֵa
			cout << "  ������" << a << "��ջ\t";
			opand.Pop(b);					//��ջȡ��ֵb
			cout << "  ������" <<  b << "��ջ\n";
			c=b+a;						//����c
			cout << "  ����" << b << "+" << a << "=" << c << endl;
			opand.Push(c);					//����������ջ
			cout << "  ������" << c << "��ջ\n"; 
			break;
		case '-':						//�ж�Ϊ'-'��
			opand.Pop(a);					//��ջȡ��ֵa
			cout << "  ������" << a << "��ջ\t";
			opand.Pop(b);					//��ջȡ��ֵb
			cout << "  ������" <<  b << "��ջ\n";
			c=b-a;						//����c
			cout << "  ����" << b << "-" << a << "=" << c << endl;
			opand.Push(c);					//����������ջ
			cout << "  ������" << c << "��ջ\n"; 
			break;
		case '*':						//�ж�Ϊ'*'��
			opand.Pop(a);					//��ջȡ��ֵa
			cout << "  ������" << a << "��ջ\t";
			opand.Pop(b);					//��ջȡ��ֵb
			cout << "  ������" <<  b << "��ջ\n";
			c=b*a;						//����c
			cout << "  ����" << b << "*" << a << "=" << c << endl;
			opand.Push(c);					//����������ջ
			cout << "  ������" << c << "��ջ\n"; 
			break;
		case '/':						//�ж�Ϊ'/'��
			opand.Pop(a);					//��ջȡ��ֵa
			cout << "  ������" << a << "��ջ\t";
			opand.Pop(b);					//��ջȡ��ֵb
			cout << "  ������" <<  b << "��ջ\n";
			if (a != 0)
			{
				c=b/a;					//����c
				cout << "  ����" << b << "/" << a << "=" << c << endl;
				opand.Push(c);				//����������ջ
				cout << "  ������" << c << "��ջ\n";
			}
			else  return false;			//������󷵻�false
			break;
		default:						//���������ַ�
			d=0;						//�����������ַ�ת������ֵ��ŵ�d��
			while (ch>='0' && ch<='9')	//�ж�Ϊ�����ַ�
			{	d=10*d+(ch-'0');
				i++;
				ch=postexp[i];
			}
			opand.Push(d);					//��ֵd��ջ
			cout << "  ������" << d << "��ջ\n";
			break;
		}
		i++;							//�������������ַ�
	}
	opand.GetTop(v);						//ջ��Ԫ�ؼ�Ϊ��ֵ���
	cout << "  ȡջ����ֵ" << v << endl;
	return true;
}
*/
int main()
{
	string str="(56-20)/(4+2)";
	Express obj(str);
	cout << "��׺���ʽ: " << str << endl;
	cout << "��׺ת��Ϊ��׺" << endl;
	obj.Trans();
	cout << "��׺���ʽ: " << obj.getpostexp() << endl;
	cout << "���׺���ʽֵ" << endl;
	cout << "��ֵ���:   " << obj.GetValue() << endl;
	return 0;
}
