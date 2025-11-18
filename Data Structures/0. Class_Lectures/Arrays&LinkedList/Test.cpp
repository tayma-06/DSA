#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList list;
    int choice, val, key, pos;

    while (true)
    {
        cout << "\n===== LINKED LIST MENU =====\n";
        cout << "1. Insert at Start\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Key\n";
        cout << "4. Insert Before a Key\n";
        cout << "5. Delete at Start\n";
        cout << "6. Delete at End\n";
        cout << "7. Delete After a Key\n";
        cout << "8. Delete Before a Key\n";
        cout << "9. Search\n";
        cout << "10. Display List\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtStart(val);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtEnd(val);
            break;

        case 3:
            cout << "Enter value: ";
            cin >> val;
            cout << "Enter key (insert after): ";
            cin >> key;
            list.insertAfter(val, key);
            break;

        case 4:
            cout << "Enter value: ";
            cin >> val;
            cout << "Enter key (insert before): ";
            cin >> key;
            list.insertBefore(val, key);
            break;

        case 5:
            list.deleteAtStart();
            break;

        case 6:
            list.deleteAtEnd();
            break;

        case 7:
            cout << "Enter key: ";
            cin >> key;
            list.deleteAfter(key);
            break;

        case 8:
            cout << "Enter key: ";
            cin >> key;
            list.deleteBefore(key);
            break;

        case 9:
            cout << "Enter value to search: ";
            cin >> val;
            if (list.search(val))
                cout << "Found\n";
            else
                cout << "Not Found\n";
            break;

        case 10:
            list.display();
            break;

        case 11:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
