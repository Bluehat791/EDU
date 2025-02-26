#include <iostream>

template<typename T>
struct Node
{
    T data;
    Node* next;
};


template<typename T>
void insertNode(Node<T>*& head, T data, int position)
{
    Node<T>* newNode = new Node<T>{data, nullptr};
    if (position == 0)
    {
        newNode->next = head;
        head = newNode
    } else {
        Node<T> current = head;
        for (int i = 0; i < position-1 && current!=nullptr; i++)
        {
            current = current->next;
        }
        if (current != nullptr)
        {
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    
}