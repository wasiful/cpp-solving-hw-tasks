#include <iostream>

int main()
{

    auto var1{12};
    auto var2{13.256};
    auto var3{14.345f};
    auto var4{15.0};
    auto var5{'e'};

    auto var6{123u};
    auto var7{1251};
    auto var8{12311};

    std::cout << "var1 occupies " << sizeof(var1) << "bytes" << std::endl;
    std::cout << "var2 occupies " << sizeof(var2) << "bytes" << std::endl;
    std::cout << "var3 occupies " << sizeof(var3) << "bytes" << std::endl;
    std::cout << "var4 occupies " << sizeof(var4) << "bytes" << std::endl;
    std::cout << "var5 occupies " << sizeof(var5) << "bytes" << std::endl;
    std::cout << "var6 occupies " << sizeof(var6) << "bytes" << std::endl;
    std::cout << "var7 occupies " << sizeof(var7) << "bytes" << std::endl;
    std::cout << "var8 occupies " << sizeof(var8) << "bytes" << std::endl;

    return 0;
}