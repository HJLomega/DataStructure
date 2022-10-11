#include<iostream>
using namespace std;
#define MAXM 100						//��ϣ����󳤶� 
template <typename T>
struct HNode                            //����������
{
	int key;							//�ؼ���
	T value;							//����ֵ 
    HNode<T> *next;						//��һ�����ָ�� 
	HNode() {}							//���캯��
	HNode(int k,T v)				//���ع��캯��
	{
		key=k;
		value=v;
		next=NULL;
	}
};
template <typename T>
class HashTable2                       	//��ϣ��(����������+������)
{
	int n;                       		//��ϣ����Ԫ�ظ���
    int m;								//��ϣ���� 
    HNode<T> *ha[20];						//��Ź�ϣ��Ԫ��
public:
	HashTable2(int m)					//��ϣ���캯�� 
	{
		this->m=m;
		for (int i=0;i<m;i++)
			ha[i]=NULL;
		n=0;
	}
	~HashTable2()						//��������
	{
		HNode<T> *pre,*p;
		for (int i=0;i<m;i++)			//�������е�ͷ���
		{
			pre=ha[i];
			if (pre!=NULL)
			{
				p=pre->next;
				while (p!=NULL)			//�ͷ�ha[i]�����н��ռ�
				{
					delete pre;
					pre=p; p=p->next;	//pre��pָ��ͬ������ 
				}
				delete pre;
			}
		}
		delete [] ha;
	}
       
    HNode<T>* search(int k)            //���ҹؼ���k,�ɹ�ʱ�������ַ�����򷵻ؿ�
	{	int d=k % m;				    		//���ϣ����ֵ
        HNode<T>* p=ha[d];                    		//pָ��ha[d]��������׽��
        while (p!=NULL && p->key!=k)     //����keyΪk�Ľ��p
            p=p->next;
        return p;                        //����p
	}
	
    void insert(int k,T v)          	//�ڹ�ϣ���в���(k,v)  
	{	//HNode<T>* p=search(k);
		//if (p!=NULL) return;			//�ظ��ؼ��ֲ��ܲ��� 
		int d=k % m;                  	//���ϣ����ֵ
        HNode<T>* p=new HNode<T>(k,v); 			//�½��ؼ���k�Ľ��p
        p->next=ha[d];               	//����ͷ�巨��p���뵽ha[d]��������
        ha[d]=p;
        n++;                       		//��ϣ��Ԫ�ظ�����1
	}

    void remove(int k)                 //ɾ���ؼ���k
	{	int d=k % m;
        if (ha[d]==NULL) return;
        if (ha[d]->next==NULL)        	//ha[d]ֻ��һ�����
		{	if (ha[d]->key==k)
			{ 
				delete ha[d];
				ha[d]=NULL;
			}
            return;
        }
        HNode<T>* pre=ha[d];          	//ha[d]��һ�����Ͻ��
        HNode<T>* p=pre->next;
        while (p!=NULL && p->key!=k)
        {	pre=p;                       //pre��pͬ������
            p=p->next;
        }
        if (p!=NULL)                     //�ҵ��ؼ���Ϊk�Ľ��p
        {
		    pre->next=p->next;             //ɾ�����p
		    delete p;
		}
	}
		    
    void dispht()                  	 //�����ϣ��
	{	for (int i=0;i<m;i++)
       	{	printf("%4d: ",i);
            HNode<T>* p=ha[i];
            while (p!=NULL)
            {	printf("%3d",p->key);
			    p=p->next;
			}
			printf("\n");
		}
	}
	double ASL1()                     	//��ɹ������ƽ�����ҳ���
	{
		int sum=0;						//�ۼƳɹ��ҵ����йؼ�����Ҫ�ıȽϴ��� 
        for (int i=0;i<m;i++)
        {
        	HNode<T> *p=ha[i];
        	int sum1=0;					//sum1�ۼƳɹ�����p->key�Ĺؼ��ֱȽϴ���
        	while (p!=NULL)
        	{
        		sum1++;					//�ɹ��ҵ�p->key 
            	sum+=sum1;				//��sum1�ۼӵ�sum��
        		p=p->next;
        	}
    	}
        return 1.0*sum/n;
	}
	double ASL2()                     	//�󲻳ɹ������ƽ�����ҳ���
	{
		int sum=0;						//�ۼƲ���ʧ��ʱ���йؼ�����Ҫ�ıȽϴ���  
        for (int i=0;i<m;i++)
        {
        	HNode<T> *p=ha[i];
        	int sum1=0;					//sum1�ۼƳɹ�����p->key�Ĺؼ��ֱȽϴ���
        	while (p!=NULL)
        	{
        		sum1++;
        		p=p->next;
        	}
           	sum+=sum1;					//��sum1�ۼӵ�sum��
    	}
        return 1.0*sum/m;
	}
	
};
int main()
{  
	int a[]={26,36,41,38,44,15,68,12,6,51,25};
	//int a[]={16,74,60,43,54,90,46,31,29,88,77};
	string b[]={"1","2","3","4","5","6","7","8","9","10","11"};
	int n=sizeof(a)/sizeof(a[0]);
	int m=13;
	HashTable2<string> ht(m);		//�����ϣ��ht
	printf("\n (1)��a,b����������ϣ��\n"); 
	for (int i=0;i<n;i++)
    	ht.insert(a[i],b[i]);
	printf(" (2)��ϣ��\n");
	ht.dispht();
	printf(" (3)��ɹ�����µ�ƽ�����ҳ���\n"); 
	printf("   ASL=%.2lf\n",ht.ASL1());
	printf(" (4)�󲻳ɹ�����µ�ƽ�����ҳ���\n"); 
	printf("   ASL=%.2lf\n",ht.ASL2());


	printf(" (4)ɾ��26\n");
	ht.remove(26);
	printf(" (5)��ϣ��\n");
	ht.dispht();
	printf(" (6)��ɹ�����µ�ƽ�����ҳ���\n"); 
	printf("   ASL=%.2lf\n",ht.ASL1());

	return 0;
}

