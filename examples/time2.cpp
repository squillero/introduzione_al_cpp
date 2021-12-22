// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <string>

typedef unsigned long long second_t;

// User-defined literals
constexpr second_t operator"" _h(unsigned long long hour)
{
    return hour * 60 * 60;
}
constexpr second_t operator"" _m(unsigned long long min)
{
    return min * 60;
}
constexpr second_t operator"" _s(second_t sec)
{
    return sec;
}

class Time
{
    friend std::ostream &operator<<(std::ostream &out, const Time &t);

    second_t h, m, s;

    void patch()
    {
        m += s / 60;
        s %= 60;
        h += m / 60;
        m %= 60;
    }

public:
    Time &operator+=(second_t);

    operator second_t()
    {
        return 1_h * h + 1_m * m + 1_s * s;
    }
};

Time &Time::operator+=(second_t inc)
{
    s += inc;
    patch();
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Time &t)
{
    if (t.h > 0)
        out << t.h << "h";
    if (t.m > 0)
        out << t.m << "'";
    out << t.s << "\"";
    return out;
}

int main()
{
    Time t{};
    std::cout << t << std::endl;

    t += 100_m + 1_h + 12_s;
    std::cout << t << std::endl;

    std::cout << second_t{t} << std::endl;

    int x = 23 + t;

    return EXIT_SUCCESS;
}
