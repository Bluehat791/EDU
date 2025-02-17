#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <deque>



int main() {
    std::vector<int> in1;
    std::vector<int> in2;

    int n;
    int k;
    std::cin >> n >> k;
    
    for (int i = 0, tmp = 0; i < n; i++)
    {   
        std::cin >> tmp;
        in1.push_back(tmp);
    }

    for (int i = 0, tmp = 0; i < k; i++)
    {   
        std::cin >> tmp;
        in2.push_back(tmp);
    }
    

    for (size_t i = 0; i < in2.size(); i++)
    {   
        auto iter = (std::lower_bound(in1.begin(),in1.end(),in2[i]));
        if(abs(in2[i]-*iter)>abs(in2[i]-*std::prev(iter)))
            std::cout << *std::prev(iter)  << "\n";
        else if (abs(in2[i]-*iter)<abs(in2[i]-*std::prev(iter)))
            std::cout << *iter  << "\n";
        else if(in2[i]-*iter == 0)
            std::cout << *iter  << "\n";
        else 
            std::cout << *std::prev(iter)  << "\n";
    }
    
    return 0;
}