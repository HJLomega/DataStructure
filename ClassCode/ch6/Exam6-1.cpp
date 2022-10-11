#include<iostream>
using namespace std;
int fun(int n)
{	if (n==1)							//Óï¾ä1
  		return 1;						//Óï¾ä2
 	else								//Óï¾ä3
  		return fun(n-1)*n;				//Óï¾ä4
}
int main()
{
	int n=5;
	cout << fun(n) << endl;
}
