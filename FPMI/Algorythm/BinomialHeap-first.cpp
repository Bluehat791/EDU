#include<iostream>
#include<vector>
#include <algorithm>
#include<cmath>
using namespace std;

class Node {
public: 
    int value;
    Node* parent;
    vector<Node*> children;
    int degree;
    bool marked;

    Node(int val)
    : value(val), parent(nullptr), degree(0),marked(false)  
    {
        children.clear();
    }
};

class BinomialHeap {
public:
    vector<Node*> trees;
    Node* min_node;
    int count;

    BinomialHeap()
    : min_node(nullptr), count(0)
    {
        trees.clear();
    }

    bool is_empty() {
        return min_node == nullptr;
    }

    void insert(int value) {
        Node* node = new Node(value);
        BinomialHeap heap;
        heap.trees.push_back(node);
        merge(heap);
    }

    int get_min(){
        return min_node->value;
    }

    int extract_min() {
        Node* minNode = min_node;
        trees.erase(remove(trees.begin(),trees.end(), minNode),trees.end());
        BinomialHeap heap;
        heap.trees = minNode->children;
        merge(heap);
        _find_min();
        count--;
        return minNode->value;
    }

    void merge(BinomialHeap& other_heap) {
        trees.insert(trees.end(),other_heap.trees.begin(), other_heap.trees.end());
        count+=other_heap.count;
        _find_min();
    }

    void _find_min(){
        min_node = nullptr;
        for(Node* tree : trees){
            if(min_node == nullptr || tree->value < min_node->value){
                min_node = tree;
            }
        }
    }

    void decrease_key(Node* node, int new_value){
        if (new_value > node->value)
        {
            throw invalid_argument("New value is greater than the current value");
        }
        node->value = new_value;
        _bubble_up(node);
    }

    void delete_node(Node* node){
        decrease_key(node, get_min());
        extract_min();
    }

    void _bubble_up(Node* node) {
        Node* parent  = node->parent;
        while (parent!=nullptr && node->value < parent->value)
        {
            swap(node->value,parent->value);
            node = parent;
            parent = node->parent;
        }
        
    }

    void _link(Node* tree1,Node* tree2){
        if (tree1->value > tree2->value)
        {
            swap(tree1,tree2);
        }
        tree2->parent = tree1;
        tree1->children.push_back(tree2);
        tree1->degree++;
    }

    void _consolidate() {
        int max_degree = static_cast<int>(floor(log2(count)))+1;
        vector<Node*> degree_to_tree(max_degree + 1, nullptr);

        while (!trees.empty())
        {
            Node* current = trees[0];
            trees.erase(trees.begin());
            int degree = current->degree;
            while (degree_to_tree[degree]!=nullptr)
            {
                Node* other = degree_to_tree[degree];
                degree_to_tree[degree] = nullptr;
                if (current->value < other->value)
                {
                    _link(current,other);
                } else {
                    _link(other, current);
                    current = other;
                }
                degree++;
            }
            degree_to_tree[degree] = current;
        }

        min_node = nullptr;
        trees.clear();
        for (Node* tree : degree_to_tree)
        {
            if(tree != nullptr){
                trees.push_back(tree);
                if (min_node == nullptr || tree->value < min_node->value)
                {
                    min_node = tree;
                }
            }
        }
    }

    int size() {
        return count;
    }
};

int main(){
    BinomialHeap heap;
    for (size_t i = 0; i < 10; i++)
    {
        heap.insert(i);
    }
    heap._consolidate();

    std::cout << "Hello\n";
}