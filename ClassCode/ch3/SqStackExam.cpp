#include"SqStack.cpp"
int main()
{	SqStack<char> st;			//����һ���ַ�˳��ջst
	char e;
	cout << "������ջst\n";
	cout << "ջst" << (st.empty()?"��":"����") << endl;
	cout << "�ַ�a��ջ\n"; st.push('a');
	cout << "�ַ�b��ջ\n"; st.push('b');
	cout << "�ַ�c��ջ\n"; st.push('c');
	cout << "�ַ�d��ջ\n"; st.push('d');
	cout << "�ַ�e��ջ\n"; st.push('e');
	cout << "ջst" << (st.empty()?"��":"����") << endl;
	st.gettop(e);
	cout << "ջ��Ԫ��:" << e << endl;
	cout << "����Ԫ�س�ջ����:";
	while (!st.empty())			//ջ����ѭ��
	{	st.pop(e);				//��ջԪ��e�����
		cout << e << " ";
	}
	cout << endl;
	cout << "����ջst" << endl;
	return 0;
}

