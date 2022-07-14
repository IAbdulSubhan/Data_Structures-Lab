#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};
class BST
{
    public:
        struct node* createNode(int data){
        struct node *n; // creating a node pointer
        n = new node; // Allocating memory in the heap
        n->data = data; // Setting the data
        n->left = NULL; // Setting the left and right children to NULL
        n->right = NULL; // Setting the left and right children to NULL
        return n; // Finally returning the created node
    }
    
    void preOrder(struct  node* root){
        if(root!=NULL){
            cout<<root->data;
            preOrder(root->left);
            preOrder(root->right);
        }
    }
    
    void postOrder(struct  node* root){
        if(root!=NULL){
            postOrder(root->left);
            postOrder(root->right);
            cout<<" "<<root->data;
        }
    }
    
    void inOrder(struct  node* root){
        if(root!=NULL){
            inOrder(root->left);
            cout<<" "<<root->data;
            inOrder(root->right);
        }
    }
    
    int isBST(struct  node* root){
        static struct node *prev = NULL;
        if(root!=NULL){
            if(!isBST(root->left)){
                return 0;
            }
            if(prev!=NULL && root->data <= prev->data){
                return 0;
            }
            prev = root;
            return isBST(root->right);
        }
        else{
            return 1;
        }
    }
    
    struct node * searchIter(struct node* root, int key){
        while(root!=NULL){
            if(key == root->data){
                return root;
            }
            else if(key<root->data){
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        return NULL;
    }
    
    void insert(struct node *root, int key){
        struct node *prev = NULL;
        while(root!=NULL){
            prev = root;
            if(key==root->data){
                cout<<"Cannot insert already in BST"<< key;
                return;
            }
            else if(key<root->data){
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        struct node* New = createNode(key);
        if(key<prev->data){
            prev->left = New;
        }
        else{
            prev->right = New;
        }
    }

    struct node *inOrderPredecessor(struct node* root){
        root = root->left;
        while (root->right!=NULL)
        {
            root = root->right;
        }
        return root;
    }

    struct node *deleteNode(struct node *root, int value){

        struct node* iPre;
        if (root == NULL){
            return NULL;
        }
        if (root->left==NULL&&root->right==NULL){
            free(root);
            return NULL;
        }

        //searching for the node to be deleted
        if (value < root->data){
            root-> left = deleteNode(root->left,value);
        }
        else if (value > root->data){
            root-> right = deleteNode(root->right,value);
        }
        //deletion strategy when the node is found
        else{
            iPre = inOrderPredecessor(root);
            root->data = iPre->data;
            root->left = deleteNode(root->left, iPre->data);
        }
        return root;
    }

    //-----------------
    // A function to search item in a BST.
    void DepthSearch(node *root, int data)
    {
        int depth = 0;
        node *temp;
        temp = root;
        // Run the loop untill temp points to a NULL pointer.
        while(temp != NULL)
        {
            depth++;
            if(temp->data == data)
            {
                cout<<"\nData found at depth: "<<depth;
                return;
            }
            // Shift pointer to left child.
            else if(temp->data > data)
                temp = temp->left;
            // Shift pointer to right child.
            else
                temp = temp->right;
        }
    
        cout<<"\n Data not found";
        return;
    }
    
        

};

int main(){
    BST b1;
    // Constructing the root node - Using Function (Recommended)
    struct node *p = b1.createNode(9);
    struct node *p1 = b1.createNode(3);
    struct node *p2 = b1.createNode(6);
    struct node *p3 = b1.createNode(1);
    struct node *p4 = b1.createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  
 
    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    b1.inOrder(p);
    cout<<"\n";
    b1.DepthSearch(p,6);
    cout<<"\n";
    b1.deleteNode(p, 9);
    cout<<"After DeleteNode:  ";
    b1.inOrder(p);
    cout<<endl;

    return 0;
}