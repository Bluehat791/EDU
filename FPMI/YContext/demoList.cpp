#include<iostream>

template <typename T>
class m_forward_list
{

    struct forward_list_node
    {
        T data;
        forward_list_node* next;
        forward_list_node() : data(T()), next(nullptr)
        {}

        forward_list_node(const T& data, forward_list_node* pNext = nullptr)
        {
            this->data = data;
            this->next = pNext;
        }
    };

    forward_list_node* head = nullptr;
    int size;
public:
    m_forward_list() : head(nullptr),size(0)
    {}

    void push_front(const T& data)
    {
        if (!head)
        {
            try
            {
                head = new forward_list_node(data);
                size++;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            return;
        }
        

        forward_list_node* current = head;
        while (current->next != nullptr && current)
        {
            current = current->next;
        }
        
        try
        {
            current->next = new forward_list_node(data);
            size++;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            delete current;
        }
        
    }

    void size_out()
    {
        std::cout << size << " is size of List\n";
    }

    void out_list()
    {
        forward_list_node* current = head;
        while (current->next != nullptr && current)
        {
            std::cout << current->data << "\n";
            current = current->next;
        }
        
    }


};


int main()
{
    m_forward_list<int> mfw;
    mfw.push_front(1);
    mfw.push_front(3);
    mfw.push_front(4);
    mfw.push_front(6);
    mfw.push_front(7);
    mfw.push_front(11);

    mfw.out_list();
}