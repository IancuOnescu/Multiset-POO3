#include "Multiset.h"

template<class T>
void Multiset<T>::Clear() {
    if(head_ == NULL)
        return;
    auto aux = head_->next_;
    while(aux) {
        delete head_;
        head_ = aux;
        aux = aux->next_;
    }
    delete head_;
    head_ = NULL;
}

template <class T>
Multiset<T>::Multiset():head_(NULL){
}

template<class T>
Multiset<T>::Multiset(const Multiset<T>& objToCopy):Multiset(){
    *this = objToCopy;
}

template<class T>
Multiset<T>& Multiset<T>::operator=(const Multiset<T>& objToCopy) {
    if(&objToCopy == this)
        return *this;
    Clear();
    auto aux = objToCopy.head_;
    while (aux){
        Push(aux->information_);
        aux = aux->next_;
    }
    return *this;
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
void Multiset<T>::Delete(T value) {
    if(head_->information_ == value){
        auto aux = head_->next_;
        delete head_;
        head_ = aux;
        return;
    }

    auto aux1 = head_;
    auto aux2 = head_->next_;
    while(aux2 != NULL && aux2->information_ != value)
        aux1 = aux1->next_, aux2 = aux2->next_;
    if(aux2 == NULL)
        return;
    aux1->next_ = aux2->next_;
    delete aux2;

}

template<class T>
void Multiset<T>::DeleteAll(T value) {
    while(Belongs(value))
        Delete(value);
}

template<class T>
unsigned int Multiset<T>::Count(const T value) const {
    unsigned int counter = 0;
    for(auto aux = head_; aux; aux = aux->next_)
        if(aux->information_ == value)
            ++counter;
    return counter;
}

template<class T>
unsigned int Multiset<T>::CountAll() const {
    unsigned int counter = 0;
    for(auto aux = head_; aux->next_; aux = aux->next_)
        if(aux->information_ != aux->next_->information_)
            ++counter;
    return counter+1;
}

template<class T>
bool Multiset<T>::Belongs(const T value) const {
    for(auto aux = head_; aux; aux=aux->next_)
        if(aux->information_ == value)
            return true;
    return false;
}

template<class T>
std::ostream& operator<<(std::ostream& output, const Multiset<T>& set) {
    for(auto aux = set.head_; aux; aux=aux->next_)
        output << aux->information_ << " ";
    output << std::endl;
    return output;
}

template<class T>
template<class U>
void Multiset<T>::Transform(U transform) {
    for(auto aux = head_; aux; aux = aux->next_)
        aux->information_ = transform(aux->information_);
}

template <class T>
Multiset<T>::~Multiset() {
    Clear();
}
