#include"CSqQueue.cpp"
int main()
{	CSqQueue<char> qu;			//����һ���ַ�˳���sq
	char e;
	cout << "����һ���ն�sq\n";
	cout << "��sq" << (qu.empty()?"��":"����") << endl;
	cout << "Ԫ��a����\n"; qu.push('a');
	cout << "Ԫ��b����\n"; qu.push('b');
	cout << "Ԫ��c����\n"; qu.push('c');
	cout << "Ԫ��d����\n"; qu.push('d');
	cout << "Ԫ��e����\n"; qu.push('e');
	cout << "��sq" << (qu.empty()?"��":"����") << endl;
	cout << "����Ԫ�س��Ӵ���:";
	while (!qu.empty())		//�Ӳ���ѭ��
	{
		qu.pop(e);				//����Ԫ��e
		cout << e << " ";			//���Ԫ��e
	}
	cout << endl;
	cout << "���ٶ�sq" << endl;
	return 0;
}

