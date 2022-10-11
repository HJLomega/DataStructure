#include<iostream>
using namespace std;
#define NULLKEY -1                 	//全局变量,空关键字
#define MAXM 100						//哈希表最大长度 
template <typename T>
struct HNode						//哈希表元素类型 
{
	int key;						//关键字
	T value;						//数据值 
	HNode():key(NULLKEY) {}			//构造函数
	HNode(int k,T v)				//重载构造函数
	{
		key=k;
		value=v;
	}
};

template <typename T>
class HashTable1                  	//哈希表(除留余数法+线性探测法)
{	int n;                       	//哈希表中元素个数
    int m;							//哈希表长度 
	int p;
    HNode<T> ha[MAXM];				//存放哈希表元素
public:
	HashTable1(int m,int p)			//哈希表构造函数 
	{
		this->m=m;
		this->p=p;
		for (int i=0;i<m;i++)
			ha[i].key=NULLKEY;
		n=0;
	}
    void insert(int k,T v)       		//在哈希表中插入(k,v)  
	{
		//int i=search(k);
		//if (i!=-1) return;				//重复关键字不能插入 
		int d=k % p;                    //求哈希函数值
        while (ha[d].key!=NULLKEY)      //找空位置
            d=(d+1) % m;				//线性探测法查找空位置				
        ha[d]=HNode<T>(k,v);           //放置(k,v)
        n++;                       		//增加一个元素
	}
    int search(int k)	            	//查找关键字k,成功时返回其位置，否则返回-1
	{	int d=k % p;				    //求哈希函数值
        while (ha[d].key!=NULLKEY && ha[d].key!=k)
            d=(d+1) % m;				//线性探测法查找空位置				
        if (ha[d].key==k)				//查找成功返回其位置
            return d;
        else						    //查找失败返回-1
            return -1;
	}
    void remove(int k)                 //删除关键字k
	{	int i=search(k);
        if (i!=-1)
		{	ha[i].key=NULLKEY;
            n--;
    	}
	}
    void dispht()                   	//输出哈希表
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
	double ASL1()                      		//求成功情况下平均查找长度
	{	int sum=0;							//累计成功找到所有关键字需要的比较次数 
        for (int i=0;i<m;i++)				//遍历哈希表的每个位置 
        {	if (ha[i].key!=NULLKEY)
            {	int k=ha[i].key;			//提取非空位置的关键字k 
				int sum1=0;					//sum1累计成功查找k需要的关键字比较次数
	            int d=k % p;		    	//求哈希函数值
                sum1++;	 
                while (ha[d].key!=NULLKEY && ha[d].key!=k)
				{	d=(d+1) % m;			//线性探测法查找下一个位置				
					sum1++;
                }
                //printf("   查找%d的比较次数=%d\n",k,sum1);
                sum+=sum1;					//将sum1累加到sum中 
            }
    	}
        return 1.0*sum/n;
	}
	double ASL2()                      		//求不成功情况下平均查找长度
	{	int sum=0;							//累计查找失败时所有关键字需要的比较次数 
        for (int i=0;i<m;i++)
        {	int sum1=1;						//sum1累计h(k)=i查找失败需要关键字比较次数 
			int j=i;
			while (ha[j].key!=NULLKEY)
            {
            	sum1++;
            	j=(j+1)%m;
        	}
           	//printf("   位置%d查找失败的比较次数=%d\n",i,sum1);
     		sum+=sum1;						//将sum1累加到sum中 
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
	HashTable1<string> ht(m,p);		//定义哈希表ht
	printf("\n (1)由a,b向量建立哈希表\n"); 
	for (int i=0;i<n;i++)
    	ht.insert(a[i],b[i]);
	printf(" (2)哈希表\n");
	ht.dispht();
	printf(" (3)求成功情况下的平均查找长度\n"); 
	printf("   ASL=%.2lf\n",ht.ASL1());
	printf(" (4)求不成功情况下的平均查找长度\n"); 
	printf("   ASL=%.2lf\n",ht.ASL2());
	printf(" (5)删除29\n");
	ht.remove(29);
	printf(" (6)哈希表\n");
	ht.dispht();
	printf(" (7)求成功情况下的平均查找长度\n"); 
	printf("   ASL=%.2lf\n",ht.ASL1());
	printf(" (8)求不成功情况下的平均查找长度\n"); 
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
	HashTable1<string> ht(m,p);				//定义哈希表ht
	printf("\n (1)由a,b向量建立哈希表\n"); 
	for (int i=0;i<n;i++)
    	ht.insert(a[i],b[i]);
	printf(" (2)哈希表\n");
	ht.dispht();
	printf(" (3)求成功情况下的平均查找长度\n"); 
	printf("   ASL=%.2lf\n",ht.ASL());
	return 0;
}
*/



