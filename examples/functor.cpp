// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <string>

struct Birillo
{
    int num;

    int operator()(int x)
    {
        return x + num;
    }
};

int main()
{
    Birillo b42{42};
    Birillo b10{10};

    // functor!
    std::cout << b42(10) << " " << b10(10) << std::endl;

    std::cout << Birillo{10}(17) << std::endl;

    return EXIT_SUCCESS;
}
