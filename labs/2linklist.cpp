/*
两个非降序链表的并集，例如将链表1->2->3 和 2->3->5 并为 1->2->3->5，只能输出结果，不能修改两个链表的数据。
*/
#include <stdio.h>

struct Node
{
	int value;
	Node* next;
};

class LinkList {
public:
	Node* head;// 头指针 head->next为第一个一个节点
	Node* end;// 尾指针 end->next为最后一个节点
	LinkList() {
		head = new Node;
		end = new Node;
		head->next = NULL;
		end->next = NULL;
	}
	bool push_back(int num) {
		Node* temp = new Node;
		temp->value = num;
		temp->next = NULL;
		if (head->next == NULL) { //空表时
			end->next = temp;
			head->next = temp;
		}
		else {
			end->next->next = temp;
			end->next = temp;
		}
		return true;
	}
	~LinkList() {
		Node* p = head->next;
		while (p != NULL) {
			Node* temp = p;
			p = p->next;
			delete temp;
		}
	}
	void display() {
		Node* p = head->next;
		while (p != NULL) {
			printf("%d ", p->value);
			p = p->next;
		}
		printf("\n");
	}
};

int main() {
	LinkList a;
	LinkList b;
	int num;
	char c;
	do {
		scanf("%d", &num);
		a.push_back(num);
	} while ((c = getchar()) != '\n' && c != EOF);
	a.display();
	do {
		scanf("%d", &num);
		b.push_back(num);
	} while ((c = getchar()) != '\n' && c != EOF);
	b.display();
}