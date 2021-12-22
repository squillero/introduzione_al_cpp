// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <string>
#include <unordered_set>

struct Musicista
{
    std::string nome;
    std::string cognome;

    bool operator==(const Musicista &m) const
    {
        return nome == m.nome && cognome == m.cognome;
    }
};

template <>
struct std::hash<Musicista>
{
    size_t operator()(const Musicista &m) const
    {
        return std::hash<std::string>()(m.nome + "#" + m.cognome);
    }
};

int main()
{
    std::unordered_set<Musicista> beatles;

    auto hash_calculator = std::hash<Musicista>();
    auto o = hash_calculator(Musicista({"Ozzy", "Osbourne"}));
    std::cout << "Hash di OO: " << o << std::endl;

    beatles.insert(Musicista({"John", "Lennon"}));
    beatles.insert(Musicista({"Paul", "Mcartney"}));
    beatles.insert(Musicista({"Ringo", "Starr"}));
    beatles.insert(Musicista({"George", "Harrison"}));

    for (const auto &b : beatles)
        std::cout << b.nome << " " << b.cognome << " (" << hash_calculator(b) << ")" << std::endl;

    return 0;
}
