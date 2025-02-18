#include <iostream>
#include <string>

class Serializer
{
public:
    virtual void BeginArray() = 0;
    virtual void AddArrayItem(const std::string&) = 0;
    virtual void EndArray() =0;

    virtual ~Serializer()
    {}
};

class JsonSerializer : public Serializer
{       
    std::string result = "";
    int count_begin = 0;
public:
    void BeginArray() override
    {   
        count_begin++;
        result += '[';
    }

    void AddArrayItem(const std::string& item) override
    {   
        if (result[result.size()-1]!='[')
        {
            result+=',';
        }
        
        result += ('"' + item + '"');
    }

    void EndArray() override
    {   
        
        result+=']';
        count_begin--;
        if (count_begin == 0)
        {
            std::cout << result << "\n";
        }
        
    }
};


int main()
{
    std::string word;
    JsonSerializer json;
    while (std::cin>> word &&word != "out")
    {
        if (word == "BeginArray")
        {
            json.BeginArray();
        }
        if (word == "AddArrayItem")
        {
            std::string word_tmp;
            std::cin>> word_tmp;
            json.AddArrayItem(word_tmp);
        }
        if (word == "EndArray")
        {
            json.EndArray();
        }
    }
    
}