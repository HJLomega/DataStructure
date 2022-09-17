#include "AList.h"
void test(){
    AList<int> &al = AList<int>();
    al.Add(5);
    al.Add(4);
    al.Add(3);
    al.Add(2);
    al.Add(1);
    al.DispList();
}
void testCreateAList() {
    int ar[] = { 1,2,3,4,5 };
    AList<int> *al = AList<int>::CreateAList(ar,5);
    al->DispList();
    delete al;
}
void testInsert() {
    int ar[] = { 1,2,3,4,5 };
    AList<int>* al = AList<int>::CreateAList(ar, 5);
    al->DispList();
    al->Insert(2, 100);
    al->Insert(6, 100);
    al->DispList();
    delete al;
}
void testRecap() {
    AList<int> *al = new AList<int>();
    for (int i = 0; i < 65; i++) {
        al->Add(i);
        std::cout << al->GetLength()<<" " << al->GetCapacity() << "\n";
    }
    for (int i = 64; i > 0; i--) {
        al->Delete(i);
        std::cout << al->GetLength() << " " << al->GetCapacity() << "\n";
    }
    delete al;
}
int main(void){
    testRecap();
    std::cin.get();
}