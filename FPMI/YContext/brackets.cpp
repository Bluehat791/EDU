#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>

bool IsCorrect(const std::string& sequence) {
    std::stack<char> brackets;

    for (char bracket : sequence) {
        if (bracket == '(' || bracket == '{' || bracket == '[') {
            brackets.push(bracket);
        } else {
            if (brackets.empty()) {
                return false;
            }
            char top = brackets.top();
            if ((top == '(' && bracket == ')') || (top == '{' && bracket == '}') || (top == '[' && bracket == ']')) {
                brackets.pop();
            } else {
                return false;
            }
        }
    }

    return brackets.empty();
}

int main()
{   
    std::string word;

    std::cin>> word;

    
    
    if (IsCorrect(word))
    {
        std::cout << "YES";
    }
    else{
        std::cout << "NO";
    }
}