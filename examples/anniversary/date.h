// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#pragma once

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
    Date(int d, Months m, int y) : day_{d}, month_{static_cast<int>(m)}, year_{y}
    {
        std::cout << "Date(int d, Months m, int y)" << std::endl;

        if (!valid())
            throw Bad_date({"Illegal date"});
    }

    // copy constructor
    Date(const Date &d) : day_{d.day_}, month_{d.month_}, year_{d.year_}
    {
        std::cout << "Date(const Date& d)" << std::endl;
    }

    bool valid() const;

    // setters & getters
    void day(int d) { day_ = d; }
    int day() { return day_; }
    void month(int m) { month_ = m; }
    int month() { return month_; }
    void year(int y) { year_ = y; }
    int year() { return year_; }

    std::string to_string() const;

    friend std::ostream &operator<<(std::ostream &out, const Date &d);
};

std::ostream &operator<<(std::ostream &out, const Date &d);

void print_date(Date d);
Date foo();
