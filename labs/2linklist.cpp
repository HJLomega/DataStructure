/*
�����ǽ�������Ĳ��������罫����1->2->3 �� 2->3->5 ��Ϊ 1->2->3->5��ֻ���������������޸�������������ݡ�
*/
#include <stdio.h>

struct Node
{
	int value;
	Node* next;
};

class LinkList {
public:
	Node* head;// ͷָ�� head->nextΪ��һ��һ���ڵ�
	Node* end;// βָ�� end->nextΪ���һ���ڵ�
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
		if (head->next == NULL) { //�ձ�ʱ
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