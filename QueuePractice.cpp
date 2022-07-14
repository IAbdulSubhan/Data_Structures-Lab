#include <iostream>
using namespace std;

class Queue
{
private:
    int *queue,*front,*rear,*temp,value,size;
public:
    Queue(/* args */);
    void Enqueue(int);
    void Dequeue();
     void Display();
};

Queue::Queue()
{
    front=rear=temp=NULL;
    size=5;
    queue = new int[size];
    for(int i=0; i<size; i++)
    {
        *(queue+i)=0;
    }
}

void Queue::Enqueue(int val)
{
    value=val;
    if(rear==queue+(size-1))
        cout<<"Queue Overflow!\n";
    else if(front==NULL && rear==NULL)
    {
        rear=front=queue;
        *rear=value;
    }
    else
    {
        rear++;
        *rear=value;
    }
}

void Queue::Dequeue()
{
    if(front==NULL && rear==NULL)
        cout<<"Queue Underflow!\n";
    else if(front==rear)
        front=rear=NULL;
    else
        front++;
}

void Queue::Display()
{
    
    int i,counter,start,cond=0;         //start --> to start the loop, cond--> ending the loop condtion
    if(front==NULL && rear==NULL)
        cout<<"Queue is Empty!\n";
    else
    {
        while (i<size)
        {
            if(*(queue+i)==*front)
                start=counter;
            if(*(queue+i)==*rear)
                cond=counter;

                i++;
                counter++;

        }
        cout<<"Values are: \n";
        for(i=start; i<cond+1; i++)
        {
            cout<<*(queue+i)<<" ";
        }
        cout<<endl;
    }
}

int main(){
    Queue q;
    q.Enqueue(8);
    q.Enqueue(7);
    q.Dequeue();
    q.Enqueue(9);
    q.Enqueue(8);
    q.Enqueue(7);
    q.Enqueue(6);
    q.Enqueue(5);
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Display();


}
