/*
Dynamic2◦. Дан адрес P1  записи типа TNode. Эта запись связана полем Next
со следующей записью того же типа, она, в свою очередь, — со следую-
щей, и так далее до записи, поле Next которой равно NIL (таким образом, возникает цепочка связанных записей). 
Вывести значения полей Data для всех элементов цепочки, длину цепочки (то есть число ее элементов) и адрес ее последнего элемента.
*/

#include <iostream>

using namespace std;

struct TNode {
    int Data;
    TNode* Next;
};

void SPISOK(TNode* P1) {
    TNode* Node = P1;
    int length = 0;

    while (Node != nullptr) {
        cout << "Data: " << Node->Data << endl;
        length++;
        Node = Node->Next;
    }

    cout << "цепочка узындыгы: " << length << endl;
    cout << "элемент сонгы адресі: " << Node << endl;
}

int main() {

    TNode* P1 = new TNode{2, nullptr};
    TNode* P2 = new TNode{2, nullptr};
    TNode* P3 = new TNode{3, nullptr};

    P1->Next = P2;
    P2->Next = P3;

    SPISOK(P1);

    delete P1;
    delete P2;
    delete P3;

    return 0;

}
