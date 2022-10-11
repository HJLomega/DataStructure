#include"LinkQueue.cpp"						//引用链队类 
int main()
{	LinkQueue<char> qu;						//定义一个字符链队qu
	char e;
	cout << "建立一个空队qu\n";
	cout << "队qu" << (qu.empty()?"空":"不空") << endl;
	cout << "元素a进队\n"; qu.push('a');
	cout << "元素b进队\n"; qu.push('b');
	cout << "元素c进队\n"; qu.push('c');
	cout << "元素d进队\n"; qu.push('d');
	cout << "元素e进队\n"; qu.push('e');
	cout << "队qu" << (qu.empty()?"空":"不空") << endl;
	cout << "所有元素出队次序:";
	while (!qu.empty())					//队不空循环
	{
		qu.pop(e);						//出队元素e
		cout << e << " ";				//输出元素e
	}
	cout << endl;
	cout << "销毁队qu" << endl;
	return 0;
}

