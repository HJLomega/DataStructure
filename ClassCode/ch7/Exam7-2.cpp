#include<iostream>
#include<vector>
using namespace std;
struct PNode 						//˫�״洢�ṹԪ������
{	char data;						//��Ž��ֵ,����Ϊchar���� 
	int parent;						//���˫������
	PNode(char d,int p)				//���캯�� 
	{
		data=d;
		parent=p;
	}
};

int Level(vector<PNode> t,int i)	//��t������i�Ľ��Ĳ��
{
	if (i<0 || i>=t.size())			//�������󷵻�0 
		return 0;
	int cnt=1;
 	while (t[i].parent!=-1)			//û�е�������ʱѭ��
  	{	cnt++;
    	i=t[i].parent;             //�ƶ���˫�׽��
 	}
	return cnt;
}
int main()
{
	vector<PNode> t;
	t.push_back(PNode('A',-1));
	t.push_back(PNode('B',0));
	t.push_back(PNode('C',0));
	t.push_back(PNode('D',1));
	t.push_back(PNode('E',1));
	t.push_back(PNode('F',1));
	t.push_back(PNode('G',4));
	for (int i=0;i<t.size();i++)
		cout << "���" << t[i].data << "�Ĳ��: " << Level(t,i) << endl;
	return 0;
}
	

