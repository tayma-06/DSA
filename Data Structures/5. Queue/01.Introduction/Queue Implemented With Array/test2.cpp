#include <iostream>
#include "myQueueString.h"

using namespace std;

int main()
{
    myQueue q(100);
    q.enqueue("Apple");
    q.enqueue("Guava");
    q.enqueue("Mango");
    cout << "Data in the Queue: " << endl;
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;
    cout << "Empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    cout << "Full? " << (q.isFull() ? "Yes" : "No") << endl;

    return 0;
}