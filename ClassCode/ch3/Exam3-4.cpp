#include "SqStack.cpp"   		//����˳��ջ��ģ��Ķ���
bool isMatch(string str)			   	//�жϱ��ʽ���������Ƿ�ƥ����㷨
{	SqStack<char> st;	                    //����һ��˳��ջ
 	int i=0;
 	char e;
 	while (i<str.length())
  	{	
    	if (str[i]=='(' || str[i]=='[' || str[i]=='{')
      		st.push(str[i]);				//������������,����ջ
     	else
      	{
		  	if (str[i]==')')					//����')' 
		  	{
         		if (st.empty())				//ջ��ʱ����false				  
         			return false;
         		st.pop(e);					//��ջԪ��e
				if (e!='(')					//ջ������ƥ���'(',����false 
					return false; 
			}
		  	if (str[i]==']')					//����']' 
		  	{
         		if (st.empty())				//ջ��ʱ����false				  
         			return false;
         		st.pop(e);					//��ջԪ��e
				if (e!='[')					//ջ������ƥ���'[',����false 
					return false; 
			}
		  	if (str[i]=='}')					//����'}' 
		  	{
         		if (st.empty())				//ջ��ʱ����false				  
         			return false;
         		st.pop(e);					//��ջԪ��e
				if (e!='{')					//ջ������ƥ���'{',����false 
					return false; 
			}
		}
    	i++;						  	//��������str
    }
	return st.empty();
}

int main()
{
	cout << "����1: ";
	string str="([)]";
	if (isMatch(str))
		cout << str << "��������ƥ���" << endl;
	else
		cout << str << "�����Ų�ƥ���" << endl;
	cout << "����2: ";
	str="([])";
	if (isMatch(str))
		cout << str << "��������ƥ���" << endl;
	else
		cout << str << "�����Ų�ƥ���" << endl;
	return 0;
}
