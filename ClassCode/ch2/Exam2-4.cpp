#include "SqList.cpp"						//����˳�������
template <typename T>
void Merge2(SqList<T> A,SqList<T> B,SqList<T> &C)
{ 	int i=0,j=0;                        	//i���ڱ���A,j���ڱ���B
 	while (i<A.length && j<B.length)  		//�������û�б������
  	{	if (A.data[i]<B.data[j])
      	{
		  	C.Add(A.data[i]);           	//�鲢A[i]:����С��A[i]��ӵ�C��
        	i++; 
        }
    	else								//�鲢B[j]:����С��B[j]��ӵ�C��
    	{
    		C.Add(B.data[j]);
    		j++;
		}
    }
 	while (i<A.length)						//��Aû�б������
 	{
  		C.Add(A.data[i]);					//�鲢A��ʣ��Ԫ�� 
    	i++;
    }
 	while (j<B.length)						//��Bû�б������
  	{	C.Add(B.data[j]);					//�鲢B��ʣ��Ԫ��
    	j++;
	}
}
int main()
{
	int a[]={1,3,5,8};
	int n=sizeof(a)/sizeof(a[0]);
	SqList<int> L1;						//����Ԫ������Ϊint��˳������L
	L1.CreateList(a,n);
	cout << "˳���L1: "; L1.DispList();

	int b[]={1,2,5,6,7,9,20};
	int m=sizeof(b)/sizeof(b[0]);
	SqList<int> L2;						//����Ԫ������Ϊint��˳������L
	L2.CreateList(b,m);
	cout << "˳���L2: "; L2.DispList();

	cout << "A,B -> C" << endl;
	SqList<int> L3;
	Merge2(L1,L2,L3);
	cout << "˳���L3: "; L3.DispList();

}
