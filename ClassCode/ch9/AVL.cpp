#include<iostream>
#include<vector>
using namespace std;
template <typename T1,typename T2>
struct AVLNode                         	//AVL�������ģ�� 
{
    T1 key;                      		//�ؼ���k
	T2 data;                     		//�ؼ��ֶ�Ӧ��ֵd
    AVLNode *lchild,*rchild;      		//����ָ��
	int ht;                       		//��ǰ���������߶�
	AVLNode(T1 k,T2 d)					//���캯�����½�����ΪҶ�ӣ��߶�Ϊ1
    {	key=k; 
        data=d;
        lchild=rchild=NULL;
        ht=1;                       	//��ǰ���������߶�
	}
};
template <typename T1,typename T2>
class AVLTree                          			//AVL����ģ�� 
{
	AVLNode<T1,T2>* r;									//AVL�ĸ���� 
public:
    AVLTree()                             		//���캯�� 
    {
		r=NULL;  						      //�����
	}
	~AVLTree()									//��������
	{
		DestroyBTree(r);						//����DestroyBTree()����
		r=NULL;
	}
	void DestroyBTree(AVLNode<T1,T2>* b)				//�ͷ����еĽ��ռ�
	{
		if (b!=NULL)
		{
			DestroyBTree(b->lchild);			//�ݹ��ͷ�������
			DestroyBTree(b->rchild);			//�ݹ��ͷ�������
			delete b;							//�ͷŸ����
		}
	}

    int getht(AVLNode<T1,T2> *p)                 //���ؽ��p�������߶�
    {	if (p==NULL) return 0;
        return p->ht;
    }

    AVLNode<T1,T2>* right_rotate(AVLNode<T1,T2>* a) //�Խ��aΪ��������ת
    {	AVLNode<T1,T2>* b=a->lchild;
        a->lchild=b->rchild;
        b->rchild=a;
        a->ht=max(getht(a->rchild),getht(a->lchild))+1;
        b->ht=max(getht(b->rchild),getht(b->lchild))+1;
        return b;
    }

    AVLNode<T1,T2>* left_rotate(AVLNode<T1,T2>* a)            //�Խ��aΪ��������ת
    {	AVLNode<T1,T2>* b=a->rchild;
        a->rchild=b->lchild;
        b->lchild=a;
        a->ht=max(getht(a->rchild),getht(a->lchild))+1;
        b->ht=max(getht(b->rchild),getht(b->lchild))+1;
        return b;
	}

    AVLNode<T1,T2>* LL(AVLNode<T1,T2>* a)                    //LL�͵���
    {
		return right_rotate(a);
	}
    AVLNode<T1,T2>* RR(AVLNode<T1,T2>* a)                     //RR�͵���
    {
		return left_rotate(a);
	}

    AVLNode<T1,T2>* LR(AVLNode<T1,T2>* a)                     //LR�͵���
    {	AVLNode<T1,T2>* b=a->lchild;
        a->lchild=left_rotate(b);    			//���b����
        return right_rotate(a);     			//���a����
	}
    AVLNode<T1,T2>* RL(AVLNode<T1,T2>* a)                     //RL�͵���
    {	AVLNode<T1,T2>* b=a->rchild;
        a->rchild=right_rotate(b);   			//���b����
        return left_rotate(a);     				 //���a����
    }

    void insert(T1 k,T2 d)                 		//����(k,d)
    {
	    r=_insert(r,k,d);
    }
        
    AVLNode<T1,T2>* _insert(AVLNode<T1,T2>* p,T1 k,T2 d)
	{	if (p==NULL)                             //����ʱ���������
        {   AVLNode<T1,T2>* q=new AVLNode<T1,T2>(k,d);
            return q;
    	}
        else if (k==p->key)
        {	p->data=d;                            //����d
            return p;
		}
        else if (k<p->key)                           	//k<p->key�����
        {	p->lchild=_insert(p->lchild,k,d);		 	//��(k,d)���뵽p����������
            if (getht(p->lchild)-getht(p->rchild)>=2)	//�ҵ�ʧ����p
            {	if (k<p->lchild->key)             		//(k,d)�ǲ�����p�����ӵ���������
                    p=LL(p);               				//����LL�͵���
                else                           			//(k,d)�ǲ�����p�����ӵ���������
                    p=LR(p);                			//����LR�͵���
        	}
		}
        else                                   			//k>p->key�����
        {	p->rchild=_insert(p->rchild,k,d);		 	//��(k,d)���뵽p����������
            if (getht(p->rchild)-getht(p->lchild)>=2)    //�ҵ�ʧ����p
            {	if (k>p->rchild->key)              //(k,d)�ǲ�����p���Һ��ӵ���������
                    p=RR(p);                //����RR�͵���
                else                           //(k,d)�ǲ�����p���Һ��ӵ���������
                    p=RL(p);                //����RL�͵���
            }
    	}
        p->ht=max(getht(p->lchild),getht(p->rchild))+1;   //���½��p�ĸ߶�
        return p;
	}

    void remove(T1 k)                         //ɾ��k
    {
		r=_remove(r,k);
    }

    // ɾ��data���
    AVLNode<T1,T2>* _remove(AVLNode<T1,T2>* p,T1 k)
    {	if (p==NULL) return p;
        if (p->key==k)                        	//�ҵ��ؼ���Ϊk�Ľ��p
        {	if (p->lchild==NULL)              	//���pֻ�������������
                return p->rchild;             	//ֱ�����Һ���������p
            else if (p->rchild==NULL)         	//���pֻ�������������
                return p->lchild;             	//ֱ��������������p
            else                           		//���pͬʱ���������������
            {	if (getht(p->lchild)>getht(p->rchild)) //���p���������ϸ�
        		{	AVLNode<T1,T2>* q=p->lchild;
                    while (q->rchild!=NULL)  	//�ڽ��p���������в��������q
                        q=q->rchild;
                    p=_remove(p,q->key); 		//ɾ�����q
                    p->key=q->key;             	//��q���ֵ���p���ֵ
                    p->data=q->data;
                    return p;
                }
                else                      		//���p���������ϸ�
                {	AVLNode<T1,T2>* q=p->rchild;
                    while (q->lchild!=NULL)   	//�ڽ��p���������в�����С���q
                        q=q->lchild;
                    p=_remove(p,q->key);			 //ɾ�����q
                    p->key=q->key;             	//��q���ֵ���p���ֵ
                    p->data=q->data;
                    return p;
                }
            }
    	}
        else if (k<p->key)                       	//k<p->key�����
        {	p->lchild=_remove(p->lchild,k);			//����������ɾ���ؼ���k�Ľ��
            if (getht(p->rchild)-getht(p->lchild)>=2) //�ҵ�ʧ����p
            {	if (getht(p->rchild->lchild)>getht(p->rchild->rchild))
                    //print("��%d��RL����" %(p->key))
                    p=RL(p);                //�����p���Һ��ӵ��������ϸ�,��RL�͵���
                else
                    //print("��%d��RR�͵���" %(p->key))
                    p=RR(p);                //�����p���Һ��ӵ��������ϸ�,��RR�͵���
        	}
    	}
		else if (k>p->key)                           //k>p->key�����
        {	p->rchild=_remove(p->rchild,k);   //����������ɾ���ؼ���k�Ľ��
            if (getht(p->lchild)-getht(p->rchild)>=2) //�ҵ�ʧ����p
            { 	if (getht(p->lchild->rchild)>getht(p->lchild->lchild))
                    //print("��%d��LR�͵���" %(p->key))
                    p=LR(p);                //�����p�����ӵ��������ϸ�,��LR�͵���
                else
                    //print("��%d��LL�͵���" %(p->key))
                    p=LL(p);                //�����p�����ӵ��������ϸ�,��LL�͵���
        	}
    	}
        p->ht=max(getht(p->lchild),getht(p->rchild))+1;   //���½��p�ĸ߶�
        return p;
    }

    AVLNode<T1,T2>* search(T1 k)		     	//��AVL���в��ҹؼ���Ϊk�Ľ��
    {
		return _search(r,k);			//rΪAVL���ĸ����
	}
	
    AVLNode<T1,T2>*_search(AVLNode<T1,T2>* p,T1 k)	                    //��search��������
    {	if (p==NULL) return NULL;					//��������Nonel
        if (p->key==k) return p->data;		        //�ҵ��󷵻�p->data
        if (k<p->key)
            return _search(p->lchild,k);	    //���������еݹ����
        else
            return _search(p->rchild,k);	    //���������еݹ����
	}

	void inorder()                         	 //����������н��
    {
		_inorder(r);
	}
    void _inorder(AVLNode<T1,T2>* p)                    //��inorder��������
    {
        if (p!=NULL)
        {	_inorder(p->lchild);
            cout << p->key << "[" << p->data << "]" << " ";
            _inorder(p->rchild);
    	}
	}

    void DispAVL()						        		//���AVL�����ű�ʾ��(����data)
    {
	    _DispAVL(r);
	}
    void  _DispAVL(AVLNode<T1,T2>* p)           		//��DispAVL��������
    {	if (p!=NULL)
    	{	cout << p->key;								//��������ֵ
            if (p->lchild!=NULL || p->rchild!=NULL)
            {	cout << "(";   			    			//�к��ӽ��ʱ�����"("
                _DispAVL(p->lchild);			    	//�ݹ鴦��������
                if (p->rchild!=NULL)
                    cout << ",";   		    			//���Һ��ӽ��ʱ�����","
                _DispAVL(p->rchild);			    	//�ݹ鴦��������
                cout << ")";   			    			//�к��ӽ��ʱ�����")"
			}
		}
	}
    void DispAVL1()						        		//���AVL�����ű�ʾ��(��data)
    {
	    _DispAVL1(r);
	}
    void  _DispAVL1(AVLNode<T1,T2>* p)           		//��DispAVL��������
    {	if (p!=NULL)
    	{	cout << p->key << "[" << p->data << "]";	//��������ֵ
            if (p->lchild!=NULL || p->rchild!=NULL)
            {	cout << "(";   			    			//�к��ӽ��ʱ�����"("
                _DispAVL1(p->lchild);			    	//�ݹ鴦��������
                if (p->rchild!=NULL)
                    cout << ",";   		    			//���Һ��ӽ��ʱ�����","
                _DispAVL1(p->rchild);			    	//�ݹ鴦��������
                cout << ")";   			    			//�к��ӽ��ʱ�����")"
			}
		}
	}
};

int main()
{
	vector<int> a={16,3,7,11,9,26,18,14,15};
	vector<string> b={"s16","s3","s7","s11","s9","s26","s18","s14","s15"};
    AVLTree<int,string> bt;
	printf("(1)����AVL\n");
    for (int i=0;i<a.size();i++)
    {	cout << "����(" << a[i] << "," << b[i] << ")\t";
        bt.insert(a[i],b[i]);
        printf("AVL:"); bt.DispAVL(); printf("\n");
	}
	vector<int> c={11,9,3};
    printf("(2)ɾ������\n");
    for (int i=0;i<c.size();i++)
    {	printf("ɾ��%d\t",c[i]);
        bt.remove(c[i]);
        printf("        AVL: "); bt.DispAVL(); printf("\n");
    }
    printf("(3)�������\n");
	bt.inorder(); printf("\n");
    return 0;
}
    
