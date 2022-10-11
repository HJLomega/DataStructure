#include <iostream>
using namespace std;
int MaxSize=100;								//存放最多元素个数
struct Stud2									//学生单链表结点类型 
{
	int no;       								//存放学号
	string name;  								//存放姓名
	int score; 									//存放分数
	Stud2 *next;								//存放下一个结点指针
	Stud2(int no1,string name1,int score1)		//重载构造函数 
	{
		no=no1;
		name=name1;
		score=score1;
		next=NULL;
	}	
};
class StudClass2								//类 
{
public:
	Stud2 *head;
	StudClass2()
	{
		head=NULL;
	}
	void Create()								//创建高数成绩单链表
	{
		Stud2 *p2,*p3,*p4,*p5,*p6,*p7;
		head=new Stud2(2018001,"王华",90);		//单链表首结点
		p2=new Stud2(2018010,"刘丽",62);		//建立其他结点 
		p3=new Stud2(2018006,"陈明",54);
		p4=new Stud2(2018009,"张强",95);
		p5=new Stud2(2018007,"许兵",76);
		p6=new Stud2(2018012,"李萍",88);
		p7=new Stud2(2018005,"李英",82);
		head->next=p2;                   		//建立结点之间的关系
 		p2->next=p3;
 		p3->next=p4;
 		p4->next=p5;
 		p5->next=p6;
 		p6->next=p7;
 		p7->next=NULL;							//尾结点的next置为空	
	}
	void display()								//输出所有结点值
	{
		Stud2 *p=head;							//p指向首结点
		cout <<"  学号\t\t姓名\t分数\n";
		cout << "  =============================\n";
		while (p!=NULL)
		{
			cout << "  " << p->no << "\t" << p->name << "\t" << p->score << endl;
			p=p->next;
		}
	}
	int Findi(int i)						//查找序号为i的学生分数
	{
		int j=0;
		Stud2 *p=head;						//p指向第一个结点
		while (j<i && p!=NULL)
		{
			j++;
			p=p->next;
		}
		if (i<=0 || p==NULL)				//i错误时返回-1
			return -1;
		else								//i正确时返回其分数
			return p->score; 
	}
};
int main()
{
	StudClass2 st2;
	cout << "① 建立存储结构\n";
	st2.Create(); 
	cout << "② 输出存储结构\n";
	st2.display();
	int i=2; 
	cout << "③ 求序号为" << i << "的学生分数\n";
	int f=st2.Findi(i);	
	if (i>=0)
		cout << "   分数为" << f << endl;
	else
		cout << "   该学生不存在" << endl; 
}
