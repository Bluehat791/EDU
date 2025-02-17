#include<iostream>
#include <algorithm>
#include <queue>
#include <set>

int main()
{
    int n;
    int k;
    std::multiset<int> window;
    std::queue<int> result;
    std::cin >> n >> k;

    for (int i = 1,tmp; i <= n; i++)
    {
        std::cin>>tmp;
        result.push(tmp);
        window.insert(tmp);
        if (i>=k)
        {
            std::cout << *window.begin() << "\n";
            auto iter = window.find(result.front());
            window.erase(iter);
            result.pop();
        }
    }
        

    
}