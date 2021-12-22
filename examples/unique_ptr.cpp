// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <string>
#include <memory>

struct B
{
    B() { std::cout << "new B @ " << this << std::endl; };
    ~B() { std::cout << "delete B @ " << this << std::endl; };
};

struct A
{
    int foo;
    double bar;
    std::unique_ptr<B> b1 = std::make_unique<B>();
    B *b2;
    A() : foo{42}, bar{0.1}
    {
        std::cout << "new A @ " << this << std::endl;
        b2 = new B; // vecchio C++
    };
    ~A()
    {
        std::cout << "delete A @ " << this << std::endl;
        delete b2; // vecchio C++
    };
};

int main()
{
    A *a = new A;

    B *b = a->b2;
    B *vecchio_stile = a->b1.get();
    {
        std::unique_ptr<B> b1;
        b1 = std::move(a->b1);
        std::cout << "1" << std::endl;
    }
    std::cout << "2" << std::endl;
    delete a; // provera` a delete b2
    std::cout << "Oh yeah" << std::endl;
}
