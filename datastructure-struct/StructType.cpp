#include <iostream>
using namespace std;

struct Height
{
    int h;
};

struct Weight
{
    int w;
};

struct Person
{
    int age;
    struct Height height;
    struct Weight weight;
};

int main()
{
    Height person_height;
    person_height.h = 167;

    Weight person_weight;
    person_weight.w = 40;

    Person per;
    per.age = 22;
    per.height = person_height;
    per.weight = person_weight;

    cout << per.age << "\n"
         << per.height.h << "\n"
         << per.weight.w << endl;

    return 0;
}