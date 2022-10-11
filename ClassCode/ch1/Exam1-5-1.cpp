#include <iostream>
using namespace std;
int MaxSize=100;								//存放最多元素个数
struct Stud1									//学生成绩元素类
{
	int no;       								//存放学号
	string name;  								//存放姓名
	int score; 									//存放分数
	Stud1() {}									//构造函数
	Stud1(int no1,string name1,int score1)		//重载构造函数 
	{
		no=no1;
		name=name1;
		score=score1;
	}	
};
class StudClass1								//类 
{
public:
	Stud1 *data;
	int length;
	StudClass1()
	{
		data=new Stud1[MaxSize]; 
		length=0;
	}
	void Create()								//创建高数成绩顺序表
	{
		data[0]=Stud1(2018001,"王华",90);
		data[1]=Stud1(2018010,"刘丽",62);
		data[2]=Stud1(2018006,"陈明",54);
		data[3]=Stud1(2018009,"张强",95);
		data[4]=Stud1(2018007,"许兵",76);
		data[5]=Stud1(2018012,"李萍",88);
		data[6]=Stud1(2018005,"李英",82);
		length=7;
	}
	void display()				//输出所有元素
	{
		cout <<"  学号\t姓名\t分数\n";
		cout << "  ========================\n";
		for (int i=0;i<length;i++)
			cout << "   " << data[i].no << "\t" << data[i].name << "\t" << data[i].score << endl;
	}
	int Findi(int i)                   			//查找序号为i的学生分数
	{
		if (i<0 || i>=length)
			return -1;
		return data[i].score;              		//i正确时返回分数
	}
};
int main()
{
	StudClass1 st1;
	cout << "① 建立存储结构\n";
	st1.Create(); 
	cout << "② 输出存储结构\n";
	st1.display();
	int i=2; 
	cout << "③ 求序号为" << i << "的学生分数\n";
	int f=st1.Findi(i);	
	if (i>=0)
		cout << "   分数为" << f << endl;
	else
		cout << "   该学生不存在" << endl; 
}
