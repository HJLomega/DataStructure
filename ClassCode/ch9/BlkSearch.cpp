#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct IdxType									//����������
{	int key;									//�ؼ��֣������Ƕ�Ӧ���е����ؼ��֣�
	int link;									//�������������ݱ��е���ʼ�±�
};

void CreateI(vector<int> &R,IdxType I[],int b)	//����������I[0..b-1]
{   int n=R.size();
    int s=(n+b-1)/b;							//ÿ���Ԫ�ظ���
    int j=0;
    int jmax=R[j];
    for (int i=0;i<b;i++)						//����b����
	{   I[i].link=j;
        while (j<=(i+1)*s-1 && j<=n-1)			//j����һ����,�����������ؼ���jmax
        {	if (R[j]>jmax) jmax=R[j];
            j++;
    	}
        I[i].key=jmax;
        if (j<=n-1)								//jû�б�����,jmax��Ϊ��һ������Ԫ�عؼ���
            jmax=R[j];
    }
}

int BlkSearch(vector<int> &R,IdxType I[],int b,int k)   //��R[0..n-1]��������I[0..b-1]�в���k
{   int n=R.size();
    int low=0,high=b-1;
    while (low<=high)					    	//�����������۰����,�ҵ����Ϊhigh+1
    {   int mid=(low+high)/2;
        if (k<=I[mid].key) high=mid-1;
        else low=mid+1;
	}
    if (high+1>=b) return -1;					//��ų���,����ʧ��,����-1
    int i=I[high+1].link;						//�����ڿ����ʼλ��
    int s=(n+b-1)/b;							//��ÿ���Ԫ�ظ���s
    if (i==b-1)									//��i��������,Ԫ�ظ�����������s
        s=n-s*(b-1);
    while (i<=I[high+1].link+s-1 && R[i]!=k)	//�ڶ�Ӧ����˳�����k 
        i++;
    if (i<=I[high+1].link+s-1)
		return i;								//���ҳɹ�,���ظ�Ԫ�ص����
    else
		return -1;								//����ʧ��,����-1
}
int main()
{
	vector<int> R={8,14,6,9,10,22,34,18,19,31,40,38,54,66,46,71,78,68,80,85,100,94,88,96,87};
	int b=5;
	IdxType *I=new IdxType[b];
	CreateI(R,I,b);
	printf("\n (1)��ʼ����\n   ");	
	for (int i=0;i<R.size();i++)
		printf("%d ",R[i]);
	printf("\n (2)����������(��Ϊb=5����)\n");
	for (int i=0;i<b;i++)
    	printf("    ��%d: [%3d,%2d]\n",i,I[i].key,I[i].link);
	printf("  (3)�ֿ����\n");
	for (int i=0;i<R.size();i+=2)
    {
		int k1=R[i],k2=R[i+1];
    	printf("    k=%3d��λ��:%2d\t  k=%3d��λ��:%2d\n",k1,BlkSearch(R,I,b,k1),k2,BlkSearch(R,I,b,k2));
    }
    return 0;
}

