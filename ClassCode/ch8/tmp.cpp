#include<iostream>
#include<queue> 
using namespace std;
struct Node
{
	int data;
	Node *next;
	Node() {}
	Node(int d,Node *n)
	{
		data=d;
		next=n;
	}
};
Node *fun()
{ 
	queue<Node> qu;
	Node p=Node(1,NULL);
	Node q=Node(2,&p);
	qu.push(p);
	qu.push(q);
	while (!qu.empty())
	{
		Node r=qu.front(); qu.pop();
		printf("³ö¶Ó%d\n",r.data);
	}
	return &p;
}

int main()
{
	Node *p=fun();
	printf("%d\n",p->data);
	return 0;
}
