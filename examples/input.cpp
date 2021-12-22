// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <vector>
#include <algorithm>

double avg(std::vector<int> array)
{
    double sum = 0;
    for (auto n : array)
        sum += n;
    return sum / array.size();
}

bool present(int num, std::vector<int> array)
{
    for (auto n : array)
        if (n == num)
            return true;
    return false;
}

int main()
{

    std::vector<int> array;
    int val;
    do
    {
        std::cin >> val;
        // if(val >= 0 && !present(val, array))
        if (val >= 0 && find(array.begin(), array.end(), val) == array.end())
            array.push_back(val);
    } while (val >= 0);

    std::cout << "Media: " << avg(array);
    return EXIT_SUCCESS;
}
