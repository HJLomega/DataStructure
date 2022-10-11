#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
int GOEk(vector<int> &R,int k)      		//���ҵ�һ�����ڵ���k����ż�k�Ĳ����
{	int n=R.size();
 	int low=0,high=n-1;
 	while (low<=high)					  	//��ǰ����������һ��Ԫ��ʱ
  	{	int mid=(low+high)/2;				//�����������м�λ��
    	if (k<=R[mid])				      	//������R[low..mid-1]�в���
      		high=mid-1;
     	else							  	//k>R[mid]
      		low=mid+1;					  	//������R[mid+1..high]�в���
	}
	return high+1;						   	//����high+1
}

int Firstequalsk(vector<int> &R,int k)      //���ҵ�һ������k��Ԫ�����
{	int n=R.size();
 	int low=0,high=n-1;
 	while (low<high)						//��ǰ����������2��Ԫ��ʱ					
  	{	int mid=(low+high)/2;				//����Ϊż��ʱ����м�λ
    	if (k<=R[mid])
			high=mid;
     	else
			low=mid+1;
	}
 	if (k==R[low]) return low;				//������ǡ����һ��Ϊk��Ԫ�� 
 	else return -1;
}

int Lastequalsk(vector<int> &R,int k)       //�������һ������k��Ԫ�����
{	int n=R.size();
 	int low=0,high=n-1;
 	while (low<high)						//��ǰ����������2��Ԫ��ʱ					
  	{	int mid=(low+high+1)/2;				//����Ϊż��ʱ����м�λ
    	if (k>=R[mid])
			low=mid;
     	else
		 	high=mid-1;
	}
 	if (k==R[low]) return low;				//������ǡ����һ��Ϊk��Ԫ�� 
 	else return -1;
}
vector<int> Intervalk(vector<int> &R,int k)    //����Ϊk��Ԫ������res
{
	vector<int> res(2);
 	res[0]=Firstequalsk(R,k);
 	res[1]=Lastequalsk(R,k);
 	return res;
}

int lower_bound2(vector<int> &a,int val)
{
    int first = 0, last = a.size() - 1, mid;
    while(first <= last) {
        mid = last - (last - first) / 2;
        if(a[mid] >= val) last = mid - 1;
        else first = mid + 1;
    }
    return first;
}
int lower_bound1(vector<int> R,int size,int k)	//���� 
{
    int low=0,high=size-1;
    int mid,pos=0;       	//��pos��¼��һ�����ڵ���k��Ԫ��λ��
    while (low<high)
    {
        mid=(low+high)/2;
        if(R[mid]<k)		//��λ��<k�����ҷ�֧ 
		{
            low=mid+1;
            pos=low;		//���������λ�ÿ�����pos 
        }
        else				//��λ�����ڵ���k�������֧ 
		{
            high=mid;
            pos=high;		//pos������mid
        }
    }
    return pos;
}
int lower_bound2(vector<int> R,int size,int k)	//��ȷ 
{
    int low=0,mid,half;
	int len=size;
    while(len>0)
	{
        half=len >> 1;
        mid=low+half;
        if (k>R[mid])
		{     
            low=mid+1;          
            len=len-half-1;       //���ұ��������в���
        }
        else
            len=half;            //����������У�����middle���в���
    }
    return low;
}
int upper_bound1(vector<int> R,int size,int k)
{
    int low=0,high=size-1;
    int mid,pos=0;
    while (low<high)
    {
        mid=(low+high)/2;
        if (k<R[mid])     //����λ������keyʱ��last��������first���ϱƽ�last
        {
            high=mid;
            pos=high;
        }
        else
		{
            low=mid+1;     //����λ��С�ڵ���keyʱ����first����������¼�µ�λ��
            pos=low;
        }
    }
    return pos;
}
int upper_bound2(vector<int> R,int size,int k)
{
    int low=0,mid,half;
	int len=size-1;
    while (len>0)
	{
        half=len>>1;
        mid=low+half;
        if (k<R[mid])     		//��λ������key,�ڰ���last�����������в��ҡ�
            len=half;
        else
		{
            low=mid+1;    		//��λ��С�ڵ���key,���Ұ�������в��ҡ�
            len=len-half-1;
        }
    }
    return low;
}
int main()
{
	//vector<int> R={1,1,1};
	vector<int> R={1,3,3,3,3};
	int k=3;
	printf("lower_bound1(%d): %d\n",k,lower_bound1(R,R.size(),k));
	//printf("lower_bound2(%d): %d\n",k,lower_bound2(R,R.size(),k));
	//printf("upper_bound(%d): %d\n",k,upper_bound(R,R.size(),k));
	return 0;
}
 
/*
int main()
{
	//vector<int> R={1,1,1};
	vector<int> R={1,2,2,2,3};
	int k=2;
	printf("%d�Ĳ����: %d\n",k,GOEk(R,k));
	printf("��һ��Ϊ%d��λ��: %d\n",k,Firstequalsk(R,k));
	printf("���һ��Ϊ%d��λ��: %d\n",k,Lastequalsk(R,k));	
	vector<int> ans;
	ans=Intervalk(R,k);
	printf("��һ��Ϊ%d��λ��: %d\n",k,ans[0]);
	printf("���һ��Ϊ%d��λ��: %d\n",k,ans[1]);	
	
	return 0;
}
*/
