#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
struct Stud
{	int no;
	string name;
	Stud(int no1,string name1)			//���캯��
	{	no=no1;
		name=name1;
	}
	bool operator<(const Stud &s) const	//��ʽ1������<�����
	{
		return no>s.no;					//���ڰ�no�ݼ����򣬽�<��Ϊ>��no��������
	}
};
struct Cmp								//��ʽ2�����غ������������()
{	bool operator()(const Stud &s,const Stud &t) const
	{
		return s.name<t.name; 			//���ڰ�name�������򣬽�<��Ϊ>��name�ݼ�����
	}
};
void Disp(vector<Stud> &myv)			//���vector��Ԫ��
{	vector<Stud>::iterator it;
	for(it = myv.begin();it!=myv.end();it++)
		cout << it->no << "," << it->name << "\t";
	cout << endl;
}
int main()
{	Stud a[]={Stud(2,"Mary"),Stud(1,"John"),Stud(5,"Smith")};
	int n=sizeof(a)/sizeof(a[0]);
	vector<Stud> myv(a,a+n);
	cout << "��ʼmyv:        "; Disp(myv);	//�����2,Mary   1,John  5,Smith
	sort(myv.begin(),myv.end());			//Ĭ��ʹ��<���������
	cout << "��no�ݼ�����:   "; Disp(myv);	//�����5,Smith  2,Mary  1,John
	sort(myv.begin(),myv.end(),Cmp());		//ʹ��Cmp�е�()�������������
	cout << "��name��������: "; Disp(myv);	//�����1,John   2,Mary  5,Smith
	return 0;
}

