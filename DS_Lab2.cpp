/*                                                      //See all in python tutor
// more pointers
#include <iostream>
using namespace std;
int main ()
{
 int firstvalue = 5, secondvalue = 15;
 int * p1, * p2;
 p1 = &firstvalue; // p1 = address of firstvalue
 p2 = &secondvalue; // p2 = address of secondvalue
 *p1 = 10; // value pointed to by p1 = 10
 *p2 = *p1; // value pointed to by p2 = value pointed to by p1
 p1 = p2; // p1 = p2 (value of pointer is copied)
 *p1 = 20; // value pointed to by p1 = 20

 cout << "firstvalue is " << firstvalue << '\n';
 cout << "secondvalue is " << secondvalue << '\n';
 return 0;
}
-----------------------------------------------------------------------
*/
/*
// more pointers
#include <iostream>
using namespace std;
int main ()
{
    int numbers[5];
    int * p;
    p = numbers;
    *p = 10;
    p++; 
    *p = 20;
    p = &numbers[2]; *p = 30;
    p = numbers + 3; *p = 40;   //here number have base address  give address and add the 3 in it it goes on 4th
    p = numbers; *(p+4) = 50;
    for (int n=0; n<5; n++)
        cout << numbers[n] << ", ";
    return 0;
}
---------------------------------------
*/
//See all in python tutor
// more pointers
// #include <iostream>
// using namespace std;
// int main ()
// {
//     int numbers[]={1,2,4,5};
//     int *p=numbers;

//     cout<<*p++<<endl;   //yaha pehly pointer p value return kary ga phir agly index py chla jay ga
//     cout<<*++p<<endl;   //yaha pehly agly index py chala jay ga phir waha ki value day ga 
//     cout<<++*p<<endl;   //ab jis index py p hai waha wo increment kary ga phir value chow kary ga
//     cout<<(*p)++<<endl; //ab yaha phir p waha ki value ko show karay ga or us mn increament kary ga

//     return 0;
// }
//-----------------------------------------

// #include <iostream>
// using namespace std;
// int main ()
// {
//     int a[]={1,2,4,5};
//     int b[]={1,2,4,5};

//     int *p = a;
//     int *q = b;

//     cout<<*p<<endl;
//     cout<<*q<<endl;

//     *p++=*q++;

//     cout<<*p<<endl;
//     cout<<*q<<endl;

//     //-------------------see the change pre increament and uper post increament
//     cout<<"--------------\n";
//     *++p=*++q;

//     cout<<*p<<endl;
//     cout<<*q<<endl;
    

//     return 0;
// }

//-----------------------------------------------------

// // // pointers as arguments:
// #include <iostream>
// using namespace std;
// void increment_all (int* start, int* stop)
// {
//     int * current = start;       //new pointer bnany ka maqasad pehly index ka adress ko apny pass maintain rakhny k liya agar naya pointer na bnay to start pointer agay jata jay ga phir first elememt k address ko access ni kar paiy gay
//     while (current != stop) 
//     {
//     ++(*current); // increment value pointed
//     ++current; // increment pointer
//     }
// }
// void print_all (const int* start, const int* stop)       //const pointer ka mtlb agar hum ny aik ponter ko aik jaga point krwa diya wo wahi sirf point kary ga us k address change ni ho sakta
// //agar int *ptr=const &x  is trha ki statement mn ku k vlaue contant hai wo pointer ko sirf readable ho gai wo change ni ho sakti
// {
//     const int * current = start;
//     while (current != stop)
//     {
//     cout << *current << '\n';
//     ++current; // increment pointer
//     }
// }
// int main ()
// {
//     int numbers[] = {10,20,30};
//     increment_all (numbers,numbers+3);
//     print_all (numbers,numbers+3);
//     return 0;;
// }

//--------------------------------------------------------------

// #include <iostream>
// using namespace std;

// int main()
// {
//     //do practise apply the statements
//     int x=5;
//     int * p1 = &x; // non-const pointer to non-const int
//     cout<<++(*p1)<<endl;
//     //int x=6;
//     const int * p2 = &x; // non-const pointer to const int
//     cout<<++(*p1)<<endl;
//     int * const p3 = &x; // const pointer to non-const int
//     const int * const p4 = &x; // const pointer to const int
// }

//----------------------------------------------------------

// #include <iostream>
// using namespace std;

// int main()
// {
//     int x=6;
//     const int * p2a = &x; // non-const pointer to const int
//     int const * p2b = &x; // also non-const pointer to const int
// }
//--------------------------------------------
//page 14 read do yourself
//------------------------------------------




