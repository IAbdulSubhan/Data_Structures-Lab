#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};

class stk_link
{
private:
    node *top,*temp;
public:
    stk_link(/* args */);
    void push();
    void pop();
    void print();
};

stk_link::stk_link(/* args */)
{
    temp=top=NULL;
}

void stk_link::push()
{
    if(top==NULL)
    {
        top=new node;
        cout<<"Enter the value: ";
        cin >> top->data;
        top->next=NULL;
    }
    else
    {
        temp=new node;
        cout<<"Enter the value: ";
        cin >> temp->data;
        temp->next=top;
        top=temp;

    }
}

void stk_link::pop()
{
    if(top==NULL)
    {
        cout<<"Stack Overflow.\n";
    }
    else
    {
        temp=top;
        top=top->next;
        delete temp;
        temp=NULL;
    }
}

void stk_link::print()
{
    temp=top;
    
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
        pop();
    }
    pop();
    
}

int main()
{
    stk_link st;
    st.push();
    st.push();
    st.pop();
    st.push();
    st.push();
    st.pop();
    st.print();
    cout<<endl;
    st.pop();
    return 0;
}