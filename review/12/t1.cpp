#include <iostream>
using namespace std;
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
    p = L->next;     /*(1)*/L->next=nullptr;
    while (/*(2)*/p!= nullptr) {
        r = L;  q = L->next;
        while (/*(3)*/ q!=nullptr && q->data <= p->data) {  
            r = q;   q = q->next;
        }
        u = p->next;      /*(4)*/p->next = q;     /*(5)*/r->next = p; p = u;
    }
}

void test() {
    const int N = 5;
    int ar[N] = { 5,4,3,2,1 };
    Link list = nullptr;
    //list->data = -1; list->next = nullptr;
    for (int i = N - 1; i >= 0; i--) {
        Link temp = new Linknode();
        temp->data = ar[i]; temp->next = list;
        list = temp;
    }
    Link temp = new Linknode();
    temp->data = -1; temp->next = list;
    list = temp;

    InsertSort(list);
    int b = 1;
}
int main() {
    test();
}

