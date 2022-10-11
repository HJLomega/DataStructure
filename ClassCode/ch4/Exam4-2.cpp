#include "SqString.cpp"							//包含顺序串的基本运算函数
int Strcmp(SqString &s,SqString &t)				//比较串s和t的算法
{	int minl=min(s.getlength(),t.getlength());  //求s和t中最小长度
 	for (int i=0;i<minl;i++)				  	//在共同长度内逐个字符比较
  		if (s.data[i]>t.data[i])
		  	return 1;
    	else if (s.data[i]<t.data[i])
			return -1;
	if (s.getlength()==t.getlength())         	//s==t
  		return 0;
 	else if (s.getlength()>t.getlength())		//s>t
  		return 1;
 	else										//s<t
	 	return -1;
}


int main()
{	SqString s1,s2,s3,s4;
	s1.StrAssign("bcd");
	cout << "s1:"; s1.DispStr();
	s2=s1;
	cout << "s2:"; s2.DispStr();
	s3.StrAssign("abc");
	cout << "s3:"; s3.DispStr();
	s4.StrAssign("bcde");
	cout << "s4:"; s4.DispStr();
	cout << "s1和s2比较:" << Strcmp(s1,s2) << endl;
	cout << "s1和s3比较:" << Strcmp(s1,s3) << endl;
	cout << "s1和s4比较:" << Strcmp(s1,s4) << endl;
	cout << "main函数结束,销毁所有的串对象" << endl;
	return 0;
}

