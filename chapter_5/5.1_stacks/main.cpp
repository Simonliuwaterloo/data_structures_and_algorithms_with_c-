#include <iostream>
#include <stack>
#include <vector>
//this is standard stack libratry
#include "ArrayStack.h"
#include "LinkedStack.h"
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
//    A.push(5);
//    std::cout << A.top() << std::endl;
//throw an error
    std::cout << "--------------" << std::endl;

}

void linked_stack_sample() {
    LinkedStack L;
    L.push("H");
    std::cout << L.top() << std::endl;
    L.push("e");
    std::cout << L.top() << std::endl;
    L.pop();
    std::cout << L.top() << std::endl;
    std::cout << "--------------" << std::endl;

}

void reverse_vector_sample() {
    //reverse vector using stack
    std::vector<int> vect{10, 20, 30};
    for (int x : vect)
        std::cout << x << " ";
    std::cout << std::endl;
    ArrayStack<int> S(vect.size());
    for (int i = 0; i < vect.size(); ++i){
        S.push(vect[i]);
    }
    for (int i = 0; i < vect.size(); ++i){
        vect[i] = S.top();
        S.pop();
    }
    for (int x : vect)
        std::cout << x << " ";
    std::cout << std::endl;
    std::cout << std::endl << "--------------" << std::endl;
}
int main() {
    standard_stack_sample();
    array_stack_sample();
    linked_stack_sample();
    reverse_vector_sample();
    return 0;
}