// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>

class Animal
{
private:
    int foo_private;

protected:
    int bar_protected;

public:
    virtual void move() const = 0;
};

class Snake : public Animal
{
    mutable int num = 0;

public:
    void set()
    {
        bar_protected = 1;
    }

    virtual void move() const
    {
        ++num;
        std::cout << this << " is crawling..." << std::endl;
    }
};

class Bird : public Animal
{
public:
    void set()
    {
        bar_protected = 1;
    }
    void eat()
    {
        std::cout << this << " is eating!" << std::endl;
    }
    virtual void move() const
    {
        std::cout << this << " is flying!" << std::endl;
    }
};

class Penguin : public Bird
{
public:
    virtual void move() const
    {
        std::cout << this << " is swimming!" << std::endl;
    }
};

int main()
{
    Bird b1, b2;
    Penguin p;
    Snake s;

    Animal *ark[4] = {&b1, &p, &s, &b2};
    for (auto a : ark)
    {
        a->move();
    }

    return EXIT_SUCCESS;
}
