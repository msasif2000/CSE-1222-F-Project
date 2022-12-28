#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

class Comics
{

    /*    Authors are :
            01. Mostafa Asif [C201014]
            02. Sorowar Mahabub [C201032]
            03. Shahin Shah [C201035]
    */

public:
    int stock, T_stock, t= 0;
    char author[30], publisher[30];
    char comicname[50];
    float price;

    //Function to Add comics in collection
    void Addcomics()
    {
        cout<<"\n\tEnter Comic Name: ";
        cin>>comicname;
        cout<<"\tEnter Author Name: ";
        cin>>author;
        cout<<"\tEnter Publisher Name: ";
        cin>>publisher;
        cout<<"\tEnter Price(Per Piece): ";
        cin>>price;
        cout<<"\tEnter Stock: ";
        cin>>stock;
        T_stock = stock;    //to use later in bor() function

        cout<<"\n\t\t-_------_------_-\n";
    }

    //Functions to display the following information
    void display()
    {
        cout<<"\n\tName of the Comic: "<<comicname;
        cout<<"\n\tAuthor of the Comic: "<<author;
        cout<<"\n\tPublisher of the Comic: "<<publisher;
        cout<<"\n\tPrice of the Comic: " << price;
        cout<<"\n\tAvailable (in stock):"<<stock;
        cout<<"\n\t\t-_-----_------_-\n";
    }

    //Function to calculate available stock
    int bor( int p)
    {
        return stock= stock-p;
    }

    //Functions to show developers Identity when the user choose exit
    void developers()
    {
        cout<<"\n\n\tBeloved Developers are:\n\n";
        cout<<"\t01. Mostafa Asif [C201014]\n";
        cout<<"\t02. Sorowar Mahabub [C201032]\n";
        cout<<"\t03. Shahin Shah [C201035]\n";
        cout<<"\n\t\t-_--You've Successfully Exited!--_-\n";

    }

};

int main()
{

    Comics ob[100];
    int ch, n, i;

    while(1)
    {
        cout<<"\n\t\tWelcome!\n\tTo SAS Comics Collection!\n";
        cout<<"\n\n\tSelect Your Choice: \n";
        cout<<"\t1. Add Comics\n\t2. Display\n";
        cout<<"\t3. Search\n\t4. Available Comics\n\t5. Exit\n";
        cout<<"\n\n\tEnter your Choice: ";
        cin>>ch;

        switch(ch)
        {

        case 1:
            cout<<"\tEnter Number of Comic/s: ";
            cin>>n;
            for(i=0; i<n; i++)
                ob[i].Addcomics();
            cout<<"\n\t\t-_---- You've successfully Inserted Comics Details! ----_-\n";
            break;

        case 2:
            cout<<"\n\t\t-_- Your Results -_-\n";
            for(i=0; i<n; i++)
                ob[i].display();
            cout<<"\n\t\t-_---- End of This Process! ----_-\n";
            break;

        case 3:
            char cname[20], aname[20];
            cout<<"\tEnter name of the Comic: ";
            cin>>cname;
            cout<<"\tEnter name of the Author: ";
            cin>>aname;
            for(int i=0; i<n; i++)
            {
                if(strcmp(cname, ob[i].comicname)==0 && strcmp(aname,ob[i].author)==0)
                {
                    cout<<"\n\t\t-_-- Your Search Results --_-\n";
                    cout<<"\n\tComics Available..!\n\n";
                    cout<<"\n\tName of the Comic: "<<ob[i].comicname;
                    cout<<"\n\tAuthor of the Comic: "<<ob[i].author;
                    cout<<"\n\tPublisher of the Comic: "<<ob[i].publisher;
                    cout<<"\n\tPrice of the Comic: "<<ob[i].price;
                    cout<<"\n\tAvailable (stock): "<<ob[i].stock;
                    cout<<"\n\t-------------\n";
                    break;
                }
            }
            break;

        default:
            cout<<"\t\tWarning!\n\tEnter a valid choice!";
            cout<<"\n\t\t-_------_------_-\n";

        case 4:
            char c_name[20], a_name[20];
            int borrow;
            cout<<"\tEnter name of the Comic: ";
            cin>>c_name;
            cout<<"\tEnter name of the Author: ";
            cin>>a_name;
            for(int i=0; i<n; i++)
            {
                if(strcmp(c_name, ob[i].comicname)==0 && strcmp(a_name,ob[i].author)==0)
                {
                    cout<<"\tEnter Number of Comic/s you've lend: ";
                    cin>>borrow;
                    ob[i].bor(borrow);  // calling bor() function
                    cout<<"\n\t\t-_-- Your Search Results --_-\n";
                    cout<<"\n\tName of the Comic: "<<ob[i].comicname;
                    cout<<"\n\tAuthor of the Comic: "<<ob[i].author;
                    cout<<"\n\tPublisher of the Comic: "<<ob[i].publisher;
                    cout<<"\n\tPrice of the Comic: "<<ob[i].price;
                    if(ob[i].stock>=0)
                        cout<<"\n\tAt Present, Available (stock): "<<ob[i].stock;
                    else if(ob[i].stock<0)
                        cout<<"\n\tAt Present, Available (stock): Unusual Lend Input";
                    cout<<"\n\t\t-_------_------_-\n";
                    break;
                }
            }
            break;

        case 5:
            ob[i].developers(); //calling developers function
            exit(1);
        }
    }
    return 0;
}
