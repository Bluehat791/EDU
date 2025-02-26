#include<iostream>
#include<cstring>

int m_atoi(const char *str)
{
    int result = 0;
    for (size_t i = 0; i < std::strlen(str); i++)
    {
        if (str[i]>57 || str[i]<48)
        {
            throw 1;
        }
       
    }
    
    for (int i = std::strlen(str)-1,radix=1; i >=0; i--, radix*=10)
    {
        result += (str[i]-48)*radix;
    }
    

    return result;
}

int main()
{
    

    std::cout << m_atoi("123") << "\n";
}