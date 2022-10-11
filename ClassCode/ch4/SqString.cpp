#include<iostream>
using namespace std;
const int MaxSize=100;						//�ַ�������󳤶� 
class SqString								//˳����
{
public:
	char *data;								//��Ŵ���Ԫ��
	int length;       						//������
    //���Ļ��������㷨
	SqString()								//���캯��
	{
		data=new char[MaxSize];
		length=0;
	}
	~SqString()								//��������
	{
		delete [] data;
	}
    void StrAssign(char *cstr)		 		//����һ����
    {
    	int i=0;
		for (;i<cstr[i]!='\0';i++)
			data[i]=cstr[i];
		length=i;
	}
	void operator=(SqString &t)		//����=�����ʵ�ִ�����StrCopy
	{
		for (int i=0;i<t.length;i++)
			data[i]=t.data[i];
		length=t.length;
	}
    int getlength()			            	//�󴮳�
    {
	    return length;
	}
	char geti(int i)						//�������i���ַ�
	{
        return data[i];
    }
    void seti(int i,char x)					//�������i���ַ�Ϊx
	{
        data[i]=x;
    }

	SqString &operator+(SqString &t) 		//������,Concat
	{
		static SqString s;					//�½�һ���մ�
		int i;
		s.length=length+t.length;
		for (i=0;i<length;i++)				//����ǰ��data[0..str.length-1]->s
			s.data[i]=data[i];
		for (i=0;i<t.length;i++)			//��t.data[0..t.length-1]->s
			s.data[length+i]=t.data[i];
		return s;							//�����´�nstr
	}
	SqString &SubStr(int i,int j)			//���Ӵ�
	{
		static SqString s;					//�½�һ���մ�
		if (i<0 || i>=length || j<0 || i+j>length)
			return s;						//��������ȷʱ���ؿմ�
		for (int k=i;k<i+j;k++)				//��str.data[i..i+j-1]->s
			s.data[k-i]=data[k];
		s.length=j;
		return s;							//�����½���˳��
	}
	SqString &InsStr(int i,SqString &t)		//������
	{
		static SqString s;					//�½�һ���մ�
		if (i<0 || i>length)				//��������ȷʱ���ؿմ�
			return s;
		for (int j=0;j<i;j++)				//����ǰ��data[0..i-2]->s
			s.data[j]=data[j];
		for (int j=0;j<t.length;j++)			//��s.data[0..s.length-1]->s
			s.data[i+j-1]=t.data[j];
		for (int j=i;j<length;j++)				//����ǰ��data[i-1..length-1]->s
			s.data[t.length+j]=data[j];
		s.length=length+t.length;
		return s;							//�����½���˳��
	}

	SqString &DelStr(int i,int j)			//��ɾ��
	{
		static SqString s;					//�½�һ���մ�
		if (i<0 || i>=length || j<0 || i+j>length)	//��������ȷʱ���ؿմ�
			return s;
		for (int k=0;k<i;k++)				//����ǰ��data[0..i-2]->s
			s.data[k]=data[k];
		for (int k=i+j;k<length;k++)		//����ǰ��data[i+j-1..length-1]->s
			s.data[k-j]=data[k];
		s.length=length-j;
		return s;								//�����½���˳��
	}

	SqString &RepStr(int i,int j,SqString t)		//���滻
	{
		static SqString s;							//�½�һ���մ�
		if (i<0 || i>=length || j<0 || i+j>length)	//��������ȷʱ���ؿմ�
			return s;
		for (int k=0;k<i;k++)						//����ǰ��data[0..i-2]->s
			s.data[k]=data[k];
		for (int k=0;k<t.length;k++)				//��s.data[0..s.length-1]->s
			s.data[i+k]=t.data[k];
		for (int k=i+j;k<length;k++)					//����ǰ��data[i+j-1..length-1]->s
			s.data[t.length+k-j]=data[k];
		s.length=length-j+t.length;
		return s;									//�����½���˳��
	}
	void DispStr()									//�����
	{
		for (int i=0;i<length;i++)
			cout << data[i];
		cout << endl;
	}
};
