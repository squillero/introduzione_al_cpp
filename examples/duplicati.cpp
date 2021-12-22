// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <vector>
#include <ctime>

constexpr size_t max_dim = 1000;
constexpr size_t max_num = 999;

int count(int number, std::vector<int> array)
{
    int cnt = 0;
    for (auto n : array)
        if (number == n)
            ++cnt;
    return cnt;
}

int main()
{
    std::vector<int> numbers;

    srand(time(NULL));
    for (auto t = 0; t < max_dim; ++t)
        numbers.push_back(rand() % (max_num + 1));

    int dups = 0;
    for (auto n : numbers)
    {
        std::cout << n;
        if (count(n, numbers) > 1)
        {
            std::cout << "*";
            ++dups;
        }
        std::cout << " ";
    }
    std::cout << "\n\nFound " << dups << " duplicates" << std::endl;
    return EXIT_SUCCESS;
}
