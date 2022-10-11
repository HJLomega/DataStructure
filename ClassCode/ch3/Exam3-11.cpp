#include "CSqQueue.cpp"   					//����ѭ��������ģ��Ķ���

bool pushk(CSqQueue<int> &qu,int k,int e)	//���ӵ�k��Ԫ��e
{
	int x;
	int n=qu.getlength();
	if (k<1 || k>n+1)
        return false;						//����k���󷵻�False
    if (k<=n)
    {	for (int i=1;i<=n;i++)				//ѭ�������������Ԫ��
        {	if (i==k)
                qu.push(e);					//��eԪ�ؽ��ӵ���k��λ��
            qu.pop(x);						//����Ԫ��x
            qu.push(x);						//����Ԫ��x
        }
    }
	else
    	qu.push(e);							//k=n+1ʱֱ�ӽ���e
    return true;
}

bool popk(CSqQueue<int> &qu,int k,int &e)	//���ӵ�k��Ԫ��
{
	int x;
	int n=qu.getlength();
    if (k<=1 || k>n) return false;			//����k���󷵻�false 
    for (int i=1;i<=n;i++)					//ѭ�������������Ԫ��
    {   qu.pop(x);							//����Ԫ��x
        if (i!=k)
            qu.push(x);						//���ǵ�k��Ԫ�ؽ���
        else
            e=x;							//ȡ��k�����ӵ�Ԫ��
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
	printf("Ԫ�ظ���=%d\n",qu.getlength());
	pushk(qu,1,5);
	printf("���ӵ�1��Ԫ��5\n"); 
	popk(qu,2,x);
	printf("���ӵ�2��Ԫ��:%d\n",x); 
	while(!qu.empty())
	{
		qu.pop(x);
    	printf("%d ",x);
	}
	printf("\n");
	return 0; 
}
