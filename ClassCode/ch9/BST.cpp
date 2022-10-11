#include<iostream>
#include<vector>
using namespace std;

template <typename T1,typename T2>
struct BSTNode											//BST�����ģ�� 
{	T1 key;							        			//��Źؼ���,����ؼ���ΪT1����
    T2 data;                                 			//���������,����������ΪT2����
    BSTNode *lchild;						   			//�������ָ��
    BSTNode *rchild;						   			//����Һ���ָ��
    BSTNode(T1 k,T2 d)    								//���췽��
    {	key=k;
        data=d;
        lchild=rchild=NULL;
	}
};
template <typename T1,typename T2>
class BSTClass								  			//BST��
{
public:
	BSTNode<T1,T2> *r;  								//BST�����
	BSTNode<T1,T2> *f;    								//���ڴ�Ŵ�ɾ������˫�׽��
    BSTClass()                             				//���췽��
    {	r=NULL;  						        		//BST�����
        f=NULL;    						        		//���ڴ�Ŵ�ɾ������˫�׽��
	}
	~BSTClass()											//��������
	{
		DestroyBTree(r);								//����DestroyBTree()����
		r=NULL;
	}
	void DestroyBTree(BSTNode<T1,T2> *b)				//�ͷ����еĽ��ռ�
	{
		if (b!=NULL)
		{
			DestroyBTree(b->lchild);					//�ݹ��ͷ�������
			DestroyBTree(b->rchild);					//�ݹ��ͷ�������
			delete b;									//�ͷŸ����
		}
	}
    //BST�Ļ��������㷨
    void InsertBST(T1 k,T2 d)			    			//����һ��(k,d)���
    {
	    r=_InsertBST(r,k,d);
	}

    BSTNode<T1,T2> *_InsertBST(BSTNode<T1,T2> *p,T1 k,T2 d)   //����pΪ����BST�в���ؼ���Ϊk�Ľ��
    {	if (p==NULL)							   		//ԭ��Ϊ��,�²����Ԫ��Ϊ�����
            p=new BSTNode<T1,T2>(k,d);
        else if (k<p->key) 
            p->lchild=_InsertBST(p->lchild,k,d);    	//���뵽p����������
        else if (k>p->key)
            p->rchild=_InsertBST(p->rchild,k,d);    	//���뵽p����������
        else                                       		//�ҵ��ؼ���Ϊk�Ľ��,�޸�data����
            p->data=d;
        return p;
	}

    void CreateBST(vector<T1> &a,vector<T2> &b)			//��a��b��������һ��BST
    {	r=new BSTNode<T1,T2>(a[0],b[0]);				//���������
        for (int i=1;i<a.size();i++)					//�����������
            _InsertBST(r,a[i],b[i]);					//����(a[i],b[i])
	}
	BSTNode<T1,T2> *SearchBST(T1 k)		        		//��BST�в��ҹؼ���Ϊk�Ľ��
    {
	    return _SearchBST(r,k);							//rΪBST�ĸ����
	}
	BSTNode<T1,T2> *_SearchBST(BSTNode<T1,T2> *p,T1 k) 	//��SearchBST��������
    {	if (p==NULL) return NULL;						//��������null
        if (p->key==k) return p;						//�ҵ��󷵻�p
        if (k<p->key)
            return _SearchBST(p->lchild,k);	    		//���������еݹ����
        else
            return _SearchBST(p->rchild,k);	    		//���������еݹ����
	}

    bool DeleteBST(T1 k)					        	//ɾ���ؼ���Ϊk�Ľ��
    {	f=NULL;
        return _DeleteBST(r,k,-1);		    			//rΪBST�ĸ����
	}

    bool _DeleteBST(BSTNode<T1,T2> *p,T1 k,int flag)  	//��DeleteBST��������
    {	if (p==NULL)
            return false;						    	//��������False
        if (p->key==k)
            return DeleteNode(p,f,flag);				//�ҵ���ɾ��p���
        if (k<p->key)
		{	f=p;
            return _DeleteBST(p->lchild,k,0);			//���������еݹ����
        }
        else
		{	f=p;
            return _DeleteBST(p->rchild,k,1);			//���������еݹ����
        }
	}
    bool DeleteNode(BSTNode<T1,T2> *p,BSTNode<T1,T2> *f,int flag) //ɾ�����p����˫��Ϊf��
	{	if (p->rchild==NULL)						    //���pֻ������(��pΪҶ�ӵ����)
        {	if (flag==-1)						    	//���p��˫��Ϊ��(pΪ�����)
				r=p->lchild;							//�޸ĸ����rΪp������
			else if (flag==0)							//pΪ˫��f������
                f->lchild=p->lchild;					//��f��������Ϊp������
            else										//pΪ˫��f���Һ���
                f->rchild=p->lchild;					//��f���Һ�����Ϊp������
    	}
        else if (p->lchild==NULL)				    	//���pֻ���Һ���
        {    if (flag==-1)						    	//���p��˫��Ϊ��(pΪ�����)
                r=p->rchild;					    	//�޸ĸ����rΪp���Һ���
            else if (flag==0)					        //pΪ˫��f������
                f->lchild=p->rchild;			    	//��f��������Ϊp������
            else										//pΪ˫��f���Һ���
                f->rchild=p->rchild;					//��f���Һ�����Ϊp������
    	}
        else                            				//���p�����Һ���
		{	BSTNode<T1,T2> *f1=p; 						//f1Ϊ���q��˫�׽��
            BSTNode<T1,T2> *q=p->lchild;             	//qת����p������
            if (q->rchild==NULL)						//�����qû���Һ���
            {	p->key=q->key;							//����ɾ���p��ֵ��q��ֵ���
                p->data=q->data;
                p->lchild=q->lchild;					//ɾ�����q
            }
            else										//�����q���Һ���
            {	while (q->rchild!=NULL)   				//�ҵ������½��q,��˫�׽��Ϊf1
				{	f1=q;
                    q=q->rchild;
                }
                p->key=q->key;							//����ɾ���p��ֵ��q��ֵ���
                p->data=q->data;
                f1->rchild=q->lchild;					//ɾ�����q
            }
        }
        return true;
    }

    void DispBST()						        		//���BST�����ű�ʾ��(����data)
    {
	    _DispBST(r);
	}
    void  _DispBST(BSTNode<T1,T2> *p)           		//��DispBST��������
    {	if (p!=NULL)
    	{	cout << p->key;								//��������ֵ
            if (p->lchild!=NULL || p->rchild!=NULL)
            {	cout << "(";   			    			//�к��ӽ��ʱ�����"("
                _DispBST(p->lchild);			    	//�ݹ鴦��������
                if (p->rchild!=NULL)
                    cout << ",";   		    			//���Һ��ӽ��ʱ�����","
                _DispBST(p->rchild);			    	//�ݹ鴦��������
                cout << ")";   			    			//�к��ӽ��ʱ�����")"
			}
		}
	}
    void DispBST1()						        		//���BST�����ű�ʾ��(��data)
    {
	    _DispBST1(r);
	}
    void  _DispBST1(BSTNode<T1,T2> *p)           		//��DispBST��������
    {	if (p!=NULL)
    	{	cout << p->key << "[" << p->data << "]";	//��������ֵ
            if (p->lchild!=NULL || p->rchild!=NULL)
            {	cout << "(";   			    			//�к��ӽ��ʱ�����"("
                _DispBST1(p->lchild);			    	//�ݹ鴦��������
                if (p->rchild!=NULL)
                    cout << ",";   		    			//���Һ��ӽ��ʱ�����","
                _DispBST1(p->rchild);			    	//�ݹ鴦��������
                cout << ")";   			    			//�к��ӽ��ʱ�����")"
			}
		}
	}
};

int main()
{
	vector<int> a={25,18,46,2,53,39,32,4,74,67,60,11};
	vector<int> b={1,1,1,1,1,1,1,1,1,1,1,1};
	cout << "\n  (1)�ؼ�������(������ֵ)\n    ";
	for (int i=0;i<a.size();i++)
		cout << a[i] << " ";
	cout << endl; 
	BSTClass<int,int> bst;
	cout << "  (2)����BSTbst\n"; 
	bst.CreateBST(a,b);
	cout << "  (3)���BST\n";
	cout << "    BST: ";bst.DispBST(); cout << endl;
	cout << "  (4)ɾ������\n";
	vector<int> c={2,4,60,25,32,11};
	for (int i=0;i<c.size();i++)
	{
		bst.DeleteBST(c[i]);
		printf("    ɾ��%2d��: ",c[i]); bst.DispBST(); cout << endl;
	}
	cout << "  (5)�������\n";
	vector<int> d={32,11,1};
	for (int i=0;i<d.size();i++)
	{
		bst.InsertBST(d[i],b[i]);
		printf("    ɾ��%2d��: ",d[i]); bst.DispBST(); cout << endl;
	}
		
	return 0;
}

