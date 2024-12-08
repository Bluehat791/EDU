#include<algorithm>
#include<iostream>

using namespace std;

template <typename T>
class AVLNode
{
public:
    T key;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(T k)
        : key(k), left(nullptr),right(nullptr), height(1)
        {}    
};

template <typename T>
class AVLTree
{
private:

    AVLNode<T>* root;

    int height(AVLNode<T>* node)
    {
        if(node == nullptr)
            return 0;
        return node->height;
    }

    int balanceFactor(AVLNode<T>* node)
    {
        if(node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    AVLNode<T>* rightRotate(AVLNode<T>* y)
    {
        AVLNode<T>* x = y->left;
        AVLNode<T>* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left),height(y->right))+1;
        x->height = max(height(x->left),height(x->right))+1;

        return x;
    }

    AVLNode<T>* leftRotate(AVLNode<T>* x)
    {
        AVLNode<T>* y = x->right;
        AVLNode<T>* T2 = y->left;

        y->left = x;
        x->right = T2;

        y->height = max(height(y->left),height(y->right))+1;
        x->height = max(height(x->left),height(x->right))+1;

        return y;
    }

    AVLNode<T>* insert(AVLNode<T>* node, T key)
    {
        if(node == nullptr)
            return new AVLNode<T>(key);

        if(key<node->key)
            node->left = insert(node->left,key);
        else if (key>node->key)
            node->right = insert(node->right,key);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        if (balance > 1 && key < node->left->key)
        {
            return rightRotate(node);
        }
        if (balance < -1 && key > node->right->key)
        {
            return leftRotate(node);
        }

        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        
        return node;    
    }

    AVLNode<T>* minValueNode(AVLNode<T>* node)
    {
        AVLNode<T>* current = node;
        while(current->left != nullptr)
            current = current->left;
        return current;
    }

    AVLNode<T>* deleteNode(AVLNode<T>* root, T key)
    {
        if (root == nullptr)
        {
            return root;
        }

        if (key < root->key)
        {
            root->left= deleteNode(root->left,key);
        } else if (key > root->key)
            root->right = deleteNode(root->right,key);
        else {
            if ((root->left == nullptr)||(root->right == nullptr))
            {
                AVLNode<T>* temp = root->left ? root->left : root->right;

                if (temp == nullptr)
                {
                    temp = root;
                    root = nullptr;
                }
                else
                    *root = *temp;
                delete temp;
            }
            else {

                AVLNode<T>* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right,temp->key);
            }
            
        }
        
        
        if(root == nullptr)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = balanceFactor(root);


        if (balance > 1 && balanceFactor(root->left) >= 0)
        {
            return rightRotate(root);
        }

        if (balance > 1 && balanceFactor(root->left)<0)
        {
            root->left = leftRotate(root);
            return rightRotate(root);
        }

        if (balance < -1 && balanceFactor(root->right) <= 0)
        {
            return leftRotate(root);
        }

        if (balance < -1 && balanceFactor(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        
        return root;
    }

    void inorder(AVLNode<T>* root)
    {
        if (root!=nullptr)
        {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }

    bool search(AVLNode<T>* root, T key)
    {
        if (root==nullptr)
        {
            return false;
        }
        if (root->key == key)
        {
            return true;
        }
        if (key<root->key)
        {
            return search(root->left, key);
        }
        return search(root->right, key);
        
    }

public:

    AVLTree() : root(nullptr)
    {}

    void insert(T key) {
        root = insert(root,key);
    }

    void remove(T key) {
        root = deleteNode(root,key);
    }

    bool search(T key){
        return search(root,key);
    }

    void printInorder() {
        inorder(root);
        cout << endl;
    }
};



int main()
{
    AVLTree<int> avl;

    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    cout << "Inorder traversal of the AVL tree: ";
    avl.printInorder();

    avl.remove(30);
    cout << "Inorder traversal after removing 30: ";
    avl.printInorder();

    cout << "Is 25 on the tree? " << (avl.search(25)? "Yes" : "No") << endl;
    cout << "Is 30 on the tree? " << (avl.search(30)? "Yes" : "No") << endl;

    return 0;
}