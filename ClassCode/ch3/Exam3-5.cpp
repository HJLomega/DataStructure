#include "SqStack.cpp"   		//����˳��ջ��ģ��Ķ���
bool isPalindrome(string str)		          	//�ж��Ƿ�Ϊ���ĵ��㷨
{
	SqStack<char> st;                   	//����һ��˳��ջ
	char e;
 	int i=0;
 	while (i<str.length()/2)							//��strǰ���ַ���ջ
  	{	st.push(str[i]);
    	i++;							//��������str
    }
	if (str.length()%2==1)						//str����Ϊ����ʱ
  		i++;							//�����м���ַ�
 	while (i<str.length())							//����str�ĺ���ַ�
  	{
  		if (st.empty())	false;			//ջ��ʱ����false	
		st.pop(e);						//��ջԪ��e
		if (e!=str[i]) return false;	//��str[i]�����ڳ�ջ�ַ�����false
  		i++;
  }
	return true;						//�ǻ��ķ���true
}
int main()
{
	cout << "����1: ";
	string str="abcba";
	if (isPalindrome(str))
		cout << str << "�ǻ���" << endl;
	else
		cout << str << "���ǻ���" << endl;
	cout << "����2: ";
	str="1221";
	if (isPalindrome(str))
		cout << str << "�ǻ���" << endl;
	else
		cout << str << "���ǻ���" << endl;
	return 0;
}
