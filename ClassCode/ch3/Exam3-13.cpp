#include "LinkQueue.cpp"   				//包含链队类模板的定义
void Jsequence(int n,int m)				//输出约瑟夫序列
{
	int x;
	LinkQueue<int> qu;                  //定义一个链队
 	for (int i=1;i<=n;i++)          	//进队编号为1到n的n个小孩
  		qu.push(i);
 	for (int i=1;i<=n;i++)				//共出列n个小孩
  	{	int j=1;
  		while (j<=m-1)		    		//出队m-1个小孩，并将他们进队
  		{
  			qu.pop(x);
  			qu.push(x);
       		j++;
       	}
    	qu.pop(x);                  	//出队第m个小孩
    	cout << x << " ";
    }
	cout << endl;
}

int main()
{
	printf("测试1: n=6,m=3\n");
	printf("  出列顺序:");
	Jsequence(6,3);
	printf("测试2: n=8,m=4\n");
	printf("  出列顺序:");
	Jsequence(8,4);
	return 0;
}

