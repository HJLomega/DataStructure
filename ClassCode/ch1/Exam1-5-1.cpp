#include <iostream>
using namespace std;
int MaxSize=100;								//������Ԫ�ظ���
struct Stud1									//ѧ���ɼ�Ԫ����
{
	int no;       								//���ѧ��
	string name;  								//�������
	int score; 									//��ŷ���
	Stud1() {}									//���캯��
	Stud1(int no1,string name1,int score1)		//���ع��캯�� 
	{
		no=no1;
		name=name1;
		score=score1;
	}	
};
class StudClass1								//�� 
{
public:
	Stud1 *data;
	int length;
	StudClass1()
	{
		data=new Stud1[MaxSize]; 
		length=0;
	}
	void Create()								//���������ɼ�˳���
	{
		data[0]=Stud1(2018001,"����",90);
		data[1]=Stud1(2018010,"����",62);
		data[2]=Stud1(2018006,"����",54);
		data[3]=Stud1(2018009,"��ǿ",95);
		data[4]=Stud1(2018007,"���",76);
		data[5]=Stud1(2018012,"��Ƽ",88);
		data[6]=Stud1(2018005,"��Ӣ",82);
		length=7;
	}
	void display()				//�������Ԫ��
	{
		cout <<"  ѧ��\t����\t����\n";
		cout << "  ========================\n";
		for (int i=0;i<length;i++)
			cout << "   " << data[i].no << "\t" << data[i].name << "\t" << data[i].score << endl;
	}
	int Findi(int i)                   			//�������Ϊi��ѧ������
	{
		if (i<0 || i>=length)
			return -1;
		return data[i].score;              		//i��ȷʱ���ط���
	}
};
int main()
{
	StudClass1 st1;
	cout << "�� �����洢�ṹ\n";
	st1.Create(); 
	cout << "�� ����洢�ṹ\n";
	st1.display();
	int i=2; 
	cout << "�� �����Ϊ" << i << "��ѧ������\n";
	int f=st1.Findi(i);	
	if (i>=0)
		cout << "   ����Ϊ" << f << endl;
	else
		cout << "   ��ѧ��������" << endl; 
}
