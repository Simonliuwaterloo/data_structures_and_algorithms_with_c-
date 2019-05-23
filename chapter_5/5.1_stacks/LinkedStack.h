#include "SLinkedList.h"
#include "StackFull.h"
#include "StackEmpty.h"

typedef std::string Elem;
class LinkedStack {
public:
    LinkedStack();
    int size() const;
    bool empty() const;
    const Elem& top() const throw(StackEmpty);
    void push(const Elem& e);
    void pop() throw(StackEmpty);

private:
    SLinkedList<Elem> S;
    int n;
};

LinkedStack::LinkedStack(){
    //note we didn't initialize S, default initialization will handle it
    n = 0;
}

int LinkedStack::size() const {
    return n;
}

bool LinkedStack::empty() const {
    return n == 0;
}

const Elem& LinkedStack::top() const throw(StackEmpty){
    return S.front();
}

void LinkedStack::push(const Elem &e) {
    S.addFront(e);
    ++n;
}

void LinkedStack::pop() throw(StackEmpty){
    if (S.empty()) {throw StackEmpty("stack is empty");}
    S.removeFront();
    --n;
}