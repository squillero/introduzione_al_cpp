// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <vector>
#include <algorithm>

void foo(int *x)
{
    ++*x;
}

void bar(int &x)
{
    ++x;
}

void run_all(std::vector<int> array, void (*func)(int))
{
    for (int n : array)
        func(n);
}

void test(int x)
{
    std::cout << "Hello! I'm testing " << x << std::endl;
}

int main()
{
    int var{42};

    foo(&var);
    bar(var);

    // f � un puntatore ad una funzione void
    // che riceve un puntatore a intero
    void (*f)(int *) = foo;

    // anche g
    auto g = foo;
    g(&var);

    // behavioral parametrization
    std::vector<int> v = {10, 23, 18, 5};
    run_all(v, test);
    auto zap = test;
    run_all(v, zap);

    // bp with lambda!
    run_all(v, [](int x)
            { std::cout << "[" << x << "]"; });
    auto lambda = [](int x)
    { std::cout << "{" << x << "}"; };
    run_all(v, lambda);

    std::cout << std::endl;
    int mult = 10;
    auto z = [&](int x)
    {
        std::cout << "<<" << x * mult << ">>";
        mult = 0;
    };
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
