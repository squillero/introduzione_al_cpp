// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <string>

struct C
{
    int foo;
    virtual ~C(){};
};

struct D1 : C
{
    int bar;
};
struct D2 : C
{
    int bar2;
};

int main()
{
    C *pc;
    D1 d1;
    D1 *pd1 = &d1;
    D2 d2;
    D2 *pd2 = &d2;

    pc = dynamic_cast<C *>(pd1);
    std::cout << "c:" << pc << " :: d1:" << pd1 << " :: d2:" << pd2 << std::endl;
    pd1 = dynamic_cast<D1 *>(pc);
    std::cout << "c:" << pc << " :: d1:" << pd1 << " :: d2:" << pd2 << std::endl;
    pd2 = dynamic_cast<D2 *>(pc);
    std::cout << "c:" << pc << " :: d1:" << pd1 << " :: d2:" << pd2 << std::endl;
}