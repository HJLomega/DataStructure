#include <iostream>
using namespace std;
struct Child					        	//С���������
{
	int no;                     			//С�����
	Child *next;							//��һ�����ָ�� 
	Child(int d):no(d),next(NULL) {}		//���캯��
};

class Joseph						   		//���Լɪ��������
{
	int n,m;
	Child *first;							//С��ѭ����������׽�� 
public:	
	Joseph(int n1,int m1):n(n1),m(m1) {}	//���캯��
	void CreateList()						//����С��ѭ�������� 
	{
		first=new Child(1);            		//ѭ���������׽��
     	Child *r=first,*p;					//rΪβ���ָ�� 
     	for (int i=2;i<=n;i++)
      	{	p=new Child(i);					//����һ�����Ϊi���½��p
        	r->next=p;						//��p�������ĩβ
        	r=p;
        }
   		r->next=first;						//����һ���׽��Ϊfirst��ѭ��������
	}
	void Jsequence()						//���Լɪ������
	{
		Child *p,*q; 
  		for (int i=1;i<=n;i++)				//������n��С��
     	{	p=first;
        	int j=1;
        	while (j!=m)		    		//��first��㿪ʼ������������m�����
         	{	j++;						//��������
            	p=p->next;			    	//�Ƶ���һ�����
         	}
         	cout << p->no << " ";		   	//�ý���С������
			q=p->next;						//qָ����p�ĺ�̽��
         	p->no=q->no;					//�����q��ֵ���Ƶ����p 
         	p->next=q->next;				//ɾ��q���
         	delete q;
         	first=p;						//�ӽ��p���¿�ʼ
    	}
		cout << endl;
	}
};

int main()
{
	int n=6,m=3;
	Joseph L(n,m);
	cout << "n=" << n << "��m=" << m << "��Լɪ������:" << endl;
	L.CreateList();
	L.Jsequence();
	return 0;
}
