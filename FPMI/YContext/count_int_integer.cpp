#include<iostream>
#include<string>
#include<algorithm>

int main()
{
    int i;
    std::cin>>i;

    int result = 0;
    while (i!=0)
    {
        if (i%10==1)
        {
            result++;
        }
        i/=10;
    }
    

    std::cout <<  result << "\n"; 
}