#pragma once
#include <iostream>
template <typename T>
struct DLinkNode				//双链表结点类型
{
	T data;					//存放数据元素
	DLinkNode<T>* next;			//指向后继结点的指针
	DLinkNode<T>* prior;			//指向前驱结点的指针
	DLinkNode() :next(NULL), prior(NULL) {}		  //构造函数
	DLinkNode(T d) :data(d), next(NULL), prior(NULL) {}  //重载构造函数
};

template <typename T>
class DLinkList			//双链表类模板
{
public:
	DLinkNode<T>* dhead;		//双链表头结点
	//基本运算算法
	void CreateListR(T a[], int n)		//尾插法建立双链表
	{
		DLinkNode<T>* s, * r;
		r = dhead;				//r始终指向尾结点,开始时指向头结点
		for (int i = 0; i < n; i++)		//循环建立数据结点
		{
			s = new DLinkNode<T>(a[i]);	//创建数据结点s
			r->next = s;			//将s结点插入r结点之后
			s->prior = r;
			r = s;
		}
		r->next = NULL;			//将尾结点的next域置为NULL
	}
	DLinkList() 		//构造函数,创建一个空链表
	{
		dhead = new DLinkNode<T>();
	}
	~DLinkList() 			//析构函数,销毁链表
	{
		DLinkNode<T> * pre, * p;
		pre = dhead; p = pre->next;
		while (p != NULL)		//用p遍历结点并释放其前驱结点 
		{
			delete pre;		//释放pre结点 
			pre = p; p = p->next;	//pre,p同步后移一个结点 
		}
		delete pre;			//p为空时pre指向尾结点,此时释放尾结点
	}
	int Getlength()			//求单链表中数据结点个数
	{
		DLinkNode<T>* p = dhead;
		int cnt = 0;
		while (p->next != NULL)		//找到尾结点为止
		{
			cnt++;
			p = p->next;
		}
		return cnt;
	}
	void DispList()			//输出单链表所有结点值
	{
		DLinkNode<T>* p;
		p = dhead->next;			//p指向开始结点
		while (p != NULL)			//p不为NULL,输出p结点的data域
		{
			std::cout << p->data << " ";
			p = p->next;			//p移向下一个结点
		}
		std::cout << std::endl;
	}
};
