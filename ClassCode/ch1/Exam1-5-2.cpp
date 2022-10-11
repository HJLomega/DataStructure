#include <iostream>
using namespace std;
int MaxSize=100;								//������Ԫ�ظ���
struct Stud2									//ѧ�������������� 
{
	int no;       								//���ѧ��
	string name;  								//�������
	int score; 									//��ŷ���
	Stud2 *next;								//�����һ�����ָ��
	Stud2(int no1,string name1,int score1)		//���ع��캯�� 
	{
		no=no1;
		name=name1;
		score=score1;
		next=NULL;
	}	
};
class StudClass2								//�� 
{
public:
	Stud2 *head;
	StudClass2()
	{
		head=NULL;
	}
	void Create()								//���������ɼ�������
	{
		Stud2 *p2,*p3,*p4,*p5,*p6,*p7;
		head=new Stud2(2018001,"����",90);		//�������׽��
		p2=new Stud2(2018010,"����",62);		//����������� 
		p3=new Stud2(2018006,"����",54);
		p4=new Stud2(2018009,"��ǿ",95);
		p5=new Stud2(2018007,"���",76);
		p6=new Stud2(2018012,"��Ƽ",88);
		p7=new Stud2(2018005,"��Ӣ",82);
		head->next=p2;                   		//�������֮��Ĺ�ϵ
 		p2->next=p3;
 		p3->next=p4;
 		p4->next=p5;
 		p5->next=p6;
 		p6->next=p7;
 		p7->next=NULL;							//β����next��Ϊ��	
	}
	void display()								//������н��ֵ
	{
		Stud2 *p=head;							//pָ���׽��
		cout <<"  ѧ��\t\t����\t����\n";
		cout << "  =============================\n";
		while (p!=NULL)
		{
			cout << "  " << p->no << "\t" << p->name << "\t" << p->score << endl;
			p=p->next;
		}
	}
	int Findi(int i)						//�������Ϊi��ѧ������
	{
		int j=0;
		Stud2 *p=head;						//pָ���һ�����
		while (j<i && p!=NULL)
		{
			j++;
			p=p->next;
		}
		if (i<=0 || p==NULL)				//i����ʱ����-1
			return -1;
		else								//i��ȷʱ���������
			return p->score; 
	}
};
int main()
{
	StudClass2 st2;
	cout << "�� �����洢�ṹ\n";
	st2.Create(); 
	cout << "�� ����洢�ṹ\n";
	st2.display();
	int i=2; 
	cout << "�� �����Ϊ" << i << "��ѧ������\n";
	int f=st2.Findi(i);	
	if (i>=0)
		cout << "   ����Ϊ" << f << endl;
	else
		cout << "   ��ѧ��������" << endl; 
}
