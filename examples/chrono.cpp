// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <chrono>

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    // calcoli…
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << "ms" << std::endl;

    return 0;
}
