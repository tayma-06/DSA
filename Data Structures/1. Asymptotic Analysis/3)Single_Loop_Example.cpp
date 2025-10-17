#include<iostream>
int main()
{
    int n;
    std::cout << "Enter the number of times to print 'Hello, World!': ";
    std::cin >> n;
    for(int i=1; i<=n; i++)
    {
        std::cout << "Hello, World!" << std::endl;
    }
    return 0;
}
// Time Complexity: O(n)