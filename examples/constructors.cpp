// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <string>

class Flower
{
    std::string kind = "iris";

public:
    Flower(std::string k)
    {
        std::cout << "Flower(k=" << k << ")" << std::endl;
        kind = k;
    }
    Flower(Flower &&f)
    {
        kind = std::move(f.kind);
        std::cout << "Flower(Flower&& f) -- move constructor" << std::endl;
    }
    Flower(Flower &f) : kind{f.kind}
    {
        std::cout << "Flower(Flower& f) -- copy constructor" << std::endl;
    }
};

Flower power()
{
    Flower f{"daisy"}; // constructor
    return f;          // move constructor
}

int main()
{
    Flower f{"rose"}; // constructor
    Flower f2 = f;    // copy

    Flower p = power(); //

    return EXIT_SUCCESS;
}
