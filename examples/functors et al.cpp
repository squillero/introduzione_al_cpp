// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <string>
#include <typeinfo>

template <int V1, int V2>
void ok(int num)
{
    std::cout << num << " in [" << V1 << ", " << V2 << "] -> ";
    if (num >= V1 && num <= V2)
        std::cout << "yeah!";
    else
        std::cout << "nope";
    std::cout << std::endl;
}

class ClassOk
{
private:
    int v1, v2;

public:
    ClassOk(int v1, int v2) : v1{v1}, v2{v2} {};
    void operator()(int num)
    {
        std::cout << num << " in [" << v1 << ", " << v2 << "] -> ";
        if (num >= v1 && num <= v2)
            std::cout << "yeah!";
        else
            std::cout << "nope";
        std::cout << std::endl;
    }
};

void ok3(int num, int v1 = -1, int v2 = -1)
{
    static int v1_;
    static int v2_;

    if (v1 > -1)
        v1_ = v1;
    if (v2 > -1)
        v2_ = v2;
    if (v1 > 0 || v2 > 0)
        return;

    std::cout << num << " in [" << v1_ << ", " << v2_ << "] -> ";
    if (num >= v1_ && num <= v2_)
        std::cout << "yeah!";
    else
        std::cout << "nope";
    std::cout << std::endl;
}

int main()
{
    constexpr int MIN = 0;
    constexpr int MAX = 100;

    ok<MIN, MAX>(101);

    ClassOk ok2(MIN, MAX);
    ok2(101);

    ok3(0, 0, 100);
    ok3(58);

    return EXIT_SUCCESS;
}
