#include<iostream>
int main()
{
    int x=2;
    int i,j,n;
    x=x+1;
    std::cin>>n;
    for(i=1;i<=n;i++)
    {
        x=x+1;
    }
    for(i=1;i<=n;i++)
    {
        x=x+1;
        for(j=1;j<=n;j++)
        {
            x=x+1;
        }
        x=x+1;
    }
    std::cout<<x;
    return 0;
}
// Time Complexity: O(n^2)