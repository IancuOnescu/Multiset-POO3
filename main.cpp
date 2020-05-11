#include <iostream>
#include "Multiset.h"

//for testing purposes only
int Incerementer(int val){
    return ++val;
}

class Increment {
public:
    explicit Increment(int num) : num_(num) { }
    int operator()(int x) const { return x + num_; }
private:
    int num_;
};
//end of testers declaration

int main() {
    //push and del testing
    Multiset<int> ms;
    ms.Push(5);
    ms.Push(7);
    ms.Push(7);
    ms.Push(6);
    ms.Push(8);
    ms.Push(7);
    ms.DeleteAll(5);
    std::cout << ms; // 6 7 7 7 8

    //count and belong testing
    std::cout << ms.Belongs(7) << std::endl; // 1 for True
    std::cout << ms.Count(7) << std::endl; // 3
    std::cout << ms.CountAll() << std::endl; // 3

    Multiset<int> md;
    md.Push(5);
    md.Push(7);
    md.Push(5);
    std::cout << md; // 5 5 7

    //Copy ctor testing
    Multiset<int> marcelo(ms);
    std::cout << marcelo; // 6 7 7 7 8

    //assignment operator testing
    md = ms;
    std::cout << md; // 6 7 7 7 8

    //transofrm using function testing
    ms.Transform(Incerementer);
    std::cout << ms; // 7 8 8 8 9

    Increment plusTwo(2);
    ms.Transform(plusTwo);
    std::cout << ms; // 9 10 10 10 11
    return 0;
}
