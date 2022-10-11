#include<iostream>
using namespace std;
const int MAXR=20;					//ϡ������������
const int MAXC=20;					//ϡ������������
const int MaxSize=100;				//��Ԫ��˳������Ԫ�ظ���
struct TupElem						//������Ԫ��Ԫ�ص�����
{	int r;							//�к�
	int c;							//�к�
	int d;							//Ԫ��ֵ
	TupElem() {}					//���캯�� 
	TupElem(int r1,int c1,int d1)	//���ع��캯�� 
	{
		r=r1;
		c=c1;
		d=d1;
	}		
};
class TupClass						//��Ԫ��洢�ṹ��
{
	int rows;						//����
	int cols;						//����
	int nums;						//����Ԫ�ظ���
	TupElem *data;					//ϡ������Ӧ����Ԫ��˳���
public:
	TupClass()						//���캯��
	{
		data=new TupElem[MaxSize];	//����ռ�
		nums=0;
	}
	~TupClass()						//��������
	{
		delete [] data;				//�ͷſռ�
	}
	void CreateTup(int A[][MAXC],int m,int n)	//������Ԫ��
	{
		rows=m; cols=n; nums=0;
		for (int i=0;i<m;i++)
			for (int j=0;j<n;j++)
				if (A[i][j]!=0)		//ֻ�洢����Ԫ��
				{
					data[nums]=TupElem(i,j,A[i][j]);
					nums++;
				}
	}
	bool Setvalue(int i,int j,int x)			//��Ԫ��Ԫ�ظ�ֵA[i][j]=x
	{
		if (i<0 || i>=rows || j<0 || j>=cols)
			return false;						//�±����ʱ����false
		int k=0,k1;
		while (k<nums && i>data[k].r)
			k++;								//���ҵ�i�еĵ�һ������Ԫ��
		while (k<nums && i==data[k].r && j>data[k].c)
			k++;								//�ڵ�i���в��ҵ�j�е�Ԫ��
		if (data[k].r==i && data[k].c==j)		//�ҵ���������Ԫ��
			data[k].d=x;
		else									//������������Ԫ��ʱ����һ��Ԫ��
		{
			for (k1=nums-1; k1>=k;k1--)			//����Ԫ���Ա����
			{
				data[k1+1].r=data[k1].r;
				data[k1+1].c=data[k1].c;
				data[k1+1].d=data[k1].d;
			}
			data[k].r=i; data[k].c=j; data[k].d=x;
			nums++;
		}
		return true;							//��ֵ�ɹ�ʱ����true
	}
	bool GetValue(int i,int j,int &x)	//��ָ��λ�õ�Ԫ��ֵ��������x=A[i][j]
	{
		if (i<0 || i>=rows || j<0 || j>=cols)
			return false;						//�±����ʱ����false
		int k=0;
		while (k<nums && data[k].r<i)
			k++;								//���ҵ�i�еĵ�һ������Ԫ��
		while (k<nums && data[k].r==i && data[k].c<j)
			k++;								//�ڵ�i���в��ҵ�j�е�Ԫ��
		if (data[k].r==i && data[k].c==j)		//�ҵ���������Ԫ��
			x=data[k].d;
		else
			x=0;								//����Ԫ����û���ҵ���ʾ����Ԫ��
		return true;							//ȡֵ�ɹ�ʱ����true
	}
	void DispMat()				//�����Ԫ��
	{
		if (nums<=0) return;					//û�з���Ԫ��ʱ����
		cout << "\t" << rows << "\t" << cols << "\t" << nums << endl;
		cout << "\t------------------\n";
		for (int i=0;i<nums;i++)
			cout << "\t" << data[i].r << "\t" << data[i].c << "\t" << data[i].d << endl;
	}
};
int main()
{
	TupClass t,tb;
	int x;
	int a[MAXR][MAXC]={{0,0,1,0,0,0,0},{0,2,0,0,0,0,0},{3,0,0,0,0,0,0},{0,0,0,5,0,0,0},{0,0,0,0,6,0,0},{0,0,0,0,0,7,4}};
	t.CreateTup(a,6,7);
	cout << "��Ԫ��t��ʾ:\n"; t.DispMat();
	cout << "ִ��A[4][1]=8\n";
	t.Setvalue(4,1,8);
	cout << "��Ԫ��t��ʾ:\n"; t.DispMat();
	cout << "��x=A[4][1]\n";
	t.GetValue(4,1,x);
	cout << "x=" << x << endl;
	return 0; 
}

