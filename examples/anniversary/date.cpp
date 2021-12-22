// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <string>
#include <sstream>

#include "date.h"

bool Date::valid() const
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

std::string Date::to_string() const
{
    return std::to_string(day_) + "-" + md[month_].n + "-" + std::to_string(year_);
}

std::ostream &operator<<(std::ostream &out, const Date &d)
{
    out << d.day_ << "-" << d.md[d.month_].n << "-" << d.year_;
    return out;
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
