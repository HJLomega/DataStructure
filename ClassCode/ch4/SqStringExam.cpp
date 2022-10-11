#include"SqString.cpp"
int main()
{	cout << "顺序串测试" << endl;
	SqString s1,s2,s3,s4,s5,s6,s7;
	s1.StrAssign("abcd");
	cout << "s1: "; s1.DispStr();
	cout << "s1[2]=" << s1.geti(2) << endl;
	cout << "执行s1[2]='x'" << endl; 
	s1.seti(2,'x');
	cout << "s1: "; s1.DispStr();
	cout << "s1的长度:" << s1.getlength() << endl;
	cout << "s1=>s2\n";
	s2=s1;
	cout << "s2:"; s2.DispStr();
	s3.StrAssign("12345678");
	cout << "s3:"; s3.DispStr();
	cout << "s1和s3连接=>s4\n";
	s4=s1+s3;
	cout << "s4:"; s4.DispStr();
	cout << "s3[2..5]=>s5\n";
	s5=s3.SubStr(2,4);
	cout << "s5:"; s5.DispStr();
	cout << "从s3中删除s3[3..6]字符=>s6\n";
	s6=s3.DelStr(3,4);
	cout << "s6:"; s6.DispStr();
	cout << "将s4[2..4]替换成s1=>s7\n";
	s7=s4.RepStr(2,3,s1);
	cout << "s7:"; s7.DispStr();
	return 0;
}

