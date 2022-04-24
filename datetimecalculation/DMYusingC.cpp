#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    // current date/time based on current system
    time_t cu = time(0);

    // convert now to string form
    char *dd = ctime(&cu);

    cout << "The local date and time is: " << dd << endl;

    // convert now to tm struct for UTC
    tm *gmtm = gmtime(&cu);
    dd = asctime(gmtm);
    cout << "The UTC date and time is:" << dd << endl;
}