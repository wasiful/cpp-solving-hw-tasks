// C++ program to display next day’s day, month and year.
#include <iostream>
using namespace std;
int main()
{
    int dd, mm, yy;
    cout << "Enter today's date in the format:DD MM YYYY\n";
    cin >> dd >> mm >> yy;
    if (dd > 0 && dd < 28) // checking for day from 0 to 27
        dd += 1;
    if (dd == 28)
    {
        if (mm == 2) // checking for February

        {
            if ((yy % 400 == 0) || (yy % 100 != 0 || yy % 4 == 0)) // leap year check in case of feb
            {
                dd = 29;
            }
            else
            {
                dd = 1;
                mm = 3;
            }
        }
        else // when it is not February
            dd += 1;
    }
    if (dd == 29) // last day check for February

    {
        if (mm == 2)
        {
            dd = 1;
            mm = 3;
        }
        else
            dd += 1;
    }
    if (dd == 30) // last day check for April, June,September,November
    {
        if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)
            dd += 1;
        else
        {
            dd = 1;
            mm += 1;
        }

        if (dd == 31) // last day of the month
        {
            dd = 1;
            if (mm == 12) // checking for last day of the year
            {
                yy += 1;
                mm = 1;
            }
            else
                mm += 1;
        }
        cout << "Tomorrow's date:\n";
        if (dd < 10) // checking if day needs to be preceded by 0
        {
            cout << "0" << dd << " ";
        }
        else
            cout << dd << " ";
        if (mm < 10) // checking if month needs to be preceded by 0
        {
            cout << "0" << mm << " ";
        }
        else
            cout << mm << " ";
        cout << yy;
        return 0;
    }
}
