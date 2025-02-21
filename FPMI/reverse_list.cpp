#include<forward_list>
#include<iostream>
#include<stack>
#include<queue>
void reverse_list(std::forward_list<int>& fl)
{   
    
    std::queue<int> tmp;
    
    for (auto& count : fl)
    {   
        tmp.push(count);
    }
    fl.clear();

    while (!tmp.empty())
    {
        fl.push_front(tmp.front());
        tmp.pop();
    }
    
    for (auto& count : fl)
    {   
        std::cout << count << "\n";
    }
    
    std::cout << "\n";
}

int main()
{
    std::forward_list<int> fl = {1,2,3,4,5,6,7};
    reverse_list(fl);
}