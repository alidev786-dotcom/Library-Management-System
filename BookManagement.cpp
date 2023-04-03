#ifndef BOOK_MANAGEMENT_H
#define BOOK_MANAGEMENT_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include"Book.cpp"
using namespace std;

//########################################## BookManagement Class ##################################
class BookManagement{

    string fileName ;
    Book *books ;

    public:
        BookManagement()
        {
            this->fileName = "" ;
            this->books = nullptr ;
        }
        BookManagement(string a_file)
        {
            this->fileName = a_file ;
        }
        int check_substring(string str1, string str2)
        {   int i;
            int c = 0; // counter for substring
            for( i=0;i<str1.length();i++)
            {
                if(c==str2.length())
                {  break; }
                if(str2[c]==str1[i])
                {
                    c++;
                }
            else
                {
                    // if the character next to ith character is duplicate
                    if(c > 0)
                    {
                        i -= c;
                    }
                    c = 0;
                }
            }
            //checking if the substring is present or not
            if(c < str2.length())
            {
                return -1;
            }
            else{
        return i-c;
            }
        }
        void displayAllBooks()
        {
            string line ;
            ifstream inFile(this->fileName) ;
            if(inFile.fail())
            {
                cout << "File not found" << endl ;
                return  ;
            }
            while(getline(inFile,line))
            {
                //splitting this line
                vector<string> tokens ;
                stringstream check(line) ;
                string intermediate ;
                while(getline(check,intermediate,','))
                {
                    tokens.push_back(intermediate) ;
                }
                //displaying this book
                string temp ;
                if(tokens[4]=="1")
                    temp="true";
                else
                    temp="false" ;
                cout << "\nBook Title: " << tokens[0] << endl ;
                cout << "Book ISBN: " << tokens[1] << endl ;
                cout << "Book Writer: " << tokens[2] << endl ;
                cout << "Book Published Date: " << tokens[3] << endl ;
                cout << "Book Available: " << temp << endl << endl ;
            }
            inFile.close() ;
        }
        void searchBook(string book_name)
        {
            string line ;
            bool found=false ;
            ifstream inFile(this->fileName) ;
            if(inFile.fail())
            {
                cout << "File not found" << endl ;
                return  ;
            }
            while(getline(inFile,line))
            {
                //splitting this line
                vector<string> tokens ;
                stringstream check(line) ;
                string intermediate ;
                while(getline(check,intermediate,','))
                {
                    tokens.push_back(intermediate) ;
                }
                //displaying this book
                if(check_substring(tokens[0],book_name)!=-1)
                {
                    cout << "\nBook Title: " << tokens[0] << endl ;
                    cout << "Book ISBN: " << tokens[1] << endl ;
                    cout << "Book Writer: " << tokens[2] << endl ;
                    cout << "Book Published Date: " << tokens[3] << endl << endl ;
                    found=true ;
                }
            }
            inFile.close() ;
            if(!found)
                cout << "Not such book found!" << endl ;
        }
        void addBook(Book book)
        {
            ofstream myFile;
            myFile.open(this->fileName,std::ios_base::app) ;
            myFile << book.getBookName() << "," << book.getISBN() << "," << book.getWriter() << "," << book.getPublishedDate() << "," << book.isBookAvailable() << endl ;
            myFile.close() ;
        }
        void saveBooksToFile(Book books[],int index)
        {
             ofstream myFile;
            myFile.open(this->fileName) ;
            for(int i=0; i<index; i++)
            {
                myFile << books[i].getBookName() << "," << books[i].getISBN() << "," << books[i].getWriter() << "," << books[i].getPublishedDate() << "," << books[i].isBookAvailable() << endl ;
            }
            myFile.close() ;
        }
        void issueBook(string book_name)
        {
            Book books[100] ; int index=0; 
            string line ;
            bool found=false ;
            ifstream inFile(this->fileName) ;
            if(inFile.fail())
            {
                cout << "File not found" << endl ;
                return  ;
            }
            while(getline(inFile,line))
            {
                //splitting this line
                vector<string> tokens ;
                stringstream check(line) ;
                string intermediate ;
                while(getline(check,intermediate,','))
                {
                    tokens.push_back(intermediate) ;
                }
                bool avail ;
                if(tokens[4]=="1")
                    avail=true ;
                else
                    avail=false; 
                Book tempBook(tokens[0],tokens[1],tokens[2],tokens[3],avail) ;
                //putting this book to books array
                books[index++] = tempBook ;
            }
            inFile.close() ;
            //now searching for given book in books array
            for(int i=0; i<index; i++)
            {
                if(book_name==books[i].getBookName())
                {
                    books[i].setAvailable(false) ;  //book has been issued
                    cout << "\nBook has been issued" << endl << endl ;
                    books[i].displayBook() ;
                    found=true;
                }
            }
            if(!found)
            {
                cout << "\nNo such book found!" << endl ;
                return  ;
            }
            //updating data into file
            saveBooksToFile(books,index) ;
        }
        void showIssuedBooks()
        {
            string line ;
            ifstream inFile(this->fileName) ;
            if(inFile.fail())
            {
                cout << "File not found" << endl ;
                return  ;
            }
            while(getline(inFile,line))
            {
                //splitting this line
                vector<string> tokens ;
                stringstream check(line) ;
                string intermediate ;
                while(getline(check,intermediate,','))
                {
                    tokens.push_back(intermediate) ;
                }
                //displaying this book
                string temp ="false";
                if(tokens[4]=="0")
                {
                    cout << "\nBook Title: " << tokens[0] << endl ;
                    cout << "Book ISBN: " << tokens[1] << endl ;
                    cout << "Book Writer: " << tokens[2] << endl ;
                    cout << "Book Published Date: " << tokens[3] << endl ;
                    cout << "Book Available: " << temp << endl << endl ;
                }
            }
            inFile.close() ;
        }
} ;


#endif