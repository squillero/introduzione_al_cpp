// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>

constexpr size_t SIZE = 12;

int main()
{
    //auto start = std::chrono::high_resolution_clock::now();
    //auto end = std::chrono::high_resolution_clock::now();
    //std::cout << std::chrono::duration<double, std::milli>(end - start).count() << "ms" << std::endl;

    auto mat = std::vector<std::vector<int>>(SIZE, std::vector<int>(SIZE));

    for (auto x = 0; x < SIZE; ++x)
    {
        for (auto y = 0; y < SIZE; ++y)
        {
            mat[x][y] = (x + 1) * (y + 1);
        }
    }

    for (auto x = 0; x < SIZE; ++x)
    {
        for (auto y = 0; y < SIZE; ++y)
        {
            std::cout << "  " << mat[x][y];
        }
        std::cout << std::endl;
    }

    return 0;
}
