#include "CDLinkList.cpp"				//引用循环双链表泛型类
template <typename T>
bool Symm(CDLinkList<T> &L)            	//求解算法
{	bool flag=true;			    		//flag表示L是否对称，初始时为真
 	DLinkNode<T> *p=L.dhead->next;		//p指向首结点
 	DLinkNode<T> *q=L.dhead->prior;	    //q指向尾结点
 	while (flag)
  	{	if (p->data!=q->data)  			//对应结点值不相同，置flag为假
      		flag=false;
     	else
      	{	if (p==q || p==q->prior)	//满足结束条件退出循环 
		  		break;
        	q=q->prior;	    			//q前移一个结点 
        	p=p->next;	    			//p后移一个结点
        }
    }
	return flag;
}
int main()
{
	int a[]={1,2,1};
	int n=sizeof(a)/sizeof(a[0]);
	CDLinkList<int> A;
	cout << "创建循环双链表A" << endl;
	A.CreateListR(a,n);
	cout << "循环双链表A: "; A.DispList();
	cout << "对称:" <<  Symm(A) << endl;
	return 0;
}
