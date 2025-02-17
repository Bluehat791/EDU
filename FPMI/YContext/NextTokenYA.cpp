#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <string_view>

bool NextToken(std::string_view& sv, const char& c, std::string_view& token)
{   
    if (sv.empty())
    {
        return false;
    }

    auto pos = sv.find(c);
    if (pos!=sv.npos)
    {
        token = sv.substr(0, pos);
        sv.remove_prefix(pos+1);
    }
    else
    {
        token = sv;
        sv.remove_prefix(sv.size());
    }
    
    return true;
}

int main() {
    std::string_view sv = "Hello world and good bye";

    const char delimiter = ' ';
    std::string_view token;

    // Делим строку на токены по разделителю и перебираем эти токены:
    while (NextToken(sv, delimiter, token)) {
        // обрабатываем очередной token
        // например, печатаем его на экране:
        std::cout << token << "\n";
    }
}