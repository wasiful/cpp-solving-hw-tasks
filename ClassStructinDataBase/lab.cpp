#include <iostream>
using namespace std;

class CVehicle
{
public:
    CVehic
    le(const std::string &plate, int year)
        : mPlate(plate), mYearofMan(year){

                         };
    void print(std::ostream &os) const
    {
        os << "car("
           << mPlate
            ","
           << year << ")";
    }

protected:
    std::string mPlate;
    int mYearofMan;
};

class CCar : public CVehicle
{
    CCar() : CVehicle(const std::string &plate, int year, )
    {
    }
};