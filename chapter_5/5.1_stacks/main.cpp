#include <iostream>
#include <stack>
//this is standard stack libratry
#include "ArrayStack.h"

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