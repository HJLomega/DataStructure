#include<iostream>
#include<string>
using namespace std;
int BF(string s,string t)					//BFģʽƥ���㷨 
{	int i=0,j=0;
	while (i<s.length() && j<t.length())	//����δ������ʱѭ��
	{
		if (s[i]==t[j])						//�Ƚϵ������ַ���ͬʱ
		{
			i++;							//�����Ƶ�s��t����һ���ַ�
			j++;
		}
		else								//�Ƚϵ������ַ�����ͬʱ
		{	i=i-j+1;						//i���˵�s�ı��˿�ʼ����һ���ַ� 
			j=0; 							//j�ƶ���t���Ŀ�ͷ
		}
	}
	if (j>=t.length())						//t��������ϣ�ƥ��ɹ� 
		return i-t.length();				//����t��s�е����ַ�����
	else									//s���������t��û�б����꣺ƥ�䲻�ɹ�
		return -1;							//����-1 
}
int main()
{
	string s="ababcabcacbab";
	cout << "s: " << s << endl;
	string t="abcac";
	cout << "t: " << t << endl;
	cout << "t��s�е�λ��: " << BF(s,t) << endl;
	return 0;
}

