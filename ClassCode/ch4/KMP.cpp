#include <iomanip>
#include<iostream>
#include<string>
using namespace std;
void Dispnext(string t,int next[])			//���next
{
	int j;
	cout << setw(10) << "j";
	for (j=0;j<t.length();j++)
		cout << setw(3) << j;
	cout << endl;
	cout << setw(10) << "t[j]";
	for (j=0;j<t.length();j++)
		cout << setw(3) << t[j];
	cout << endl;
	cout << setw(10) << "next[j]";
	for (j=0;j<t.length();j++)
		cout << setw(3) << next[j];
	cout << endl;
}
void GetNext(string t,int *next)			//��ģʽ��t���nextֵ
{
	int j,k;
	j=0; k=-1;
	next[0]=-1;
	while (j<t.length()-1)
	{	if (k==-1 || t[j]==t[k])			//kΪ-1��Ƚϵ��ַ����ʱ
		{	j++; k++;						//�����Ƶ���һ���ַ�
			next[j]=k;
		}
		else								//�Ƚϵ��ַ������ʱ
			k=next[k];						//k���� 
	}
}
int KMP(string s,string t)					//����KMP�㷨
{
	int n=s.length(),m=t.length();
	int *next=new int[m];
	GetNext(t,next);						//�������ƥ����Ϣnext����
	Dispnext(t,next);
	int i=0,j=0;
	while (i<n && j<m)						//s��t��û�б����� 
	{
		if (j==-1 || s[i]==t[j])			//j=-1���߱Ƚϵ��ַ���ͬʱ 
		{	i++;
			j++;							//i,j����1
		}
		else								//�Ƚϵ��ַ�����ͬʱ
			j=next[j]; 						//i����,j����
	}
	if (j>=m)								//t��������ϣ�ƥ��ɹ�
		return i-m;							//����t��s�е����ַ�����
	else									//s���������t��û�б����꣺ƥ�䲻�ɹ�
		return -1;							//����-1
}
void GetNextval(string t,int *nextval)		//��ģʽ��t���nextvalֵ
{	int j=0,k=-1;
	nextval[0]=-1;
	while (j<t.length())
	{	if (k==-1 || t[j]==t[k])			//kΪ-1��Ƚϵ��ַ����ʱ
		{	j++;k++;
			if (t[j]!=t[k])					//�����ַ������ʱ
				nextval[j]=k;
			else
				nextval[j]=nextval[k];
		}
		else								//�Ƚϵ��ַ������ʱ
			k=nextval[k];					//k����
	}
}
void Dispnextval(string t,int nextval[])	//���nextval
{
	int j;
	cout << setw(10) << "j";
	for (j=0;j<t.length();j++)
		cout << setw(3) << j;
	cout << endl;
	cout << setw(10) << "t[j]";
	for (j=0;j<t.length();j++)
		cout << setw(3) << t[j];
	cout << endl;
	cout << setw(10) << "nextval[j]";
	for (j=0;j<t.length();j++)
		cout << setw(3) << nextval[j];
	cout << endl;
}
int KMPval(string s,string t)				//�Ľ���KMP�㷨
{
	int n=s.length(),m=t.length();
	int *nextval=new int[m];
	GetNextval(t,nextval);					//���nextval����
	Dispnextval(t,nextval);
	int i=0,j=0;
	while (i<n && j<m) 
	{
		if (j==-1 || s[i]==t[j])
		{	i++;							//i,j����1 
			j++;
		}
		else j=nextval[j];					//i����,j����
	}
	if (j>=m)
		return i-m;
	else
		return -1;
}
 
int main()
{
	//s="ababcabcacbab";
	string s="abcaabbabcabaacbacba";
	cout << "s: " << s << endl;
	//t="abcac";
	string t="abcabaa";
	cout << "t: " << t << endl;
	cout << "t��s�е�λ��: " << KMP(s,t) << endl;
	return 0;
}

/*
void GetNext1(string t,int *next)			//��ģʽ��t���nextֵ
{
	int j,k;
	j=0; k=-1;
	next[0]=-1;
	while (j<t.length()-1)
	{	cout << "k=" << k << ",j=" << j << endl;
		if (k==-1 || t[j]==t[k])			//kΪ-1��Ƚϵ��ַ����ʱ
		{	j++; k++;						//�����Ƶ���һ���ַ�
			next[j]=k;
		}
		else								//�Ƚϵ��ַ������ʱ
			k=next[k];						//k���� 
	}
}

int main()
{
	//s="ababcabcacbab";
	string s="abcd";
	int n=4;
	int next[10];
	GetNext1(s,next);
		cout << setw(10) << "j";

	for (int j=0;j<n;j++)
		cout << setw(3) << j;
	cout << endl;
	cout << setw(10) << "t[j]";
	for (int j=0;j<n;j++)
		cout << setw(3) << s[j];
	cout << endl;
	cout << setw(10) << "next[j]";
	for (int j=0;j<n;j++)
		cout << setw(3) << next[j];
	cout << endl;

	return 0;
}
*/

