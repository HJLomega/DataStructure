#include"LinkList.cpp"				//���ô�ͷ���ĵ�������LinkList 

void Positive(LinkNode<int> *p)		//����������н��ֵ
{	if (p==NULL)
  		return;
  	else
  	{	printf("%d ",p->data);
    	Positive(p->next);
	}
}
void Invert(LinkNode<int> *p) 		//����������н��ֵ
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
	cout << "������L:  "; L.DispList();
	cout << "�������: "; Positive(L.head->next); cout << endl;
	cout << "�������: "; Invert(L.head->next); cout << endl;
	return 0;	
}

