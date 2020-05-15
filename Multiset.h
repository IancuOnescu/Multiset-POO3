#ifndef MULTISET_POO3_MULTISET_H
#define MULTISET_POO3_MULTISET_H

#include<iostream>
#define NDEBUG
#include<cassert>
#include<exception>

template<class T>
class Multiset{
    struct Element{
        T information_;
        Element *next_;
        explicit Element(T value):information_(value), next_(NULL){};
    }*head_;
    void Clear();
public:
    Multiset();
    Multiset(const Multiset<T>&);
    Multiset<T>& operator=(const Multiset<T>&);
    void Push(T);
    void Delete(T);
    void DeleteAll(T);
    unsigned int Count(T) const;
    unsigned int CountAll() const;
    bool Belongs(T) const;
    template <class U> friend std::ostream& operator<<(std::ostream&, const Multiset<U>&);
    template <class U> void Transform(U);
    ~Multiset();
};

#include "Multiset.cpp"

#endif //MULTISET_POO3_MULTISET_H
