#include "SqListSearch.h"					//�������Ա������ģ�������
template <typename T>
SqListSearchClass<T>::SqListSearchClass()	//���캯�������ڲ���˳���ĳ�ʼ��
{
	length=0;
}
template <typename T>
void SqListSearchClass<T>::SetK(T a[],int n)	//����˳���Ĺؼ���
{
	int i;
	for (i=0;i<n;i++)
		R[i].key=a[i];
	length=n;
}
template <typename T>
int SqListSearchClass<T>::SeqSearch(T k)	//˳������㷨
{
	int i=0;
	while (i<length && R[i].key!=k)	i++;	//�ӱ�ͷ������
	if (i>=length) return 0;				//δ�ҵ�����0
	else return i+1;						//�ҵ��󷵻����߼����i+1
}
template <typename T>
int SqListSearchClass<T>::BinSearch(T k)	//�����ҷǵݹ��㷨
{
	int low=0,high=length-1,mid;
	while (low<=high)			//��ǰ�������Ԫ��ʱѭ��
	{
		mid=(low+high)/2;		//�����������м�λ��
		if (R[mid].key==k)		//���ҳɹ��������߼����mid+1
			return mid+1;		//�ҵ��󷵻����߼����mid+1
		if (R[mid].key>k)		//������R[low..mid-1]�в���
			high=mid-1;
		else					//R[mid].key<k
			low=mid+1;			//������R[mid+1..high]�в���
	}
	return 0;					//����ǰ��������û��Ԫ��ʱ����0
}
template <typename T>
int SqListSearchClass<T>::BinSearch1(T k)	//�����ҵݹ��㷨
{
	return BinSearch11(0,length-1,k);
}
template <typename T>
int SqListSearchClass<T>::BinSearch11(int low,int high,T k)	//��BinSearch1��������
{
	int mid;
	if (low<=high)				//����ǰ�����������Ԫ��
	{
		mid=(low+high)/2;		//�����������м�λ��
		if (R[mid].key==k)		//���ҳɹ��������߼����mid+1
			return mid+1;		//�ҵ��󷵻����߼����mid+1
		if (R[mid].key>k)		//������R[low..mid-1]�в���
			return BinSearch11(low,mid-1,k);//�ݹ����������в���
		else						//R[mid].key<k
			return BinSearch11(mid+1,high,k);	//�ݹ����������в���
	}
	else return 0;				//����ǰ��������û��Ԫ��ʱ����0
}
template <typename T>
int SqListSearchClass<T>::IdxSearch(IdxType<T> I[],int b,T k)
//��˳���R[0..length-1]��������I[0..b-1]�в��ҹؼ���k�ļ�¼
{
	int low=0,high=b-1,mid,i;
	int s=(length+b-1)/b;		//sΪÿ���Ԫ�ظ�����ӦΪn/b������ȡ��
	while (low<=high)			//���������н����۰����,�ҵ���λ��Ϊhigh+1
	{
		mid=(low+high)/2;
		if (I[mid].key>=k)
			high=mid-1;
		else 
			low=mid+1;
	}
	//�ҵ��������high+1��,����˳����ڸÿ���˳�����
	i=I[high+1].link;
	while (i<=I[high+1].link+s-1 && R[i].key!=k)
		i++;
	if (i<=I[high+1].link+s-1)
		return i+1;		//���ҳɹ�,���ظ�Ԫ�ص��߼����
	else
		return 0;		//����ʧ��,����0
}
template <typename T>
void SqListSearchClass<T>::dispR()		//���˳���R�е�Ԫ��
{
	int i;
	for (i=0;i<length;i++)
		cout << R[i].key << " ";
	cout << endl;
}
void main()
{
	SqListSearchClass<int> s,s1,s2;
	int k=7,i;
	int A[]={3,9,1,5,8,10,6,7,2,4},n1=10;
	int B[]={2,4,7,9,10,14,18,26,32,40},n2=10;
	int C[]={8,14,6,9,10,22,34,18,19,31,40,38,54,66,46,71,78,68,80,85,100,94,88,96,87},n3=25,b=5;
	//---------------˳�����------------------
	s.SetK(A,n1);
	cout << "�ؼ�������:"; s.dispR();
	i=s.SeqSearch(k);
	if (i>0)
		cout << "˳�����:��" << i << "����¼�Ĺؼ�����" << k << endl;
	else
		cout << "˳�����:δ�ҵ��ؼ���" << k << endl;
	//---------------�����Ҳ���------------------
	k=7;
	s1.SetK(B,n2);
	cout << "�ؼ�������:"; s1.dispR();
	i=s1.BinSearch(k);
	if (i>0)
		cout << "������1:��" << i << "����¼�Ĺؼ�����" << k << endl;
	else
		cout << "������1:δ�ҵ��ؼ���" << k << endl;
	i=s1.BinSearch1(k);
	if (i>0)
		cout << "������2:��" << i << "����¼�Ĺؼ�����" << k << endl;
	else
		cout << "������2:δ�ҵ��ؼ���" << k << endl;
	//---------------�ֿ���Ҳ���------------------
	k=80;
	IdxType<int> I[MaxSize];
	I[0].key=14; I[0].link=0; 
	I[1].key=34; I[1].link=5; 
	I[2].key=66; I[2].link=10; 
	I[3].key=85; I[3].link=15; 
	I[4].key=100; I[4].link=20; 
	s2.SetK(C,n3);
	cout << "�ؼ�������:"; s2.dispR();
	i=s2.IdxSearch(I,b,k);
	if (i>0)
		cout << "�ֿ����:��" << i << "����¼�Ĺؼ�����" << k << endl;
	else
		cout << "�ֿ����:δ�ҵ��ؼ���" << k << endl;
}
