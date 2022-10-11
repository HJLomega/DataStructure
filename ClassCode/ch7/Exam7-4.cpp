#include<iostream>
#include<vector>
using namespace std;
struct EBNode					    //�����ֵ����н����
{	char data;				     	//����ֵ
    EBNode *brother;				//ָ���ֵ�
    EBNode *eson;					//ָ���ӽ��
	EBNode() 						//���캯�� 
	{
		brother=eson=NULL;
	}	
	EBNode(char d)					//���ع��캯�� 
	{
		data=d;
		brother=eson=NULL;
	}	
};
int Height(EBNode *t)                	//��t�ĸ߶�
{	if (t==NULL)              			//�����߶�Ϊ0
  		return 0;
 	int maxsh=0;
 	EBNode *p=t->eson;                 	//pָ��t���ĳ���
 	while (p!=NULL)
  	{	EBNode *q=p->brother;           //q��ʱ������p�ĺ�̽��
    	int sh=Height(p);               //�ݹ�����p�������ĸ߶�
    	maxsh=max(maxsh,sh);        	//����t���������������߶�
    	p=q;
	}
 	return maxsh+1;
}
int main()
{
	EBNode *t,*b,*c,*d,*e,*f,*g;
	t=new EBNode('A');					//����� 
	b=new EBNode('B');
	c=new EBNode('C');
	d=new EBNode('D');
	e=new EBNode('E');
	f=new EBNode('F');
	g=new EBNode('G');
	t->eson=b;
	b->eson=d; b->brother=c;
	d->brother=e;
	e->eson=g; e->brother=f;
	cout << "���߶�: " << Height(t) << endl;
	return 0;
}
	

