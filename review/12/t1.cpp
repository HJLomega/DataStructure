/* 
对单链表中元素按直接插入方法进行排序，算法的C语言描述如下，
其中L为指向链表头结点的指针。请在空白处填入合适的代码，以完成排序功能。
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
