#include "SqList.cpp"						//����˳����� 
int main()
{
	int i,e;
	SqList<int> L;							//����Ԫ������Ϊint��˳������L
	cout << "��������˳���L" << endl;
	L.Insert(0,2);							//����Ԫ��2
	L.Insert(1,3);							//����Ԫ��3
	L.Insert(2,1);							//����Ԫ��1
	L.Insert(3,5);							//����Ԫ��5
	L.Insert(4,4);							//����Ԫ��4
	L.Insert(5,1);							//����Ԫ��1
	L.Add(8);								//�������8 
	cout << "˳���L:"; L.DispList();
	cout << "����:" << L.length << "  ����:" << L.capacity << endl;
	i=3; L.GetElem(i,e);
	cout << "���Ϊ" << i << "��Ԫ��:" << e << endl;
	e=1;
	cout << "��һ��" << e << "��Ԫ�����=" << L.GetNo(e) << "\n";
	i=2; cout << "ɾ�����Ϊ" << i << "��Ԫ��\n";
	L.Delete(i);
	cout << "˳���L:";L.DispList();
	cout << "����:" << L.length << "  ����:" << L.capacity << endl;
	int b[]={0,1,1,0,1};
	for (int i=0;i<5;i++)
	{	cout << "ɾ�����Ϊ" << b[i] << "��Ԫ��\n";
		L.Delete(b[i]);
		cout << "˳���L:";L.DispList();
		cout << "����:" << L.length << "  ����:" << L.capacity << endl;
	}
	cout << "����˳���L" << endl;
	return 0;
}

