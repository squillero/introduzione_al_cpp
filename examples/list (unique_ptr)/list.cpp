// Copyright © 2019 Giovanni Squillero <squillero@polito.it>
// Free for personal or classroom use; see 'LICENCE.md' for details.
// https://github.com/squillero/introduzione_al_cpp

#include <iostream>
#include <string>

#include "list.h"

void List::dump()
{
    std::cout << "List:";
    for (Node *n = head.get(); n; n = n->next.get())
        std::cout << " " << n->data;
    std::cout << std::endl;
}

void List::add(int data)
{
    auto n = std::make_unique<Node>();
    n->data = data;
    n->next = std::move(head);
    head = std::move(n);
}

void List::del_first()
{
    // unique_ptr magic!
    if (!head)
        return;
    std::cout << "head: " << head << std::endl;
    auto n = std::move(head);
    std::cout << "head: " << head << std::endl;
    head = std::move(n->next);
}
