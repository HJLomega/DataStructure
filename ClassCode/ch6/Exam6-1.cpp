#include<iostream>
using namespace std;
int fun(int n)
{	if (n==1)							//���1
  		return 1;						//���2
 	else								//���3
  		return fun(n-1)*n;				//���4
}
int main()
{
	int n=5;
	cout << fun(n) << endl;
}
