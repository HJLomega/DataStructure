#pragma once

template <typename T>
struct LinkNode				//������������
{
	T data;					//�������Ԫ��
	LinkNode<T>* next;				//��һ������ָ��
	LinkNode() :next(NULL) {}			//���캯��
	LinkNode(T d) :data(d), next(NULL) {}	//���ع��캯��
};