#include <iostream>
using namespace std;

class Queue
{
private:
    int *que,*front,*rear,*temp,size,value;
public:
    Queue(/* args */);
    void EnQueue(int);
    void DeQueue();
    void Print();
};

Queue::Queue(/* args */)
{
    size=4;
    que = new int[size];
    for(int i=0;i<size;i++)
    {
        *(que+i)=0;
    }
    front=rear=NULL;
    return;
}

void Queue::EnQueue(int val)
{
    value=val;
    if(front==NULL && rear==NULL)
    {
        front=que;
        rear=que;
        temp=que;
        *rear=value;
        return;
    }
    else if((rear!=(que+(size-1)) && rear+1!=front) )
    {
        rear++;
        *rear=value;
        return;
    }
    else if(rear==que+(size-1)&& front!=que)
    {
        rear=que;
        *rear=val;
        return;
    }
    else
    {
        cout<<"Queue Overflow!\n";
        return;
    }
}

void Queue::DeQueue()
{
    if(front==NULL && rear==NULL)
        cout<<"Queue Underflow!\n";
    else if(front==rear)
        front=rear=NULL;
    else if(front == que+(size-1))
        front=que;
    else
        front++;
}

void Queue::Print()
{
    temp=que;
    cout<<"Output = ";
    if(front==NULL && rear==NULL)
    {
        cout<<"Empty\n";
    }
    else
    {
      for(int i=0;i<size;i++)
      {
        cout<<*(temp+i)<<" ";
      }
        // while(temp!=rear)
        // {
        //     cout<<*temp<<" ";
        //     temp++;
        // }
        // cout<<*temp<<" ";
        cout<<"\n";
    }
}
int main(){
    Queue q;
    q.DeQueue();
    q.EnQueue(8);
    q.DeQueue();
    q.EnQueue(7);
    q.EnQueue(9);
    q.EnQueue(8);
    q.EnQueue(7);
    q.EnQueue(6);
    q.DeQueue();
    q.DeQueue();
    q.EnQueue(5);
    q.Print();


}

