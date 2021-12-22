// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <string>

#include "list.h"

int main()
{
    List l;

    l.add(23);
    l.add(10);
    l.add(18);
    l.add(5);
    l.dump();

    l.del_first();
    l.dump();
}