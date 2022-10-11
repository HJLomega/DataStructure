#include<iostream>
#include<vector>
using namespace std;
template <typename T1,typename T2>
struct AVLNode                         	//AVL树结点类模板 
{
    T1 key;                      		//关键字k
	T2 data;                     		//关键字对应的值d
    AVLNode *lchild,*rchild;      		//左右指针
	int ht;                       		//当前结点的子树高度
	AVLNode(T1 k,T2 d)					//构造函数，新建结点均为叶子，高度为1
    {	key=k; 
        data=d;
        lchild=rchild=NULL;
        ht=1;                       	//当前结点的子树高度
	}
};
template <typename T1,typename T2>
class AVLTree                          			//AVL树类模板 
{
	AVLNode<T1,T2>* r;									//AVL的根结点 
public:
    AVLTree()                             		//构造函数 
    {
		r=NULL;  						      //根结点
	}
	~AVLTree()									//析构函数
	{
		DestroyBTree(r);						//调用DestroyBTree()函数
		r=NULL;
	}
	void DestroyBTree(AVLNode<T1,T2>* b)				//释放所有的结点空间
	{
		if (b!=NULL)
		{
			DestroyBTree(b->lchild);			//递归释放左子树
			DestroyBTree(b->rchild);			//递归释放右子树
			delete b;							//释放根结点
		}
	}

    int getht(AVLNode<T1,T2> *p)                 //返回结点p的子树高度
    {	if (p==NULL) return 0;
        return p->ht;
    }

    AVLNode<T1,T2>* right_rotate(AVLNode<T1,T2>* a) //以结点a为根做右旋转
    {	AVLNode<T1,T2>* b=a->lchild;
        a->lchild=b->rchild;
        b->rchild=a;
        a->ht=max(getht(a->rchild),getht(a->lchild))+1;
        b->ht=max(getht(b->rchild),getht(b->lchild))+1;
        return b;
    }

    AVLNode<T1,T2>* left_rotate(AVLNode<T1,T2>* a)            //以结点a为根做左旋转
    {	AVLNode<T1,T2>* b=a->rchild;
        a->rchild=b->lchild;
        b->lchild=a;
        a->ht=max(getht(a->rchild),getht(a->lchild))+1;
        b->ht=max(getht(b->rchild),getht(b->lchild))+1;
        return b;
	}

    AVLNode<T1,T2>* LL(AVLNode<T1,T2>* a)                    //LL型调整
    {
		return right_rotate(a);
	}
    AVLNode<T1,T2>* RR(AVLNode<T1,T2>* a)                     //RR型调整
    {
		return left_rotate(a);
	}

    AVLNode<T1,T2>* LR(AVLNode<T1,T2>* a)                     //LR型调整
    {	AVLNode<T1,T2>* b=a->lchild;
        a->lchild=left_rotate(b);    			//结点b左旋
        return right_rotate(a);     			//结点a右旋
	}
    AVLNode<T1,T2>* RL(AVLNode<T1,T2>* a)                     //RL型调整
    {	AVLNode<T1,T2>* b=a->rchild;
        a->rchild=right_rotate(b);   			//结点b右旋
        return left_rotate(a);     				 //结点a左旋
    }

    void insert(T1 k,T2 d)                 		//插入(k,d)
    {
	    r=_insert(r,k,d);
    }
        
    AVLNode<T1,T2>* _insert(AVLNode<T1,T2>* p,T1 k,T2 d)
	{	if (p==NULL)                             //空树时创建根结点
        {   AVLNode<T1,T2>* q=new AVLNode<T1,T2>(k,d);
            return q;
    	}
        else if (k==p->key)
        {	p->data=d;                            //更新d
            return p;
		}
        else if (k<p->key)                           	//k<p->key的情况
        {	p->lchild=_insert(p->lchild,k,d);		 	//将(k,d)插入到p的左子树中
            if (getht(p->lchild)-getht(p->rchild)>=2)	//找到失衡结点p
            {	if (k<p->lchild->key)             		//(k,d)是插入在p的左孩子的左子树中
                    p=LL(p);               				//采用LL型调整
                else                           			//(k,d)是插入在p的左孩子的右子树中
                    p=LR(p);                			//采用LR型调整
        	}
		}
        else                                   			//k>p->key的情况
        {	p->rchild=_insert(p->rchild,k,d);		 	//将(k,d)插入到p的右子树中
            if (getht(p->rchild)-getht(p->lchild)>=2)    //找到失衡结点p
            {	if (k>p->rchild->key)              //(k,d)是插入在p的右孩子的右子树中
                    p=RR(p);                //采用RR型调整
                else                           //(k,d)是插入在p的右孩子的左子树中
                    p=RL(p);                //采用RL型调整
            }
    	}
        p->ht=max(getht(p->lchild),getht(p->rchild))+1;   //更新结点p的高度
        return p;
	}

    void remove(T1 k)                         //删除k
    {
		r=_remove(r,k);
    }

    // 删除data结点
    AVLNode<T1,T2>* _remove(AVLNode<T1,T2>* p,T1 k)
    {	if (p==NULL) return p;
        if (p->key==k)                        	//找到关键字为k的结点p
        {	if (p->lchild==NULL)              	//结点p只有右子树的情况
                return p->rchild;             	//直接用右孩子替代结点p
            else if (p->rchild==NULL)         	//结点p只有左子树的情况
                return p->lchild;             	//直接用左孩子替代结点p
            else                           		//结点p同时有左右子树的情况
            {	if (getht(p->lchild)>getht(p->rchild)) //结点p的左子树较高
        		{	AVLNode<T1,T2>* q=p->lchild;
                    while (q->rchild!=NULL)  	//在结点p的左子树中查找最大结点q
                        q=q->rchild;
                    p=_remove(p,q->key); 		//删除结点q
                    p->key=q->key;             	//用q结点值替代p结点值
                    p->data=q->data;
                    return p;
                }
                else                      		//结点p的右子树较高
                {	AVLNode<T1,T2>* q=p->rchild;
                    while (q->lchild!=NULL)   	//在结点p的右子树中查找最小结点q
                        q=q->lchild;
                    p=_remove(p,q->key);			 //删除结点q
                    p->key=q->key;             	//用q结点值替代p结点值
                    p->data=q->data;
                    return p;
                }
            }
    	}
        else if (k<p->key)                       	//k<p->key的情况
        {	p->lchild=_remove(p->lchild,k);			//在左子树中删除关键字k的结点
            if (getht(p->rchild)-getht(p->lchild)>=2) //找到失衡结点p
            {	if (getht(p->rchild->lchild)>getht(p->rchild->rchild))
                    //print("以%d做RL调整" %(p->key))
                    p=RL(p);                //若结点p的右孩子的左子树较高,做RL型调整
                else
                    //print("以%d做RR型调整" %(p->key))
                    p=RR(p);                //若结点p的右孩子的右子树较高,做RR型调整
        	}
    	}
		else if (k>p->key)                           //k>p->key的情况
        {	p->rchild=_remove(p->rchild,k);   //在右子树中删除关键字k的结点
            if (getht(p->lchild)-getht(p->rchild)>=2) //找到失衡结点p
            { 	if (getht(p->lchild->rchild)>getht(p->lchild->lchild))
                    //print("以%d做LR型调整" %(p->key))
                    p=LR(p);                //若结点p的左孩子的右子树较高,做LR型调整
                else
                    //print("以%d做LL型调整" %(p->key))
                    p=LL(p);                //若结点p的左孩子的左子树较高,做LL型调整
        	}
    	}
        p->ht=max(getht(p->lchild),getht(p->rchild))+1;   //更新结点p的高度
        return p;
    }

    AVLNode<T1,T2>* search(T1 k)		     	//在AVL树中查找关键字为k的结点
    {
		return _search(r,k);			//r为AVL树的根结点
	}
	
    AVLNode<T1,T2>*_search(AVLNode<T1,T2>* p,T1 k)	                    //被search方法调用
    {	if (p==NULL) return NULL;					//空树返回Nonel
        if (p->key==k) return p->data;		        //找到后返回p->data
        if (k<p->key)
            return _search(p->lchild,k);	    //在左子树中递归查找
        else
            return _search(p->rchild,k);	    //在右子树中递归查找
	}

	void inorder()                         	 //中序遍历所有结点
    {
		_inorder(r);
	}
    void _inorder(AVLNode<T1,T2>* p)                    //被inorder方法调用
    {
        if (p!=NULL)
        {	_inorder(p->lchild);
            cout << p->key << "[" << p->data << "]" << " ";
            _inorder(p->rchild);
    	}
	}

    void DispAVL()						        		//输出AVL的括号表示串(不含data)
    {
	    _DispAVL(r);
	}
    void  _DispAVL(AVLNode<T1,T2>* p)           		//被DispAVL方法调用
    {	if (p!=NULL)
    	{	cout << p->key;								//输出根结点值
            if (p->lchild!=NULL || p->rchild!=NULL)
            {	cout << "(";   			    			//有孩子结点时才输出"("
                _DispAVL(p->lchild);			    	//递归处理左子树
                if (p->rchild!=NULL)
                    cout << ",";   		    			//有右孩子结点时才输出","
                _DispAVL(p->rchild);			    	//递归处理右子树
                cout << ")";   			    			//有孩子结点时才输出")"
			}
		}
	}
    void DispAVL1()						        		//输出AVL的括号表示串(含data)
    {
	    _DispAVL1(r);
	}
    void  _DispAVL1(AVLNode<T1,T2>* p)           		//被DispAVL方法调用
    {	if (p!=NULL)
    	{	cout << p->key << "[" << p->data << "]";	//输出根结点值
            if (p->lchild!=NULL || p->rchild!=NULL)
            {	cout << "(";   			    			//有孩子结点时才输出"("
                _DispAVL1(p->lchild);			    	//递归处理左子树
                if (p->rchild!=NULL)
                    cout << ",";   		    			//有右孩子结点时才输出","
                _DispAVL1(p->rchild);			    	//递归处理右子树
                cout << ")";   			    			//有孩子结点时才输出")"
			}
		}
	}
};

int main()
{
	vector<int> a={16,3,7,11,9,26,18,14,15};
	vector<string> b={"s16","s3","s7","s11","s9","s26","s18","s14","s15"};
    AVLTree<int,string> bt;
	printf("(1)创建AVL\n");
    for (int i=0;i<a.size();i++)
    {	cout << "插入(" << a[i] << "," << b[i] << ")\t";
        bt.insert(a[i],b[i]);
        printf("AVL:"); bt.DispAVL(); printf("\n");
	}
	vector<int> c={11,9,3};
    printf("(2)删除操作\n");
    for (int i=0;i<c.size();i++)
    {	printf("删除%d\t",c[i]);
        bt.remove(c[i]);
        printf("        AVL: "); bt.DispAVL(); printf("\n");
    }
    printf("(3)中序遍历\n");
	bt.inorder(); printf("\n");
    return 0;
}
    
