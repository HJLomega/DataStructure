#include "CDLinkList.cpp"				//����ѭ��˫��������
template <typename T>
bool Symm(CDLinkList<T> &L)            	//����㷨
{	bool flag=true;			    		//flag��ʾL�Ƿ�Գƣ���ʼʱΪ��
 	DLinkNode<T> *p=L.dhead->next;		//pָ���׽��
 	DLinkNode<T> *q=L.dhead->prior;	    //qָ��β���
 	while (flag)
  	{	if (p->data!=q->data)  			//��Ӧ���ֵ����ͬ����flagΪ��
      		flag=false;
     	else
      	{	if (p==q || p==q->prior)	//������������˳�ѭ�� 
		  		break;
        	q=q->prior;	    			//qǰ��һ����� 
        	p=p->next;	    			//p����һ�����
        }
    }
	return flag;
}
int main()
{
	int a[]={1,2,1};
	int n=sizeof(a)/sizeof(a[0]);
	CDLinkList<int> A;
	cout << "����ѭ��˫����A" << endl;
	A.CreateListR(a,n);
	cout << "ѭ��˫����A: "; A.DispList();
	cout << "�Գ�:" <<  Symm(A) << endl;
	return 0;
}
