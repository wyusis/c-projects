#include <iostream>

struct TNode {
    int Data;
    TNode* Next;
    TNode* Prev;
};

TNode* SplitList(TNode* P1, TNode* P2) {

    if (P2->Data == 0) {
        return P2;
    }

    TNode* newBarrier = new TNode{0, nullptr, nullptr}; 

    TNode* current = P2;
    TNode* prev = nullptr;

    while (current != nullptr) {
        TNode* next = current->Next;
        if (next == nullptr) {
            
            newBarrier->Prev = prev;
            prev->Next = newBarrier;
            return newBarrier;
        }
        prev = current;
        current = next;
    }

    return nullptr;
}

int main() {

    TNode* P1 = new TNode{0, nullptr, nullptr}; 
    TNode* P2 = new TNode{1, nullptr, nullptr};
    TNode* P3 = new TNode{2, nullptr, nullptr};
    TNode* P4 = new TNode{3, nullptr, nullptr};

    P1->Next = P2;
    P2->Next = P3;
    P3->Next = P4;

    TNode* newBarrier = SplitList(P1, P2);
    std::cout << "Указатель на барьерный элемент второго списка: " << newBarrier << std::endl;

    while (P1 != nullptr) {
        TNode* temp = P1;
        P1 = P1->Next;
        delete temp;
    }

    return 0;
}
