#include <iostream>
#include "List.h"
using namespace std;

int main() {
    List L;

    L.insertFirst(10, 'A');
    L.insertFirst(20, 'B');
    L.insertEnd(30, 'C');

    cout << "List contents:\n";
    L.traverse();

    cout << "\nOrdered insertion:\n";
    L.orderinsert(5, 'X');
    L.orderinsert(25, 'Y');
    L.traverse();

    cout << "\nList size: " << L.listSize() << endl;

    return 0;
}
