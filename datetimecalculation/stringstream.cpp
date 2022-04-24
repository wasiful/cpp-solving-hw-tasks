#include <iostream>
#include <ctime>
#include <cassert>

// Adjust date by a number of days +/-
void DatePlusDays(struct tm *date, int days)
{
    const time_t ONE_DAY = 24 * 60 * 60;

    // Seconds since start of epoch
    time_t date_seconds = mktime(date) + (days * ONE_DAY);

    // Update caller's date
    // Use localtime because mktime converts to UTC so may change date
    *date = *localtime(&date_seconds);
    ;
}

struct tm createDate(int year, int month, int day)
{
    struct tm date = {0, 0, 12};
    date.tm_year = year - 1900;
    date.tm_mon = month - 1; // note: zero indexed
    date.tm_mday = day;      // note: not zero indexed
    return date;
}


int main()
{
    struct tm myDate = createDate(2000, 2, 15);
    char buffer[20];

    strftime(buffer, sizeof buffer, "%Y-%m-%d", &myDate);

    // puts(buffer);

    std::string str = buffer;

    std::cout << str << std::endl;

    assert(str == "2000-02-15");

    // std::string myDateString = convertToString(buffer, 18);

    // std::cout << myDateString << std::endl;

    // std::cout
    //     << asctime(&myDate) << std::endl;

    // Date, less 100 days

    // DatePlusDays(&myDate, +(365));

    // Show time/date using default formatting
    // std::cout << asctime(&myDate) << std::endl;
}