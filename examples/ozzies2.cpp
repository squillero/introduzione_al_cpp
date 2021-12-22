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
    std::vector<std::unique_ptr<Ozzy>> wizards;

    wizards.push_back(std::make_unique<Ozzy>());
    wizards.push_back(std::make_unique<Ozzy>());
    wizards.push_back(std::make_unique<Ozzy>());

    std::for_each(wizards.begin(), wizards.end(),
                  [](const std::unique_ptr<Ozzy> &o)
                  { std::cout << " " << o.get(); });
    std::cout << std::endl;

    std::cout << "Deleting Ozzy number 2" << std::endl;
    auto itr = wizards.begin() + 1;
    wizards.erase(itr); // also erase the Ozzy!
    std::cout << "That's all folks" << std::endl;

    std::for_each(wizards.begin(), wizards.end(),
                  [](const std::unique_ptr<Ozzy> &o)
                  { std::cout << " " << o.get(); });
    std::cout << std::endl;

    // no memory leaked
    return 0;
}
