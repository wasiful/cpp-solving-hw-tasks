#include <iostream>
#include <string>

int main()
{
    /*
        std::cout << "Hello" << std ::endl;

            int age{21};
            std::cout << "Age:" << age << std::endl;

    std::cerr << "something is wrong" << std::endl;
    std::clog << "log msg wrong! " << std::endl;

    int age1;
    std::string name;

    std::cout << "please give name and age:" << std::endl;

    std::cin >> name;
    std::cin >> age1;

    std::cin >> name >> age1;
    std::cout << "Hello " << name << " u r " << age1 << std::endl;
    */
    std::string full_name;
    int age3;

    std::cout << "Please type in your fullname and age" << std::endl;

    std::getline(std::cin, full_name);

    std::cin >> age3;
    std::cout << "Hello " << full_name << " u r " << age3 << std::endl;

    return 0;
}
