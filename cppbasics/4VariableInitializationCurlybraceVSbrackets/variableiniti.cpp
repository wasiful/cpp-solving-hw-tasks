#include <iostream>

int main()
{
    int elephant; // add a little garbage to your life :)
    int elephant_count;
    int lion_count{};
    int dog_count{3};
    int cat_count{4};

    int animals{dog_count + cat_count + lion_count + elephant_count + elephant}; // garbage elephant all over the world
    int totalanimals{dog_count + cat_count + lion_count};

    // int fractionInCurly{2.438}; it can not run in curly but in bracket
    int fraction(2.53555754343235); //.535 will be chopped off of here as float is not used
    std::cout << "amount of elephants " << elephant_count << std::endl;
    std::cout << "amount of lions " << lion_count << std::endl;
    std::cout << "amount of dogs " << dog_count << std::endl;
    std::cout << "amount of cats " << cat_count << std::endl;
    std::cout << "amount of garbage animals  " << animals << std::endl;
    std::cout << "amount of total animals without garbage elephants  " << totalanimals << std::endl;
    std::cout << "unfortunate fraction 2.53... ...  in int " << fraction << std::endl; // usefull only for chopping

    // checking data storage size of the variables in memory
    std::cout << "size of int in bytes" << sizeof(int) << std::endl;
    std::cout << "size of dog in bytes" << sizeof(dog_count) << std::endl;
    return 0;
}