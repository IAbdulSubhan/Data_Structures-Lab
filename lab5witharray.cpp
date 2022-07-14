#include <iostream>
using namespace std;

class stk_array
{
private:
    int *top,*stack;
    int size,count;
public:
    stk_array(/* args */);
    void push();
    void pop();
    void print();
};

stk_array::stk_array(/* args */)
{
    top=nullptr;
    count=0;
    cout<<"Enter the size of the stack: ";
    cin >> size;
    stack=new int[size];
}

void stk_array::push()
{
    if(count==size)
    {
        cout<<"Stack Overflow.\n";
    }
    else if(count==0)
    {
        top=stack;
        cout<<"Enter the value: ";
        cin >> *top;
        count++;
    }
    else
    {
        top++;
        cout<<"Enter the value: ";
        cin >> *top;
        count++;
    }
}

void stk_array::pop()
{
    if(top==nullptr)
    {
        cout<<"Stack Overflow.\n";
    }
    else
    {
        top--;
        count--;
    }
}

void stk_array::print()
{
    cout<<"Values in Stack are: ";
    while(top!=NULL)
    {
        cout<<*(top)<<" ";
    }
}
int main()
{
    stk_array st;
    st.push();
    st.push();
    st.pop();
    st.push();
    st.push();
    st.pop();
    st.print();
    cout<<"\n";
    return 0;
}