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
    p = L->next;     /*(1)*/;
    while (/*(2)*/p) {
        r = L;  q = L->next;
        while (/*(3)*/ && q->data <= p->data) {  
            r = q;   q = q->next;
        }
        u = p->next;      /*(4)*/;     /*(5)*/; p = u;
    }
}
