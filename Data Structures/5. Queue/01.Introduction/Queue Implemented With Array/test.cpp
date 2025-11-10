#include <iostream>
#include "myQueueInt.h"

using namespace std;

int main()
{
    myQueue q(100);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Data in the Queue: " << endl;
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;
    cout << "Empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    cout << "Full? " << (q.isFull() ? "Yes" : "No") << endl;

    return 0;
}