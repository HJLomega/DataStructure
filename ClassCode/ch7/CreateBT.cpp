#include"BTree.cpp"										//�����������Ļ��������㷨
#include<vector>
#include<algorithm>
BTNode *CreateBTree11(vector<char> pres,int i,vector<char> ins,int j,int n)	//��CreateBTree1����
{
	if (n<=0) return NULL;
 	char d=pres[i];										//ȡ�����ֵd
 	BTNode *b=new BTNode(d);							//���������(���ֵΪd)
 	int p=j;
 	while (ins[p]!=d) p++;								//��ins���ҵ�����������p
	int k=p-j;											//ȷ���������н�����k
 	b->lchild=CreateBTree11(pres,i+1,ins,j,k);		  	//�ݹ鹹��������
 	b->rchild=CreateBTree11(pres,i+k+1,ins,p+1,n-k-1);	//�ݹ鹹��������
 	return b;
}

void CreateBTree1(BTree &bt,vector<char> pres,vector<char> ins) //����������pres����������ins���������
{
	int n=pres.size();
	bt.r=CreateBTree11(pres,0,ins,0,n);
}


BTNode *CreateBTree21(vector<char> posts,int i,vector<char> ins,int j,int n)	//��CreateBTree2����
{ 	if (n<=0) return NULL;
 	char d=posts[i+n-1];						     	//ȡ��������βԪ�ؼ������ֵd
	BTNode *b=new BTNode(d);			         		//���������(���ֵΪd)
 	int p=j;
 	while (ins[p]!=d) p++;								//��ins���ҵ�����������p
	int k=p-j;											//ȷ���������н�����k
	b->lchild=CreateBTree21(posts,i,ins,j,k);			//�ݹ鹹��������
 	b->rchild=CreateBTree21(posts,i+k,ins,p+1,n-k-1);	//�ݹ鹹��������
 	return b;
}

void CreateBTree2(BTree &bt,vector<char> posts,vector<char> ins) //�ɺ�������posts����������ins���������
{
	int n=posts.size();
	bt.r=CreateBTree21(posts,0,ins,0,n);
}


//���л�
string PreOrderSeq1(BTNode *b)
{
	if (b==NULL) return "#";
 	string s(1,b->data);							//�������
 	s+=PreOrderSeq1(b->lchild);						//���������������л�����
 	s+=PreOrderSeq1(b->rchild);						//���������������л�����
 	return s;
}
string PreOrderSeq(BTree &bt)                		//������bt�����л�
{
	return PreOrderSeq1(bt.r);
}

//�����л�
BTNode *CreateBTree31(string s,int &i)				//���ò���i�൱��ȫ�ֱ��� 
{
	if (i>=s.length()) return NULL;					//i���緵��NULL 
	char d=s[i]; i++; 								//ȡs[i]��ֵd 
	if (d=='#') return NULL;						//��Ϊ"#"������NULL
    BTNode *b=new BTNode(d);    					//���������(���ֵΪd
	b->lchild=CreateBTree31(s,i);					//�ݹ鹹��������
    b->rchild=CreateBTree31(s,i);					//�ݹ鹹��������
    return b;
}
void CreateBTree3(BTree &bt,string s)				//�����л�����s�����������������л�
{
	int i=0;
 	bt.r=CreateBTree31(s,i);
}


/*
int main()
{
	string a="ABDGCEF";
	vector<char> pres(a.begin(),a.end());
	string b="DGBAECF";
	vector<char> ins(b.begin(),b.end());
	string c="GDBEFCA"; 
	vector<char> posts(c.begin(),c.end());
	BTree bt1;
	cout << "��" << a << "�������к�" << b << "�������д���bt1" << endl; 
	CreateBTree1(bt1,pres,ins);
	cout << "������bt1:"; bt1.DispBTree(); cout << endl;
	cout << "���ٶ�����bt1\n";

	BTree bt2;
	cout << "��" << b << "�������к�" << c << "�������д���bt2" << endl; 
	CreateBTree2(bt2,posts,ins);
	cout << "������bt2:"; bt2.DispBTree(); cout << endl;
	cout << "���ٶ�����bt2\n";
	return 0;
}
*/
int main()
{
	string str="A(B(D(,G)),C(E,F))";
	BTree bt;
	bt.CreateBTree(str);
	cout << "������bt:"; bt.DispBTree(); cout << endl;
	string s= PreOrderSeq(bt);
	cout << "���л�����s: " << s << endl; 
	cout << "�����л�" << endl;
	BTree bt1;
	CreateBTree3(bt1,s);
	cout << "������bt1:"; bt1.DispBTree(); cout << endl;
	return 0;
}
