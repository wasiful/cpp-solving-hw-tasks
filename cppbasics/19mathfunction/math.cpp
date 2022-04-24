#include <iostream>
#include <cmath>

int main()
{
    double weight{-3.34234};

    std::cout << "kut down after point " << std::floor(weight) << std::endl;
    std::cout << "rounds it up to next number " << std::ceil(weight) << std::endl;

    std::cout << "for absolute value|| " << std::abs(weight) << std::endl;

    double exponential = std::exp(10); // e=2.71828
    std::cout << "e to power x " << exponential << std::endl;

    std::cout << "3^4 " << std::pow(3, 4) << std::endl;
    std::cout << "5^4 " << std::pow(5, 4) << std::endl;

    std::cout << "e based log of a 5.456 num  " << std::log(5.456) << std::endl;
    std::cout << "10 based log of a 5.456 num  " << std::log10(5.456) << std::endl;

    std::cout << "81sqrt  " << std::sqrt(81) << std::endl;

    std::cout << "round more than .5  " << std::round(81.5) << std::endl;

    return 0;
}