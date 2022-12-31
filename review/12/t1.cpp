#include <iostream>
using namespace std;
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

