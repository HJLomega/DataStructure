/*
�������������������Ԫ��Ϊ����������ÿ��Ԫ��ֵ��Ψһ�ģ�Ԫ�ظ�
���ֱ�Ϊ m��n�������ô�ͷ���ĵ�����洢��������Ͷ������£�

���һ�������ܸ�Ч���㷨���������������� ha��hb �е� k ���Ԫ�أ�1��k��m + n����
���������Ϊ��1, 2, 3, 4, 5������ 2 ���Ԫ��Ϊ 4
*/

typedef struct node
{
	int data;
	struct node* next;
} LinkNode;

//��Ч�����n+m-k+1��Ԫ��
int k_max(LinkNode* ha, LinkNode* hb,int k) {
	
	LinkNode* a = ha->next;
	LinkNode* b = hb->next;
	int m_a=0;
	int n_b=0;
	//����������
	while (a) {
		m_a++;
		a = a->next;
	}
	while (b) {
		n_b++;
		b = b->next;
	}

	//�鲢�Ƚ�
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