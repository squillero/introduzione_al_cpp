// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <string>
#include <set>

struct Musicista
{
    std::string nome;
    std::string cognome;
};

bool operator<(const Musicista &a1, const Musicista &a2)
{
    if (a1.cognome != a2.cognome)
        return a1.cognome < a2.cognome;
    else
        return a1.nome < a2.nome;
}

int main()
{
    std::set<Musicista> beatles;

    beatles.insert(Musicista({"John", "Lennon"}));
    beatles.insert(Musicista({"Paul", "Mcartney"}));
    beatles.insert(Musicista({"Ringo", "Starr"}));
    beatles.insert(Musicista({"George", "Harrison"}));

    for (const auto &b : beatles)
        std::cout << b.nome << " " << b.cognome << std::endl;

    return 0;
}
