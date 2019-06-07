#include "StackEmpty.h"
#include "StackFull.h"

template <typename E>
class ArrayStack {
    //our implementation of stack with C++ array
    enum { DEF_CAPACITY = 100};
public:
    ArrayStack(int cap = DEF_CAPACITY);
    ~ArrayStack();
    int size() const;
    bool empty() const;
    const E& top() const throw(StackEmpty);
    void push (const E& e) throw(StackFull);
    void pop() throw(StackEmpty);

private:
    E* S;
    int capacity;
    int t;

};


template <typename E>
ArrayStack<E>::ArrayStack(int cap) {
    S = new E[cap];
    t = -1;
    capacity = cap;
}

template <typename E>
ArrayStack<E>::~ArrayStack() {
    delete[] S;
    S = nullptr;
}

template <typename E>
int ArrayStack<E>::size() const {
    return t + 1;
}

template <typename E>
bool ArrayStack<E>::empty() const {
    return t < 0;
}

template <typename E>
const E& ArrayStack<E>::top() const throw(StackEmpty){
    if (empty()) throw StackEmpty("Top of empty stack");
    return S[t];
}

template <typename E>
void ArrayStack<E>::push(const E &e) throw(StackFull){
    if (size() < capacity) {
        S[++t] = e;
    }
    else {
        throw StackFull("stack has reached capacity");
    }
}

template  <typename E>
void ArrayStack<E>::pop() throw(StackEmpty) {
    if (!empty()) {
        --t;
    }
    else {
        throw StackEmpty("cannot pop an empty stack");
    }
}