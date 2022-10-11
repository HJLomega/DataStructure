#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class Heap               					//�����ݽṹ��ʵ��(Ĭ�ϴ����)
{	int n;									//����Ԫ�� 
	vector<T> R;							//��R[0..n-1]��Ŷ���Ԫ��
public:
	Heap()									//���캯�� 
	{
		n=0;
	}
	void siftDown(int low,int high)			//R[low..high]���Զ�����ɸѡ
  	{	int i=low;
    	int j=2*i+1;				     	//R[j]��R[i]������
     	T tmp=R[i];							//tmp��ʱ��������
     	while (j<=high)						//ֻ��R[low..high]��Ԫ�ؽ���ɸѡ
      	{	if (j<high && R[j]<R[j+1])
        		j++;						//���Һ��ӽϴ�,��jָ���Һ���
            if (tmp<R[j])					//tmp�ĺ��ӽϴ�
            { 	R[i]=R[j];					//��R[j]������˫��λ����
            	i=j; j=2*i+1;				//�޸�i��jֵ,�Ա��������ɸѡ
            }
			else break;						//�����ӽ�С����ɸѡ����
		}
        R[i]=tmp;							//ԭ������������λ��
    }

	void siftUp(int j)		        		//�Ե�����ɸѡ:��Ҷ�ӽ��j����ɸѡ
  	{	int i=(j-1)/2;   					//iָ��R[j]��˫��
     	while (true)
      	{	if (R[i]<R[j]) 					//�����ӽϴ��򽻻�
         		swap(R[i],R[j]);
        	if (i==0) break;				//��������ʱ����
        	j=i; i=(j-1)/2;					//�������ϵ���
		}
	}
	//�ѵĻ��������㷨
	void push(T e)			    		//����Ԫ��e
	{
  		n++;				    			//����Ԫ�ظ�����1
		if (R.size()>=n)					//R���ж���ռ� 
			R[n-1]=e;
		else								//R��û�ж���ռ� 
			R.push_back(e); 				//��e��ӵ�ĩβ
  		if (n==1) return;	    			//e��Ϊ���������
  		int j=n-1;
  		siftUp(j);              			//��Ҷ�ӽ��R[j]����ɸѡ
	}
	T pop()				    				//ɾ���Ѷ�Ԫ��
	{	if (n==1)
  		{	n=0;
    		return R[0];
    	}
  		T e=R[0];				    		//ȡ���Ѷ�Ԫ��
 		R[0]=R[n-1];  						//��βԪ�ظ���R[0]
 		n--;				    			//Ԫ�ظ�������1
 		siftDown(0,n-1);   					//ɸѡΪһ����
 		return e;
 	}

	T gettop()                    			//ȡ�Ѷ�Ԫ��
	{
		return R[0];
	}
	bool empty()							//�ж϶��Ƿ�Ϊ��
	{
		return n==0;
	}
	void disp()								//���R�������� 
	{
		for (int i=0;i<n;i++)
			printf("%d ",R[i]);
		printf("\n");
	}
};

struct ENode
{
	int data;								//���� 
	int cnt; 								//�������ֵĴ���
	ENode(int d,int c):data(d),cnt(c) {} 	//���캯�� 
	bool operator<(ENode &s)
	{
		return cnt<s.cnt;					//���ڰ�cnt���������
	}
};

int main() 
{
	vector<ENode> a={{1,5},{2,3},{3,1},{5,2},{4,4}};
	Heap<ENode> hp;
	for (int i=0;i<a.size();i++)
		hp.push(a[i]);
	while (!hp.empty())
	{
		ENode e=hp.pop();
		printf("[%d,%d]  ",e.data,e.cnt);
	}
	return 0;
}
/*
int main()
{
	Heap<int> big;
	vector<int> a={3,1,4,2};
	for (int i=0;i<a.size();i++)
	{
		big.push(a[i]);
		printf("����%d\n",a[i]); 
		big.disp();
	}
	while (!big.empty())
		printf("%d ",big.pop());
	printf("\n");
	return 0;
}
*/

