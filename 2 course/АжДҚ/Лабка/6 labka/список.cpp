/*
Dynamic30◦. Дан указатель P1 на начало непустой цепочки элементов-записей
типа TNode, связанных между собой с помощью поля Next. Используя по-
ле Prev записи TNode, преобразовать исходную (односвязную) цепочку в двусвязную, в которой каждый элемент связан не только с последующим элементом (с помощью поля Next), но и с предыдущим (с помощью поля Prev).
Поле Prev первого элемента положить равным NIL. Вывести указа- тель на последний элемент преобразованной цепочки.
*/

#include <iostream>
using namespace std;
struct TNode {
    int Data;
    TNode* Next;
    TNode* Prev; 
};

TNode* ConvertToDoublyLinkedList(TNode* P1) {
    TNode* current = P1;
    TNode* prev = nullptr;

    while (current != nullptr) {
        TNode* next = current->Next; 

        current->Prev = prev;

        if (prev == nullptr) {
            current->Prev = nullptr;
        }

        prev = current;
        current = next;
    }

    return prev; 
}

int main() {
    TNode* P1 = new TNode{1, nullptr, nullptr};
    TNode* P2 = new TNode{2, nullptr, nullptr};
    TNode* P3 = new TNode{3, nullptr, nullptr};

    P1->Next = P2;
    P2->Next = P3;

    TNode* lastNode = ConvertToDoublyLinkedList(P1);

    cout << "Сонгы элементке указатель: " << lastNode << endl;

    while (lastNode != nullptr) {
        TNode* temp = lastNode;
        lastNode = lastNode->Prev;
        delete temp;
    }

    return 0;
}
