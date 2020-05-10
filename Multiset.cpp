#include "Multiset.h"

template <class T>
Multiset<T>::Multiset():head_(NULL) {
}

template<class T>
Multiset<T>::Multiset(Multiset<T>& copyObj) {
}

template<class T>
void Multiset<T>::Push(T value) {
    if(head_ == NULL) {
        head_ = new Element(value);
        return;
    }

    Element* aux1 = head_;
    Element* aux2 = head_->next_;
    while(aux2 != NULL && aux2->information_ < value)
        aux1 = aux1->next_, aux2 = aux2->next_;
    auto newElem = new Element(value);
    aux1->next_ = newElem;
    newElem->next_ = aux2;
}

template<class T>
void Multiset<T>::Delete(T) {

}

template<class T>
void Multiset<T>::DeleteAll(T) {

}

template<class T>
unsigned int Multiset<T>::Count(const T) const {
    return 0;
}

template<class T>
bool Multiset<T>::Belongs(const T) const {
    return false;
}

template<class T>
std::ostream& operator<<(std::ostream& output, const Multiset<T>& set) {
    for(auto aux = set.head_; aux; aux=aux->next_)
        output << aux->information_ << " ";
    return output;
}

template<class T>
template<class U>
void Multiset<T>::Transform(U *) {

}

template <class T>
Multiset<T>::~Multiset() {
    auto aux = head_->next_;
    while(aux) {
        delete head_;
        head_ = aux;
        aux = aux->next_;
    }
    delete head_;
}
