#include "SqList.cpp"							//����˳�������
template <typename T>
bool Deletek(SqList<T> &L,int i,int k)           //����㷨
{
	if (i<0 || k<1 || i+k<1 || i+k>L.length)
		return false;							//����i��k���󷵻�false
	for (int j=i+k;j<L.length;j++)				//ɾ��k��Ԫ�� 
 		L.data[j-k]=L.data[j];
	L.length-=k;								//���ȼ�k
	return true;
}

int main()
{
	int n=5,i=1,k=3;
	int a[]={1,2,3,4,5};
	SqList<int> L;								//����Ԫ������Ϊint��˳������L
	cout << "����˳���L" << endl;
	L.CreateList(a,n);
	cout << "˳���L:"; L.DispList();
	cout << "ɾ��L�����" << i << "��ʼ��" << k << "��Ԫ��" << endl;
	Deletek(L,i,k);
	cout << "˳���L:"; L.DispList();
	cout << "����˳���L" << endl;
	return 0;
}

