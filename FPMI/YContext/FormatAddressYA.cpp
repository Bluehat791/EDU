#include <iostream>
#include <string>

struct Address {
    std::string Country;
    std::string City;
    std::string Street;
    std::string House;
};

void Parse(const std::string& line, Address* const address);
void Unify(Address* const address);
std::string Format(const Address& address);

int main() {
    
    std::string line;
    while (getline(std::cin,line))
    {   
        Address* address = new Address;
        try
        {
            Parse(line, address);
            Unify(address);
            std::cout << Format(*address) << "\n";
        } 
        catch(...)
        {   
            delete address;
            std::cout << "exception" << '\n';
            continue;
        }
        delete address;
    }
    

}