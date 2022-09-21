//#include "SLList.h"
#include "CLinkList.h"
#include "DLinkList.h"
/*
void test() {
	SLList<int> sl = SLList<int>();
	for (int i = 0; i < 6; i++) {
		sl.Add(i);
	}
	sl.DispList();
}
void testInstert() {
	SLList<int> sl = SLList<int>();
	for (int i = 0; i < 6; i++) {
		sl.Add(i);
	}
	sl.DispList();
	sl.Insert(0, 100);
	sl.DispList();
	sl.Insert(7, 100);
	sl.DispList();
	sl.Insert(4, 100);
	sl.DispList();
}
void testClear() {
	SLList<int> sl = SLList<int>();
	for (int i = 0; i < 6; i++) {
		sl.Add(i);
	}
	sl.DispList();
	sl.clear();
	sl.DispList();
	sl.Add(1);
	sl.DispList();
}
*/
void testCLinkLIst() {
	CLinkList<int> sl1 = CLinkList<int>();
	int ar1[] = { 1,1,1,1,4,4,5,5 };
	sl1.CreateListR(ar1, 8);
	sl1.DispList();
}
void testDLinkLIst() {
	DLinkList<int> sl1 = DLinkList<int>();
	int ar1[] = { 1,1,1,1,4,4,5,5 };
	sl1.CreateListR(ar1, 8);
	sl1.DispList();
}
int main() {
	testDLinkLIst();
	std::cin.get();
}