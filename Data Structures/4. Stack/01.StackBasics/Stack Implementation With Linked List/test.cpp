#include <iostream>
#include "myStackInt.h"

using namespace std;

int main()
{
    myStack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Popped: " << st.peek() << endl;
    st.pop();

    cout << "Top element: " << st.peek() << endl;

    cout << "Is stack empty: " << (st.isEmpty() ? "Yes" : "No") << endl;

    cout << "Current size: " << st.size() << endl;

    return 0;
}