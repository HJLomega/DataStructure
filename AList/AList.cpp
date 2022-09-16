#include "AList.h"
template<typename T>
AList<T>::AList() {
	data = new T[DEFAULT_CAPACITY];
	capacity = DEFAULT_CAPACITY;
	length = 0;
}

template<typename T>
AList<T>::~AList() {
	delete[] data;
}
template<typename T>
void AList<T>::Add(T e) {
	if (length == capacity) {
		recap(capacity * 2);
	}
	data[length] = e;
	length += 1;
}
template<typename T>
int AList<T>::GetLength() {
	return length;
}
template<typename T>
bool AList<T>::GetElem(int i, T &e) {
	if (i < 0 || i >= length) {
		return false;
	}
	e = dara[i];
	return true;
}
template<typename T>
int AList<T>::GetNo(T e) {
	for (int i = 0; i < length; i++) {
		if (data[i] == e) {
			return i;
		}
	}
	return - 1;
}