#pragma once
#include <iostream>
#include "LinkNode.h"

template <typename T>
class LinkList			//��������ģ��
{
public:
	LinkNode<T>* head;		//������ͷ���
	//���������㷨
	void CreateListR(T a[], int n)		//β�巨����������
	{
		LinkNode<T>* s, * r;
		r = head;				//rָ��β���,��ʼʱָ��ͷ���
		for (int i = 0; i < n; i++)		//ѭ���������ݽ��
		{
			s = new LinkNode<T>(a[i]);	//�������ݽ��s
			r->next = s;			//�����s������r֮��
			r = s;
		}
		r->next = NULL;			//��β����next����ΪNULL
	}
	LinkList() 		//���캯��,����һ���յ�����
	{
		head = new LinkNode<T>();
	}
	~LinkList() 			//��������,���ٵ�����
	{
		LinkNode<T>* pre, * p;
		pre = head; p = pre->next;
		while (p != NULL)		//��p������㲢�ͷ���ǰ����� 
		{
			delete pre;		//�ͷ�pre��� 
			pre = p; p = p->next;	//pre,pͬ������һ����� 
		}
		delete pre;			//pΪ��ʱpreָ��β���,��ʱ�ͷ�β���
	}
	int Getlength()			//�����������ݽ�����
	{
		LinkNode<T>* p = head;
		int cnt = 0;
		while (p->next != NULL)		//�ҵ�β���Ϊֹ
		{
			cnt++;
			p = p->next;
		}
		return cnt;
	}
	void DispList()			//������������н��ֵ
	{
		LinkNode<T>* p;
		p = head->next;			//pָ��ʼ���
		while (p != NULL)			//p��ΪNULL,���p����data��
		{
			std::cout << p->data << " ";
			p = p->next;			//p������һ�����
		}
		std::cout << std::endl;
	}
	void Add(T e)			//�ڵ�����ĩβ���һ��ֵΪe�Ľ�� 
	{
		LinkNode<T>* s = new LinkNode<T>(e);	//�½����s
		LinkNode<T>* p = head;
		while (p->next != NULL)			//����β���p
			p = p->next;
		p->next = s;					//��β���֮�������s
	}
	
};

