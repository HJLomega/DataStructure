#pragma once
#include <iostream>
#include "LinkNode.h"

template <typename T>
class CLinkList             //循环单链表类
{
public:
    LinkNode<T>* head;	      //循环单链表头结点
    CLinkList()		      //构造函数,创建空循环单链表
    {
        head = new LinkNode<T>();
        head->next = head;	      //构成循环的空链表
    }
    ~CLinkList()		      //析构函数,销毁循环单链表
    {
        LinkNode<T>* pre, * p;
        pre = head; p = pre->next;
        while (p != head)	      //用p遍历并释放其前驱结点
        {
            delete pre;	      //释放pre结点 
            pre = p; p = p->next;    //pre,p同步后移一个结点
        }
        delete pre;	      //释放尾结点
    }
    //线性表的基本运算算法
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
        r->next = head;			//将尾结点的next域置为NULL
    }
    int Getlength()			//求单链表中数据结点个数
    {
        LinkNode<T>* p = head;
        int cnt = 0;
        while (p->next != head)		//找到尾结点为止
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
        while (p != head)			//p不为NULL,输出p结点的data域
        {
            std::cout << p->data << " ";
            p = p->next;			//p移向下一个结点
        }
        std::cout << std::endl;
    }
};
