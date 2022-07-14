#include <iostream>
using namespace std;

struct node
{
    int value;
    node *right,*left;
};

class traverse
{
public:
    node *root;
    traverse(/* args */);
    void pre_traversal(int value,node *temp);
};

traverse::traverse(/* args */)
{
    root=NULL;
}

void traverse::pre_traversal(int value,node *temp)
{
    if(root==NULL)
        return;
    cout<<temp->value<<endl;
    if(temp->left!=NULL)
        pre_traversal(value,temp->left);
    if(temp->right!=NULL)
        pre_traversal(value,temp->right);
}

int main()
{
    traverse t;
    t.pre_traversal(5,t.root);
    t.pre_traversal(4,t.root);
    t.pre_traversal(6,t.root);
    return 0;
}