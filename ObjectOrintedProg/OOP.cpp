#include <iostream>
#include <string>
using std::string;

class Employee
{
private:
    string Name;
    string Company;
    int Age;

public:
    void setName(string name)
    {
        Name = name;
    }
    string getName()
    {
        return Name;
    }

    void setCompany(string company)
    {
        Company = company;
    }
    string getCompany()
    {
        return Company;
    }

    void setAge(int age)
    {
        Age = age;
    }
    int getAge()
    {
        return Age;
    }

    void Introduce()
    {
        std::cout << "name " << Name << std::endl;
        std::cout << "company " << Company << std::endl;
        std::cout << "age " << Age << std::endl;
    }
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }
};

int main()
{
    Employee employe1 = Employee("choppy", "chip", 27);
    employe1.Introduce();

    Employee employe2 = Employee("hoppy", "hip", 37);
    employe2.Introduce();

    employe1.setAge(39);
    std::cout << employe1.getName() << "is" << employe1.getAge() << "year"
}