/*
�����ǽ�������Ĳ��������罫����1->2->3 �� 2->3->5 ��Ϊ 1->2->3->5��ֻ���������������޸�������������ݡ�
*/
#include <stdio.h>
#include <list>
using namespace std;

int main(void) {
	list<int> a;
	list<int> b;
	int num;
	char c;
	//��ȡ����
	do {
		scanf("%d", &num);
		a.push_back(num);
	} while ((c = getchar()) != '\n' && c != EOF);
	do {
		scanf("%d", &num);
		b.push_back(num);
	} while ((c = getchar()) != '\n' && c != EOF);

	/*
	 �����ȶ� a��b����ð������ʹ���㷨����׳
	*/ 

	//�鲢����
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
	//ȥ�����
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