#include "SqString.cpp"							//����˳�򴮵Ļ������㺯��
int Strcmp(SqString &s,SqString &t)				//�Ƚϴ�s��t���㷨
{	int minl=min(s.getlength(),t.getlength());  //��s��t����С����
 	for (int i=0;i<minl;i++)				  	//�ڹ�ͬ����������ַ��Ƚ�
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
	cout << "s1��s2�Ƚ�:" << Strcmp(s1,s2) << endl;
	cout << "s1��s3�Ƚ�:" << Strcmp(s1,s3) << endl;
	cout << "s1��s4�Ƚ�:" << Strcmp(s1,s4) << endl;
	cout << "main��������,�������еĴ�����" << endl;
	return 0;
}

