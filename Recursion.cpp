//loops k kam ko fuction k through karna recusion kehlata hai
//"Base  case"--> the condtion at which function stops 
//recursion k andar static,global,loops nai use karny
//see in tutor
//jab yeah apni excicuiton 10 tak complete karta hai to line 13  ki condion true ho jay gi to yeah dobara line 23 py aa jay ga ---------------------
//forward for example for 10 value it will print 1 to 10 numbers
//backward  for example for 10 value it will print 10 to 1 numbers
//forward and backword will be at a time according to bellow code line 22 ki waja sy

// #include <iostream>
// #include <string>
// using namespace std;

// void function(int i =1)
// {
//     cout<<i<<" ";
//     if(i==10)
//     {
//        return;
//     }
//     function(i+1);
//     cout<<i<<" ";
// }

// int main()
// {
//     function();
//     return 0;
// }

//------------------------------
//print table
// #include <iostream>
// #include <string>
// using namespace std;

// void function(int i =1)
// {
//     cout<<"2"<<" "<<" * "<<i<<" = "<<i*2<<endl;
//     if(i==10)
//     {
//        return;
//     }
//     function(i+1);
// }

// int main()
// {
//     function();
//     return 0;
// }
//---------------------------------
//find factorial --------? do yourself
// #include <iostream>
// using namespace std;

// void function(int i =4)
// {
//     cout<<"4"<<"!"<<" = "<<4*i<<endl;
//     if(i==0)
//     {
//        return;
//     }
//     function(i-1);
// }

// int main()
// {
//     function();
//     return 0;
// }
//------------------------------------
//Hum aik array pass karain gay gay us k mid say koi val b dain gay hmain wo value us sy agay ki phir us say phishay ki value ko print karna ho ga
//Do yourself
#include <iostream>
using namespace std;

void function(int *start,int *pointer,int *stop)
{
   cout<<*p<<endl;
   if(p==stop)
   {
       return;

   }
   myfun++(p,start,stop);
   if(p==start-1)
   {
       return;
   }
   myfun(--p,start,stop);
}

int main()
{
    int A[]={1,2,3,4,5,6,7};

    function(A,&A[3],A);
    return 0;
}
