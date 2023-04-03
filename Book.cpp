#ifndef BOOK_H
#define BOOK_H

#include<iostream>
using namespace std;

//########################################## Book Class ######################################
class Book{

    string book_name ;
    string ISBN ;
    string writer ;
    string published_date ;
    bool available;
    public:
        Book()
        {
            this->book_name = this->ISBN = this->published_date = this->writer = "" ;
        }
        Book(string a_bookName,string a_ISBN,string a_writer,string a_published_date,bool available)
        {
            this->book_name = a_bookName ;
            this->ISBN = a_ISBN ;
            this->writer = a_writer ;
            this->published_date = a_published_date ;
            this->available = available ;
        }
        void setBookName(string a_bookName)
        {
            this->book_name = a_bookName ;
        }
        void setISBN(string a_isbn)
        {
            this->ISBN = a_isbn ;
        }
        void setWriter(string a_writer)
        {
            this->writer = a_writer ;
        }
        void setPublishedDate(string a_date)
        {
            this->published_date = a_date ;
        }
        void setAvailable(bool avail)
        {
            this->available = avail ;
        }
        string getBookName()
        {
            return this->book_name ;
        }
        string getISBN()
        {
            return this->ISBN ;
        }
        string getWriter()
        {
            return this->writer ;
        }
        string getPublishedDate()
        {
            return this->published_date ;
        }
        void displayBook()
        {
            string temp;
            if(this->available)
                temp="true";
            else
                temp="false" ;
            cout << "Book title: " << this->book_name << endl ;
            cout << "Book ISBN: " << this->ISBN << endl ;
            cout << "Book Writer: " << this->writer << endl ;
            cout << "Book Published Date: " << this->published_date << endl ;
            cout << "Book Available: " << temp << endl ;
        }
        bool isBookAvailable()
        {
            return this->available ;
        }
} ;
 

#endif

