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
        cout << "car properties " << endl;
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
    car2.displayData();

    return 0;
}