#include "SLList.h"
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
int main() {
	testClear();
	std::cin.get();
}