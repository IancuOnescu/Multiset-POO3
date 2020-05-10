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
    std::cout << ms;
    return 0;
}
