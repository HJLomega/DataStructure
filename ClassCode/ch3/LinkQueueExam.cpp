#include"LinkQueue.cpp"						//���������� 
int main()
{	LinkQueue<char> qu;						//����һ���ַ�����qu
	char e;
	cout << "����һ���ն�qu\n";
	cout << "��qu" << (qu.empty()?"��":"����") << endl;
	cout << "Ԫ��a����\n"; qu.push('a');
	cout << "Ԫ��b����\n"; qu.push('b');
	cout << "Ԫ��c����\n"; qu.push('c');
	cout << "Ԫ��d����\n"; qu.push('d');
	cout << "Ԫ��e����\n"; qu.push('e');
	cout << "��qu" << (qu.empty()?"��":"����") << endl;
	cout << "����Ԫ�س��Ӵ���:";
	while (!qu.empty())					//�Ӳ���ѭ��
	{
		qu.pop(e);						//����Ԫ��e
		cout << e << " ";				//���Ԫ��e
	}
	cout << endl;
	cout << "���ٶ�qu" << endl;
	return 0;
}

