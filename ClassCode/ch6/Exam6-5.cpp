#include<iostream>
using namespace std;
int Min(int a[],int i)              //��a[0..i]�е���Сֵ
{	if (i==0)						//�ݹ����
  		return a[0];
  	else							//�ݹ���
  	{	int mind=Min(a,i-1);
     	return min(mind,a[i]);
	}
}
int main()
{
	int a[]={1,2,3,4,5};
	int n=sizeof(a)/sizeof(a[0]);
	cout << Min(a,n-1) << endl;
}
