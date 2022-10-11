#include"LinkList.cpp"				//引用带头结点的单链表类LinkList 

void Positive(LinkNode<int> *p)		//正向输出所有结点值
{	if (p==NULL)
  		return;
  	else
  	{	printf("%d ",p->data);
    	Positive(p->next);
	}
}
void Invert(LinkNode<int> *p) 		//反向输出所有结点值
{	if (p==NULL)
  		return;
 	else
  	{	Invert(p->next);
    	printf("%d ",p->data);
    }
}

int main()
{
	LinkList<int> L;
	int a[]={1,2,3,4,5};
	int n=sizeof(a)/sizeof(a[0]);
	L.CreateListR(a,n);
	cout << "单链表L:  "; L.DispList();
	cout << "正向输出: "; Positive(L.head->next); cout << endl;
	cout << "反向输出: "; Invert(L.head->next); cout << endl;
	return 0;	
}

