#include <iostream>
using namespace std;

void myFun(int &myInt)
{
    myInt = myInt+1;
    cout<<"Value of myInt is:     "<<myInt<<endl;
}
int main()
{
    // int var;
    // var=12;
    // cout<<"Value stored in var:          "<<var<<endl;
    // cout<<"Address of var:          "<<&var<<endl;
    // int *ptr = nullptr;
    // cout<<"Address of pointer:  "<<&ptr<<endl;
    // ptr=&var;
    // cout<<"Address stored in pointer:    "<<ptr<<endl;


    // myFun(var);
    //----------------------------------------
    //task1-below------
    char var;
    var='S';
    char *chptr;
    chptr=nullptr;
    chptr=&var;
    cout<<"Value stored in Char variable: "<<var<<endl;
    cout<<"Address of var:   "<<&var<<endl;//here problem is it treat the char var as char array not as var solution is below this is type casting
    cout<<"Address of var:   "<<(void *)&var<<endl;
    cout<<"Address stored in pointer:    "<<(void *)chptr<<endl;
    cout<<"Address of pointer:  "<<&chptr<<endl;
    cout<<"Value refer by pointer: "<<*chptr<<endl;
    //------------------------------------------






    return 0;
}