// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <string>
#include <sstream>

struct Bad_date
{
    std::string explanation;
};

class Date
{
private:
    int day_, month_, year_;
    mutable struct
    {
        std::string n;
        int d;
    } md[13] =
        {
            {"", 0},
            {"january", 31},
            {"february", 28},
            {"march", 31},
            {"april", 30},
            {"may", 31},
            {"june", 30},
            {"july", 31},
            {"august", 31},
            {"september", 30},
            {"october", 31},
            {"november", 30},
            {"december", 31}};

public:
    // enum class
    enum class Months : short int
    {
        january = 1,
        february,
        march,
        april,
        may,
        june,
        july,
        august,
        september,
        october,
        december
    };

    // default constructor
    Date() : day_{1}, month_{1}, year_{1970}
    {
        std::cout << "Date()" << std::endl;
    }

    // "normal" constructor
    Date(int d, int m, int y) : day_{d}, month_{m}, year_{y}
    {
        std::cout << "Date(int d, int m, int y)" << std::endl;

        if (!valid())
            throw Bad_date({"Illegal date"});
    }

    // copy constructor
    Date(const Date &d) : day_{d.day_}, month_{d.month_}, year_{d.year_}
    {
        std::cout << "Date(const Date& d)" << std::endl;
    }

    bool valid() const
    {
        if (year_ % 400 == 0 ||
            (year_ % 4 == 0 && year_ % 100 != 0))
            md[2].d = 29;
        else
            md[2].d = 28;

        if (month_ < 1 || month_ > 12)
            return false;
        if (day_ < 1 || day_ > md[month_].d)
            return false;
        return true;
    }

    // setters & getters
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
    return std::to_string(day_) + "-" + md[month_].n + "-" + std::to_string(year_);
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

    try
    {
        Date zap{29, Date::Months::february, 1900};
    }
    catch (Bad_date err)
    {
        std::cerr << "Yeuch: " << err.explanation << std::endl;
    }
    return EXIT_SUCCESS;
}
