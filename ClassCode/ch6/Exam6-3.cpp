#include<iostream>
using namespace std;
void Hanoi(int n,char X,char Y,char Z)   	//Hanoi�ݹ��㷨
{
	if (n==1)								//ֻ��һ����Ƭ�����
  		printf("����%d����Ƭ��%c�ƶ���%c\n",n,X,Z);
 	else									//������������Ƭ�����
  	{
		printf("Hanoi(%d,%c,%c,%c)\n",n-1,X,Z,Y);  
	  	Hanoi(n-1,X,Z,Y);
    	printf("����%d����Ƭ��%c�ƶ���%c\n",n,X,Z);
		printf("Hanoi(%d,%c,%c,%c)\n",n-1,Y,X,Z);  
    	Hanoi(n-1,Y,X,Z);
    }
}
int main()
{
	int n=3;
	char a='a',b='b',c='c';
	printf("Hanoi(%d,%c,%c,%c)\n",n,a,b,c);  
	Hanoi(n,a,b,c);
	return 0;
}

