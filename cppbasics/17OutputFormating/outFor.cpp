/* ios and iomanip libraries can formate the out puts using
std::flush,endl,showpoint,right,left,boolalpha,setfill(),stew(),
hex,fixed,internal,setprecision(),dec,scientific,showbase,
uppercase,showpass,oct..........input output manupulator */
#include <iostream> //for std
#include <iomanip>  //for setw()
int main()
{
    std::cout << "Hellow" << std::endl;
    std::cout << "world" << std::endl;

    // /n or making a new line using std
    std::cout << std::endl;

    // adds 10 spaces between outputs
    std::cout << std::setw(10) << "asda" << std::setw(10) << "swwsdasd" << std::endl;
    std::cout << std::setw(10) << "asda" << std::setw(10) << "swwsdasd" << std::endl;
    std::cout << std::setw(10) << "asda" << std::setw(10) << "swwsdasd" << std::endl;

    int clo_width{15}; // can be used as int
    std::cout << std::setw(clo_width) << "asda" << std::setw(clo_width) << "swwsdasd" << std::endl;
    std::cout << std::setw(clo_width) << "asda" << std::setw(clo_width) << "swwsdasd" << std::endl;
    std::cout << std::setw(clo_width) << "asda" << std::setw(clo_width) << "swwsdasd" << std::endl;

    std::cout << std::left; // can be pleased in a side
    std::cout << std::setw(clo_width) << "asda" << std::setw(clo_width) << "swwsdasd" << std::endl;
    std::cout << std::setw(clo_width) << "asda" << std::setw(clo_width) << "swwsdasd" << std::endl;
    std::cout << std::setw(clo_width) << "asda" << std::setw(clo_width) << "swwsdasd" << std::endl;

    std::cout << std::internal;
    std::cout << std::setw(clo_width) << -231231 << std::endl; // negative sign goes to left

    std::cout << std::setfill('#'); // spaces are going to be replased by #
    std::cout << std::setw(clo_width) << "asda" << std::setw(clo_width) << "swwsdasd" << std::endl;
    std::cout << std::setw(clo_width) << "asda" << std::setw(clo_width) << "swwsdasd" << std::endl;
    std::cout << std::setw(clo_width) << "asda" << std::setw(clo_width) << "swwsdasd" << std::endl;

    bool a{true};
    bool b{false};
    std::cout << std::boolalpha; // true or false
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << std::noboolalpha; // 0 or 1
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    int c{40};
    int d{-21};
    std::cout << std::showpos; // shows + sign
    std::cout << c << std::endl;
    std::cout << d << std::endl;

    std::cout << std::noshowpos; // shows the sign
    std::cout << c << std::endl;
    std::cout << d << std::endl;

    std::cout << std::uppercase;
    std::cout << std::hex << d << std::endl;
    std::cout << std::oct << d << std::endl;

    double e{2134.445656756786878979789};

    std::cout << std::fixed;
    std::cout << e << std::endl;

    std::cout << std::scientific;
    std::cout << e << std::endl;

    std::cout.unsetf(std::ios::scientific | std::ios::fixed);
    std::cout << e << std::endl;

    std::cout << std::showpoint;
    std::cout << e << std::endl;

    std::cout << std::setprecision(16);
    std::cout << e << std::endl;

    return 0;
}