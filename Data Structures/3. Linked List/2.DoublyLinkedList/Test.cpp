#include <bits/stdc++.h>
#include "DoublyList.h"

using namespace std;

int main()
{
    DoublyList dl;

    // Insertion tests
    dl.push_back(10);
    dl.push_back(20);
    dl.push_front(5);
    dl.push(15, 3);

    cout << "After insertions: ";
    dl.display();

    // Deletion tests
    dl.delete_front();
    cout << "After delete front: ";
    dl.display();

    dl.delete_back();
    cout << "After delete back: ";
    dl.display();

    dl.delete_pos(2);
    cout << "After delete position 2: ";
    dl.display();

    return 0;
}