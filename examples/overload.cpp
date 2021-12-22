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

struct Time
{
    second_t h, m, s;
    Time &operator+=(second_t);
    void patch()
    {
        m += s / 60;
        s %= 60;
        h += m / 60;
        m %= 60;
    }
};

Time &Time::operator+=(second_t inc)
{
    s += inc;
    patch();
    return *this;
}

Time operator+(Time t1, Time t2)
{
    Time t{};
    t += 1_h * (t1.h + t2.h) + 1_m * (t1.m + t2.m) + 1_s * (t1.s + t2.s);
    return t;
}

std::ostream &operator<<(std::ostream &out, const Time &t)
{
    out << t.h << "h" << t.m << "'" << t.s << "\"";
    return out;
}

int main()
{
    Time t{};
    std::cout << t << std::endl;

    t += 100_m + 1_h + 12_s;
    std::cout << t << std::endl;

    Time sum = Time({1, 10, 12}) + Time({1, 51, 1});
    std::cout << sum << std::endl;

    return EXIT_SUCCESS;
}
