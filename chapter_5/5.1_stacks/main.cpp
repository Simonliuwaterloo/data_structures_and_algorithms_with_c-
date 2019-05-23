#include <iostream>
#include <stack>
//this is standard stack libratry

class StackEmpty: public std::runtime_error {
public:
    StackEmpty(const std::string& err): std::runtime_error(err) {}
};

class StackFull: public std::runtime_error {
public:
    StackFull(const std::string& err): std::runtime_error(err) {}
};


template <typename E>
class ArrayStack {
    //our implementation of stack with C++ array
    enum { DEF_CAPACITY = 100};
public:
    ArrayStack(int cap = DEF_CAPACITY);
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
void standard_stack_sample() {
    std::stack<int> my_stack;
    my_stack.push(5);
    std::cout << my_stack.top() << std::endl;
    my_stack.push(3);
    std::cout << my_stack.top() << std::endl;
    my_stack.pop();
    std::cout << my_stack.top() << std::endl;
    std::cout << "--------------" << std::endl;
}

void array_stack_sample() {
    ArrayStack<int> A(4);
    A.push(7);
    A.push(13);
    std::cout << A.top() << std::endl;
    A.pop();
    std::cout << A.top() << std::endl;
    A.push(2);
    std::cout << A.top() << std::endl;
    A.push(3);
    std::cout << A.top() << std::endl;
    A.push(4);
    std::cout << A.top() << std::endl;
    A.push(5);
    std::cout << A.top() << std::endl;
}
int main() {
    standard_stack_sample();
    array_stack_sample();
    return 0;
}