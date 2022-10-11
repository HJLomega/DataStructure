#include "LinkString.cpp"		//����˳�򴮵Ļ������㺯��
bool StrEqueal1(LinkString &s,LinkString &t)	//�ж�����s��t�Ƿ����
{
	if (s.length!=t.length)
		return false;	
	for (int i=0; i<s.length;i++)
		if (s.geti(i)!=t.geti(i))
			return false;
	return true;
}
bool StrEqueal2(LinkString &s,LinkString &t)	//�ж�����s��t�Ƿ����
{
	if (s.length!=t.length)
		return false;
	LinkNode *p=s.head->next;
	LinkNode *q=t.head->next;
 	while (p!=NULL && q!=NULL)
 	{
  		if (p->data!=q->data)
      		return false;
    	p=p->next;
		q=q->next;
	}
	return true;
}

int main()
{	LinkString s1,s2,s3;
	s1.StrAssign("abcd");
	cout << "s1:"; s1.DispStr();
	s2=s1;
	cout << "s2:"; s2.DispStr();
	s3.StrAssign("abc");
	cout << "s3:"; s3.DispStr();
	cout << "s1=s2:" << (StrEqueal2(s1,s2)?"����":"������") << endl;
	cout << "s1=s3:" << (StrEqueal2(s1,s3)?"����":"������") << endl;
	return 0;
}

