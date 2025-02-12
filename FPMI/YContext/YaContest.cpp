#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void word_cin(string word_tmp, set<string>& result)
{   
    
    string pwd;
    for (size_t i = word_tmp.size()-1; i > 0; i--)
    {
        if (word_tmp[i]=='/' && i+1<word_tmp.size())
        {   
            pwd = word_tmp.substr(0,i+1);
            result.insert(pwd);
            word_cin(pwd,result);
            break;
        }
        
    }
    
}

int main() {
    set<string> result;
    vector<string> tmp;
    string res = "";
    string word;
    while (cin >> word)
    {

        tmp.push_back(word);

    }
    
    if(tmp.size()>0)
        result.insert("/");
    
    for (size_t i = 0; i < tmp.size(); i++)
    {   
        word_cin(tmp[i],result);
    }
    

    for (const auto& x : result)
    {
        cout << x << endl;
    }
    
    cout << '\n';
    
}