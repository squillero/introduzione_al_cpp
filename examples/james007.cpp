// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <string>

class Agent {
private:
    std::string code_name_;
public:
    std::string name;
    std::string surname;

    // getter
    std::string code_name() const {
        return code_name_;
    }
    // setter
    void code_name(const std::string n) {
        code_name_ = n;
    }

    void greet() const {
        std::cout << "My name is " << surname << ", " << name << " " << surname << "." << std::endl;
    }
};

int main() {
    Agent jb;

    jb.code_name("007");

    jb.greet();

    return EXIT_SUCCESS;
}
