// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <sstream>
#include <string>
#include <map>

int main()
{
    std::map<std::string, int> contatore;

    std::string s;
    while (std::cin >> s)
    {
        auto p = std::make_pair(s, 0);
        auto r = contatore.insert(p);
        ++r.first->second;
    }

    for (const auto &e : contatore)
        std::cout << e.first << " " << e.second << " volte" << std::endl;

    return 0;
}
