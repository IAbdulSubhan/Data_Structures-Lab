//6 libraries

#include <iostream>              // for input output
// for file opening and closing
#include <fstream>
//for setw function
#include <iomanip>
// for flush all that is to clear the buffer memmory
#include <stdio.h>
//for getch function
// #include <conio.h>
//for use system function for clearing the screen
#include <stdlib.h>
using namespace std;

// Phonebook class
class phonebook
{
private:
    int code;
    char name[15];
    long int phone_no;

public:
    void get_person(void);
    void put_person(void);
    int get_code(void)
    {
        return code;
    }

void update_phoneno(int num)  // internal function for update/modify phone number
{
    phone_no = num;       // variable for axchange phone number
}
};

 // function for collecting data from user
void phonebook :: get_person(void)
{
    cout << "Enter code: ";
    cin >> code;
    fflush(stdin);
    cout << "Enter person: ";
    cin >> name;
    cout << "Enter phone_no like(301234567): ";
    cin >>phone_no;
}
// funtion for Display data
void phonebook :: put_person(void)
{

    cout  <<code <<"               "<<name <<"                       "<<phone_no << endl;

}


//1st function  1GV9Jm2u7rmsCe65wKzPTw5jtS38n2tVEGi1111

phonebook va;       // class Variable
fstream file;               // file variable
// function for saving contact record
void add_record()

{

    char ch = 'y';
    file.open("record.dat", ios::app | ios::binary);
    // loop is used for store 2 or more record
    while(ch =='y' || ch == 'Y')
    {
        va.get_person();     //line 39
        file.write((char*)&va, sizeof(va));
        cout << "Add more Contact....(y 'or' n)?";
        cin >>ch;
    }
    file.close();


}
// for Display all contact list
void show_All(void)
{


    file.open("record.dat", ios::in | ios::binary);
    if(!file)
    {
        cout << "File not found: ";
        exit(0);
    }
    else
    {
        file.read((char*)&va, sizeof(va));
        while(!file.eof())
        {
            // line 50
            va.put_person();
            file.read((char*)&va, sizeof(va));
        }
    }
    file.close();



}

//
void search_record(void)
{


    int no, flag= 0;
    file.open("record.dat", ios::in | ios::binary);
    if(!file)
    {
        cout << "File not Found";
        exit(0);
    }

    else
    {
        cout << "Enter person code to search Contact: ";
        cin >> no;
        file.read((char*)&va, sizeof(va));
        while(!file.eof())
        {
            if(no == va.get_code())
            {
                flag = 1;

            cout << setw(1) << "Code  |"<<setw(18)<< "Name |"<<setw(28)<<"phone_no |" << endl;

            va.put_person();
            break;
        }
        file.read((char*)&va, sizeof(va));
        }
        if(flag == 0)
        {
            cout << "Person  not Found.. \n";
        }
    }
    file.close();
}

//For delete any contact
void delete_record(void)
{
    int no;
    cout << "Enter Person code code to Delete Contact: ";
    cin >> no;
    ofstream file2;

    file2.open("new.dat" , ios::out | ios::binary);
    file.open("record.dat", ios::in | ios::binary);
    if(!file)
    {
        cout << "File not found: ";
        exit(0);
    }
    else{
        file.read((char*)&va, sizeof(va));
        while(!file.eof())
        {
            if(no !=  va.get_code())
            {
                file2.write((char*)&va, sizeof(va));
            }
            file.read((char*)&va, sizeof(va));
        }
    }
    file2.close();
    file.close();
    remove("record.dat");
    rename("new.dat", "record.dat");

}
// update phone number
void modify_record(void)
{

    int no, num;
    cout << "Enter person code to for update phone Number: ";
    cin >> no;
    cout << "Enter new number:  ";
    cin >> num;
    file.open("record.dat", ios::in | ios::out | ios::binary);
    if(!file)
    {
        cout << "File no Found";
        exit(0);
    }

    while(file.read((char*)&va, sizeof(va)))
    {
        if(va.get_code() == no)
        {
            va.update_phoneno(num);
            int pos = sizeof(va);
            file.seekp(-pos, ios::cur);

            file.write((char*)&va, sizeof(va));

        }
    }
    file.close();

}



//*******
//*******
//*******
//Main Function
int main()
{
    int option;
    while(1)
    {
        system("cls");
cout <<"\n\t################ (   Welcome to Contact Management System   ) ################# " << endl;
cout << endl;
cout << "\n\n\tPhone Book\n\t\t**\n\t\t[1] Add a new Contact\n\t\t[2] show All contact\n\t\t[3] Search contact\n\t\t[4] delete_record\n\t\t[5] update_phonenuber\n\t\t[6] Exit\n\t\t*\n\t\t" << endl;

        cout << endl;
        cout << "Enter: ";


cin >> option;

    switch(option)
    {
        case 1:
        {
            add_record();
            cout << "Press any key for Main Menu .. ";
            getch();
            break;
        }
        case 2:
        {

            cout << setw(1) << "Code |"<<setw(18)<< "Name |"<<setw(28)<<"phone_no|" << endl;
            cout <<"-------------------------------------------------------------------------"<< endl;
            show_All();
            cout << "-------------------------------------------------------------------------"<< endl;

            cout << "Press any key for Main Menu...";
            getch();
            break;
        }

        case 3:
        {
            search_record();   //line 109
            cout << "press any key for Main Menu...";
            getch();
            break;
        }

        case 4:
            {
                delete_record();
                cout << "press any key for Main Menu...";
                getch();
                break;
            }


        case 5:
            {
                modify_record();
                cout << "press any key for Main Menu...";
                getch();
                break;
            }


        case 6:
            {

                cout << "Thank you so much: ";
                cout << endl;


                exit(0);
            }
        default:
            {
                cout << "Incorrect Option: ";
                getch();
                break;
            }
    }

    }

    return 0;

}