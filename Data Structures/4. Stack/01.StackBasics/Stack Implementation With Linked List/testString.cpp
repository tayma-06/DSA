#include <iostream>
#include <string>
#include "myStackString.h"

using namespace std;

int main()
{
    myStack st;
    st.push("Violet");
    st.push("Lily");
    st.push("Hyacinth");
    st.push("Roses");

    cout << "Popped: " << st.peek() << endl;
    st.pop();

    cout << "Top element: " << st.peek() << endl;

    cout << "Is stack empty: " << (st.isEmpty() ? "Yes" : "No") << endl;

    cout << "Current size: " << st.size() << endl;

    return 0;
}