#include <iostream>
using namespace std;

class Stack
{
private:
    int *top,*temp,*stack;
    int count,limit;

public:
    Stack();
    void Push();
    void Pop();
    // void Top();
    void Print();
};

Stack::Stack(/* args */)
{
    temp=NULL;
    count=0;
    cout<<"Enter the limit of Stack!  ";
    cin >> limit;
    
    stack=new int[limit];
    top=stack;
    for(int i=0;i<limit;i++)
    {
        *(stack+i)=0;
    }
    
}

void Stack::Push()
{
    if(count==limit)
    cout<<"Stack Overflow.\n";
    else if(count == 0)
    {
        cin >> *(top);
        count++;
    }
    else
    {
        top++;
        cin >> *(top);
        count++;
    }
}

void Stack::Pop()
{
    if(top==NULL)
    cout<<"Stack Overflow.\n";
    else
    {
        // *(top)=0;
        top--;
        count--;
    }
}

// void Stack::Top()
// {
//     cout<<"Top Element in Stack = "<<*top<<endl;
// }

void Stack::Print()
{
    temp=top;
    cout<<"Elements in Stack is \n";
    for(int i=(count-1);i>=0;i--)
    {
        cout<<*(stack+i)<<" ";
    }
    cout<<endl;
}






int main()
{
    Stack st;
    st.Push();
    st.Push();
    // st.pop();
    st.Push();
    st.Push();
    st.Pop();
    st.Print();
    return 0;
}