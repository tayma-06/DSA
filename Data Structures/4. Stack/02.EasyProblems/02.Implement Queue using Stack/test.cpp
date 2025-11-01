#include <iostream>
#include "myQueue.h"

using namespace std;

int main()
{
    myQueue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front: " << q.front() << endl;
    cout << "Size: " << q.size() << endl;

    q.dequeue();
    cout << "Front: " << q.front() << endl;
    cout << "Size: " << q.size() << endl;

    return 0;
}