// By refrence pointer passing see in line 26
#include <iostream>
using namespace std;


struct node
{
    int value;
    node *right,*left;
};

class trees_1
{
public:
    node *root;
    
    trees_1()
    {
        root=NULL;
    }

    //case LL Rotation
    void Left_Left(node *&temp)
    {
        node *temp2=temp->left;
        temp->left=temp2->right;
        temp2->right=temp;
        temp=temp2;
    }

    void right_right(node *&temp)
    {
        node *temp2=temp->right;
        temp->right=temp2->left;
        temp2->left=temp;
        temp=temp2;
    }
    //------------BalanceFactor
    int balance_Fact(node *point)
    {
        int left=0;
        int right=0;
        if(point!=NULL)
        {
            if (point->left!=NULL)
            {
                left=maxDepth(point->left);
            }
            if (point->right!=NULL)
            {
                right=maxDepth(point->right);
            }
        }
        return left-right;
    }

    void insertion(int key, node *&temp)
    {
        if(temp==NULL)
        {
            temp=new node;
            temp->value=key;
            temp->right=NULL;
            temp->left=NULL;
            if(root==NULL)
            {
                root=temp;
            }
            return;
        }
        //Duplication check
        if(temp->value==key)
        {
            cout<<"Duplication not Allowed in BST!\n";
            return;
        }
        if(temp->value > key)
        {
            return(insertion(key,temp->left));
        }
        if(temp->value < key)
        {
            return(insertion(key,temp->right));
        }

        //------------AVL next part for rotation wagara
        int balance=balance_Fact(*&temp);
        if(balance==2)
        {
            if(key<temp->left->value)
            {
                //LL rotation
                Left_Left(temp);
                cout<<"After Left_Left case Balance Factor of tree "<<balance_Fact(root)<<endl;
            }
            else
            {
                //LR rotation
                Left_Left(temp->left);
                right_right(temp);
            }
        }
        if(balance==-2)
        {
            if(key<temp->right->value)
            {
                //RR rotation
                right_right(temp);
            }
            else
            {
                //RL rotation
                right_right(temp->right);
                Left_Left(temp);
            }
        }

    }

    int maxDepth(node* node)
    {
        if (node == NULL)
            return 0;
        else
        {
            int left=maxDepth(node->left);
            int right=maxDepth(node->right);
            
            if(left>right)
            {
                return left+1;
            }
            else
                return right+1;
        }
    }



};
int main()
{
    trees_1 t;
    t.insertion(50,t.root);
    t.insertion(40,t.root);
    t.insertion(65,t.root);
    t.insertion(45,t.root);
    t.insertion(30,t.root);
    t.insertion(35,t.root);
    t.insertion(20,t.root);
    t.insertion(10,t.root);
    cout<<"Balance Factor of tree "<<t.balance_Fact(t.root)<<endl;
    cout<<"MaxDepth of tree "<<t.maxDepth(t.root)<<endl;
    return 0;
}