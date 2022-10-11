#include<iostream>
using namespace std;
#define MAXM 100						//哈希表最大长度 
template <typename T>
struct HNode                            //单链表结点类
{
	int key;							//关键字
	T value;							//数据值 
    HNode<T> *next;						//下一个结点指针 
	HNode() {}							//构造函数
	HNode(int k,T v)				//重载构造函数
	{
		key=k;
		value=v;
		next=NULL;
	}
};
template <typename T>
class HashTable2                       	//哈希表(除留余数法+拉链法)
{
	int n;                       		//哈希表中元素个数
    int m;								//哈希表长度 
    HNode<T> *ha[20];						//存放哈希表元素
public:
	HashTable2(int m)					//哈希表构造函数 
	{
		this->m=m;
		for (int i=0;i<m;i++)
			ha[i]=NULL;
		n=0;
	}
	~HashTable2()						//析构函数
	{
		HNode<T> *pre,*p;
		for (int i=0;i<m;i++)			//遍历所有的头结点
		{
			pre=ha[i];
			if (pre!=NULL)
			{
				p=pre->next;
				while (p!=NULL)			//释放ha[i]的所有结点空间
				{
					delete pre;
					pre=p; p=p->next;	//pre和p指针同步后移 
				}
				delete pre;
			}
		}
		delete [] ha;
	}
       
    HNode<T>* search(int k)            //查找关键字k,成功时返回其地址，否则返回空
	{	int d=k % m;				    		//求哈希函数值
        HNode<T>* p=ha[d];                    		//p指向ha[d]单链表的首结点
        while (p!=NULL && p->key!=k)     //查找key为k的结点p
            p=p->next;
        return p;                        //返回p
	}
	
    void insert(int k,T v)          	//在哈希表中插入(k,v)  
	{	//HNode<T>* p=search(k);
		//if (p!=NULL) return;			//重复关键字不能插入 
		int d=k % m;                  	//求哈希函数值
        HNode<T>* p=new HNode<T>(k,v); 			//新建关键字k的结点p
        p->next=ha[d];               	//采用头插法将p插入到ha[d]单链表中
        ha[d]=p;
        n++;                       		//哈希表元素个数增1
	}

    void remove(int k)                 //删除关键字k
	{	int d=k % m;
        if (ha[d]==NULL) return;
        if (ha[d]->next==NULL)        	//ha[d]只有一个结点
		{	if (ha[d]->key==k)
			{ 
				delete ha[d];
				ha[d]=NULL;
			}
            return;
        }
        HNode<T>* pre=ha[d];          	//ha[d]有一个以上结点
        HNode<T>* p=pre->next;
        while (p!=NULL && p->key!=k)
        {	pre=p;                       //pre和p同步后移
            p=p->next;
        }
        if (p!=NULL)                     //找到关键字为k的结点p
        {
		    pre->next=p->next;             //删除结点p
		    delete p;
		}
	}
		    
    void dispht()                  	 //输出哈希表
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
	double ASL1()                     	//求成功情况下平均查找长度
	{
		int sum=0;						//累计成功找到所有关键字需要的比较次数 
        for (int i=0;i<m;i++)
        {
        	HNode<T> *p=ha[i];
        	int sum1=0;					//sum1累计成功查找p->key的关键字比较次数
        	while (p!=NULL)
        	{
        		sum1++;					//成功找到p->key 
            	sum+=sum1;				//将sum1累加到sum中
        		p=p->next;
        	}
    	}
        return 1.0*sum/n;
	}
	double ASL2()                     	//求不成功情况下平均查找长度
	{
		int sum=0;						//累计查找失败时所有关键字需要的比较次数  
        for (int i=0;i<m;i++)
        {
        	HNode<T> *p=ha[i];
        	int sum1=0;					//sum1累计成功查找p->key的关键字比较次数
        	while (p!=NULL)
        	{
        		sum1++;
        		p=p->next;
        	}
           	sum+=sum1;					//将sum1累加到sum中
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
	HashTable2<string> ht(m);		//定义哈希表ht
	printf("\n (1)由a,b向量建立哈希表\n"); 
	for (int i=0;i<n;i++)
    	ht.insert(a[i],b[i]);
	printf(" (2)哈希表\n");
	ht.dispht();
	printf(" (3)求成功情况下的平均查找长度\n"); 
	printf("   ASL=%.2lf\n",ht.ASL1());
	printf(" (4)求不成功情况下的平均查找长度\n"); 
	printf("   ASL=%.2lf\n",ht.ASL2());


	printf(" (4)删除26\n");
	ht.remove(26);
	printf(" (5)哈希表\n");
	ht.dispht();
	printf(" (6)求成功情况下的平均查找长度\n"); 
	printf("   ASL=%.2lf\n",ht.ASL1());

	return 0;
}

