#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
struct Stud
{	int no;
	string name;
	Stud(int no1,string name1)			//构造函数
	{	no=no1;
		name=name1;
	}
	bool operator<(const Stud &s) const	//方式1：重载<运算符
	{
		return no>s.no;					//用于按no递减排序，将<改为>则按no递增排序
	}
};
struct Cmp								//方式2：重载函数调用运算符()
{	bool operator()(const Stud &s,const Stud &t) const
	{
		return s.name<t.name; 			//用于按name递增排序，将<改为>则按name递减排序
	}
};
void Disp(vector<Stud> &myv)			//输出vector的元素
{	vector<Stud>::iterator it;
	for(it = myv.begin();it!=myv.end();it++)
		cout << it->no << "," << it->name << "\t";
	cout << endl;
}
int main()
{	Stud a[]={Stud(2,"Mary"),Stud(1,"John"),Stud(5,"Smith")};
	int n=sizeof(a)/sizeof(a[0]);
	vector<Stud> myv(a,a+n);
	cout << "初始myv:        "; Disp(myv);	//输出：2,Mary   1,John  5,Smith
	sort(myv.begin(),myv.end());			//默认使用<运算符排序
	cout << "按no递减排序:   "; Disp(myv);	//输出：5,Smith  2,Mary  1,John
	sort(myv.begin(),myv.end(),Cmp());		//使用Cmp中的()运算符进行排序
	cout << "按name递增排序: "; Disp(myv);	//输出：1,John   2,Mary  5,Smith
	return 0;
}

