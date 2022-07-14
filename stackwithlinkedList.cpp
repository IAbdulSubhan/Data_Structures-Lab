#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class stacklink
{
private:
    node *top,*temp,*newnode;
    int limit,count;
public:
    stacklink(/* args */);
    void Push();
    void Pop();
    void Top();
    void Print();
};

stacklink::stacklink()
{
    newnode=top=temp=NULL;
    count=0;
    cout<<"Enter the limit: ";
    cin >> limit;
}

void stacklink::Push()
{
    if(count==limit)
    {
        cout<<"Stack Overflow.\n";
    }
    else
    {
        newnode=new node;
        cout<<"Enter the value: ";
        cin >> newnode->data;
        newnode->next=top;
        top=newnode;
        count++;
    }
}

void stacklink::Pop()
{
    if(top==NULL)
    cout<<"Stack overflow.\n";
    else
    {
        temp=top;
        top=top->next;
        delete temp;
    }
}

void stacklink::Top()
{
    cout<<"The Top element is  "<<(top->data)<<endl;
}

void stacklink::Print()
{
    temp=top;
    cout<<"Values are: ";
    while (temp!=0)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
}


int main()
{
    stacklink st;
    st.Push();
    st.Push();
    st.Pop();
    st.Push();
    st.Push();
    st.Pop();
    st.Push();
    st.Push();
    st.Pop();
    st.Print();
    cout<<endl;
    st.Top();
    return 0;
}