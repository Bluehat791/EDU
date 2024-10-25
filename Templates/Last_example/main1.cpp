#include <iostream>
#include <type_traits> // for std::is_pointer_v and std::is_null_pointer_v
#include <memory>
#include <string>

template <typename T, typename S>
class Pair {
    T m_first;
    S m_second;
public:
    Pair(T _first,S _second) 
        : m_first(_first),m_second(_second){}
    T first(){
        return m_first;
    }
    const T first() const{
        return m_first;
    }

    S second(){
        return m_second;
    }

    const S second() const{
        return m_second;
    }
};


template<typename T>
class StringValuePair : public Pair<std::string,T> 
{   
public:
    StringValuePair(std::string first,T second)
    : Pair<std::string, T> { first,second} 
    {}

    
};

int main()
{
	StringValuePair<int> svp { "Hello", 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
	return 0;
}