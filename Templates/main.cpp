#include <unordered_map>
#include <string>
#include <algorithm>
#include <string>

template <typename Key, typename Value>
class KeyValueStorage {
private:
      std::unordered_map<Key, Value> data;

public:
    void Insert(const Key& key, const Value& value) {
        data.insert({key,value});
        //data[key] = value;
    }

    void Remove(const Key& key) {
        data.erase(key);
    }

    bool Find(const Key& key, Value* const value = nullptr) const;
};


// Почему-то не работает...
//
// template <typename Key, typename Value>
// bool KeyValueStorage<Key, Value>::Find(const Key& key, Value* value) const {
//     auto it = std::find(data.begin(), data.end(), key);
//     auto val = *it;
//     if (value != nullptr)
//         value = val->second();
//     return it != data.end();
// }

// Ваша реализация функции KeyValueStorage::find будет вставлена сюда:

// template <typename Key, typename Value>
// bool KeyValueStorage<Key, Value>::Find(const Key& key, Value* const value) const {
//     auto it = std::find(data.begin(), data.end(), key);
//     auto val = *it;
//     if (value != nullptr)
//         value = &val;
//     return it != data.end();
// }

template <typename Key, typename Value>
bool KeyValueStorage<Key, Value>::Find(const Key &key, Value* const value) const
{
    auto it = data.find(key);//std::find(data.begin(), data.end(), key);
    Value val = it->second;
    return false;
}


int main() {
    KeyValueStorage<std::string, int> kv;
    kv.Insert("hello", 42);
    kv.Insert("bye", -13);
    int value = 123;
    auto res = kv.Find("wrong", &value);  // должно вернуться false, а value не должен меняться
    // res = kv.Find("bye", &value);  // должно вернуться true, в value должно быть -13
    // res = kv.Find("hello", nullptr);  // должно вернуться true
    return 0;
}
