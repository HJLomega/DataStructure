#include<iostream>
#include<queue>
using namespace std;

struct Box
{
	int i,j;
};
Box *q;
void fun()
{
	queue<Box *> qu;
	Box *p=new Box();
	p->i=1; p->j=2;
	qu.push(p);
	q=qu.front();
	qu.pop();
	cout << "fun q: " << q->i << "," << q->j << endl;
}

int main()
{
	fun();
	cout << getVirtualMemory() << endl;
	cout << "main p: " << q->i << "," << q->j << endl;
	return 0;
}
