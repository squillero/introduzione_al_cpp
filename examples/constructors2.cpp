// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <string>

class Useless
{
private:
    int num;

public:
    Useless(int n) : num{n}
    {
        std::cout << "Useless(int n)" << std::endl;
    };

    /**
    Useless(Useless& u) : num{ u.num } {
        std::cout << "Useless(Useless& u)" << std::endl;
    };
    **/
    Useless(Useless &u) = default;
    Useless(Useless &&u) : num{u.num}
    {
        std::cout << "Useless(Useless&& u)" << std::endl;
    };

    // friend functions
    friend std::ostream &operator<<(std::ostream &out, const Useless &u);
};

std::ostream &operator<<(std::ostream &out, const Useless &u)
{
    out << "Useless{" << u.num << "}";
    return out;
}

Useless test(int n)
{
    Useless x{n};
    return x;
}

int main()
{
    Useless u42{42}; // Costruttore standard
    std::cout << u42 << std::endl;

    Useless u = u42; // Costruttore di copia
    std::cout << u << std::endl;

    std::cout << test(17) << std::endl;

    return EXIT_SUCCESS;
}
