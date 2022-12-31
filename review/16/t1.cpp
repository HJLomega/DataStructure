/*
有两个递增有序表，所有元素为整数，均采用带头结点的单链表存储，结
点类型定义如下
*/
typedef struct node
{
	int data;
	struct node* next;
} LinkNode;
/*
设计一个尽可能高效的算法，将两个递增有序单链表 ha、hb 合并为一个递减有序单链
表 hc，要求算法空间复杂度为 O(1)
*/

//头插归并
LinkNode* reverse_merge(LinkNode* ha , LinkNode* hb) {
	LinkNode* a = ha->next;
	LinkNode* b = hb->next;
	LinkNode* new_list = new LinkNode();
	new_list->next = nullptr;

	while (a != nullptr && b != nullptr) {
		if (a->data < b->data) {
			LinkNode* temp = a;
			a = a->next;
			temp->next = new_list->next;
			new_list->next = temp;
		}
		else {
			LinkNode* temp = b;
			b = b->next;
			temp->next = new_list->next;
			new_list->next = temp;
		}
	}
	while (a != nullptr) {
		LinkNode* temp = a;
		a = a->next;
		temp->next = new_list->next;
		new_list->next = temp;
	}
	while (b != nullptr) {
		LinkNode* temp = b;
		b = b->next;
		temp->next = new_list->next;
		new_list->next = temp;
	}
	return new_list;
}