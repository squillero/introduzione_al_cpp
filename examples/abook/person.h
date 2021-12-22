// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#pragma once

class Person
{
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    //template<> friend struct std::hash<Person>; -- how!?
private:
    std::string ssn_;
    std::string name_, surname_;
    std::string tel_;

public:
    Person(std::string ssn, std::string name, std::string surname, std::string tel) : ssn_{ssn}, name_{name}, surname_{surname}, tel_{tel}
    {
        std::cout << "Constructed Person @ " << this << std::endl;
    }
    Person(Person &p)
    {
        std::cout << "Copy-constructed Person @ " << this << std::endl;
        ssn_ = p.ssn_;
        name_ = p.name_;
        surname_ = p.surname_;
        tel_ = p.tel_;
    }
    Person(Person &&p)
    {
        std::cout << "Move-constructed Person @ " << this << std::endl;
        ssn_ = std::move(p.ssn_);
        name_ = std::move(p.name_);
        surname_ = std::move(p.surname_);
        tel_ = std::move(p.tel_);
    }
    virtual ~Person()
    {
        std::cout << "Destructed Person @ " << this << std::endl;
    }

public:
    std::string ssn() const { return ssn_; }
    std::string name() const { return name_; }
    void name(std::string n) { name_ = n; }
    std::string surname() const { return surname_; }
    void surname(std::string s) { surname_ = s; }
    std::string tel() const { return tel_; }
    void tel(std::string t) { tel_ = t; }

public:
    operator std::string() const;
    bool operator==(const Person &p) const;
};

template <>
struct std::hash<Person>
{
    size_t operator()(const Person &p) const
    {
        return std::hash<std::string>()(p.ssn());
    }
};
