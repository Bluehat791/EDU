#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::string word;
    std::map<std::string, int> ms;

    std::cin >> n;
    
    while (std::cin >> word && word != "out")
    {
        ++ms[word];
    }

    std::vector<std::pair<std::string, int>> sortedByFreq(
        ms.begin(),
        ms.end()
    );

    std::sort(
        sortedByFreq.begin(),
        sortedByFreq.end(),
        [](const auto& p1, const auto& p2) {
            // сначала сравниваем частоты по убыванию, потом — слова по возрастанию
            return std::tie(p2.second, p1.first) < std::tie(p1.second, p2.first);
        }
    );

    int x =0;
    for (const auto& [key, value] : sortedByFreq) {
        if (x>=n)
        {
            break;
        }
        
        std::cout << key << "\t" << value << "\n";
        x++;
    }
    

}