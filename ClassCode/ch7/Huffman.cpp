#include<iostream>
#include <queue>
#include <string>
#include<algorithm>
using namespace std;
const int MaxSize=100;						//最多总结点个数
int n0=4;									//编码的字符个数
char D[]={'a','b','c','d'};        			//字符列表
double W[]={1,3,5,7};          				//权值列表

struct HTNode 								//哈夫曼树结点类
{	char data;								//结点值
	double weight;							//权值
	int parent;								//双亲结点
	int lchild;								//左孩子结点
	int rchild;								//右孩子结点
	bool flag;								//标识是双亲的左(True)或者右(False)孩子
	HTNode() 								//构造函数
  	{ 	parent=-1;
     	lchild=-1;
     	rchild=-1;
	}	
	HTNode(char d,double w) 				//重载构造函数
  	{	data=d;
    	weight=w;
     	parent=-1;
     	lchild=-1;
     	rchild=-1;
     	flag=true;
	}
};

HTNode ht[MaxSize];                 		//ht存放哈夫曼树
string hcd[MaxSize];                		//hcd存放哈夫曼编码

struct HeapNode								//优先队列元素类型 
{
	double w;								//权值
	int i;									//对应哈夫曼树中结点编号
	HeapNode(double w1,int i1):w(w1),i(i1) {}	//构造函数 
	bool operator<(const HeapNode &s) const	
	{										//将当前对象跟对象s进行比较
		return w>s.w;						//按w越小越优先出队
	}	
};
void CreateHT()								//构造哈夫曼树
{
	priority_queue<HeapNode> qu;			//建立优先队列(w小根堆) 
 	for (int i=0;i<n0;i++)              	//i从0到n0-1循环建立n0个叶子结点并进队
  	{	ht[i]=HTNode(D[i],W[i]);        		//建立一个叶子结点
    	qu.push(HeapNode(W[i],i));         	//将(W[i],i)进队
	}
 	for (int i=n0;i<2*n0-1;i++)				//i从n0到2n0-2循环做n0-1次合并操作
  	{
	  	HeapNode p1=qu.top(); qu.pop();  	//出队两个权值最小的元素p1和p2
	  	HeapNode p2=qu.top(); qu.pop();
     	ht[i]=HTNode();						//新建ht[i]结点
     	ht[i].weight=ht[p1.i].weight+ht[p2.i].weight;	//求权值和
     	ht[p1.i].parent=i;                 	//设置p1的双亲为ht[i]
     	ht[i].lchild=p1.i;                 	//将p1作为双亲ht[i]的左孩子
     	ht[p1.i].flag=true;
     	ht[p2.i].parent=i;                 	//设置p2的双亲为ht[i]
     	ht[i].rchild=p2.i;                 	//将p2作为双亲ht[i]的右孩子
     	ht[p2.i].flag=false; 
     	qu.push(HeapNode(ht[i].weight,i));	//将新结点ht[i]进队
     }
}

void DispHT()                              	//输出哈夫曼树
{
    printf("  i      ");
    for (int i=0;i<2*n0-1;i++)
        printf("%3d",i);
    printf("\n");
    printf("  D[i]   ");
    for (int i=0;i<2*n0-1;i++)
        printf("%3c",ht[i].data);
    printf("\n");
    printf("  W[i]   ");
    for (int i=0;i<2*n0-1;i++)
        printf("%3g",ht[i].weight);
    printf("\n");
    printf("  parent ");
    for (int i=0;i<2*n0-1;i++)
        printf("%3d",ht[i].parent);
    printf("\n");
    printf("  lchild ");
    for (int i=0;i<2*n0-1;i++)
        printf("%3d",ht[i].lchild);
    printf("\n");
    printf("  rchild ");
    for (int i=0;i<2*n0-1;i++)
        printf("%3d",ht[i].rchild);
    printf("\n");
}

void CreateHCode()						//根据哈夫曼树求哈夫曼编码
{
    for (int i=0;i<n0;i++)		    			//遍历下标从0到n0-1的叶子结点
	{	string code="";
		int j=i;							    //从ht[i]开始找双亲结点
        while (ht[j].parent!=-1)
		{	if (ht[j].flag)				//ht[j]结点是双亲的左孩子
                code+="0";
            else						//ht[j]结点是双亲的右孩子
                code+="1";
            j=ht[j].parent;
    	}
    	reverse(code.begin(),code.end());	//将code逆置并添加到hcd中
    	hcd[i]=code;					
	}
}

void DispHCode()						//输出哈夫曼编码
{
    for (int i=0;i<n0;i++)
    	cout << "  " << ht[i].data << ":" << hcd[i] << endl;
}

int main()
{
	printf("(1)建立哈夫曼树\n");
    CreateHT();
    printf("(2)输出哈夫曼树\n");
    DispHT();
    printf("(3)建立哈夫曼编码\n");
    CreateHCode();
    printf("(4)输出哈夫曼编码\n");
    DispHCode();
	return 0;
}
