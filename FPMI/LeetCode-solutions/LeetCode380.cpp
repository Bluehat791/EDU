#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
    unordered_set<int> data;
public:
    RandomizedSet() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        return data.insert(val).second;
    }
    
    bool remove(int val) {
        return data.erase(val);
    }
    
    int getRandom() {
        size_t random_index = rand() % (data.size());
        int i = 0;
        auto iter = data.begin();
        while (iter != data.end())
        {
            if(i==random_index)
                return *iter;

            iter++;
            i++;
        }
        
        return 0;
    }
};

int main()
{   
    int val = 1;

    RandomizedSet* obj = new RandomizedSet();
    bool param_1 = obj->insert(val);
    cout << "insert - " << param_1 << " : value - " << val << endl;

    val=2;
    bool param_2 = obj->remove(val);
    cout << "remove - " << param_2 << " : value - " << val << endl;

    param_1 = obj->insert(val);
    cout << "insert - " << param_1 << " : value - " << val << endl;

    int param_3 = obj->getRandom();
    cout << "random count - " << param_3 << endl;
 
    val = 1;
    param_2 = obj->remove(val);
    cout << "remove - " << param_2 << " : value - " << val << endl;

    val =2;
    param_1 = obj->insert(val);
    cout << "insert - " << param_1 << " : value - " << val << endl;

    param_3 = obj->getRandom();
    cout << "random count - " << param_3 << endl;
}