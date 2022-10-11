#include "LinkStack.cpp"   			//������ջ��ģ��Ķ���
const int MaxSize=100;
void Reverse(LinkStack<int> &st)    //����ջst
{
	int a[MaxSize];					//����һ���������� 
	int i=0,e;
 	while (!st.empty())				//����ջ��Ԫ�طŵ�����a��
 	{
 		st.pop(e);
 		a[i++]=e;
 	}
	for (int j=0;j<i;j++)         	//������a������Ԫ�ؽ�ջ
  		st.push(a[j]);
}

int main()
{
	LinkStack<int> st;
	cout << "1��5��ջ" << endl; 
	for (int i=1;i<=5;i++)
		st.push(i);
	cout << "ջԪ������" << endl;
	Reverse(st);
	int e;
	cout << "��ջ����: "; 
	while (!st.empty())
	{
		st.pop(e);
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
