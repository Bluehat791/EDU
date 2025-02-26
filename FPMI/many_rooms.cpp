#include <iostream>
#include <vector>
#include <string>

using namespace std;

int off_light(vector<string>& tm, int& x, int& y)
{
    vector<char> light_window;
    
    for(int x = 0; x < tm.size();x++)
    for (int i = 0; i < x; i++)
    {
        for (size_t j = 0; j < y; j++)
        {
            light_window.push_back(tm[i][j]);
        }
        
    }
    
}

int main()
{
    int n,m,x,y;

    std::cin >> n >> m >> x >> y;
    
    vector<string> n_string;
    string word;
    getline(cin,word);
    for (int i = 0; i < m*n; i++)
    {   
        getline(cin,word);

        n_string.push_back(word);
    }

    cout << off_light(n_string,x,y);
    
}
