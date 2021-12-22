// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <string>
#include <unordered_map>

#include "person.h"

class ABook
{
private:
    std::unordered_map<std::string, Person> data;

public:
    void add(std::string ssn, std::string name, std::string surname, std::string tel);
    void erase(std::string ssn);
    void modify(std::string ssn, std::string name, std::string surname, std::string tel);
};

void ABook::add(std::string ssn, std::string name, std::string surname, std::string tel)
{
    if (data.find(ssn) != data.end())
        throw std::invalid_argument(ssn);
    data.emplace(ssn, Person(ssn, name, surname, tel));
}

void ABook::erase(std::string ssn)
{
    if (data.find(ssn) == data.end())
        throw std::invalid_argument(ssn);
    data.erase(ssn);
}

void ABook::modify(std::string ssn, std::string name, std::string surname, std::string tel)
{
    if (data.find(ssn) == data.end())
        throw std::invalid_argument(ssn);
    erase(ssn);
    add(ssn, name, surname, tel);
}

int main()
{
    ABook test;
    test.add("007", "James", "Bond", "na.");
    test.modify("007", "James", "Bond", "+39 011 090 7186");

    std::cout << "\nThat's all folks!" << std::endl;
    return 0;
}
