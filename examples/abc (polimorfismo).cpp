// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <string>

class A
{
public:
    virtual void foo() = 0;
    virtual void bar();
    void baz() { std::cout << "A::baz (inline)" << std::endl; };
};

void A::bar()
{
    std::cout << "A::bar!" << std::endl;
}

class B1 : public A
{
public:
    void foo() { std::cout << "B1::foo (inline)" << std::endl; };
    void bar() { std::cout << "B1::bar (inline)" << std::endl; };
    void baz() { std::cout << "B1::baz (inline)" << std::endl; };
};

class B2 : public A
{
public:
    void foo() { std::cout << "B2::foo (inline)" << std::endl; };
    void baz() { std::cout << "B2::baz (inline)" << std::endl; };
};

class C : public B2
{
public:
    void bar() { std::cout << "C::bar (inline)" << std::endl; };
    void baz() { std::cout << "C::baz (inline)" << std::endl; };
};

int main()
{
    B1 b1;
    B2 b2;

    b1.foo();
    b1.bar();
    b1.baz();

    b2.foo();
    b2.bar();
    b2.baz();

    A *generic;

    std::cout << "\n";
    generic = &b1;
    generic->foo();
    generic->bar();
    generic->baz();

    std::cout << "\n";
    generic = &b2;
    generic->foo();
    generic->bar();
    generic->baz();

    std::cout << "\n";
    C c;
    generic = &c;
    generic->foo();
    generic->bar();
    generic->baz();
    c.baz();
    C *puntatore_a_c = &c;
    puntatore_a_c->baz();
    B2 *puntature_a_b2 = &c;
    puntature_a_b2->baz();
    puntature_a_b2->bar();
}
