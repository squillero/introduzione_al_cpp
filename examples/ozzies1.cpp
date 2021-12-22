// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

struct Ozzy
{
    int bat;
    Ozzy();
    virtual ~Ozzy()
    {
        std::cout << "Delete Ozzy @ " << this << std::endl;
    }
};
Ozzy::Ozzy()
{
    std::cout << "New Ozzy @ " << this << std::endl;
}

int main()
{
    std::vector<Ozzy *> wizards;

    wizards.push_back(new Ozzy);
    wizards.push_back(new Ozzy);
    wizards.push_back(new Ozzy);

    std::for_each(wizards.begin(), wizards.end(),
                  [](Ozzy *o)
                  { std::cout << " " << o; });
    std::cout << std::endl;

    auto itr = wizards.begin() + 1;
    delete *itr;
    wizards.erase(itr);

    std::for_each(wizards.begin(), wizards.end(),
                  [](Ozzy *o)
                  { std::cout << " " << o; });
    std::cout << std::endl;

    return 0;
}
