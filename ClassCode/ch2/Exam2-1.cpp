#include "SqList.cpp"					//����˳������� 
template <typename T>
void Reverse(SqList<T> &L)				//����㷨
{	T tmp;
	int i=0,j=L.length-1;
	while (i<j)
	{	swap(L.data[i],L.data[j]);		//���Ϊi��j������Ԫ�ؽ���
		i++; j--;
	}
}


int main()
{
	int n=6;
	int a[]={1,2,3,4,5,6};
	SqList<int> L;		//����Ԫ������Ϊint��˳������L
	cout << "����˳���L" << endl;
	L.CreateList(a,n);
	cout << "˳���L:"; L.DispList();
	cout << "����˳���L" << endl;
	Reverse(L);
	cout << "˳���L:"; L.DispList();
	cout << "����˳���L" << endl;
	return 0;
}
