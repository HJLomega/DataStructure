/*
�����ǽ�������Ĳ��������罫����1->2->3 �� 2->3->5 ��Ϊ 1->2->3->5��ֻ���������������޸�������������ݡ�
*/
#include <iostream>
#include <list>
using namespace std;

int main(void) {
	list<int> a;
	list<int> b;
	int num;
	
	//��ȡ����
	while (cin >> num) {
		a.push_back(num);
		if (cin.get() == '\n') {
			break;
		}
	}
	while (cin >> num) {
		b.push_back(num);
		if (cin.get() == '\n') {
			break;
		}
	}

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
	cout<<pre<<" ";
	for (int n : m) {
		if (n == pre) {
			continue;
		}
		else {
			cout << n << " ";
			pre = n;
		}
	}
}