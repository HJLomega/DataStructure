#include <iostream>
using namespace std;
const int initcap=5;						//˳���ĳ�ʼ����
template <typename T>
class SqList								//˳�������
{
public:
	T *data;								//���˳�����Ԫ��
	int capacity;							//˳�������� 
	int length;   							//���˳���ĳ���
	SqList()								//���캯��
	{
		data=new T[initcap];				//Ϊdata�����ʼ������С�Ŀռ�
		capacity=initcap;
		length=0;							//��ʼʱ��lengthΪ0
	}
	~SqList()								//��������
	{
		delete [] data;						//�ͷſռ� 
		
	}
	SqList(const SqList<T> &s)					//���Ƴ�ʼ�����캯�� 
	{
		capacity=s.capacity;
		length=s.length;
		data=new T[capacity];				//Ϊ��ǰ˳������ռ�
		for (int i=0;i<length;i++)
			data[i]=s.data[i];
	}	
	void CreateList(T a[],int n)			//������a��Ԫ�����彨��˳���
	{
		for (int i=0;i<n;i++)
		{
			if(length==capacity)			//���������ʱ
				recap(2*length);			//��������
     		data[length]=a[i];
     		length++;                   	//��Ӻ�Ԫ�ظ�������1
		}
	}
	void Add(T e)	        				//�����Ա��ĩβ���һ��Ԫ��e
	{
		if (length==capacity)    			//˳���ռ���ʱ��������
			recap(2*length);
		data[length]=e;						//���Ԫ��e
		length++;    						//������1
	}
	int Getlength()							//��˳���ĳ��� 
	{
		return length;
	}
	bool GetElem(int i, T &e)				//�����Ϊi��Ԫ��
	{
		if (i<0 || i>=length)
			return false;					//��������ʱ����false
		e=data[i];							//ȡԪ��ֵ
		return true;						//�ɹ��ҵ�Ԫ��ʱ����true
	}
	bool SetElem(int i,T e)             	//�������Ϊi��Ԫ��
	{
		if (i<=0 || i>=length)				//��������ʱ����false
			return false; 
 		data[i]=e;
 		return true;
 	}
	int GetNo(T e)						    //���ҵ�һ��Ϊe��Ԫ�ص����
	{ 
		int i=0;
 		while(i<length && data[i]!=e)
  			i++;							//����Ԫ��e
		if (i>=length)						//δ�ҵ�ʱ����-1
 			return -1;
		else
  			return i;						//�ҵ��󷵻������
	}
	bool Insert(int i, T e)                 //�����Ա������iλ�ò���Ԫ��e
	{
		if (i<0 || i>length)				//����i���󷵻�false
			return false;
		if(length==capacity)		    	//��ʱ��������
			recap(2*length);
		for(int j=length;j>i;j--)			//��data[i]������Ԫ�غ���һ��λ��
			data[j]=data[j-1];
		data[i]=e;			        		//����Ԫ��e
 		length++;				        	//������1
 		return true;
 	}

	bool Delete(int i) 		        		//�����Ա���ɾ�����i��Ԫ��
	{
		if (i<0 || i>=length)				//����i���󷵻�false
			return false;
		for(int j=i;j<length-1;j++)
			data[j]=data[j+1];         		//��data[i]֮���Ԫ��ǰ��һ��λ��
		length--;                           //���ȼ�1
		if (capacity>initcap && length<=capacity/4)
 			recap(capacity/2);       		//����������������������
 		return true;
	}
	void DispList()							//���˳���L������Ԫ��
	{
		for (int i=0;i<length;i++)			//����˳����и�Ԫ��ֵ
			cout << data[i] << " ";
		cout << endl;
	}
private:
	void recap(int newcap)					//�ı�˳��������Ϊnewcap
	{
		if (newcap<=0) return;
		T *olddata=data;
 		data=new T[newcap];					//�����¿ռ�
 		capacity=newcap;					//�������� 
 		for(int i=0;i<length;i++)			//����
			data[i]=olddata[i];
		delete [] olddata;  				//�ͷžɿռ�
	}
};
	
/*
//main������������
int main()
{
	int i;
	char e;
	SqList<char> L;							//����Ԫ������Ϊint��˳������L
	cout << "����˳���L" << endl;
	L.Insert(0,'1');							//����Ԫ��1
	L.Insert(1,'3');							//����Ԫ��3
	L.Insert(2,'1');							//����Ԫ��1
	L.Insert(3,'5');							//����Ԫ��5
	L.Insert(4,'4');							//����Ԫ��4
	L.Insert(5,'2');							//����Ԫ��2
	cout << "˳���L:"; L.DispList();
	cout << "����:" << L.length << "  ����:" << L.capacity << endl;
	i=3; L.GetElem(i,e);
	cout << "���Ϊ" << i << "��Ԫ��:" << e << endl;
	e='1';
	cout << "��һ��" << e << "��Ԫ�����=" << L.GetNo(e) << "\n";
	i=2; cout << "ɾ�����Ϊ" << i << "��Ԫ��\n";
	L.Delete(i);
	cout << "˳���L:";L.DispList();
	cout << "����:" << L.length << "  ����:" << L.capacity << endl;
	i=0; cout << "ɾ�����Ϊ" << i << "��Ԫ��\n";
	L.Delete(i);
	cout << "˳���L:";L.DispList();
	cout << "����:" << L.length << "  ����:" << L.capacity << endl;
	i=1; cout << "ɾ�����Ϊ" << i << "��Ԫ��\n";
	L.Delete(i);
	cout << "˳���L:";L.DispList();
	cout << "����:" << L.length << "  ����:" << L.capacity << endl;
	i=1; cout << "ɾ�����Ϊ" << i << "��Ԫ��\n";
	L.Delete(i);
	cout << "˳���L:";L.DispList();
	cout << "����:" << L.length << "  ����:" << L.capacity << endl;
	i=0; cout << "ɾ�����Ϊ" << i << "��Ԫ��\n";
	L.Delete(i);
	cout << "˳���L:";L.DispList();
	cout << "����:" << L.length << "  ����:" << L.capacity << endl;
	cout << "����˳���L" << endl;
	return 0;
}

//����һ������main 
int main()
{
	int i,e;
	SqList<int> L;							//����Ԫ������Ϊint��˳������L
	cout << "����˳���L" << endl;
	L.Insert(0,1);							//����Ԫ��1
	L.Insert(1,3);							//����Ԫ��3
	L.Insert(2,1);							//����Ԫ��1
	L.Insert(3,5);							//����Ԫ��5
	L.Insert(4,4);							//����Ԫ��4
	L.Insert(5,2);							//����Ԫ��2
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
	i=0; cout << "ɾ�����Ϊ" << i << "��Ԫ��\n";
	L.Delete(i);
	cout << "˳���L:";L.DispList();
	cout << "����:" << L.length << "  ����:" << L.capacity << endl;
	i=1; cout << "ɾ�����Ϊ" << i << "��Ԫ��\n";
	L.Delete(i);
	cout << "˳���L:";L.DispList();
	cout << "����:" << L.length << "  ����:" << L.capacity << endl;
	i=1; cout << "ɾ�����Ϊ" << i << "��Ԫ��\n";
	L.Delete(i);
	cout << "˳���L:";L.DispList();
	cout << "����:" << L.length << "  ����:" << L.capacity << endl;
	i=0; cout << "ɾ�����Ϊ" << i << "��Ԫ��\n";
	L.Delete(i);
	cout << "˳���L:";L.DispList();
	cout << "����:" << L.length << "  ����:" << L.capacity << endl;
	cout << "����˳���L" << endl;
	return 0;
}
*/
