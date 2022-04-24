#include <iostream>
#include <string>
#include <list>
using namespace std;

struct carData
{
    string company_name; // mamber variables
    string modle_name;
    string fule_type;
    float milage;
    double price;
};

class cars
{

private:
    std::list<struct carData> registry;
    // delete[] registry;
public:
    cars()
    { // constructor
        cout << "default constructor from private" << endl
             << endl;
    }
    // ~cars()
    // { // destructor ~deletes the data.........for 8 car data distructor will be called 8 times
    //     cout << "destructor called" << endl
    //          << endl;
    // }

    bool createCar(string carname, string modlename, string fueltype, float speed, double cost)
    {
        struct carData newCar;
        newCar.company_name = carname;
        newCar.modle_name = modlename;
        newCar.fule_type = fueltype;
        newCar.milage = speed;
        newCar.price = cost;

        for (list<carData>::iterator iter = registry.begin(); iter != registry.end(); iter++)
        {
            return false;
        }

        registry.push_back(newCar);
        return true;
    }

    void displayData()

    {
        cout << "car properties from display function " << endl;
        for (list<carData>::iterator iter = registry.begin(); iter != registry.end(); iter++)
        {
            cout << "Showing Result for Car " << iter->modle_name << endl;
            cout << "\tCompany: " << iter->company_name << endl;
            cout << "\tFuel: " << iter->fule_type << endl;
            cout << "\tSpeed: " << iter->milage << endl;
            cout << "\tValue: " << iter->price << endl;
        }
    }
};

int main()
{
    cars carDb; // car1 is and object of type car, objs are variables of type class
    carDb.createCar("toyota", "altis", "petrol", 15.5, 15000000);
    carDb.createCar("bugatti", "balchal", "petrol", 15.5, 15000000);
    carDb.displayData();
    return 0;
}