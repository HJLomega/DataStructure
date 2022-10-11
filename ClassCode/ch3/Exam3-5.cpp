#include "SqStack.cpp"   		//包含顺序栈类模板的定义
bool isPalindrome(string str)		          	//判断是否为回文的算法
{
	SqStack<char> st;                   	//建立一个顺序栈
	char e;
 	int i=0;
 	while (i<str.length()/2)							//将str前半字符进栈
  	{	st.push(str[i]);
    	i++;							//继续遍历str
    }
	if (str.length()%2==1)						//str长度为奇数时
  		i++;							//跳过中间的字符
 	while (i<str.length())							//遍历str的后半字符
  	{
  		if (st.empty())	false;			//栈空时返回false	
		st.pop(e);						//出栈元素e
		if (e!=str[i]) return false;	//若str[i]不等于出栈字符返回false
  		i++;
  }
	return true;						//是回文返回true
}
int main()
{
	cout << "测试1: ";
	string str="abcba";
	if (isPalindrome(str))
		cout << str << "是回文" << endl;
	else
		cout << str << "不是回文" << endl;
	cout << "测试2: ";
	str="1221";
	if (isPalindrome(str))
		cout << str << "是回文" << endl;
	else
		cout << str << "不是回文" << endl;
	return 0;
}
