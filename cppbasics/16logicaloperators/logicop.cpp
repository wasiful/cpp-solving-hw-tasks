#include <iostream>
int main()
{

    bool a{true};
    bool b{false};
    bool c{true};
    int d{45};
    int e{60};
    int f{20};

    std::cout << std::boolalpha;
    std::cout << "a and b " << (a && b) << std::endl;
    std::cout << "a and b and c " << (a && b && c) << std::endl;

    std::cout << "a or b " << (a || b) << std::endl;
    std::cout << "a or b or c  " << (a || b || c) << std::endl;

    std::cout << " notb " << (!b) << std::endl;
    std::cout << "a or notb " << (a || !b) << std::endl;
    std::cout << "a or b and notc  " << (a || b && !c) << std::endl;

    std::cout << "( (d>e) and (d>f) or (e>=f) )  " << ((d > e) && (d > f) || (e >= f)) << std::endl;

    return 0;
}