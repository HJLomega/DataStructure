/*
�������������������Ԫ��Ϊ�����������ô�ͷ���ĵ�����洢����
�����Ͷ�������
*/
typedef struct node
{
	int data;
	struct node* next;
} LinkNode;
/*
���һ�������ܸ�Ч���㷨�������������������� ha��hb �ϲ�Ϊһ���ݼ�������
�� hc��Ҫ���㷨�ռ临�Ӷ�Ϊ O(1)
*/

//ͷ��鲢
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