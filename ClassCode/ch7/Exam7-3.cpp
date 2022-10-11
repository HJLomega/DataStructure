#include<iostream>
#include<vector>
using namespace std;
struct SonNode         	        		//�������洢�ṹ�����
{	char data;                 			//��Ž��ֵ,����Ϊchar����
	vector<SonNode *> sons;				//ָ���ӽ���ָ������ 
	SonNode() {}						//���캯�� 
	SonNode(char d):data(d) {}			//���ع��캯�� 
};
int Height(SonNode *t)                	//��t�ĸ߶�
{	if (t==NULL)              			//�����߶�Ϊ0
  		return 0;
 	int maxsh=0;
	for (int i=0;i<t->sons.size();i++)  //������������
  	{	int sh=Height(t->sons[i]);     	//������t.sons[i]�ĸ߶�
    	maxsh=max(maxsh,sh);         	//���������������߶�
    }
 	return maxsh+1;
}
int main()
{
	SonNode *t,*b,*c,*d,*e,*f,*g;
	t=new SonNode('A');					//����� 
	b=new SonNode('B');
	c=new SonNode('C');
	d=new SonNode('D');
	e=new SonNode('E');
	f=new SonNode('F');
	g=new SonNode('G');
	t->sons.push_back(b);
	t->sons.push_back(c);
	b->sons.push_back(d);
	b->sons.push_back(e);
	b->sons.push_back(f);
	e->sons.push_back(g);
	cout << "���߶�: " << Height(t) << endl;
	return 0;
}
	

