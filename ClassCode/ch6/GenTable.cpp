#include "GenTable.h"				//����������������
#include <string.h>
template <typename T>
GenTableClass<T>::GenTableClass()		//���캯��
{
	ghead=new GLNode<T>();
	ghead->val.sublist=NULL;
	ghead->link=NULL;
}
template <typename T>
GenTableClass<T>::~GenTableClass()		//��������
{
	DestroyGL(ghead);
}
template <typename T>
void GenTableClass<T>::DestroyGL(GLNode<T> *g)	//�ͷŹ�������н��ռ�
{
	GLNode<T> *g1,*g2;
	g1=g->val.sublist;		//g1ָ������ĵ�һ��Ԫ��
	while (g1!=NULL)		//��������Ԫ��
	{
		if (g1->tag==0)		//��Ϊԭ�ӽ��
		{
			g2=g1->link;	//g2��ʱ�����ֵܽ��
			delete g1;		//�ͷ�g1��ָԭ�ӽ��
			g1=g2;			//g1ָ�����ֵܽ��
		}
		else				//��Ϊ�ӱ�
		{
			g2=g1->link;	//g2��ʱ�����ֵܽ��
			DestroyGL(g1);	//�ݹ��ͷ�g1��ָ�ӱ�Ŀռ�
			g1=g2;			//g1ָ�����ֵܽ��
		}
	}
	delete g;				//�ͷ�ͷ���ռ�
}
template <typename T>
int GenTableClass<T>::GLLength()//������ĳ���
{
	int n=0;
	GLNode<T> *g1;
	g1=ghead->val.sublist;		//g1ָ������ĵ�һ��Ԫ��
	while (g1!=NULL)
	{
		n++;					//�ۼ�Ԫ�ظ���
		g1=g1->link;
	}
	return n;
}
template <typename T>
int GenTableClass<T>::GLDepth()	//����������
{
	return GLDepth1(ghead);
}
template <typename T>
int GenTableClass<T>::GLDepth1(GLNode<T> *g) //��GLDepth��������
{
	GLNode<T> *g1;
	int max=0,dep;
	if (g->tag==0) return 0;	//Ϊԭ��ʱ����0
	g1=g->val.sublist;			//g1ָ���һ��Ԫ��
	if (g1==NULL) return 1;		//Ϊ�ձ�ʱ����1
	while (g1!=NULL)			//�������е�ÿһ��Ԫ��
	{
		if (g1->tag==1)			//Ԫ��Ϊ�ӱ�����
		{
			dep=GLDepth1(g1);	//�ݹ��������ӱ�����
			if (dep>max) max=dep;//maxΪͬһ����������ӱ�����ȵ����ֵ
		}
		g1=g1->link;			//ʹg1ָ����һ��Ԫ��
	}
	return(max+1);				//���ر�����
}
template <typename T>
void GenTableClass<T>::DispGL()	//��������
{
	DispGL1(ghead);
}
template <typename T>
void GenTableClass<T>::DispGL1(GLNode<T> *g)//��DispGL����
{
	if (g!=NULL)						//��Ϊ���ж�
	{
		if (g->tag==0)					//g��Ԫ��Ϊԭ��ʱ
			cout << g->val.data;		//���ԭ��ֵ
		else							//g��Ԫ��Ϊ�ӱ�ʱ
		{
			cout << "(";				//���'('
			if (g->val.sublist==NULL)	//Ϊ�ձ�ʱ
				cout << "#";
			else						//Ϊ�ǿ��ӱ�ʱ
				DispGL1(g->val.sublist);//�ݹ�����ӱ�
			cout << ")";				//���')'
		}
		if (g->link!=NULL)				//���ֵ�ʱ
		{
			cout << ",";
			DispGL1(g->link);			//�ݹ����g���ֵ�
		}
	}
}
template <typename T>
void GenTableClass<T>::CreateGL(char *&str)	//���������ű�ʾ��str��ʾ�Ĺ������ʽ�洢�ṹ
{
	ghead=CreateGL1(str);
}
template <typename T>
GLNode<T> *GenTableClass<T>::CreateGL1(char *&s)//��CreateGL()����
{
	GLNode<T> *g;
	char ch=*s++;						//ȡһ���ַ�ch
	if (ch!='\0')						//��sδ������,�ȴ���(��ԭ�Ӻ�#�ַ�
	{
		g=new GLNode<T>();				//����һ���½��
		if (ch=='(')					//chΪ������ʱ
		{
			g->tag=1;					//�½����Ϊ��ͷ���
			g->val.sublist=CreateGL1(s);//�ݹ鹹���ӱ�������ͷ���
		}
		else if (ch=='#') g=NULL;		//����'#'�ַ�,��ʾ�ձ�
		else							//Ϊԭ���ַ�
		{
			g->tag=0;					//�½����Ϊԭ�ӽ��
			g->val.data=ch;
		}
	}
	else g=NULL;						//��s�������,g��Ϊ��
	ch=*s++;							//ȡ��һ���ַ�ch
	if (g!=NULL)						//ǰ�����ٹ�����һ����㣬�ٴ���')'��','�ַ�
		if (ch==',')					//��ǰ�ַ�Ϊ','
			g->link=CreateGL1(s);		//�ݹ鹹���ֵܽ��
		else							//Ϊ')'��s�������,��*g�����ֵ�ָ����ΪNULL
			g->link=NULL;
		return g;						//���ع����g
}
/*main��������
void main()
{
	char *str="(((#),(a)),b,(((#))))";
	char s[100];
	strcpy(s,str);
	GenTableClass<char> gl;
	gl.CreateGL(str);
	cout << "�����gl:"; gl.DispGL(); cout << endl;
	cout << "str=     " << s << endl;
	cout << "gl�ĳ���:" << gl.GLLength() << endl;
	cout << "gl�����:" << gl.GLDepth() << endl;
	cout << "mainִ�����,���ٽ����Ĺ����" << endl;
}

main��������
void main()
{
	char *str="((#),((#),c,((#))))";
	GenTableClass<char> gl;
	gl.CreateGL(str);
	cout << "�����gl:"; gl.DispGL(); cout << endl;
	cout << "gl�ĳ���:" << gl.GLLength() << endl;
	cout << "gl�����:" << gl.GLDepth() << endl;
	cout << "mainִ�����,���ٽ����Ĺ����" << endl;
}
*/