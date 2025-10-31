#include <iostream>
#include "CircularQueue.h"

using namespace std;

CircularQueue cq(10000);

int ping(int t)
{
    cq.push(t);
    while (!cq.empty() && cq.getFront() < t - 3000)
    {
        cq.pop();
    }
    return cq.size();
}
int main()
{
    cout << ping(1) << "\n";
    cout << ping(2) << "\n";
    cout << ping(3) << "\n";
    cout << ping(4) << "\n";
    cout << ping(3001) << "\n";
    cout << ping(3002) << "\n";
    cout << ping(3003) << "\n";
    cout << ping(6003) << "\n";
    cout << ping(10003) << "\n";
    return 0;
}