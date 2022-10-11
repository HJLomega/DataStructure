#include "SqList.cpp"							//����˳�������
template <typename T>
T Middle(SqList<T> A,SqList<T> B)             	//����㷨
{	int i=0,j=0;								//i,j�ֱ����A��B 
	int k=0;									//�ۼƹ鲢�Ĵ��� 
	while (i<A.length && j<B.length)			//��������˳����û��ɨ����
  	{
	  	k++;							      	//�鲢������1
    	if (A.data[i]<B.data[j])            	//A�е�ǰԪ��Ϊ��С��Ԫ��
      	{	if (k==A.length)					//ǡ�ñȽ���n��
         		return A.data[i];				//����A�еĵ�ǰԪ��
        	i++;
    	}
    	else 									//B�е�ǰԪ��Ϊ��С��Ԫ��
    	{
      		if (k==B.length)					//ǡ�ñȽ���n��
       			return B.data[j];				//����B�еĵ�ǰԪ��
       		j++;
       }
   }
	return 0;
}

int main()
{
	int a[]={11,13,15,17,19};
	int n=sizeof(a)/sizeof(a[0]);
	SqList<int> L1;						//����Ԫ������Ϊint��˳������L
	L1.CreateList(a,n);
	cout << "˳���L1: "; L1.DispList();

	int b[]={2,4,6,8,20};
	int m=sizeof(b)/sizeof(b[0]);
	SqList<int> L2;						//����Ԫ������Ϊint��˳������L
	L2.CreateList(b,m);
	cout << "˳���L2: "; L2.DispList();
	int ans=Middle(L1,L2);

	cout << "��λ��: " << ans << endl;
	return 0;
}
