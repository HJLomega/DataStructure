#include "SqList.cpp"					//����˳�������
template <typename T>
void Deletex1(SqList<T> &L, int x)   	//����㷨1
{
    int k=0;
    for (int i=0;i<L.length;i++)
    	if (L.data[i]!=x)				//����Ϊx��Ԫ�ز��뵽data��
    	{
    		L.data[k]=L.data[i];
    		k++;
    	}
    L.length=k;							//����L�ĳ���Ϊk
}

template <typename T>
void Deletex2(SqList<T> &L, int x)   	//����㷨2
{
    int k=0;							//�ۼƵ���k��Ԫ�ظ���			
    for (int i=0;i<L.length;i++)
        if (L.data[i]!=x)				//����Ϊx��Ԫ��ǰ��k��λ��
            L.data[i-k]=L.data[i];
        else							//�ۼ�ɾ����Ԫ�ظ���k
            k++;
    L.length-=k;						//���ó���
}        

template <typename T>
void Deletex3(SqList<T> &L, int x)   	//����㷨3
{
	int i=-1,j=0;
    while (j<L.length)					//j��������Ԫ��
    {
        if (L.data[j]!=x)				//�ҵ���Ϊx��Ԫ��a[j]
        {
            i++;					    //����Ϊx������
            if (i!=j)
				swap(L.data[i],L.data[j]);	//���Ϊi��j������Ԫ�ؽ���
		}
        j++;							//����ɨ��
    }
    L.length=i+1;						//���ó���
}
int main()
{
	int a[]={2,1,1,1,1,1,3};
	int n=sizeof(a)/sizeof(a[0]);
	SqList<int> L1;						//����Ԫ������Ϊint��˳������L
	L1.CreateList(a,n);
	cout << "˳���L1:"; L1.DispList();
	int x=1;
	printf("�ⷨ1:ɾ��L1������%d��Ԫ��\n",x);
	Deletex1(L1,x);
	cout << "˳���L1:"; L1.DispList();

	SqList<int> L2;						//����Ԫ������Ϊint��˳������L
	L2.CreateList(a,n);
	cout << "˳���L2:"; L2.DispList();
	printf("�ⷨ2:ɾ��L2������%d��Ԫ��\n",x);
	Deletex2(L2,x);
	cout << "˳���L2:"; L2.DispList();


	SqList<int> L3;						//����Ԫ������Ϊint��˳������L
	L3.CreateList(a,n);
	cout << "˳���L3:"; L3.DispList();
	printf("�ⷨ3:ɾ��L3������%d��Ԫ��\n",x);
	Deletex3(L3,x);
	cout << "˳���L3:"; L3.DispList();

	return 0;
}
