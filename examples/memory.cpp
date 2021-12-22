// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <string>
#include <memory>

struct A
{
    int foo;
    double bar;
    A() : foo{42}, bar{0.1} { std::cout << "new A @ " << this << std::endl; };
    ~A() { std::cout << "delete A @ " << this << std::endl; };
};

int main()
{
    // vecchio stile C
    A *array = static_cast<A *>(std::malloc(1000 * sizeof(A)));
    std::cout << "0} foo:" << array[0].foo << " bar:" << array[0].bar << std::endl;
    std::free(array);

    // vecchio stile C++
    A *gargle = new A;
    std::cout << "gargle} foo:" << gargle->foo << " bar:" << gargle->bar << std::endl;
    delete gargle;

    // nuovo stile!
    std::unique_ptr<A> blaster{new A};

    // nuovissimo stile!
    auto blaster2 = std::make_unique<A>();
}
