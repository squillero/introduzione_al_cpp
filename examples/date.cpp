// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <string>
#include <sstream>

class Date
{
private:
    int day_, month_, year_;

public:
    // default constructor
    Date() : day_{1}, month_{1}, year_{1970}
    {
        std::cout << "Date()" << std::endl;
    }

    // "normal" constructor
    Date(int d, int m, int y) : day_{d}, month_{m}, year_{y}
    {
        std::cout << "Date(int d, int m, int y)" << std::endl;
    }

    // copy constructor
    Date(const Date &d) : day_{d.day_}, month_{d.month_}, year_{d.year_}
    {
        std::cout << "Date(const Date& d)" << std::endl;
    }

    void day(int d) { day_ = d; }
    int day() { return day_; }
    void month(int m) { month_ = m; }
    int month() { return month_; }
    void year(int y) { year_ = y; }
    int year() { return year_; }

    std::string to_string() const;
};

std::string Date::to_string() const
{
    std::stringstream ss;
    ss << day_ << "-" << month_ << "-" << year_;
    return ss.str();
}

void print_date(Date d)
{
    std::cout << d.to_string() << std::endl;
}

Date foo()
{
    Date d;
    return d;
}

int main()
{
    Date today{16, 4, 2019};

    Date today_again1(today);
    Date today_again2{today};
    Date today_again3 = today;

    print_date(today);
    foo();

    Date zap = {22, 10, -4004};

    return EXIT_SUCCESS;
}
