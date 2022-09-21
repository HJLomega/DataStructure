#pragma once

template <typename T>
struct LinkNode				//单链表结点类型
{
	T data;					//存放数据元素
	LinkNode<T>* next;				//下一个结点的指针
	LinkNode() :next(NULL) {}			//构造函数
	LinkNode(T d) :data(d), next(NULL) {}	//重载构造函数
};