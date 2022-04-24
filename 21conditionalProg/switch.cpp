#include <iostream>
#include <string> //for using name, characters

const int pen{10};
const int marker{20};
const int eraser{30};
const int rectangle{40};
const int circle{50};
const int eclipse{60};

int main()
{
    int tool{marker};

    switch (tool)
    {
    case pen:
    {
        std::cout << "using " << std::endl;
    }
    break;

    case marker:
    {
        std::cout << "using marker " << std::endl;
    }
    break;

    case circle:
    {
        std::cout << "using circle " << std::endl;
    }
    break;

    case eclipse:
    {
        std::cout << "using ellipse " << std::endl;
    }
    break;
    case rectangle:
    {
        std::cout << "using rectangle " << std::endl;
    }
    break;

    default:
    {
        std::cout << "no tool found " << std::endl;
    }
    break;
    }
    return 0;
}