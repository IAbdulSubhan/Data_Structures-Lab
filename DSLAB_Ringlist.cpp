#include <iostream>
using namespace std;

struct Node
{
    int Value;
    Node *Next;
    Node *prev;
};

class DoubleRing
{
    private:
        Node *head;
        Node *newnode;
        Node *tail;
    public:
        DoubleRing()
        {
            head=newnode=tail=NULL;
        }
        void insert();
        void insert_aft_val();
        void show();
        void delete_vals();
};
void DoubleRing::insert()
{
    if(head==NULL)
    {
        newnode=new Node;
        cout<<"Enter a value: ";
        cin >> newnode->Value;
        newnode->Next=newnode;
        newnode->prev=newnode;
        head=tail=newnode;
    }
    else
    {
        newnode=new Node;
        cout<<"Enter a value: ";
        cin >> newnode->Value;
        newnode->prev=tail;
        tail->Next=newnode;
        //----------
        newnode->Next=head->prev;
        head->prev=newnode;
        tail=newnode;
        free(newnode);
    }
}


void DoubleRing::insert_aft_val()
{
    int myval;
    head=tail;
    cout<<"Enter the value after which node enter: ";
    cin >>  myval;
    if(tail->Next==head->prev)
        {
            newnode=new Node;
            cout<<"Enter a value: ";
            cin >> newnode->Value;
            newnode->prev=tail;
            tail->Next=newnode;
            //----------
            newnode->Next=head;
            head->prev=newnode;
            tail=newnode;
        }

    else
    
    {
        while(tail->Value!=myval)
        {
            {
                newnode=new Node;
                cout<<"Enter a value: ";
                cin >> newnode->Value;
                newnode->Next=tail->Next;
                newnode->Next->prev=newnode;
                tail->Next=newnode;
                newnode->prev=tail;


            }
            tail=tail->Next;
        }
    }
    

}

void DoubleRing::show()
{
    cout<<"values are: ";
    newnode=head;
    while(newnode->Next!=head)
    {
        cout<<newnode->Value<<" ";
        newnode=newnode->Next;
    }
    cout<<newnode->Value;
}



int main()
{
    DoubleRing obj1;
    obj1.insert();
    obj1.insert_aft_val();
    obj1.insert_aft_val();
    obj1.show();
    cout<<"\n";


    return 0;
}