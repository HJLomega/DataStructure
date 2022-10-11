#include <iostream>
#include <stack>
using namespace std;
class Express									//求表达式值类
{
	string exp;									//存放中缀表达式
	string postexp;								//存放后缀表达式
public:
	Express(string str)							//构造函数
	{
		exp=str; 
		postexp="";
	}
	string getpostexp()							//返回postexp 
	{
		return postexp;
	}
	void Trans()								//将算术表达式exp转换成后缀表达式postexp
	{
		stack<char> opor;						//运算符栈
		int i=0;								//i为exp的下标
		char ch,e;
		while (i<exp.length())					//exp表达式未扫描完时循环
		{
			ch=exp[i];
			if (ch=='(')						//遇到左括号
				opor.push(ch);					//将左括号直接进栈
			else if (ch==')')					//遇到右括号
			{
				while (!opor.empty() && opor.top()!='(')
				{	e=opor.top();				//将栈中'('之前的运算符退栈并存入postexp
					opor.pop();
					postexp+=e;
				}
				opor.pop();						//将(退栈
			}
			else if (ch=='+' || ch=='-')		//遇到加或减号
			{
				while (!opor.empty() && opor.top()!='(')
				{	
					e=opor.top();				//将栈中(之前的所有运算符退栈并存入postexp
					opor.pop();
					postexp+=e;
				}
				opor.push(ch);					//再将'+'或'-'进栈
			}
			else if (ch=='*' || ch=='/')		//遇到'*'或'/'号
			{
				while (!opor.empty() && opor.top()!='(' && (opor.top()=='*' || opor.top()=='/'))
				{	e=opor.top();				//将栈中(之前的所有*或/依次出栈并存入postexp
					opor.pop();
					postexp+=e;
				}
				opor.push(ch);					//再将'*'或'/'进栈
			}
			else								//遇到数字字符
			{
				string d="";
       			while (ch>='0' && ch<='9') 		//遇到数字
         		{	d+=ch;                  	//提取所有连续的数字字符
           			i++;
          			if (i<exp.length())
             			ch=exp[i];
           			else
             			break;
             	}
           		i--;							//退一个字符
           		postexp+=d;						//将数字串存入postexp
				postexp+="#";					//用#标识一个数字串结束
			}
			i++;								//继续处理其他字符
		}
		while (!opor.empty())					//此时exp扫描完毕,栈不空时循环
		{
			e=opor.top();
			opor.pop();							//将栈中所有运算符退栈并放入postexp
			postexp+=e;
		}
	}
	double GetValue()							//计算后缀表达式postexp的值
	{
		stack<double> opand;					//定义运算数栈opand
		double a,b,c,d;
		char ch;
		int i=0;
		while (i<postexp.length())				//postexp字符串未扫描完时循环
		{
			ch=postexp[i];
			switch (ch)
			{
			case '+':							//遇到+
				a=opand.top(); opand.pop();		//退栈运算数a
				b=opand.top(); opand.pop();		//退栈运算数b 
				c=b+a;							//计算c
				opand.push(c);					//将计算结果进栈
				break;
			case '-':							//遇到-
				a=opand.top(); opand.pop();		//退栈运算数a
				b=opand.top(); opand.pop();		//退栈运算数b 
				c=b-a;							//计算c
				opand.push(c);					//将计算结果进栈
				break;
			case '*':							//遇到*
				a=opand.top(); opand.pop();		//退栈运算数a
				b=opand.top(); opand.pop();		//退栈运算数b 
				c=b*a;							//计算c
				opand.push(c);					//将计算结果进栈
				break;
			case '/':							//遇到/
				a=opand.top(); opand.pop();		//退栈运算数a
				b=opand.top(); opand.pop();		//退栈运算数b 
				c=b/a;							//计算c
				opand.push(c);					//将计算结果进栈
				break;
			default:							//遇到数字字符
				d=0;							//将连续的数字符转换成数值存放到d中
				while (ch>='0' && ch<='9')
				{	d=10*d+(ch-'0');
					i++;
					ch=postexp[i];
				}
				opand.push(d);					//将数值d进栈
				break;
			}
			i++;								//继续处理其他字符
		}
		return opand.top();						//栈顶元素即为求值结果
	}
};
/*
void Express::Disppostexp()		//输出后缀表达式
{
	int i;
	for (i=0; i < pnum; i++)
		cout << postexp[i];
	cout << endl;
}
//----------显示求解过程------------------------------------------
void Express::Trans1()				//输出将算术表达式exp转换成后缀表达式postexp的过程
{
	SqStackClass<char> op;				//运算符栈op
	int i=0, j=0;						//i、j作为exp和postexp的下标
	char ch,e;
	while (exp[i])						//exp表达式未扫描完时循环
	{
		ch=exp[i];
		if (ch=='(')					//判定为左括号
		{
			op.Push(ch);
			cout << "  运算符'" << ch << "'进栈\n";
		}
		else if (ch==')')				//判定为右括号
		{
			while (!op.StackEmpty() && op.GetTop(e) && e!='(')
			{	//将op栈中'('之前的运算符退栈并存放到postexp中
				op.Pop(e);
				postexp[j++]=e;
				cout << "  运算符'" << e <<	"'退栈→postexp\n";
			}
			op.Pop(e);					//将(退栈
			cout << "  运算符')'退栈\n";
		}
		else if (ch=='+' || ch=='-')	//判定为加或减号
		{
			while (!op.StackEmpty() && op.GetTop(e) && e!='(')
			{	//将op栈中'('之前的运算符退栈并存放到postexp中
				op.Pop(e);
				postexp[j++]=e;
				cout << "  运算符'" << e <<	"'退栈→postexp\n";
			}
			op.Push(ch);				//将'+'或'-'进栈
			cout << "  运算符'" << ch << "'进栈\n";
		}
		else if (ch=='*' || ch=='/')	//判定为'*'或'/'号
		{
			while (!op.StackEmpty() && op.GetTop(e) && e!='(' && (e=='*' || e=='/'))
			{	//将op栈中'('之前的'*'或'/'运算符依次出栈并存放到postexp中
				op.Pop(e);
				postexp[j++]=e;
				cout << "  运算符'" << e <<	"'退栈→postexp\n";
			}
			op.Push(ch);				//将'*'或'/'进栈
			cout << "  运算符'" << ch << "'进栈\n";
		}
		else							//处理数字字符
		{
			while (ch>='0' && ch<='9')	//判定为数字
			{
				postexp[j++]=ch;
				cout << "  "  << ch << "→postexp\t";
				i++;
				if (exp[i]) ch=exp[i];	//exp表达式未扫描完时取下一个字符
				else  break;
			}
			i--;
			postexp[j++]='#';			//用#标识一个数值串结束
			cout << "  postexp中加#\n";
		}
		i++;							//继续处理其他字符
	}
	while (!op.StackEmpty())			//此时exp扫描完毕,栈不空时循环
	{
		op.Pop(e);
		postexp[j++]=e;
		cout << "  运算符'" << e <<	"'退栈→postexp\n";
	}
	pnum=j;
}
bool Express::GetValue1(double &v)	//输出计算后缀表达式postexp的值的过程
{
	SqStackClass<double> st;			//运算数栈
	double a,b,c,d; int i=0; char ch;
	while (i < pnum)					//postexp字符串未扫描完时循环
	{
		ch=postexp[i];
		switch (ch)
		{
		case '+':						//判定为'+'号
			opand.Pop(a);					//退栈取数值a
			cout << "  运算数" << a << "退栈\t";
			opand.Pop(b);					//退栈取数值b
			cout << "  运算数" <<  b << "退栈\n";
			c=b+a;						//计算c
			cout << "  计算" << b << "+" << a << "=" << c << endl;
			opand.Push(c);					//将计算结果进栈
			cout << "  运算数" << c << "进栈\n"; 
			break;
		case '-':						//判定为'-'号
			opand.Pop(a);					//退栈取数值a
			cout << "  运算数" << a << "退栈\t";
			opand.Pop(b);					//退栈取数值b
			cout << "  运算数" <<  b << "退栈\n";
			c=b-a;						//计算c
			cout << "  计算" << b << "-" << a << "=" << c << endl;
			opand.Push(c);					//将计算结果进栈
			cout << "  运算数" << c << "进栈\n"; 
			break;
		case '*':						//判定为'*'号
			opand.Pop(a);					//退栈取数值a
			cout << "  运算数" << a << "退栈\t";
			opand.Pop(b);					//退栈取数值b
			cout << "  运算数" <<  b << "退栈\n";
			c=b*a;						//计算c
			cout << "  计算" << b << "*" << a << "=" << c << endl;
			opand.Push(c);					//将计算结果进栈
			cout << "  运算数" << c << "进栈\n"; 
			break;
		case '/':						//判定为'/'号
			opand.Pop(a);					//退栈取数值a
			cout << "  运算数" << a << "退栈\t";
			opand.Pop(b);					//退栈取数值b
			cout << "  运算数" <<  b << "退栈\n";
			if (a != 0)
			{
				c=b/a;					//计算c
				cout << "  计算" << b << "/" << a << "=" << c << endl;
				opand.Push(c);				//将计算结果进栈
				cout << "  运算数" << c << "进栈\n";
			}
			else  return false;			//除零错误返回false
			break;
		default:						//处理数字字符
			d=0;						//将连续的数字符转换成数值存放到d中
			while (ch>='0' && ch<='9')	//判定为数字字符
			{	d=10*d+(ch-'0');
				i++;
				ch=postexp[i];
			}
			opand.Push(d);					//数值d进栈
			cout << "  运算数" << d << "进栈\n";
			break;
		}
		i++;							//继续处理其他字符
	}
	opand.GetTop(v);						//栈顶元素即为求值结果
	cout << "  取栈顶数值" << v << endl;
	return true;
}
*/
int main()
{
	string str="(56-20)/(4+2)";
	Express obj(str);
	cout << "中缀表达式: " << str << endl;
	cout << "中缀转换为后缀" << endl;
	obj.Trans();
	cout << "后缀表达式: " << obj.getpostexp() << endl;
	cout << "求后缀表达式值" << endl;
	cout << "求值结果:   " << obj.GetValue() << endl;
	return 0;
}
