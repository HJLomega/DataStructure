#include <iostream>
template <typename T2>
class LinkNode
{
public:
	LinkNode() {
		next = NULL;
	}
	LinkNode(T2 e) {
		data = e;
		next = NULL;
	}
	~LinkNode() {}

	//private:
	T2 data;
	LinkNode<T2>* next;
};

template<typename T>
class SLList
{	

public:
	SLList() {
		head = new LinkNode<T>();
		end = new LinkNode<T>();
		length = 0;
	}
	~SLList() {
		LinkNode<T>* p = head->next;
		LinkNode<T>* temp;
		while (p != NULL) {
			temp = p;
			p = p->next;
			delete temp;
		}
		delete head;
		delete end;
	}
	void clear() {
		LinkNode<T>* p = head->next;
		LinkNode<T>* temp;
		while (p != NULL) {
			temp = p;
			p = p->next;
			delete temp;
		}
		length = 0; 
		head->next = NULL;
		end->next = NULL;
	}
	/* add a element at the end of the AList */
	void Add(T e) {
		LinkNode<T>* node = new LinkNode<T>(e);
		if (length == 0) {
			head->next = node;
			end->next = node;
			length += 1;
			return;
		}
		end->next->next = node;
		end->next = node;
		length += 1;
	}
	int GetLength() {
		return length;
	}
	/* get i-th element, bound it to e */
	bool GetElem(int i, T& e) {
		if (i < 0 || i >= length) {
			return false;
		}
		LinkNode<T>* p = get(i);
		e = p->data;
		return true;
	}
	/* set i-th element to e */
	bool SetElem(int i, T e) {
		if (i < 0 || i >= length) {
			return false;
		}
		LinkNode<T>* p = get(i);
		p->data = e;
		return true;
	}
	/* get the index of the first item whose value is equal to e, if not return -1*/
	int GetNo(T e) {
		LinkNode<T>* p = head->next;
		int i = 0;
		while (p != NULL) {
			if (p->data == e) {
				return i;
			}
			i += 1;
			p = p->next;
		}
		return -1;
	}
	/* insert e at index of i */
	bool Insert(int i, T e) { 
		if (i < 0 || i > length) {
			return false;
		}
		LinkNode<T>* node = new LinkNode<T>(e);
		if (length == 0) {
			head->next = node;
			end->next = node;
			length += 1;
			return true;
		}
		LinkNode<T>* pre = get(i - 1);
		node->next = pre->next;
		pre->next = node;
		length += 1;
		return true;
	}
	T Delete(int i) {
		if (i < 0 || i >= length) {
			return NULL;
		}
		LinkNode<T>* pre = get(i-1);
		LinkNode<T>* p = pre->next;
		length -= 1;
		pre->next = p->next;
		if (p->next = NULL) {
			end->next = pre
		}
		T rv = p->value;
		delete p;
		return rv;
	}
	void DispList() {
		LinkNode<T>* p = head->next;
		while (p != NULL) {
			std::cout << p->data<<" ";
			p = p->next;
		}
		std::cout << "\n";
	}
	

//private:
	LinkNode<T>* head;
	LinkNode<T>* end;
	int length;
	/* get i-th Node,if i == -1,return head */
	LinkNode<T>* get(int i) {
		if (i < -1 || i >= length) {
			return NULL;
		}
		LinkNode<T>* p = head;
		for (int index = -1; index < i; index++) {
			p = p->next;
		}
		return p;
	}
};