#include <iostream>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};
class AVL
{
    public:
    Node * Root=nullptr;
    int Height(Node *n)
    {
        if(n==NULL)
            return 0;
        return n->height;
    }
    
    struct Node *create_Node(int key){
        struct Node* node = new Node;
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;
        return node;
    }
    
    
    int Balance_factor(Node * n){
        if(n==NULL){
            return 0;
        }
        return Height(n->left) - Height(n->right);
    }
    
    struct Node* rightRotate(struct Node* n){
        struct Node* temp2 = n->left;
        struct Node* temp = temp2->right;
    
        temp2->right = n;
        n->left = temp;
    
        temp2->height = (Height(temp2->right), Height(temp2->left)) + 1;
        n->height = (Height(n->right), Height(n->left)) + 1;
    
        return temp2;
    }
    
    struct Node* leftRotate(Node* temp2){
        struct Node* n = temp2->right;
        struct Node* temp = n->left;
    
        n->left = temp2;
        temp2->right = temp;
    
        temp2->height =(Height(temp2->right), Height(temp2->left)) + 1;
        n->height =(Height(n->right), Height(n->left)) + 1;
    
        return n;
    }
    
    struct Node *insert(Node* node, int key){
        if (node == NULL)
            return  create_Node(key);
    
        if (key < node->key)
            node->left  = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
    
        node->height = 1 + (Height(node->left), Height(node->right));
        int balance_fact = Balance_factor(node);
    
        // Left Left Case
            if(balance_fact>1 && key < node->left->key){
                return rightRotate(node);
            }
        // Right Right Case
            if(balance_fact<-1 && key > node->right->key){
                return leftRotate(node);
            }
        // Left Right Case
        if(balance_fact>1 && key > node->left->key){
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        // Right Left Case
        if(balance_fact<-1 && key < node->right->key){
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        return node;
    }
    
    void preOrder(Node *Root)
    {
        if(Root != NULL)
        {
            cout<<Root->key<<" ";
            preOrder(Root->left);
            preOrder(Root->right);
        }
    }
};
int main(){

    AVL a;
    a.Root=a.insert(a.Root,13);
	a.Root=a.insert(a.Root,10);
	a.Root=a.insert(a.Root,24);
	a.Root=a.insert(a.Root,7);
	a.Root=a.insert(a.Root,20);
	a.Root=a.insert(a.Root,30);
	a.Root=a.insert(a.Root,15);
	a.Root=a.insert(a.Root,25);
	a.Root=a.insert(a.Root,36);
    a.preOrder(a.Root);
	cout<<endl;
	cout<<"BalanceFactor "<<a.Balance_factor(a.Root)<<endl;
    return 0;
}
