// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <list>

int main()
{
    std::list<int> odd;
    std::list<int> even;

    for (int t = 0; t < 100; ++t)
        if (t % 2)
            odd.push_back(t);
        else
            even.push_back(t);

    auto x = even.begin();
    even.splice(x, odd, odd.begin(), odd.end());

    for (auto l : even)
    {
        std::cout << " " << l;
    }
    std::cout << std::endl;

    return 0;
}
