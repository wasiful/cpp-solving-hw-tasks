
#include <iostream>
#include <string>
using namespace std;

class cars
{

private:
    string company_name; // mamber variables
    string modle_name;
    string fule_type;
    float milage;
    double price;

public:
    cars()
    { // constructor
        cout << "default constructor from private" << endl
             << endl;
    }
    cars(string carname, string modlename, string fueltype, float speed, double cost)
    { // parametrized constructor
        cout << "parametrized constructor" << endl
             << endl;
        company_name = carname;
        modle_name = modlename;
        fule_type = fueltype;
        milage = speed;
        price = cost;
    }

    cars(cars &obj)
    { // copy constructor
        cout << "copy constructor" << endl
             << endl;
        company_name = obj.company_name;
        modle_name = obj.modle_name;
        fule_type = obj.fule_type;
        milage = obj.milage;
        price = obj.price;
    }
    ~cars()
    { // destructor ~deletes the data.........for 8 car data distructor will be called 8 times
        cout << "destructor called" << endl
             << endl;
    }

    void setData(string carname, string modlename, string fueltype, float speed, double cost)
    {
        company_name = carname; // mamber variables
        modle_name = modlename;
        fule_type = fueltype;
        milage = speed;
        price = cost;
    } // member function

    void displayData()
    {
        cout << "car properties from display function " << endl;
        cout << "car company name " << company_name << endl;
        cout << "car modle " << modle_name << endl;
        cout << "car fuel required " << fule_type << endl;
        cout << "car speed " << milage << endl;
        cout << "car value " << price << endl;
    }
};

int main()
{
    cars car1;                   // car1 is and object of type car, objs are variables of type class
    cars car2, car3, car4, car5; // Now I can take data for 5 cars and display those

    car1.setData("toyota", "altis", "petrol", 15.5, 15000000);
    car1.displayData();

    car2.setData("wagon", "W2018", "octen", 20.00009, 123000000);
    car2.displayData(); // setdata function is used from the class

    cars car7, car6("tata", "hispeed", "disel", 16.789, 6000000); // using parametrized constructor ... setdata function not required any more
    car6.displayData();
    cars car8 = car1; // using copy constructor now  1 data can be copied to another
    car8.displayData();

    return 0;
}

// std::list<int> allInvoice;

// for (list<companyData>::const_iterator comp = registry.begin(); comp != registry.end(); comp++)
// {
//     int compAmount = comp->Amount;

//     if (compAmount > 0)
//     {
//         allInvoice.push_back(compAmount);
//     }
// }
// allInvoice.sort();
// double median;
// auto itr = allInvoice.begin();
// if (allInvoice.size() % 2 == 0)
// {
//     for (int i = 0; i < allInvoice.size() / 2; i++)
//     {
//         itr++;
//     }
//     median = *itr;
// }
// else
// {
//     for (int i = 0; i < allInvoice.size() / 2; i++)
//     {
//         itr++;
//     }

//     median = *itr;
// }
// unsigned int newMedian;
// newMedian = median;

// void displayInvoices()
// {
//     cout << "Displaying New Chunks:" << endl;
//     for (std::vector<unsigned int>::iterator i = allInvoices.begin(); i != allInvoices.end(); ++i)
//     {
//         cout << *i << "\n\t";
//     }
// }

// void displayData()

// {
//     cout << "car properties from display function " << endl;
//     for (list<companyData>::iterator iter = registry.begin(); iter != registry.end(); iter++)
//     {
//         cout << "Showing Result for Company " << iter->Name << endl;
//         cout << "\tAddress: " << iter->Addr << endl;
//         cout << "\tTax ID: " << iter->TaxID << endl;
//         cout << "\tAmount: " << iter->Amount << endl;
//     }
// }