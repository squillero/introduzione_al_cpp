// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <vector>

constexpr size_t n_primi = 10000;

typedef unsigned long long int primo_t;

bool divisibile(primo_t numero, const std::vector<primo_t> list)
{
    for (auto n : list)
        if (numero % n == 0)
            return true;
    return false;
}

bool divisibile2(primo_t numero, const std::vector<primo_t> list)
{
    primo_t max = std::sqrt(numero);
    for (auto n = list.begin(); *n <= max; ++n)
        if (numero % *n == 0)
            return true;
    return false;
}

int main()
{
    std::vector<primo_t> primi = {2, 3};

    auto numero = primi[1];
    while (primi.size() < n_primi)
    {
        numero += 2;
        if (!divisibile2(numero, primi))
            primi.push_back(numero);
    }

    std::cout << "Last but not least: " << primi[primi.size() - 1] << std::endl;

    //for(auto n : primi)
    //    std::cout << n << " ";
    //std::cout << std::endl;

    return EXIT_SUCCESS;
}
