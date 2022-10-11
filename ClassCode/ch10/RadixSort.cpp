#include"LinkList.cpp"					//���õ�2�µĵ�������
#define MAXR 20
int geti(int key,int r,int i)     		//�����Ϊr��������key�ĵ�iλ
{	int k=0;
 	for (int j=0;j<=i;j++)
  	{	k=key%r;
    	key=key/r;
	}
 	return k;
}
void RadixSort1(LinkList<int> &L,int d,int r)	//���λ���Ȼ��������㷨
{
	LinkNode<int>* front[MAXR];			//�������Ӷ�ͷ����
	LinkNode<int>* rear[MAXR];			//�������Ӷ�β����
	LinkNode<int> *p,*t;
	for (int i=0;i<d;i++)				//�ӵ�λ����λѭ��
	{
		for (int j=0;j<r;j++) 			//��ʼ���������ס�βָ��
			front[j]=rear[j]=NULL;
		p=L.head->next;
		while (p!=NULL)					//���䣺����ԭ������ÿ�����ѭ��
		{
			int k=geti(p->data,r,i);	//��ȡ���ؼ��ֵĵ�k��λ�������k������
			if (front[k]==NULL)			//��k�����ӿ�ʱ����ͷ��β��ָ��*p���
			{	front[k]=p;
				rear[k]=p;
			}
			else						//��k�����ӷǿ�ʱ��*p������
			{	rear[k]->next=p;
				rear[k]=p;
			}
			p=p->next;					//ȡ��һ��������Ľ��
		}
		LinkNode<int> *h=NULL;			//������h���ռ����н��
		for (int j=0;j<r;j++)			//�ռ�������ÿһ������ѭ��
			if (front[j]!=NULL)			//����j�������ǵ�һ���ǿ�����
			{	if (h==NULL)
				{	h=front[j];
					t=rear[j];
				}
				else					//����j�������������ǿ�����
				{	t->next=front[j];
					t=rear[j];
				}
			}
			t->next=NULL;				//β����next����NULL
			L.head->next=h;
	}
}
int main()
{
	int a[]={75,23,98,44,57,12,29,64,38,82};
	int n=sizeof(a)/sizeof(a[0]);
	LinkList<int> L;
	L.CreateListR(a,n);
	cout << "����ǰ:"; L.DispList();
	RadixSort1(L,10,2);
	cout << "�����:"; L.DispList();
	return 0;
}
