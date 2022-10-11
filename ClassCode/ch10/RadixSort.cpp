#include"LinkList.cpp"					//引用第2章的单链表类
#define MAXR 20
int geti(int key,int r,int i)     		//求基数为r的正整数key的第i位
{	int k=0;
 	for (int j=0;j<=i;j++)
  	{	k=key%r;
    	key=key/r;
	}
 	return k;
}
void RadixSort1(LinkList<int> &L,int d,int r)	//最低位优先基数排序算法
{
	LinkNode<int>* front[MAXR];			//建立链队队头数组
	LinkNode<int>* rear[MAXR];			//建立链队队尾数组
	LinkNode<int> *p,*t;
	for (int i=0;i<d;i++)				//从低位到高位循环
	{
		for (int j=0;j<r;j++) 			//初始化各链队首、尾指针
			front[j]=rear[j]=NULL;
		p=L.head->next;
		while (p!=NULL)					//分配：对于原链表中每个结点循环
		{
			int k=geti(p->data,r,i);	//提取结点关键字的第k个位并放入第k个链队
			if (front[k]==NULL)			//第k个链队空时，队头队尾均指向*p结点
			{	front[k]=p;
				rear[k]=p;
			}
			else						//第k个链队非空时，*p结点进队
			{	rear[k]->next=p;
				rear[k]=p;
			}
			p=p->next;					//取下一个待排序的结点
		}
		LinkNode<int> *h=NULL;			//重新用h来收集所有结点
		for (int j=0;j<r;j++)			//收集：对于每一个链队循环
			if (front[j]!=NULL)			//若第j个链队是第一个非空链队
			{	if (h==NULL)
				{	h=front[j];
					t=rear[j];
				}
				else					//若第j个链队是其他非空链队
				{	t->next=front[j];
					t=rear[j];
				}
			}
			t->next=NULL;				//尾结点的next域置NULL
			L.head->next=h;
	}
}
int main()
{
	int a[]={75,23,98,44,57,12,29,64,38,82};
	int n=sizeof(a)/sizeof(a[0]);
	LinkList<int> L;
	L.CreateListR(a,n);
	cout << "排序前:"; L.DispList();
	RadixSort1(L,10,2);
	cout << "排序后:"; L.DispList();
	return 0;
}
