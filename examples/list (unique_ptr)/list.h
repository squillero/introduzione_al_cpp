// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#pragma once

#include <memory>

struct Node
{
    int data;
    std::unique_ptr<Node> next = nullptr;
    Node() { std::cout << "Creo Node@" << this << std::endl; };
    ~Node() { std::cout << "Distruggo Node@" << this << std::endl; };
};

class List
{
    std::unique_ptr<Node> head = nullptr;

public:
    void add(int data);
    void del_first();
    void dump();
};
