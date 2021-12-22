// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
//#include <string>

class Time_error
{
};

class Time
{
private:
    int h_, m_, s_;

public:
    void h(int x)
    {
        if (x < 0 || x > 24)
            throw Time_error();
        h_ = x;
    };
    void m(int x)
    {
        if (x < 0 || x > 60)
            throw Time_error();
        m_ = x;
    };
    void s(int x)
    {
        if (x < 0 || x > 60)
            throw Time_error();
        s_ = x;
    };
    int h() { return h_; };
    int m() { return m_; };
    int s() { return s_; };

    // constructors
    Time() = default;

    Time(int h, int m, int s) : h_{h}, m_{m}, s_{s}
    {
        std::cout << "Time(int h, int m, int s)" << std::endl;
    };
};

int main()
{
    Time t42;
    std::cout << "Sono le " << t42.h() << ":" << t42.m() << ":" << t42.s() << std::endl;
    Time t43{};
    std::cout << "Sono le " << t43.h() << ":" << t43.m() << ":" << t43.s() << std::endl;

    Time t0(20, 30, 15);
    std::cout << "Sono le " << t0.h() << ":" << t0.m() << ":" << t0.s() << std::endl;

    t0.h(10);
    std::cout << "Sono le " << t0.h() << ":" << t0.m() << ":" << t0.s() << std::endl;

    t0.m(42);
    std::cout << "Sono le " << t0.h() << ":" << t0.m() << ":" << t0.s() << std::endl;

    return EXIT_SUCCESS;
}
