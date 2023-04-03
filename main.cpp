#include<iostream>
#include"BookManagement.cpp"
#include"Book.cpp"
#include"Customer.cpp"
#include<string>
using namespace std;


void menu()
{
    BookManagement manager("books.txt") ;
    int choice ;
    cout << "################## Welcome to Library Management System ####################" << endl << endl ;
    cout << "1-Display All Books" << endl ;
    cout << "2-Add A Book" << endl ;
    cout << "3-Display All Issued Books" << endl ;
    cout << "4-Issue A Book" << endl ;
    cout << "5-Search A Book" << endl ;
    cout << "6-Exit" << endl ;
    cout << "Enter your choice(1-6): " ;
    cin >> choice ;
    while(choice<1 || choice>6)
    {
        cout << "\nPlease enter valid choice(1-5)" << endl << endl ;
        cout << "################## Welcome to Library Management System ####################" << endl << endl ;
        cout << "1-Display All Books" << endl ;
        cout << "2-Add A Book" << endl ;
        cout << "3-Display All Issued Books" << endl ;
        cout << "4-Issue A Book" << endl ;
        cout << "5-Search A Book" << endl ;
        cout << "6-Exit" << endl ;
        cout << "Enter your choice(1-6): " ;
        cin >> choice ;
    }
    if(choice==6)
    {
        return  ;
    }
    else if(choice==1)
    {
        manager.displayAllBooks() ;
        menu() ;
    }
    else if(choice==2)
    {
        string name,isbn,writer,date;
        cin.ignore() ;
        cout << endl << endl ;
        cout << "Enter book name: " ;
        getline(cin,name) ;
        cout << "Enter book ISBN: " ;
        getline(cin,isbn);
        cout << "Enter book writer: " ;
        getline(cin,writer) ;
        cout << "Enter book published date(DD-MM-YYYY): " ;
        getline(cin,date) ;
        Book tempBook(name,isbn,writer,date,true) ;
        manager.addBook(tempBook) ;
        cout << endl << endl ;
        menu() ;
    }
    else if(choice==3)
    {
        manager.showIssuedBooks() ;
        cout << endl << endl ;
        menu() ;
    }
    else if(choice==4)
    {
        string name ;
        cin.ignore() ;
        cout << "Enter Book name to be issued: " ;
        getline(cin,name) ;
        manager.issueBook(name) ;
        cout << endl << endl ;
        menu() ; //again displaying  menu
    }
    else if(choice==5)
    {
        string name ;
        cin.ignore() ;
        cout << "Enter book name to be searched: " ;
        getline(cin,name) ;
        manager.searchBook(name) ;
        cout << endl << endl ;
        menu() ;   //again display menu
    }
}


int main()
{
    string name,city;
    int age; 
    cout << "\nEnter your name: " ;   //customer entering his data
    getline(cin,name) ;
    cout << "Enter your age: " ;
    cin >> age ;
    cin.ignore() ;
    cout << "Enter your city: " ;
    getline(cin,city) ;
    Customer customer(name,age,city) ;
    cout << endl << endl ;
    menu() ;                         //calling menu function
    return  0 ;
}