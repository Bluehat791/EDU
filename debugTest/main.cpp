#include <iostream>

int main(){

for (size_t i = 0; i < 25; i++)
{
    if(i%2==0)
        std::cout << "YES\n";
    else continue;
}
    return 0;
}