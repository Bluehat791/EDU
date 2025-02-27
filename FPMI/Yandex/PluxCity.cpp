#include<iostream>
#include<vector>

using namespace std;

void max_distance(int i,int j, vector<vector<pair<int,int>>>& distance_,const vector<vector<char>>& matrix )
{
    if (matrix[i][j]=='x')
    {
        return;
    }

    int right_path =0;
    int i1=i;
    int j2 = j;
    while (matrix[i][j2]!='x' && j2 <matrix[i].size())
    {
        right_path++;
        j2++;
    }
    int down_path = 0;
    while (i1 <matrix.size() && matrix[i1][j]!='x')
    {
        down_path++;
        i1++;
    }
    
    distance_[i][j] = {right_path,down_path};
}

int largestSquare(const vector<vector<char>>& matrix )
{
    int rows = matrix.size();
    if (rows == 0)
    {
        return 0;
    }
    int cols = matrix[0].size();
    
    vector<vector<pair<int,int>>> distance_(rows,vector<pair<int,int>>(cols,{0,0}));
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            max_distance(i,j,distance_,matrix);
        }
        
    }
    
    return 1;
}

int main()
{
    int n,m,d;
    cin>>n >> m >> d;
    vector<vector<char>> town_map(n);

    for (size_t i = 0; i < n; i++)
    {   
        char tmp;
        for (size_t j = 0; j < m; j++)
        {
            cin >> tmp;
            town_map[i].push_back(tmp);
        }
        
    }
    

    cout << largestSquare(town_map) <<" hello\n";
}