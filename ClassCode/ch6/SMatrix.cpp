#include "SMatrix.h"				//����ϡ�������Ԫ���ʾ��������
SMatrixClass::SMatrixClass()		//���캯��
{
	data=new TupNode[MaxSize];		//����ռ�
}
SMatrixClass::~SMatrixClass()		//��������
{	delete [] data;	}		//�ͷſռ�
void SMatrixClass::CreateTSMatrix(int A[][MAXC],int m,int n)	//������Ԫ��
{
	int i,j;
	rows=m; cols=n; nums=0;
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
			if (A[i][j]!=0)		//ֻ�洢����Ԫ��
			{
				data[nums].r=i;
				data[nums].c=j;
				data[nums].d=A[i][j];
				nums++;
			}
	}
}
bool SMatrixClass::Setvalue(int i,int j,int x)	//��Ԫ��Ԫ�ظ�ֵA[i][j]=x
{
	int k=0,k1;
	if (i<0 || i>=rows || j<0 || j>=cols)
		return false;						//�±����ʱ����false
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
bool SMatrixClass::GetValue(int i,int j,int &x)	//��ָ��λ�õ�Ԫ��ֵ��������x=A[i][j]
{
	int k=0;
	if (i<0 || i>=rows || j<0 || j>=cols)
		return false;						//�±����ʱ����false
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
void SMatrixClass::DispMat()				//�����Ԫ��
{
	int i;
	if (nums<=0) return;					//û�з���Ԫ��ʱ����
	cout << "\t" << rows << "\t" << cols << "\t" << nums << endl;
	cout << "\t------------------\n";
	for (i=0;i<nums;i++)
		cout << "\t" << data[i].r << "\t" << data[i].c << "\t" << data[i].d << endl;
}
void SMatrixClass::Transpose(SMatrixClass &tb)	//����ת��
{
	int p,q=0,v;							//qΪtb.data���±�
	tb.rows=cols;
	tb.cols=rows;
	tb.nums=nums;
	if (nums!=0)							//��ǰ��Ԫ���ʾ�д��ڷ���Ԫ��ʱִ��ת��
	{
		for (v=0;v<cols;v++)				//tb.data[q]�еļ�¼��c��Ĵ�������
			for (p=0;p<nums;p++)			//pΪdata���±�
				if (data[p].c==v)
				{
					tb.data[q].r=data[p].c;
					tb.data[q].c=data[p].r;
					tb.data[q].d=data[p].d;
					q++;
				}
	}
}
//main������������
/*void main()
{
	SMatrixClass t,tb;
	int x;
	int a[MAXR][MAXC]={{0,0,1,0,0,0,0},{0,2,0,0,0,0,0},{3,0,0,0,0,0,0},{0,0,0,5,0,0,0},{0,0,0,0,6,0,0},{0,0,0,0,0,7,4}};
	t.CreateTSMatrix(a,6,7);
	cout << "��Ԫ��t��ʾ:\n"; t.DispMat();
	cout << "ִ��A[4][1]=8\n";
	t.Setvalue(4,1,8);
	cout << "��Ԫ��t��ʾ:\n"; t.DispMat();
	cout << "��x=A[4][1]\n";
	t.GetValue(4,1,x);
	cout << "x=" << x << endl;
	cout << "tת��Ϊtb\n";
	t.Transpose(tb);
	cout << "��Ԫ��tb��ʾ:\n"; tb.DispMat();
	cout << "main��������,�������е���Ԫ�����" << endl;
}
*/