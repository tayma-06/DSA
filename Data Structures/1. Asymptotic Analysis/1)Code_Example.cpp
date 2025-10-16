// C++ program to find sum of first n natural numbers
#include<iostream>
int main(){
    int i, sum=0, n;
    std::cout<<"Enter a number: ";
    std::cin>>n;
    for(i=1; i<=n; i++){
        sum += i;
    }
    std::cout<<"Sum of first "<<n<<" natural numbers is: ";
    std::cout<<sum;
    return 0;
}