// C++ program to find sum of first n natural numbers
#include<iostream>
int main(){
    int i, n;
    std::cout<<"Enter a number: ";
    std::cin>>n;
    std::cout<<"Sum of first "<<n<<" natural numbers is: "<< (n*(n+1))/2;
    return 0;
}
// Time Complexity: O(1)