#include <iostream>
#include "Multiset.h"

int main() {
    Multiset<int> ms;
    ms.Push(5);
    ms.Push(7);
    ms.Push(7);
    ms.Push(6);
    ms.Push(8);
    ms.Push(7);
    ms.DeleteAll(5);
    std::cout << ms;

    Multiset<int> md;
    md.Push(5);
    md.Push(7);
    md.Push(5);
    std::cout << md;
    md = ms;
    std::cout << md;
    return 0;
}
