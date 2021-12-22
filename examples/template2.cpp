// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <string>
#include <typeinfo>

template <typename T>
void my_size(T d)
{
    std::cout << "val: " << d << " " << typeid(d).name() << " (" << sizeof(T)
              << " bytes)" << std::endl;
}

int main()
{
    my_size(42);
    my_size('4');
    my_size(4.2);
    my_size(std::string{"Hey!"});

    my_size<double>(42);
    my_size<short int>(4.2);

    return EXIT_SUCCESS;
}
