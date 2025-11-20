#include <bits/stdc++.h>
#include "SinglyList.h"
using namespace std;

int main()
{
    SinglyList sl;

    sl.push_front(10);
    sl.display();

    sl.push_back(20);
    sl.display();

    sl.push_before(5, 10);
    sl.display();

    sl.push_after(15, 10);
    sl.display();

    sl.push_front(0);
    sl.push_back(25);

    sl.pop_front();
    sl.display();

    sl.pop_back();
    sl.display();

    sl.pop_after(5);
    sl.display();

    sl.pop_before(20);
    sl.display();

    return 0;
}