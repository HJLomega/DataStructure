#pragma once
#include <iostream>
#include "LinkNode.h"

template <typename T>
class CLinkList             //ѭ����������
{
public:
    LinkNode<T>* head;	      //ѭ��������ͷ���
    CLinkList()		      //���캯��,������ѭ��������
    {
        head = new LinkNode<T>();
        head->next = head;	      //����ѭ���Ŀ�����
    }
    ~CLinkList()		      //��������,����ѭ��������
    {
        LinkNode<T>* pre, * p;
        pre = head; p = pre->next;
        while (p != head)	      //��p�������ͷ���ǰ�����
        {
            delete pre;	      //�ͷ�pre��� 
            pre = p; p = p->next;    //pre,pͬ������һ�����
        }
        delete pre;	      //�ͷ�β���
    }
    //���Ա�Ļ��������㷨
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
        r->next = head;			//��β����next����ΪNULL
    }
    int Getlength()			//�����������ݽ�����
    {
        LinkNode<T>* p = head;
        int cnt = 0;
        while (p->next != head)		//�ҵ�β���Ϊֹ
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
        while (p != head)			//p��ΪNULL,���p����data��
        {
            std::cout << p->data << " ";
            p = p->next;			//p������һ�����
        }
        std::cout << std::endl;
    }
};
