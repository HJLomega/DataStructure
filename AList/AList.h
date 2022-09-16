#pragma once
template<typename T>
class AList{

private:
	T *data;
	int capacity;
	int length;
	void recap(int newcap);
	static const int DEFAULT_CAPACITY = 8;
public:
	/* create empty Array List*/
	AList();
	~AList();
	/* add a element at the end of the AList */
	void Add(T e);
	int GetLength();\
	/* get i-th element, bound it to e */
	bool GetElem(int i, T &e);
	/* set i-th element to e */
	bool SetElem(int i, T e);
	/* get the index of the first item whose value is equal to e, if not return -1*/
	int GetNo(T e);
	/* insert e at index of i */
	bool Insert(int i, T e);
	bool Delete(int i);
	void DispList();



};

