#ifndef MULTISET_POO3_MULTISET_H
#define MULTISET_POO3_MULTISET_H

#include<iostream>

template<class T>
class Multiset{
    struct Element{
        T information_;
        Element *next_;
        explicit Element(T value):information_(value), next_(NULL){};
    }*head_;
public:
    Multiset();
    Multiset(Multiset&);
    void Push(T);
    void Delete(T);
    void DeleteAll(T);
    unsigned int Count(const T) const;
    bool Belongs(const T) const;
    template <class U>friend std::ostream& operator<<(std::ostream&, const Multiset<U>&);
    template <class U> void Transform(U*);
    ~Multiset();
};

#include "Multiset.cpp"

#endif //MULTISET_POO3_MULTISET_H
