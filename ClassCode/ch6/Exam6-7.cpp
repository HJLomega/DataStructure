#include"LinkList.cpp"				//���ô�ͷ���ĵ�������LinkList 

LinkNode<int> *Reverse(LinkNode<int> *p) //���õ�����p 
{
	if (p==NULL)					//�ձ����� 
  		return NULL;
	if (p->next==NULL)				//ֻ��һ��������� 
		return p; 
 	else							//��2�������Ͻ������ 
  	{	LinkNode<int> *np;
	  	np=Reverse(p->next);		//��������� 
		p->next->next=p;			//�����p��Ϊβ��� 
		p->next=NULL;
		return np;					//�������õ�������׽�� 
    }
}

int main()
{
	LinkList<int> L;
	int a[]={1,2,3,4,5};
	int n=sizeof(a)/sizeof(a[0]);
	L.CreateListR(a,n);
	cout << "������L:  "; L.DispList();
	cout << "����L: " << endl;
	L.head->next=Reverse(L.head->next);
	cout << "������L:  "; L.DispList();
	return 0;	
}

