#include "LinkQueue.cpp"   				//����������ģ��Ķ���
void Jsequence(int n,int m)				//���Լɪ������
{
	int x;
	LinkQueue<int> qu;                  //����һ������
 	for (int i=1;i<=n;i++)          	//���ӱ��Ϊ1��n��n��С��
  		qu.push(i);
 	for (int i=1;i<=n;i++)				//������n��С��
  	{	int j=1;
  		while (j<=m-1)		    		//����m-1��С�����������ǽ���
  		{
  			qu.pop(x);
  			qu.push(x);
       		j++;
       	}
    	qu.pop(x);                  	//���ӵ�m��С��
    	cout << x << " ";
    }
	cout << endl;
}

int main()
{
	printf("����1: n=6,m=3\n");
	printf("  ����˳��:");
	Jsequence(6,3);
	printf("����2: n=8,m=4\n");
	printf("  ����˳��:");
	Jsequence(8,4);
	return 0;
}

