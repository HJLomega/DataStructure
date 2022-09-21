#pragma once
#include <iostream>
template <typename T>
struct DLinkNode				//˫����������
{
	T data;					//�������Ԫ��
	DLinkNode<T>* next;			//ָ���̽���ָ��
	DLinkNode<T>* prior;			//ָ��ǰ������ָ��
	DLinkNode() :next(NULL), prior(NULL) {}		  //���캯��
	DLinkNode(T d) :data(d), next(NULL), prior(NULL) {}  //���ع��캯��
};

template <typename T>
class DLinkList			//˫������ģ��
{
public:
	DLinkNode<T>* dhead;		//˫����ͷ���
	//���������㷨
	void CreateListR(T a[], int n)		//β�巨����˫����
	{
		DLinkNode<T>* s, * r;
		r = dhead;				//rʼ��ָ��β���,��ʼʱָ��ͷ���
		for (int i = 0; i < n; i++)		//ѭ���������ݽ��
		{
			s = new DLinkNode<T>(a[i]);	//�������ݽ��s
			r->next = s;			//��s������r���֮��
			s->prior = r;
			r = s;
		}
		r->next = NULL;			//��β����next����ΪNULL
	}
	DLinkList() 		//���캯��,����һ��������
	{
		dhead = new DLinkNode<T>();
	}
	~DLinkList() 			//��������,��������
	{
		DLinkNode<T> * pre, * p;
		pre = dhead; p = pre->next;
		while (p != NULL)		//��p������㲢�ͷ���ǰ����� 
		{
			delete pre;		//�ͷ�pre��� 
			pre = p; p = p->next;	//pre,pͬ������һ����� 
		}
		delete pre;			//pΪ��ʱpreָ��β���,��ʱ�ͷ�β���
	}
	int Getlength()			//�����������ݽ�����
	{
		DLinkNode<T>* p = dhead;
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
		DLinkNode<T>* p;
		p = dhead->next;			//pָ��ʼ���
		while (p != NULL)			//p��ΪNULL,���p����data��
		{
			std::cout << p->data << " ";
			p = p->next;			//p������һ�����
		}
		std::cout << std::endl;
	}
};
