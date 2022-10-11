#include<iostream>
using namespace std;
#define NULLKEY -1                 	//ȫ�ֱ���,�չؼ���
#define MAXM 100						//��ϣ����󳤶� 
template <typename T>
struct HNode						//��ϣ��Ԫ������ 
{
	int key;						//�ؼ���
	T value;						//����ֵ 
	HNode():key(NULLKEY) {}			//���캯��
	HNode(int k,T v)				//���ع��캯��
	{
		key=k;
		value=v;
	}
};

template <typename T>
class HashTable1                  	//��ϣ��(����������+����̽�ⷨ)
{	int n;                       	//��ϣ����Ԫ�ظ���
    int m;							//��ϣ���� 
	int p;
    HNode<T> ha[MAXM];				//��Ź�ϣ��Ԫ��
public:
	HashTable1(int m,int p)			//��ϣ���캯�� 
	{
		this->m=m;
		this->p=p;
		for (int i=0;i<m;i++)
			ha[i].key=NULLKEY;
		n=0;
	}
    void insert(int k,T v)       		//�ڹ�ϣ���в���(k,v)  
	{
		//int i=search(k);
		//if (i!=-1) return;				//�ظ��ؼ��ֲ��ܲ��� 
		int d=k % p;                    //���ϣ����ֵ
        while (ha[d].key!=NULLKEY)      //�ҿ�λ��
            d=(d+1) % m;				//����̽�ⷨ���ҿ�λ��				
        ha[d]=HNode<T>(k,v);           //����(k,v)
        n++;                       		//����һ��Ԫ��
	}
    int search(int k)	            	//���ҹؼ���k,�ɹ�ʱ������λ�ã����򷵻�-1
	{	int d=k % p;				    //���ϣ����ֵ
        while (ha[d].key!=NULLKEY && ha[d].key!=k)
            d=(d+1) % m;				//����̽�ⷨ���ҿ�λ��				
        if (ha[d].key==k)				//���ҳɹ�������λ��
            return d;
        else						    //����ʧ�ܷ���-1
            return -1;
	}
    void remove(int k)                 //ɾ���ؼ���k
	{	int i=search(k);
        if (i!=-1)
		{	ha[i].key=NULLKEY;
            n--;
    	}
	}
    void dispht()                   	//�����ϣ��
	{	for (int i=0;i<m;i++)
            printf("%4d",i);
        printf("\n");
        for (int i=0;i<m;i++)
		{	if (ha[i].key==NULLKEY)
                printf("    ");
            else
                printf("%4d",ha[i].key);
    	}
        printf("\n");
    }
	double ASL1()                      		//��ɹ������ƽ�����ҳ���
	{	int sum=0;							//�ۼƳɹ��ҵ����йؼ�����Ҫ�ıȽϴ��� 
        for (int i=0;i<m;i++)				//������ϣ���ÿ��λ�� 
        {	if (ha[i].key!=NULLKEY)
            {	int k=ha[i].key;			//��ȡ�ǿ�λ�õĹؼ���k 
				int sum1=0;					//sum1�ۼƳɹ�����k��Ҫ�Ĺؼ��ֱȽϴ���
	            int d=k % p;		    	//���ϣ����ֵ
                sum1++;	 
                while (ha[d].key!=NULLKEY && ha[d].key!=k)
				{	d=(d+1) % m;			//����̽�ⷨ������һ��λ��				
					sum1++;
                }
                //printf("   ����%d�ıȽϴ���=%d\n",k,sum1);
                sum+=sum1;					//��sum1�ۼӵ�sum�� 
            }
    	}
        return 1.0*sum/n;
	}
	double ASL2()                      		//�󲻳ɹ������ƽ�����ҳ���
	{	int sum=0;							//�ۼƲ���ʧ��ʱ���йؼ�����Ҫ�ıȽϴ��� 
        for (int i=0;i<m;i++)
        {	int sum1=1;						//sum1�ۼ�h(k)=i����ʧ����Ҫ�ؼ��ֱȽϴ��� 
			int j=i;
			while (ha[j].key!=NULLKEY)
            {
            	sum1++;
            	j=(j+1)%m;
        	}
           	//printf("   λ��%d����ʧ�ܵıȽϴ���=%d\n",i,sum1);
     		sum+=sum1;						//��sum1�ۼӵ�sum�� 
        }
        return 1.0*sum/m;
	}
};

int main()
{  
	int a[]={16,74,60,43,54,90,46,31,29,88,77};
	string b[]={"1","2","3","4","5","6","7","8","9","10","11"};
	int n=sizeof(a)/sizeof(a[0]);
	int m=13;
	int p=13;
	HashTable1<string> ht(m,p);		//�����ϣ��ht
	printf("\n (1)��a,b����������ϣ��\n"); 
	for (int i=0;i<n;i++)
    	ht.insert(a[i],b[i]);
	printf(" (2)��ϣ��\n");
	ht.dispht();
	printf(" (3)��ɹ�����µ�ƽ�����ҳ���\n"); 
	printf("   ASL=%.2lf\n",ht.ASL1());
	printf(" (4)�󲻳ɹ�����µ�ƽ�����ҳ���\n"); 
	printf("   ASL=%.2lf\n",ht.ASL2());
	printf(" (5)ɾ��29\n");
	ht.remove(29);
	printf(" (6)��ϣ��\n");
	ht.dispht();
	printf(" (7)��ɹ�����µ�ƽ�����ҳ���\n"); 
	printf("   ASL=%.2lf\n",ht.ASL1());
	printf(" (8)�󲻳ɹ�����µ�ƽ�����ҳ���\n"); 
	printf("   ASL=%.2lf\n",ht.ASL2());
	return 0;
}

/*            
int main()
{  
	int a[]={16,74,60,43,54,90,46,31,29,88,77};
	string b[]={"16","74","60","43","54","90","46","31","29","88","77"};
	int n=sizeof(a)/sizeof(a[0]);
	int m=13;
	int p=13;
	HashTable1<string> ht(m,p);				//�����ϣ��ht
	printf("\n (1)��a,b����������ϣ��\n"); 
	for (int i=0;i<n;i++)
    	ht.insert(a[i],b[i]);
	printf(" (2)��ϣ��\n");
	ht.dispht();
	printf(" (3)��ɹ�����µ�ƽ�����ҳ���\n"); 
	printf("   ASL=%.2lf\n",ht.ASL());
	return 0;
}
*/



