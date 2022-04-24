#include <iostream>

int main()
{

    int num1{65};
    int num2{60};

    bool result = (num1 < num2);
    std::cout << std::boolalpha << "result " << result << std::endl;

    std::cout << std::endl;
    std::cout << "free standing if statement" << std::endl;

    if (result == true)
    {
        std::cout << num1 << "is less than " << num2 << std::endl;
    }
    if (!(result == true))
    {
        std::cout << num1 << "is not less than" << num2 << std::endl;
    }

    int num3{23};
    int num4{120};

    result = (num3 < num4);

    if (result == true)
    {
        std::cout << num3 << "is less than " << num4 << std::endl;
    }
    else
    {
        std::cout << num3 << "is not less than" << num4 << std::endl;
    }

    bool red = false;
    bool green{true};
    bool yellow{false};
    bool police_stop{true};
    if (red)
    {
        std::cout << "stop " << std::endl;
    }
    if (yellow)
    {
        std::cout << "slow down " << std::endl;
    }
    if (green)
    {
        std::cout << " light is green .....Go" << std::endl;
    }

    // nested if else loop , loop within loop
    if (green)
    {
        if (police_stop)
        {
            std::cout << "police there........stop " << std::endl;
        }
        else
        {
            std::cout << "no police and green so .....GO " << std::endl;
        }

        // using logic , shorter version of nested loop
    }

    if (green && !police_stop)
    {
        std::cout << "police there........stop " << std::endl;
    }
    else
    {
        std::cout << "no police and green so GO " << std::endl;
    }

    return 0;
}