#include "DLinkList.cpp"						//引用双链表类 
int main()
{
	int i,e;
	DLinkList<int> L;						//建立元素类型为int的顺序表对象L
	cout << "创建整数双链表L" << endl;
	L.Insert(0,2);							//插入元素2
	L.Insert(1,3);							//插入元素3
	L.Insert(2,1);							//插入元素1
	L.Insert(3,5);							//插入元素5
	L.Insert(4,4);							//插入元素4
	L.Insert(5,1);							//插入元素1
	L.Add(8);								//添加整数8 
	cout << "双链表L:"; L.DispList();
	cout << "长度:" << L.Getlength() << endl;
	i=3; L.GetElem(i,e);
	cout << "序号为" << i << "的元素:" << e << endl;
	e=1;
	cout << "第一个" << e << "的元素序号=" << L.GetNo(e) << "\n";
	i=2; cout << "删除序号为" << i << "的元素\n";
	L.Delete(i);
	cout << "双链表L:";L.DispList();
	cout << "长度:" << L.Getlength() << endl;
	int b[]={0,1,1,0,1};
	for (int i=0;i<5;i++)
	{	cout << "删除序号为" << b[i] << "的元素\n";
		L.Delete(b[i]);
		cout << "双链表L:";L.DispList();
		cout << "长度:" << L.Getlength() << endl;
	}
	cout << "销毁双链表L" << endl;
	return 0;
}



