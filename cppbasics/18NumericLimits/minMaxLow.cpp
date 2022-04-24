#include <iostream>
#include <limits> //it lets us limit the values
int main()
{

    std::cout << "range short" << std::numeric_limits<short>::min() << " to " << std::numeric_limits<short>::max() << std::endl;

    std::cout << "range unsigned short " << std::numeric_limits<unsigned short>::min() << " to " << std::numeric_limits<unsigned short>::max() << std::endl;

    std::cout << "range int " << std::numeric_limits<int>::min() << " to " << std::numeric_limits<int>::max() << std::endl;

    std::cout << "range unsigned int" << std::numeric_limits<unsigned int>::min() << " to " << std::numeric_limits<unsigned int>::max() << std::endl;

    std::cout << "range long " << std::numeric_limits<long>::min() << " to " << std::numeric_limits<long>::max() << std::endl;

    std::cout << "range float " << std::numeric_limits<float>::min() << " to " << std::numeric_limits<float>::max() << std::endl;

    std::cout << "range(with lowest) float " << std::numeric_limits<float>::lowest() << " to " << std::numeric_limits<float>::max() << std::endl;

    std::cout << "range(with lowest) double " << std::numeric_limits<double>::lowest() << " to " << std::numeric_limits<double>::max() << std::endl;

    std::cout << "range(with lowest) long double " << std::numeric_limits<long double>::lowest() << " to " << std::numeric_limits<long double>::max() << std::endl;

    std::cout << "int is signed : " << std::numeric_limits<int>::is_signed << std::endl;
    std::cout << "int digits : " << std::numeric_limits<int>::digits << std::endl;
    return 0;
}