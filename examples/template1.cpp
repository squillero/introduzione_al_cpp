// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <string>
#include <typeinfo>

class OptionalError
{
};

template <typename T>
class Optional
{
private:
    bool valid_ = false;
    T data_;

public:
    void data(T d)
    {
        valid_ = true;
        data_ = d;
    }
    T data()
    {
        if (!valid_)
            throw OptionalError();
        return data_;
    }
    bool valid()
    {
        return valid_;
    }
    void invalidate()
    {
        valid_ = false;
    }
};

int main()
{
    Optional<int> opt;

    opt.data(42);
    std::cout << opt.data() << " :" << typeid(opt.data()).name() << std::endl;
    opt.invalidate();

    Optional<std::string> opt2;
    opt2.data("ciao");
    std::cout << opt2.data() << std::endl;

    return EXIT_SUCCESS;
}
