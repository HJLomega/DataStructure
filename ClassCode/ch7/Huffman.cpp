#include<iostream>
#include <queue>
#include <string>
#include<algorithm>
using namespace std;
const int MaxSize=100;						//����ܽ�����
int n0=4;									//������ַ�����
char D[]={'a','b','c','d'};        			//�ַ��б�
double W[]={1,3,5,7};          				//Ȩֵ�б�

struct HTNode 								//�������������
{	char data;								//���ֵ
	double weight;							//Ȩֵ
	int parent;								//˫�׽��
	int lchild;								//���ӽ��
	int rchild;								//�Һ��ӽ��
	bool flag;								//��ʶ��˫�׵���(True)������(False)����
	HTNode() 								//���캯��
  	{ 	parent=-1;
     	lchild=-1;
     	rchild=-1;
	}	
	HTNode(char d,double w) 				//���ع��캯��
  	{	data=d;
    	weight=w;
     	parent=-1;
     	lchild=-1;
     	rchild=-1;
     	flag=true;
	}
};

HTNode ht[MaxSize];                 		//ht��Ź�������
string hcd[MaxSize];                		//hcd��Ź���������

struct HeapNode								//���ȶ���Ԫ������ 
{
	double w;								//Ȩֵ
	int i;									//��Ӧ���������н����
	HeapNode(double w1,int i1):w(w1),i(i1) {}	//���캯�� 
	bool operator<(const HeapNode &s) const	
	{										//����ǰ���������s���бȽ�
		return w>s.w;						//��wԽСԽ���ȳ���
	}	
};
void CreateHT()								//�����������
{
	priority_queue<HeapNode> qu;			//�������ȶ���(wС����) 
 	for (int i=0;i<n0;i++)              	//i��0��n0-1ѭ������n0��Ҷ�ӽ�㲢����
  	{	ht[i]=HTNode(D[i],W[i]);        		//����һ��Ҷ�ӽ��
    	qu.push(HeapNode(W[i],i));         	//��(W[i],i)����
	}
 	for (int i=n0;i<2*n0-1;i++)				//i��n0��2n0-2ѭ����n0-1�κϲ�����
  	{
	  	HeapNode p1=qu.top(); qu.pop();  	//��������Ȩֵ��С��Ԫ��p1��p2
	  	HeapNode p2=qu.top(); qu.pop();
     	ht[i]=HTNode();						//�½�ht[i]���
     	ht[i].weight=ht[p1.i].weight+ht[p2.i].weight;	//��Ȩֵ��
     	ht[p1.i].parent=i;                 	//����p1��˫��Ϊht[i]
     	ht[i].lchild=p1.i;                 	//��p1��Ϊ˫��ht[i]������
     	ht[p1.i].flag=true;
     	ht[p2.i].parent=i;                 	//����p2��˫��Ϊht[i]
     	ht[i].rchild=p2.i;                 	//��p2��Ϊ˫��ht[i]���Һ���
     	ht[p2.i].flag=false; 
     	qu.push(HeapNode(ht[i].weight,i));	//���½��ht[i]����
     }
}

void DispHT()                              	//�����������
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

void CreateHCode()						//���ݹ������������������
{
    for (int i=0;i<n0;i++)		    			//�����±��0��n0-1��Ҷ�ӽ��
	{	string code="";
		int j=i;							    //��ht[i]��ʼ��˫�׽��
        while (ht[j].parent!=-1)
		{	if (ht[j].flag)				//ht[j]�����˫�׵�����
                code+="0";
            else						//ht[j]�����˫�׵��Һ���
                code+="1";
            j=ht[j].parent;
    	}
    	reverse(code.begin(),code.end());	//��code���ò���ӵ�hcd��
    	hcd[i]=code;					
	}
}

void DispHCode()						//�������������
{
    for (int i=0;i<n0;i++)
    	cout << "  " << ht[i].data << ":" << hcd[i] << endl;
}

int main()
{
	printf("(1)������������\n");
    CreateHT();
    printf("(2)�����������\n");
    DispHT();
    printf("(3)��������������\n");
    CreateHCode();
    printf("(4)�������������\n");
    DispHCode();
	return 0;
}
