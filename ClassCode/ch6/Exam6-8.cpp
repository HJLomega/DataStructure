#include<iostream>
using namespace std;
double pow(double x,int n)     	//��x��n����
{
	printf("����pow(%g,%d)\n",x,n); 
	if (n==1)
  		return x;
 	double p=pow(x,n/2);
	if (n%2==1)					//nΪ����
	  		return x*p*p;
 	else						//nΪż��
  		return p*p;
}
int main()
{
	double x=2.0;
	int n=10;
	printf("pow(%g,%d)=%g\n",x,n,pow(x,n));
	return 0;	
}

