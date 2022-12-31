/*
有两个递增有序表，所有元素为整数，并且每个元素值是唯一的，元素个
数分别为 m、n，均采用带头结点的单链表存储，结点类型定义如下：

设计一个尽可能高效的算法，求这两个单链表 ha、hb 中第 k 大的元素（1≤k≤m + n）。
例如有序表为（1, 2, 3, 4, 5），第 2 大的元素为 4
*/

typedef struct node
{
	int data;
	struct node* next;
} LinkNode;

//等效于求第n+m-k+1个元素
int k_max(LinkNode* ha, LinkNode* hb,int k) {
	
	LinkNode* a = ha->next;
	LinkNode* b = hb->next;
	int m_a=0;
	int n_b=0;
	//计算链表长度
	while (a) {
		m_a++;
		a = a->next;
	}
	while (b) {
		n_b++;
		b = b->next;
	}

	//归并比较
	a = ha->next;
	b = hb->next;
	int num =0;
	int count = 1;
	int target = m_a + n_b - k + 1;
	while (count <= target &&a != nullptr && b != nullptr) {
		if (a->data < b->data) {
			num = a->data;
			a = a->next;
		}
		else {
			num = b->data;
			b = b->next;
		}
		count++;
	}
	while (count <= target&&a != nullptr) {
		num = a->data;
		a = a->next;
		count++;
	}
	while (count <= target && b != nullptr) {
		num = b->data;
		b = b->next;
		count++;
	}
	return  num;
}