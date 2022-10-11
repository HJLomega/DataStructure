#include"LinkStack.cpp"
int main()
{	LinkStack<char> st;						//定义一个字符链栈st
	char e;
	cout << "建立空栈st\n";
	cout << "栈st" << (st.empty()?"空":"不空") << endl;
	cout << "字符a进栈\n"; st.push('a');
	cout << "字符b进栈\n"; st.push('b');
	cout << "字符c进栈\n"; st.push('c');
	cout << "字符d进栈\n"; st.push('d');
	cout << "字符e进栈\n"; st.push('e');
	cout << "栈st" << (st.empty()?"空":"不空") << endl;
	st.gettop(e);
	cout << "栈顶元素:" << e << endl;
	cout << "所有元素出栈次序:";
	while (!st.empty())		//栈不空循环
	{	st.pop(e);					//出栈元素e并输出
		cout << e << " ";
	}
	cout << endl;
	cout << "销毁栈st" << endl;
	return 0;
}

