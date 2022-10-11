#include"LinkList.cpp"				//引用带头结点的单链表类LinkList 

LinkNode<int> *Reverse(LinkNode<int> *p) //逆置单链表p 
{
	if (p==NULL)					//空表的情况 
  		return NULL;
	if (p->next==NULL)				//只有一个结点的情况 
		return p; 
 	else							//有2个及以上结点的情况 
  	{	LinkNode<int> *np;
	  	np=Reverse(p->next);		//求解子问题 
		p->next->next=p;			//将结点p作为尾结点 
		p->next=NULL;
		return np;					//返回逆置单链表的首结点 
    }
}

int main()
{
	LinkList<int> L;
	int a[]={1,2,3,4,5};
	int n=sizeof(a)/sizeof(a[0]);
	L.CreateListR(a,n);
	cout << "单链表L:  "; L.DispList();
	cout << "逆置L: " << endl;
	L.head->next=Reverse(L.head->next);
	cout << "单链表L:  "; L.DispList();
	return 0;	
}

