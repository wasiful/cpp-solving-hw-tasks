#ifndef __PROGTEST__
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdexcept>
using namespace std;
#endif /* __PROGTEST__ */

//=================================================================================================
// a dummy exception class, keep this implementation
class InvalidDateException : public invalid_argument
{
public:
    InvalidDateException()
        : invalid_argument("invalid date or format")
    {
    }
};
//=================================================================================================
// date_format manipulator - a dummy implementation. Keep this code unless you implement your
// own working manipulator.
ios_base &(*date_format(const char *fmt))(ios_base &x)
{
    return [](ios_base &ios) -> ios_base &
    { return ios; };
}
//=================================================================================================
class CDate
{
private:
    int Year, Month, Day;
    struct tm date = {0, 0, 12};
    const time_t ONE_DAY = 24 * 60 * 60;

public:
    string strRepresent()
    {
        char buffer[20];

        strftime(buffer, sizeof buffer, "%Y-%m-%d", &date);

        // puts(buffer);

        std::string str = buffer;

        return str;
    }

    struct tm getTm()
    {
        return date;
    }

    CDate(int year, int month, int day)
    {
        if (month > 12 || day > 31)
        {
            throw InvalidDateException();
        }
        date.tm_year = year - 1900;
        date.tm_mon = month - 1; // note: zero indexed
        date.tm_mday = day;      // note: not zero indexed
        // cout << Year << Month << Date << "........." << endl;
    }

    void displayData()
    {
        // cout << Year << Month << Day << endl;
        cout << strRepresent() << endl;
    }

    friend ostream &operator<<(ostream &os, CDate &ref)
    {
        return os << ref.strRepresent();
    }

    friend istream &operator>>(istream &is, CDate &d)
    {

        is >> d.Year >> d.Month >> d.Day;
        d.Month = abs(d.Month);
        d.Day = abs(d.Day);

        if (d.Month == 2 && d.Year % 400 != 0 && d.Day == 29)
        {
            return is;
        }

        if (d.Year % 4 != 0 && d.Month == 2 && d.Day == 29)
        {
            return is;
        }

        if ((d.Month == 4 || d.Month == 6 || d.Month == 9 || d.Month == 11) && d.Day > 30)
        {
            return is;
        }

        if (d.Day > 31)
        {
            return is;
        }

        d.date.tm_year = d.Year - 1900;
        d.date.tm_mon = d.Month - 1;
        d.date.tm_mday = d.Day;
        return is;
    }

    CDate &operator+(int days)
    {
        time_t date_seconds = mktime(&date) + (days * ONE_DAY);
        date = *localtime(&date_seconds);
        return *this;
    }

    CDate &operator++()
    {
        time_t date_seconds = mktime(&date) + (1 * ONE_DAY);
        date = *localtime(&date_seconds);
        return *this;
    }

    CDate operator++(int)
    {
        CDate temp = *this;
        ++*this;
        return temp;
    }

    CDate operator--(int)
    {
        CDate temp = *this;
        --*this;
        return temp;
    }

    CDate &operator-(int days)
    {
        time_t date_seconds = mktime(&date) - (days * ONE_DAY);
        date = *localtime(&date_seconds);
        return *this;
    }

    CDate &operator--()
    {
        time_t date_seconds = mktime(&date) - (1 * ONE_DAY);
        date = *localtime(&date_seconds);
        return *this;
    }

    int operator-(CDate &temp)
    {
        int d = 24, h = 60, min = 60;
        time_t date_seconds1 = mktime(&date);
        time_t date_seconds2 = mktime(&temp.date);
        double seconds = difftime(date_seconds1, date_seconds2);

        int days = seconds / min / h / d;
        return days;
    }

    bool operator==(CDate &temp)
    {

        time_t date_seconds1 = mktime(&date);
        time_t date_seconds2 = mktime(&temp.date);

        return date_seconds1 == date_seconds2;
    }

    bool operator!=(CDate &temp)
    {

        time_t date_seconds1 = mktime(&date);
        time_t date_seconds2 = mktime(&temp.date);

        return date_seconds1 != date_seconds2;
    }

    bool operator<=(CDate &temp)
    {

        time_t date_seconds1 = mktime(&date);
        time_t date_seconds2 = mktime(&temp.date);
        // double seconds = difftime(date_seconds1, date_seconds2);
        return date_seconds1 <= date_seconds2;
    }

    bool operator<(CDate &temp)
    {

        time_t date_seconds1 = mktime(&date);
        time_t date_seconds2 = mktime(&temp.date);
        // double seconds = difftime(date_seconds1, date_seconds2);
        return date_seconds1 < date_seconds2;
    }

    bool operator>=(CDate &temp)
    {

        time_t date_seconds1 = mktime(&date);
        time_t date_seconds2 = mktime(&temp.date);
        // double seconds = difftime(date_seconds1, date_seconds2);
        return date_seconds1 >= date_seconds2;
    }

    bool operator>(CDate &temp)
    {

        time_t date_seconds1 = mktime(&date);
        time_t date_seconds2 = mktime(&temp.date);
        // double seconds = difftime(date_seconds1, date_seconds2);
        return date_seconds1 > date_seconds2;
    }

    CDate &operator=(const CDate &temp)
    {
        date.tm_year = temp.date.tm_year;
        date.tm_mon = temp.date.tm_mon; // note: zero indexed
        date.tm_mday = temp.date.tm_mday;

        return *this;
    }
};

#ifndef __PROGTEST__
int main(void)
{
    ostringstream oss;
    istringstream iss;
    CDate a(2000, 1, 2);

    // cout << a;
    CDate b(2010, 2, 3);
    CDate c(2004, 2, 10);
    // c.displayData();
    oss.str("");
    oss << a;
    // cout << oss.str();
    assert(oss.str() == "2000-01-02");
    oss.str("");
    oss << b;
    assert(oss.str() == "2010-02-03");
    oss.str("");
    oss << c;
    assert(oss.str() == "2004-02-10");

    a = a + 1500;
    oss.str("");
    oss << a;
    assert(oss.str() == "2004-02-10");
    b = b - 2000;
    oss.str("");
    oss << b;
    assert(oss.str() == "2004-08-13");
    assert(b - a == 185);

    assert((b == a) == false);
    assert((b != a) == true);
    assert((b <= a) == false);
    assert((b < a) == false);
    assert((b >= a) == true);
    assert((b > a) == true);
    assert((c == a) == true);
    assert((c != a) == false);
    assert((c <= a) == true);
    assert((c < a) == false);
    assert((c >= a) == true);
    assert((c > a) == false);
    a = ++c;

    oss.str("");
    oss << a << " " << c;
    assert(oss.str() == "2004-02-11 2004-02-11");
    a = --c;
    oss.str("");
    oss << a << " " << c;
    assert(oss.str() == "2004-02-10 2004-02-10");
    a = c++;
    oss.str("");
    oss << a << " " << c;
    assert(oss.str() == "2004-02-10 2004-02-11");
    a = c--;
    oss.str("");
    oss << a << " " << c;
    assert(oss.str() == "2004-02-11 2004-02-10");
    iss.clear();
    iss.str("2015-09-03");
    assert((iss >> a));
    oss.str("");
    oss << a;
    assert(oss.str() == "2015-09-03");
    a = a + 70;
    oss.str("");
    oss << a;
    assert(oss.str() == "2015-11-12");

    CDate d(2000, 1, 1);
    try
    {
        CDate e(2000, 32, 1);
        assert("No exception thrown!" == nullptr);
    }
    catch (...)
    {
    }
    iss.clear();
    iss.str("2000-12-33");
    iss >> d;
    assert(!(iss >> d));
    oss.str("");
    oss << d;
    assert(oss.str() == "2000-01-01");
    iss.clear();
    iss.str("2000-11-31");
    iss >> d;
    assert(!(iss >> d));
    oss.str("");
    oss << d;
    assert(oss.str() == "2000-01-01");
    iss.clear();
    iss.str("2000-02-29");
    assert((iss >> d));
    oss.str("");
    oss << d;
    assert(oss.str() == "2000-02-29");
    iss.clear();
    iss.str("2001-02-29");
    iss >> d;
    assert(!(iss >> d));
    oss.str("");
    oss << d;
    assert(oss.str() == "2000-02-29");

    //-----------------------------------------------------------------------------
    // bonus test examples
    //-----------------------------------------------------------------------------
    // CDate f(2000, 5, 12);
    // oss.str("");
    // oss << f;
    // assert(oss.str() == "2000-05-12");
    // oss.str("");
    // oss << date_format("%Y/%m/%d") << f;
    // assert(oss.str() == "2000/05/12");
    // oss.str("");
    // oss << date_format("%d.%m.%Y") << f;
    // assert(oss.str() == "12.05.2000");
    // oss.str("");
    // oss << date_format("%m/%d/%Y") << f;
    // assert(oss.str() == "05/12/2000");
    // oss.str("");
    // oss << date_format("%Y%m%d") << f;
    // assert(oss.str() == "20000512");
    // oss.str("");
    // oss << date_format("hello kitty") << f;
    // assert(oss.str() == "hello kitty");
    // oss.str("");
    // oss << date_format("%d%d%d%d%d%d%m%m%m%Y%Y%Y%%%%%%%%%%") << f;
    // assert(oss.str() == "121212121212050505200020002000%%%%%");
    // oss.str("");
    // oss << date_format("%Y-%m-%d") << f;
    // assert(oss.str() == "2000-05-12");
    // iss.clear();
    // iss.str("2001-01-1");
    // assert(!(iss >> f));
    // oss.str("");
    // oss << f;
    // assert(oss.str() == "2000-05-12");
    // iss.clear();
    // iss.str("2001-1-01");
    // assert(!(iss >> f));
    // oss.str("");
    // oss << f;
    // assert(oss.str() == "2000-05-12");
    // iss.clear();
    // iss.str("2001-001-01");
    // assert(!(iss >> f));
    // oss.str("");
    // oss << f;
    // assert(oss.str() == "2000-05-12");
    // iss.clear();
    // iss.str("2001-01-02");
    // assert((iss >> date_format("%Y-%m-%d") >> f));
    // oss.str("");
    // oss << f;
    // assert(oss.str() == "2001-01-02");
    // iss.clear();
    // iss.str("05.06.2003");
    // assert((iss >> date_format("%d.%m.%Y") >> f));
    // oss.str("");
    // oss << f;
    // assert(oss.str() == "2003-06-05");
    // iss.clear();
    // iss.str("07/08/2004");
    // assert((iss >> date_format("%m/%d/%Y") >> f));
    // oss.str("");
    // oss << f;
    // assert(oss.str() == "2004-07-08");
    // iss.clear();
    // iss.str("2002*03*04");
    // assert((iss >> date_format("%Y*%m*%d") >> f));
    // oss.str("");
    // oss << f;
    // assert(oss.str() == "2002-03-04");
    // iss.clear();
    // iss.str("C++09format10PA22006rulez");
    // assert((iss >> date_format("C++%mformat%dPA2%Yrulez") >> f));
    // oss.str("");
    // oss << f;
    // assert(oss.str() == "2006-09-10");
    // iss.clear();
    // iss.str("%12%13%2010%");
    // assert((iss >> date_format("%%%m%%%d%%%Y%%") >> f));
    // oss.str("");
    // oss << f;
    // assert(oss.str() == "2010-12-13");

    // CDate g(2000, 6, 8);
    // iss.clear();
    // iss.str("2001-11-33");
    // assert(!(iss >> date_format("%Y-%m-%d") >> g));
    // oss.str("");
    // oss << g;
    // assert(oss.str() == "2000-06-08");
    // iss.clear();
    // iss.str("29.02.2003");
    // assert(!(iss >> date_format("%d.%m.%Y") >> g));
    // oss.str("");
    // oss << g;
    // assert(oss.str() == "2000-06-08");
    // iss.clear();
    // iss.str("14/02/2004");
    // assert(!(iss >> date_format("%m/%d/%Y") >> g));
    // oss.str("");
    // oss << g;
    // assert(oss.str() == "2000-06-08");
    // iss.clear();
    // iss.str("2002-03");
    // assert(!(iss >> date_format("%Y-%m") >> g));
    // oss.str("");
    // oss << g;
    // assert(oss.str() == "2000-06-08");
    // iss.clear();
    // iss.str("hello kitty");
    // assert(!(iss >> date_format("hello kitty") >> g));
    // oss.str("");
    // oss << g;
    // assert(oss.str() == "2000-06-08");
    // iss.clear();
    // iss.str("2005-07-12-07");
    // assert(!(iss >> date_format("%Y-%m-%d-%m") >> g));
    // oss.str("");
    // oss << g;
    // assert(oss.str() == "2000-06-08");
    // iss.clear();
    // iss.str("20000101");
    // assert((iss >> date_format("%Y%m%d") >> g));
    // oss.str("");
    // oss << g;
    // assert(oss.str() == "2000-01-01");

    return EXIT_SUCCESS;
}
#endif /* __PROGTEST__ */