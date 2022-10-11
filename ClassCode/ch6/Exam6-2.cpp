#include<iostream>
using namespace std;
void Hanoi(int n,char X,char Y,char Z)   	//Hanoi递归算法
{
	if (n==1)								//只有一个盘片的情况
  		printf("将第%d个盘片从%c移动到%c\n",n,X,Z);
 	else									//有两个或多个盘片的情况
  	{
		//printf("Hanoi(%d,%c,%c,%c)\n",n-1,X,Z,Y);  
	  	Hanoi(n-1,X,Z,Y);
    	printf("将第%d个盘片从%c移动到%c\n",n,X,Z);
		//printf("Hanoi(%d,%c,%c,%c)\n",n-1,Y,X,Z);  
    	Hanoi(n-1,Y,X,Z);
    }
}
int main()
{
	Hanoi(3,'a','b','c');
	return 0;
}

