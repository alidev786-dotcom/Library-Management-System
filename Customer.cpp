#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<iostream>
using namespace std;

//################################################# Customer Class #####################################
class Customer{

    string customer_name ;
    int customer_age ;
    string customer_city ;

    public:
        Customer(string name,int age,string city)
        {
            this->customer_name = name ;
            this->customer_age = age ;
            this->customer_city = city ;
        }
        void displayCustomer()
        {
            cout << "Customer Name: " << this->customer_name << endl ;
            cout << "Customer Age: " << this->customer_age << endl ;
            cout << "Customer City: " << this->customer_city << endl ;
        }
} ;

#endif