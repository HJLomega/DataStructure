#include<iostream>
using namespace std;
void f(int n)							//�ݹ麯��
{	if (n==0)							//�ݹ����
  		return;
	else								//�ݹ���
  	{	printf("Pre:  n=%d\n",n);
    	printf("ִ��f(%d)\n",n-1);
     	f(n-1);
     	printf("Post: n=%d\n",n);
	}
}
int main()
{
	f(4);
	return 0;
}

