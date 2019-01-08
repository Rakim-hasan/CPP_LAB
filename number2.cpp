#include<iostream>
using namespace std;

class Customer;
class Person
{
    public:
    string name;

    Person(){}
    Person(string name)
    {
        this->name=name;
    }
};

class Book
{
private:
    string bookTitle,writerName;
    int price,quantity,edition;

public:
    Book(){}

    Book(string bookTitle,string writerName,int price,int quantity,int edition)
    {
       this-> bookTitle = bookTitle;
       this->writerName = writerName;
       this->price = price;
       this->quantity = quantity;
       this->edition = edition;
    }

    void showBook()
    {
        cout<<"Book Title    :  "<<bookTitle<<endl;
        cout<<"Writer Name   :  "<<writerName<<endl;
        cout<<"Price         :  "<<price<<endl;
        cout<<"Edition       :  "<<edition<<endl;
        cout<<"Quantity      :  "<<quantity<<endl;
    }
};

class BookCategory : public Book
{
private:
    string category;

public:
    BookCategory(){}

    BookCategory(string category,string bookTitle,string writerName,int price,int edition,int quantity):Book(bookTitle,writerName,price,edition,quantity)
    {
        this->category =category ;
    }

    void showDetail()
    {
        cout<<"Book Description : "<<endl<<endl;
        cout<<"Book Category :  "<<category<<endl;
        showBook();

        cout<<endl;
    }

    friend void buyBooks(BookCategory , Customer );
};

class Customer:public Person
{


public:
    Customer(){}

    Customer(string name):Person(name)
    {

    }

    friend void buyBooks(BookCategory , Customer );
};

    void buyBooks(BookCategory b, Customer c)
    {
        cout<<"Dear customer Mr./Mrs. "<<c.name<<" , you will get discount if you are our regular customer."<<endl;
    }

int main()
{
    BookCategory A("Fiction","Past tense","Lee Child",500,20,5);
    BookCategory B("Non-Fiction","In cold blood","Truman capote",450,25,7);
    BookCategory C("Comic","Maus","Art Spiegelman",400,18,6);

    A.showDetail();
    B.showDetail();
    C.showDetail();

    Customer D("Eyasin");
    buyBooks(B,D);

}
