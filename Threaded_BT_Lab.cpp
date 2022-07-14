#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;
    bool leftbit;   //leftbit=0 ->thread    leftbit=1 ->Child
    bool rightbit;  //rightbit=0 ->thread    rightbit=1 ->Child
};


class threaded
{
public:
    Node *root;
    Node *ptr,*n,*dummy,*temp;
    threaded()
    {
        root=NULL;
        ptr,temp,dummy=NULL;
        dummy=new Node;
        dummy->right=dummy->left;    //Child
        dummy->left=dummy->right;     //Thread
        dummy->leftbit=0;
        dummy->rightbit=1;
    }

    void Insertion(int key,Node *temp)
    {
        if(root==NULL)
        {
            root=new Node;
            temp=root;
            root->value=key;
            root->left=dummy->left;
            root->right=dummy->right;
            root->rightbit=0;
            root->leftbit=0;
            return;
        }
        if(temp->value==key)
        {
            cout<<"Duplication not allowed!\n";
            return;
        }
        if(key<temp->value)
        {
            if(temp->leftbit==0)
            {
                n=new Node;
                n->value=key;
                n->left=temp->left;
                n->leftbit=temp->leftbit;
                n->right=temp;
                n->rightbit=0;
                temp->left=n;
                temp->leftbit=1;
                return;
            }
            else
            {
                Insertion(key,temp->left);
            }

        }

        if(key>temp->value)
        {
            if(temp->rightbit==0)
            {
                n=new Node;
                n->value=key;
                n->right=temp->right;
                n->rightbit=temp->rightbit;
                n->left=temp;
                temp->rightbit=0;
                temp->left=n;
                temp->rightbit=1;
            }
        }
        

    }

    //Deletion 
    void Delete(int key, Node *temp)
    {
        if(root==NULL)
        {
            cout<<"Tree is empty!\n";
            return;
        }
        if(temp->left->value==key)
        {
            Delete_Node(temp->left,temp);
            return;
        }
        if((temp!=dummy)&&(temp->right->value==key))
        {
            Delete_Node(temp->right,temp);
            return;
        }
        if(temp==dummy)
        {
            Delete(key,temp->left);
            return;
        }
        if((key>temp->value)&&(temp->rightbit==1))
        {
            Delete(key,temp->right);
            return;
        }
        if((key<temp->value)&&(temp->rightbit==1))
        {
            Delete(key,temp->left);
            return;
        }
        cout<<"Value doesn't exist!\n";
        return;
    }


    //find_successor
    Node *find_successor(Node *temp,Node *&parent)
    {
        if(temp->leftbit==0)
        {
            return temp;
        }
        parent = temp;
        return find_successor(temp->left,parent);
    }

    //Deletion_Node
    void Delete_Node(Node *temp,Node *parent)
    {
        if(temp->leftbit==1 && temp->rightbit==1)//1st condition
        {
            Node *successor_parent=temp;
            Node *successor=find_successor(temp->right, successor_parent);
            temp->value=successor->value;
            Delete_Node(successor,successor_parent);
            return;
        }
        if(temp->leftbit==1 && temp->rightbit==0)//2nd condition
        {
            if(temp->value<parent->value)
            {
                parent->left=temp->left;
                parent->leftbit=temp->leftbit;
            }
            else
            {
                parent->right=temp->left;
                parent->rightbit=temp->leftbit;
            }
            Node *temp2=temp->left;
            while(temp2->rightbit!=0)
            {
                temp2=temp2->right;
            }
            temp2->right=temp->right;
            delete temp;
            return ;
        }

        if(temp->rightbit==1 && temp->leftbit==0)//3rd condition
        {
            if(temp->value < parent->value)
            {
                parent->right=temp->right;
                parent->rightbit=temp->rightbit;
            }
            else
            {
                parent->left=temp->right;
                parent->leftbit=temp->rightbit;
            }
            Node *temp2=temp->right;
            while(temp2->leftbit!=0)
            {
                temp2=temp2->left;
            }
            temp2->left=temp->left;
            delete temp;
            return ;
        }


        if(temp->leftbit==0 && temp->rightbit==0)  //4th condition
        {
            if(parent->left==temp)
            {
                parent->left=temp->left;
                parent->leftbit=0;
            }
            if(parent->right==temp && parent !=dummy)
            {
                parent->right=temp->right;
                parent->rightbit=0;
            }
        }
        if(temp==root)
        {
            root=NULL;
            dummy->left=dummy;
            dummy->leftbit=0;
        }
        delete temp;
    }

    void Inorder(Node *n)
    {
         if(root != NULL)
        {
            cout<<n->value<<" ";
            Inorder(n->left);
            Inorder(n->right);
        }
    }
};


int main()
{
    threaded t;

    t.Insertion(61,t.root);
    t.Insertion(50,t.root);
    t.Insertion(45,t.root);
    t.Insertion(40,t.root);
    t.Insertion(51,t.root);
    t.Insertion(10,t.root);
    // t.Inorder(t.root);
}
