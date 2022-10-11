#include "CSqQueue.cpp"   					//包含循环队列类模板的定义

bool pushk(CSqQueue<int> &qu,int k,int e)	//进队第k个元素e
{
	int x;
	int n=qu.getlength();
	if (k<1 || k>n+1)
        return false;						//参数k错误返回False
    if (k<=n)
    {	for (int i=1;i<=n;i++)				//循环处理队中所有元素
        {	if (i==k)
                qu.push(e);					//将e元素进队到第k个位置
            qu.pop(x);						//出队元素x
            qu.push(x);						//进队元素x
        }
    }
	else
    	qu.push(e);							//k=n+1时直接进队e
    return true;
}

bool popk(CSqQueue<int> &qu,int k,int &e)	//出队第k个元素
{
	int x;
	int n=qu.getlength();
    if (k<=1 || k>n) return false;			//参数k错误返回false 
    for (int i=1;i<=n;i++)					//循环处理队中所有元素
    {   qu.pop(x);							//出队元素x
        if (i!=k)
            qu.push(x);						//将非第k个元素进队
        else
            e=x;							//取第k个出队的元素
	}
    return true;
}

int main()
{
	int x;
	CSqQueue<int> qu;
	qu.push(1);
	qu.push(2);
	qu.push(3);
	qu.push(4);
	printf("元素个数=%d\n",qu.getlength());
	pushk(qu,1,5);
	printf("进队第1个元素5\n"); 
	popk(qu,2,x);
	printf("出队第2个元素:%d\n",x); 
	while(!qu.empty())
	{
		qu.pop(x);
    	printf("%d ",x);
	}
	printf("\n");
	return 0; 
}
