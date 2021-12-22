// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <sstream>
#include <unordered_set>

int main()
{
    std::unordered_set<std::string> foo;

    std::string word;

    while (std::cin >> word)
    {
        auto i = foo.insert(word);
        if (i.second)
        {
            std::cout << "Bravo! Hai scritto \"" << word << "\"" << std::endl;
        }
        else
        {
            std::cout << "Parola \"" << word << "\" già inserita" << std::endl;
        }
    }

    std::cout << "Parole:";
    for (auto w : foo)
        std::cout << " " << w;
    std::cout << std::endl;

    return 0;
}
