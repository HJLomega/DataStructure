#include<iostream>
#include<vector>
using namespace std;
int SeqSearch1(vector<int> &R,int k)	//˳������㷨1
{	int n=R.size();
 	int i=0;
 	while (i<n && R[i]!=k)
	 	i++;	    					//�ӱ�ͷ������
 	if (i>=n) return -1;		        //δ�ҵ�����-1
 	else return i;						//�ҵ��󷵻������i
}

int SeqSearch2(vector<int> &R,int k)	//˳������㷨2
{	int n=R.size();
 	R.push_back(k);                     //ĩβ���һ���ڱ�
 	int i=0;
 	while (R[i]!=k) i++;				//�ӱ�ͷ������
 	if (i==n) return -1;				//δ�ҵ�����-1
 	else return i;						//�ҵ��󷵻������i
}

int main()
{
	vector<int> R={3,9,1,5,8,10,6,7,2,4};
	int k=6;
	printf("R[%d]=%d\n",SeqSearch1(R,k),k);
	printf("R[%d]=%d\n",SeqSearch2(R,k),k);
	return 0;
}
