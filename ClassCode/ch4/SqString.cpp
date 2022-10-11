#include<iostream>
using namespace std;
const int MaxSize=100;						//字符串的最大长度 
class SqString								//顺序串类
{
public:
	char *data;								//存放串中元素
	int length;       						//串长度
    //串的基本运算算法
	SqString()								//构造函数
	{
		data=new char[MaxSize];
		length=0;
	}
	~SqString()								//析构函数
	{
		delete [] data;
	}
    void StrAssign(char *cstr)		 		//创建一个串
    {
    	int i=0;
		for (;i<cstr[i]!='\0';i++)
			data[i]=cstr[i];
		length=i;
	}
	void operator=(SqString &t)		//重载=运算符实现串复制StrCopy
	{
		for (int i=0;i<t.length;i++)
			data[i]=t.data[i];
		length=t.length;
	}
    int getlength()			            	//求串长
    {
	    return length;
	}
	char geti(int i)						//返回序号i的字符
	{
        return data[i];
    }
    void seti(int i,char x)					//设置序号i的字符为x
	{
        data[i]=x;
    }

	SqString &operator+(SqString &t) 		//串连接,Concat
	{
		static SqString s;					//新建一个空串
		int i;
		s.length=length+t.length;
		for (i=0;i<length;i++)				//将当前串data[0..str.length-1]->s
			s.data[i]=data[i];
		for (i=0;i<t.length;i++)			//将t.data[0..t.length-1]->s
			s.data[length+i]=t.data[i];
		return s;							//返回新串nstr
	}
	SqString &SubStr(int i,int j)			//求子串
	{
		static SqString s;					//新建一个空串
		if (i<0 || i>=length || j<0 || i+j>length)
			return s;						//参数不正确时返回空串
		for (int k=i;k<i+j;k++)				//将str.data[i..i+j-1]->s
			s.data[k-i]=data[k];
		s.length=j;
		return s;							//返回新建的顺序串
	}
	SqString &InsStr(int i,SqString &t)		//串插入
	{
		static SqString s;					//新建一个空串
		if (i<0 || i>length)				//参数不正确时返回空串
			return s;
		for (int j=0;j<i;j++)				//将当前串data[0..i-2]->s
			s.data[j]=data[j];
		for (int j=0;j<t.length;j++)			//将s.data[0..s.length-1]->s
			s.data[i+j-1]=t.data[j];
		for (int j=i;j<length;j++)				//将当前串data[i-1..length-1]->s
			s.data[t.length+j]=data[j];
		s.length=length+t.length;
		return s;							//返回新建的顺序串
	}

	SqString &DelStr(int i,int j)			//串删除
	{
		static SqString s;					//新建一个空串
		if (i<0 || i>=length || j<0 || i+j>length)	//参数不正确时返回空串
			return s;
		for (int k=0;k<i;k++)				//将当前串data[0..i-2]->s
			s.data[k]=data[k];
		for (int k=i+j;k<length;k++)		//将当前串data[i+j-1..length-1]->s
			s.data[k-j]=data[k];
		s.length=length-j;
		return s;								//返回新建的顺序串
	}

	SqString &RepStr(int i,int j,SqString t)		//串替换
	{
		static SqString s;							//新建一个空串
		if (i<0 || i>=length || j<0 || i+j>length)	//参数不正确时返回空串
			return s;
		for (int k=0;k<i;k++)						//将当前串data[0..i-2]->s
			s.data[k]=data[k];
		for (int k=0;k<t.length;k++)				//将s.data[0..s.length-1]->s
			s.data[i+k]=t.data[k];
		for (int k=i+j;k<length;k++)					//将当前串data[i+j-1..length-1]->s
			s.data[t.length+k-j]=data[k];
		s.length=length-j+t.length;
		return s;									//返回新建的顺序串
	}
	void DispStr()									//串输出
	{
		for (int i=0;i<length;i++)
			cout << data[i];
		cout << endl;
	}
};
