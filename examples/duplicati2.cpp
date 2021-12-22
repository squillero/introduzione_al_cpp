// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <vector>
#include <ctime>

constexpr size_t max_dim = 1000;
constexpr size_t max_num = 100;

int main()
{
    std::vector<int> numbers;

    // srand(time(NULL));
    for (auto t = 0; t < max_dim; ++t)
        numbers.push_back(rand() % (max_num + 1));

    for (auto n : numbers)
        std::cout << n << " ";
    std::cout << std::endl;

    auto itr = numbers.begin();
    while (itr != numbers.end())
    {
        bool duplicated = false;
        for (auto itr2 = numbers.begin(); itr2 != itr; ++itr2)
            if (*itr == *itr2 && itr2 != itr)
                duplicated = true;
        if (duplicated)
        {
            std::cout << *itr << " is a dup!" << std::endl;
            itr = numbers.erase(itr);
        }
        else
        {
            ++itr;
        }
    }

    for (auto n : numbers)
        std::cout << n << " ";
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
