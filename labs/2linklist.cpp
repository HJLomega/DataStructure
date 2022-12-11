/*
两个非降序链表的并集，例如将链表1->2->3 和 2->3->5 并为 1->2->3->5，只能输出结果，不能修改两个链表的数据。
*/
#include <stdio.h>
#include <list>
using namespace std;

int main(void) {
	list<int> a;
	list<int> b;
	int num;
	char c;
	//读取输入
	do {
		scanf("%d", &num);
		a.push_back(num);
	} while ((c = getchar()) != '\n' && c != EOF);
	do {
		scanf("%d", &num);
		b.push_back(num);
	} while ((c = getchar()) != '\n' && c != EOF);

	/*
	 可以先对 a，b进行冒泡排序，使得算法更健壮
	*/ 

	//归并排序
	list<int> m;
	auto pa = a.begin();
	auto pb = b.begin();
	while (pa!=a.end()&& pb != b.end()) {
		if (*pa < *pb){
			m.push_back(*pa);
			pa++;
		}
		else {
			m.push_back(*pb);
			pb++;
		}
	}
	while (pa != a.end()) {
		m.push_back(*pa);
		pa++;
	}
	while (pb != b.end()) {
		m.push_back(*pb);
		pb++;
	}
	//去重输出
	int pre = *m.begin();
	printf("%d ", pre);
	for (int n : m) {
		if (n == pre) {
			continue;
		}
		else {
			printf("%d ", n);
			pre = n;
		}
	}
}