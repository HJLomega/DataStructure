#pragma once
#include <iostream>
#include "LinkNode.h"

template <typename T>
class LinkList			//单链表类模板
{
public:
	LinkNode<T>* head;		//单链表头结点
	//基本运算算法
	void CreateListR(T a[], int n)		//尾插法建立单链表
	{
		LinkNode<T>* s, * r;
		r = head;				//r指向尾结点,开始时指向头结点
		for (int i = 0; i < n; i++)		//循环建立数据结点
		{
			s = new LinkNode<T>(a[i]);	//创建数据结点s
			r->next = s;			//将结点s插入结点r之后
			r = s;
		}
		r->next = NULL;			//将尾结点的next域置为NULL
	}
	LinkList() 		//构造函数,创建一个空单链表
	{
		head = new LinkNode<T>();
	}
	~LinkList() 			//析构函数,销毁单链表
	{
		LinkNode<T>* pre, * p;
		pre = head; p = pre->next;
		while (p != NULL)		//用p遍历结点并释放其前驱结点 
		{
			delete pre;		//释放pre结点 
			pre = p; p = p->next;	//pre,p同步后移一个结点 
		}
		delete pre;			//p为空时pre指向尾结点,此时释放尾结点
	}
	int Getlength()			//求单链表中数据结点个数
	{
		LinkNode<T>* p = head;
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
		LinkNode<T>* p;
		p = head->next;			//p指向开始结点
		while (p != NULL)			//p不为NULL,输出p结点的data域
		{
			std::cout << p->data << " ";
			p = p->next;			//p移向下一个结点
		}
		std::cout << std::endl;
	}
	void Add(T e)			//在单链表末尾添加一个值为e的结点 
	{
		LinkNode<T>* s = new LinkNode<T>(e);	//新建结点s
		LinkNode<T>* p = head;
		while (p->next != NULL)			//查找尾结点p
			p = p->next;
		p->next = s;					//在尾结点之后插入结点s
	}
	
};

