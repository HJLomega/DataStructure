#pragma once
#include <iostream>
template<typename T>
class AList{

private:
	T *data;
	int capacity;
	int length;
	void recap(int newcap) {
		T* newData = new T[newcap];
		for (int i = 0; i < length; i++) {
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
		capacity = newcap;
	}
	static const int DEFAULT_CAPACITY = 8;
public:
	/* create empty Array List*/
	AList(){
		data = new T[DEFAULT_CAPACITY];
	capacity = DEFAULT_CAPACITY;
	length = 0;
}
	~AList() {
		delete[] data;
	}
	/* add a element at the end of the AList */
	void Add(T e) {
		if (length == capacity) {
			recap(capacity * 2);
		}
		data[length] = e;
		length += 1;
	}
	int GetLength() {
		return length;
	}
	/* get i-th element, bound it to e */
	bool GetElem(int i, T &e) {
		if (i < 0 || i >= length) {
			return false;
		}
		e = data[i];
		return true;
	}
	/* set i-th element to e */
	bool SetElem(int i, T e) {
		if (i < 0 || i >= length) {
			return false;
		}
		data[i] = e;
		return true;
	}
	/* get the index of the first item whose value is equal to e, if not return -1*/
	int GetNo(T e) {
		for (int i = 0; i < length; i++) {
			if (data[i] == e) {
				return i;
			}
		}
		return -1;
	}
	/* insert e at index of i */
	bool Insert(int i, T e) {
		if (i < 0 || i > length) {
			return false;
		}
		if (length == capacity) {
			recap(capacity * 2);
		}
		for (int index = length - 1; index >= i; index--) {
			data[index + 1] = data[index];
		}
		data[i] = e;
		length += 1;
		return true;
	}
	T Delete(int i) {
		if (i < 0 || i >= length) {
			return NULL;
		}
		T rv = data[i];
		for (int index = i + 1; index < length; index++) {
			data[index - 1] = data[index];
		}
		length -= 1;

		if (length * 4 < capacity && capacity > DEFAULT_CAPACITY) {
			recap(capacity / 2);
		}
		return rv;
	}
	void DispList(){
		if (length <= 0) {
			return;
		}
		for (int i = 0; i < length; i++) {
			
			std::cout << data[i];
			std::cout << " ";
		}
	std::cout << "\n";
	}
	static AList *CreateAList(T a[], int n) {
		AList *al = new AList<T>();
		for (int i = 0; i < n; i++) {
			al->Add(a[i]);
		}
		return al;
	}
	double useRate() {
		return double(length) / double(capacity);
	}
	int GetCapacity() {
		return capacity;
	}
};

