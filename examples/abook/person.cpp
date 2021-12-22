// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "person.h"

Person::operator std::string() const
{
    return this->name_ + " " + this->surname_ + " (" + this->ssn_ + ")";
}

bool Person::operator==(const Person &p) const
{
    return ssn_ == p.ssn_;
}

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << p.name_ << " " << p.surname_ << " (" << p.ssn_ << ")";
    return os;
}
