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

class Item
{
private:
 string itemName,productOrigin;
 int price,quantity;

public:
     Item(){}
     Item(string itemName,string productOrigin,int price,int quantity)
     {
       this-> itemName =itemName;
       this->productOrigin = productOrigin;
       this->price = price;
       this->quantity = quantity;

    }

    void showItem()
    {
        cout<<"Item Name     :  "<<itemName<<endl;
        cout<<"ProductOrigin :  "<<productOrigin<<endl;
        cout<<"Price         :  "<<price<<endl;
        cout<<"Quantity      :  "<<quantity<<endl;

    }
};

class ItemCategory : public Item
{
private:
    string itemCategory;

public:
    ItemCategory(){}

    ItemCategory(string itemCategory,string itemName,string productOrigin,int price,int quantity):Item(itemName,productOrigin,price,quantity)
    {
        this->itemCategory =itemCategory ;
    }

    void showDetail()
    {
        cout<<"Item Description : "<<endl<<endl;
        cout<<"Item Category :  "<<itemCategory<<endl;
        showItem();

        cout<<endl;
    }

    friend void buyItems(ItemCategory , Customer );
};

class Customer:public Person
{
public:
    string customerCategory;
    Customer(){}

    Customer(string customerCategory,string name):Person(name)
    {
        this->customerCategory=customerCategory;


    }


    friend void buyItems(ItemCategory , Customer );
};

    void buyItems(ItemCategory b, Customer c)
    {
        cout<<"Customer category:"<<c.customerCategory<<endl;
        cout<<"Dear customer "<<c.name<<" , you will get discount if you are our regular customer."<<endl;
    }

int main()
{

    ItemCategory A("Cosmetic","Nail polish","Bangladeshi",500,5);
    ItemCategory B("Stationary","Pen","Bangladeshi",30,5);
    ItemCategory C("Garment","Sweater","Bangladeshi",500,5);

    A.showDetail();
    B.showDetail();
    C.showDetail();



    Customer D("Male","Eyasin");
    buyItems(A,D);

}
