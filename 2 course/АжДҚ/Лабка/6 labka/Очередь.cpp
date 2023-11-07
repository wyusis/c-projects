/* Dynamic15. Дан набор из 10 чисел. Создать две очереди: первая должна со- держать числа из исходного набора с нечетными номерами
 (1, 3, . . ., 9), а вторая — с четными (2, 4, . . ., 10); порядок чисел в каждой очереди
 дол- жен совпадать с порядком чисел в исходном наборе. Вывести указатели на начало и конец первой, а затем второй очереди.*/


#include <iostream>
using namespace std;

struct TNode {
    int Data;
    TNode* Next;
};

struct Ukazatel {
    TNode* First; 
    TNode* Last; 
};

void Initialize_Ukazatel(Ukazatel& queue) {
    queue.First = nullptr;
    queue.Last = nullptr;
}

void Enqueue(Ukazatel& queue, int value) {
    TNode* newNode = new TNode{value, nullptr};
    if (queue.Last == nullptr) {
        queue.First = newNode;
        queue.Last = newNode;
    } else {
        queue.Last->Next = newNode;
        queue.Last = newNode;
    }
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    Ukazatel oddQueue;
    Ukazatel evenQueue;

    Initialize_Ukazatel(oddQueue);
    Initialize_Ukazatel(evenQueue);

    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            Enqueue(evenQueue, numbers[i]); 
        } else {
            Enqueue(oddQueue, numbers[i]); 
        }
    }

    cout << "Указател так сан:" << endl;
    cout << "Басы: " << oddQueue.First << endl;
    cout << "Соңы: " << oddQueue.Last << endl;

    cout << "Указател жуп сан:" << endl;
    cout << "Басы: " << evenQueue.First << endl;
    cout << "Соңы: " << evenQueue.Last << endl;
 
    while (oddQueue.First != nullptr) {
        TNode* temp = oddQueue.First;
        oddQueue.First = oddQueue.First->Next;
        delete temp;
    }

    while (evenQueue.First != nullptr) {
        TNode* temp = evenQueue.First;
        evenQueue.First = evenQueue.First->Next;
        delete temp;
    }

    return 0;
}
