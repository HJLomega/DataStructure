/* 
�Ե�������Ԫ�ذ�ֱ�Ӳ��뷽�����������㷨��C�����������£�
����LΪָ������ͷ����ָ�롣���ڿհ״�������ʵĴ��룬����������ܡ�
*/

typedef struct node {
    int data;
    struct node* next;
} Linknode, * Link;
void InsertSort(Link L) {
    Link p, q, r, u;
    p = L->next;     /*(1)*/L->next=nullptr;
    while (/*(2)*/p!= nullptr) {
        r = L;  q = L->next;
        while (/*(3)*/ q!=nullptr && q->data <= p->data) {  
            r = q;   q = q->next;
        }
        u = p->next;      /*(4)*/p->next = q;     /*(5)*/r->next = p; p = u;
    }
}



