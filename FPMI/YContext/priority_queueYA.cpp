#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

int main()
{
    std::priority_queue<int> p_que;
    std::string word;

    while (std::cin>>word)
    {
        if (word == "ADD")
        {
            int x;
            std::cin>> x;
            p_que.push(x);
        }
        else if (word == "CLEAR")
        {
            while (!p_que.empty())
            {
                p_que.pop();
            }
            
        }
        else if (word=="EXTRACT")
        {   
            if (p_que.empty())
            {
                std::cout << "CANNOT\n";
            }
            else{
                std::cout << p_que.top() << "\n";
                p_que.pop();
            }
        }
        
    }
    
}
